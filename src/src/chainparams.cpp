// Copyright (c) 2009-2017 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Developers
// Copyright (c) 2017 Entanglement Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "chainparamsseeds.h"
#include "consensus/merkle.h"
#include "random.h"
#include "tinyformat.h"
#include "util.h"
#include "utilstrencodings.h"
#include "uint256.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

void MineGenesis(CBlock genesis, uint256 bnProofOfWorkLimit){
    // This will figure out a valid hash and Nonce if you're creating a different genesis block:
    uint256 hashTarget = bnProofOfWorkLimit;
    printf("Target: %s\n", hashTarget.GetHex().c_str());
    uint256 newhash = genesis.GetHash();
    uint256 besthash;
    memset(&besthash,0xFF,32);
    while (newhash > hashTarget) {
        ++genesis.nNonce;
        if (genesis.nNonce == 0){
            printf("NONCE WRAPPED, incrementing time");
            ++genesis.nTime;
        }
    newhash = genesis.GetHash();
    if(newhash < besthash){
        besthash=newhash;
        printf("New best: %s\n", newhash.GetHex().c_str());
    }
    }
    printf("Genesis Hash: %s\n", genesis.GetHash().ToString().c_str());
    printf("Genesis Hash Merkle: %s\n", genesis.hashMerkleRoot.ToString().c_str());
    printf("Genesis nTime: %u\n", genesis.nTime);
    printf("Genesis nBits: %08x\n", genesis.nBits);
    printf("Genesis Nonce: %u\n\n\n", genesis.nNonce);
}

/**
 * Main network
 */
static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    std::vector<CTxIn> vin;
    vin.resize(1);
    vin[0].scriptSig = CScript() << 1473949500 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    std::vector<CTxOut> vout;
    vout.resize(1);
    vout[0].scriptPubKey = genesisOutputScript;
    vout[0].nValue = 0;
    CMutableTransaction txNew(1, 1473949300, vin, vout, 0);

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(txNew);
    genesis.hashPrevBlock = 0;
    genesis.hashMerkleRoot = genesis.BuildMerkleTree();

    return genesis;
}

static CBlock CreateTestNetGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    std::vector<CTxIn> vin;
    vin.resize(1);
    vin[0].scriptSig = CScript() << 1473949300 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    std::vector<CTxOut> vout;
    vout.resize(1);
    vout[0].scriptPubKey = genesisOutputScript;
    vout[0].nValue = 0;
    CMutableTransaction txNew(1, 1478106900, vin, vout, 0);

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(txNew);
    genesis.hashPrevBlock = 0;
    genesis.hashMerkleRoot = genesis.BuildMerkleTree();

    return genesis;
}

