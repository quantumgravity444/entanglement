// Copyright (c) 2009-2017 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Developers
// Copyright (c) 2017 Entanglement Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ENTANGLEMENT_CHECKPOINTS_H
#define ENTANGLEMENT_CHECKPOINTS_H

#include "serialize.h"
#include "sync.h"
#include "uint256.h"

#include <map>

class CBlockIndex;
struct CCheckpointData;
class CNode;
class CSyncCheckpoint;


/** 
 * Block-chain checkpoints are compiled-in sanity checks.
 * They are updated every release or three.
 */
namespace Checkpoints
{
//! Returns true if block passes checkpoint checks
bool CheckBlock(const CCheckpointData& data, int nHeight, const uint256& hash);

//! Return conservative estimate of total number of blocks, 0 if unknown
int GetTotalBlocksEstimate(const CCheckpointData& data);

//! Returns last CBlockIndex* in mapBlockIndex that is a checkpoint
CBlockIndex* GetLastCheckpoint(const CCheckpointData& data);

double GuessVerificationProgress(const CCheckpointData& data, CBlockIndex* pindex, bool fSigchecks = true);

} //namespace Checkpoints

namespace CheckpointsSync
{

    extern uint256 hashSyncCheckpoint;
    extern CSyncCheckpoint checkpointMessage;
    extern uint256 hashInvalidCheckpoint;
    extern CCriticalSection cs_hashSyncCheckpoint;

    bool WriteSyncCheckpoint(const uint256& hashCheckpoint);
    bool AcceptPendingSyncCheckpoint();
    uint256 AutoSelectSyncCheckpoint();
    bool CheckSync(const uint256& hashBlock, const CBlockIndex* pindexPrev);
    bool ResetSyncCheckpoint(const CCheckpointData& data);
    bool SetCheckpointPrivKey(std::string strPrivKey);
    bool SendSyncCheckpoint(uint256 hashCheckpoint);

}  //namespace CheckpointsSync

// ppcoin: synchronized checkpoint
class CUnsignedSyncCheckpoint
{
public:
    int nVersion;
    uint256 hashCheckpoint;      // checkpoint block

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action, int nType, int nVersion) {
        READWRITE(this->nVersion);
        nVersion = this->nVersion;
        READWRITE(hashCheckpoint);
    }

    void SetNull()
    {
        nVersion = 1;
        hashCheckpoint = 0;
    }

    std::string ToString() const;

    void print() const;
};

class CSyncCheckpoint : public CUnsignedSyncCheckpoint
{
public:
    static const std::string strMasterPubKey;
    static std::string strMasterPrivKey;

    std::vector<unsigned char> vchMsg;
    std::vector<unsigned char> vchSig;

    CSyncCheckpoint()
    {
        SetNull();
    }

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action, int nType, int nVersion) {
        READWRITE(vchMsg);
        READWRITE(vchSig);
    }

    void SetNull()
    {
        CUnsignedSyncCheckpoint::SetNull();
        vchMsg.clear();
        vchSig.clear();
    }

    bool IsNull() const
    {
        return (hashCheckpoint == 0);
    }

    uint256 GetHash() const;

    bool RelayTo(CNode* pnode) const;

    bool CheckSignature();
    bool ProcessSyncCheckpoint();
};

#endif // ENTANGLEMENT_CHECKPOINTS_H
