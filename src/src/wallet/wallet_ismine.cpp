// Copyright (c) 2009-2017 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Developers
// Copyright (c) 2017 Entanglement Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "wallet/wallet_ismine.h"

#include "hooks.h"
#include "key.h"
#include "keystore.h"
#include "script/script.h"
#include "script/standard.h"


using namespace std;

unsigned int HaveKeys(const vector<valtype>& pubkeys, const CKeyStore& keystore)
{
    unsigned int nResult = 0;
    for(const valtype& pubkey : pubkeys)
    {
        CKeyID keyID = CPubKey(pubkey).GetID();
        if (keystore.HaveKey(keyID))
            ++nResult;
    }
    return nResult;
}

isminetype IsMineInner(const CKeyStore &keystore, const CScript& scriptPubKey, txnouttype& whichType)
{
    vector<valtype> vSolutions;
    if (!Solver(scriptPubKey, whichType, vSolutions)) {
        if (keystore.HaveWatchOnly(scriptPubKey))
            return ISMINE_WATCH_ONLY;
        return ISMINE_NO;
    }

    CKeyID keyID;
    switch (whichType)
    {
    case TX_NONSTANDARD:
    case TX_NULL_DATA:
        break;
    case TX_PUBKEY:
        keyID = CPubKey(vSolutions[0]).GetID();
        if (keystore.HaveKey(keyID))
            return ISMINE_SPENDABLE;
        break;
    case TX_PUBKEYHASH:
    case TX_NAME:
        keyID = CKeyID(uint160(vSolutions[0]));
        if (keystore.HaveKey(keyID))
            return ISMINE_SPENDABLE;
        break;
    case TX_SCRIPTHASH:
    {
        CScriptID scriptID = CScriptID(uint160(vSolutions[0]));
        CScript subscript;
        if (keystore.GetCScript(scriptID, subscript)) {
            isminetype ret = IsMine(keystore, subscript);
            if (ret == ISMINE_SPENDABLE)
                return ret;
        }
        break;
    }
    case TX_MULTISIG:
    {
        // Only consider transactions "mine" if we own ALL the
        // keys involved. multi-signature transactions that are
        // partially owned (somebody else has a key that can spend
        // them) enable spend-out-from-under-you attacks, especially
        // in shared-wallet situations.
        vector<valtype> keys(vSolutions.begin()+1, vSolutions.begin()+vSolutions.size()-1);
        if (HaveKeys(keys, keystore) == keys.size())
            return ISMINE_SPENDABLE;
        break;
    }
    }

    if (keystore.HaveWatchOnly(scriptPubKey))
        return ISMINE_WATCH_ONLY;
    return ISMINE_NO;
}

isminetype IsMine(const CKeyStore &keystore, const CTxDestination& dest)
{
    CScript script = GetScriptForDestination(dest);
    txnouttype whichType;
    return IsMineInner(keystore, script, whichType);
}

isminetype IsMine(const CKeyStore &keystore, const CScript& scriptPubKey)
{
    txnouttype whichType;
    return IsMineInner(keystore, scriptPubKey, whichType);
}

// normal check + name check
isminetype IsMine(const CKeyStore &keystore, const CScript& scriptPubKey, bool &fName)
{
    fName = false;
    txnouttype whichType;
    isminetype ret = IsMineInner(keystore, scriptPubKey, whichType);
    fName = whichType == TX_NAME;

    return ret;
}