static CBlock CreateTestNetGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "Some String";
    const CScript genesisOutputScript = CScript() << ParseHex("") << OP_CHECKSIG;
    return CreateTestNetGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "Some String";
    const CScript genesisOutputScript = CScript() << ParseHex("") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.bnProofOfWorkLimit = ~uint256(0) >> 26;
        consensus.bnProofOfStakeLimit = ~uint256(0) >> 26;
        consensus.nEnforceBlockUpgradeMajority = 750;
        consensus.nRejectBlockOutdatedMajority = 950;
        consensus.nToCheckBlockUpgradeMajority = 1000;
        consensus.nMinerThreads = 0;
        consensus.nTargetSpacingMax = 1 * 30;     // 64 second max spacing target
        consensus.nPoWTargetSpacing = 1 * 30;     // 30 seconds PoW Target
        consensus.fAllowMinDifficultyBlocks = false;
        consensus.nPoSTargetSpacing = 1 * 30;     // 30 seconds PoS Target
        consensus.nStakeMinAge = 1 * 60 * 60;     // 1 hour minimum stake age
        consensus.nStakeMaxAge = std::numeric_limits<int64_t>::max(); // Unlimited stake age
        consensus.nModifierInterval = 15 * 60;    // 15 minutes to elapse before new modifier is computed
        consensus.nLastPOWBlock = 101325;          // Proof of Work finishes on block 10000
        bool startNewChain = false;

        genesis = CreateGenesisBlock(1473949500, 37239843, consensus.bnProofOfWorkLimit.GetCompact(), 1, (0 * COIN));
        
        consensus.hashGenesisBlock = genesis.GetHash();

        assert(consensus.hashGenesisBlock == uint256("0x"));
        assert(genesis.hashMerkleRoot == uint256("0x"));

        //TODO: DNS Seeder
        vSeeds.push_back(CDNSSeedData("", ""));
        vSeeds.push_back(CDNSSeedData("", ""));

        // Entanglement PUBKEY_ADDRESS addresses start with 'E'
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,33);
        // Entanglement SCRIPT_ADDRESS addresses start with 'G'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,38);
        // Entanglement SECRET_KEY start with '2'
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,170);
        // Entanglement BIP32 pubkeys start with 'xpub' (Bitcoin defaults)
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x88, 0xB2, 0x1E};
        // Entanglement BIP32 prvkeys start with 'xprv' (Bitcoin defaults)
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x88, 0xAD, 0xE4};
        // Entanglement BIP44 coin type is '5'
        nExtCoinType = 5;

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));

        pchMessageStart[0] = 0x02;
        pchMessageStart[1] = 0x11;
        pchMessageStart[2] = 0x22;
        pchMessageStart[3] = 0x01;
        //TODO: Parse hex
        vAlertPubKey = ParseHex("");
        nDefaultPort = 51000;
        nMaxTipAge = 24 * 60 * 60;

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = false;

        checkpointData = (CCheckpointData) {
            boost::assign::map_list_of
            ( 0, uint256("0x")),
            1486676814, // * UNIX timestamp of last checkpoint block
            0,          // * total number of transactions between genesis and last checkpoint
						  //   (the tx=... number in the SetBestChain debug.log lines)
            2000        // * estimated number of transactions per day after checkpoint
        };
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
        strNetworkID = "test";
        consensus.bnProofOfWorkLimit = ~uint256(0) >> 26;
        consensus.bnProofOfStakeLimit = ~uint256(0) >> 26;
        consensus.nEnforceBlockUpgradeMajority = 51;
        consensus.nRejectBlockOutdatedMajority = 75;
        consensus.nToCheckBlockUpgradeMajority = 100;
        consensus.nMinerThreads = 0;
        consensus.fAllowMinDifficultyBlocks = false;
        consensus.nStakeMinAge = 30 * 60;         // 30 minute minimum stake age
        consensus.nModifierInterval = 15 * 60;    // 15 minutes to elapse before new modifier is computed
        consensus.nLastPOWBlock = 100000;         // Proof of Work finishes on block 300000
        bool startNewChain = false;

        genesis = CreateTestNetGenesisBlock(1478107000, 82131309, consensus.bnProofOfWorkLimit.GetCompact(), 1, (0 * COIN));
        if(startNewChain == true) { MineGenesis(genesis, consensus.bnProofOfWorkLimit); }
        consensus.hashGenesisBlock = genesis.GetHash();

        assert(consensus.hashGenesisBlock == uint256("0x"));
        assert(genesis.hashMerkleRoot == uint256("0x"));

        vFixedSeeds.clear();
        vSeeds.clear();

        // Entanglement PUBKEY_ADDRESS addresses start with 'R'
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,60);
        // Entanglement PUBKEY_ADDRESS addresses start with 'B'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,25);
        // Entanglement SECRET_KEY start with 'X or 7'
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,204);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x11, 0x35, 0xAA, 0xEE};
        base58Prefixes[EXT_SECRET_KEY] = {0x35, 0x11, 0xDD, 0xFF};
        nExtCoinType = 1;

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));

        pchMessageStart[0] = 0x22;
        pchMessageStart[1] = 0x21;
        pchMessageStart[2] = 0x04;
        pchMessageStart[3] = 0x34;
        vAlertPubKey = ParseHex("");
        nDefaultPort = 52000;
        nMaxTipAge = 24 * 60 * 60;

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        
        checkpointData = (CCheckpointData) {
            boost::assign::map_list_of
            ( 0, uint256("0x")),
            1478107000, // * UNIX timestamp of last checkpoint block
            0,          // * total number of transactions between genesis and last checkpoint
						  //   (the tx=... number in the SetBestChain debug.log lines)
            2000        // * estimated number of transactions per day after checkpoint
        };
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CChainParams {
public:
    CRegTestParams() {
        strNetworkID = "regtest";
        consensus.nEnforceBlockUpgradeMajority = 750;
        consensus.nRejectBlockOutdatedMajority = 950;
        consensus.nToCheckBlockUpgradeMajority = 1000;
        consensus.nMinerThreads = 1;
        consensus.bnProofOfWorkLimit = ~uint256(0) >> 22;
        consensus.bnProofOfStakeLimit = ~uint256(0) >> 22;
        consensus.fAllowMinDifficultyBlocks = true;
        consensus.nLastPOWBlock = 100;    // Proof of Work finishes on block 100
        
        genesis = CreateGenesisBlock(1473949500, 1427578, 0x1e00ffff, 1, (0 * COIN));
        
        consensus.hashGenesisBlock = genesis.GetHash();

        assert(consensus.hashGenesisBlock == uint256("0x"));
        assert(genesis.hashMerkleRoot == uint256("0x"));

        vFixedSeeds.clear(); //! Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();  //! Regtest mode doesn't have any DNS seeds.

        nExtCoinType = 1;

        pchMessageStart[0] = 0x44;
        pchMessageStart[1] = 0x02;
        pchMessageStart[2] = 0x55;
        pchMessageStart[3] = 0x05;
        nDefaultPort = 53000;
        nMaxTipAge = 24 * 60 * 60;

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
        
        checkpointData = (CCheckpointData) {
            boost::assign::map_list_of
            ( 0, uint256("0x")),
            1473949500, // * UNIX timestamp of last checkpoint block
            0,          // * total number of transactions between genesis and last checkpoint
						  //   (the tx=... number in the SetBestChain debug.log lines)
            2000        // * estimated number of transactions per day after checkpoint
        };
    }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = 0;

const CChainParams &Params() {
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN)
        return mainParams;
    else if (chain == CBaseChainParams::TESTNET)
        return testNetParams;
    else if (chain == CBaseChainParams::REGTEST)
        return regTestParams;
    else
        throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectParams(const std::string& network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}
