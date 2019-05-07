// Copyright (c) 2009-2017 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Developers
// Copyright (c) 2013-2017 Emercoin Developers
// Copyright (c) 2017 Entanglement Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef NAMETABLEMODEL_H
#define NAMETABLEMODEL_H

#include "uint256.h"

#include <QAbstractTableModel>
#include <QStringList>

#include <vector>

class NameTablePriv;
class CWallet;
class WalletModel;

/**
   Qt model for "DNS" page.
 */
class NameTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit NameTableModel(CWallet *wallet, WalletModel *parent = 0);
    ~NameTableModel();

    bool fMyNames;
    bool fOtherNames;
    bool fExpired;

    enum ColumnIndex {
        Name = 0,
        Value = 1,
        Address = 2,
        ExpiresIn = 3
    };

    /** @name Methods overridden from QAbstractTableModel
        @{*/
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    /*@}*/

private:
    WalletModel *walletModel;
    CWallet *wallet;
    QStringList columns;
    NameTablePriv *priv;
    int cachedNumBlocks;

    /** Notify listeners that data changed. */
    void emitDataChanged(int index);

public Q_SLOTS:
    void updateEntry(const QString &name, const QString &value, const QString &address, int nHeight, int status, int *outNewRowIndex = NULL);
    void update(bool forced = false);

    friend class NameTablePriv;
};

struct NameTableEntry
{
    QString name;
    QString value;
    QString address;
    int nExpiresAt;
    bool fIsMine;

    // for pending (not yet in a block) name operations
    static const int NAME_NEW = -1;
    static const int NAME_UPDATE = -2;
    static const int NAME_DELETE = -3;
    static const int NAME_NON_EXISTING = -4; //no pending operation, just a blank
    static const int NAME_MULTISIG = -5;
    
    bool HeightValid() { return nExpiresAt >= 0; }

    NameTableEntry() : nExpiresAt(NAME_NON_EXISTING), fIsMine(true) {}
    NameTableEntry(const QString &name, const QString &value, const QString &address, int nExpiresAt, bool fIsMine = true) :
        name(name), value(value), address(address), nExpiresAt(nExpiresAt), fIsMine(fIsMine) {}
    NameTableEntry(const std::string &name, const std::string &value, const std::string &address, int nExpiresAt, bool fIsMine = true) :
        name(QString::fromStdString(name)), value(QString::fromStdString(value)), address(QString::fromStdString(address)), nExpiresAt(nExpiresAt), fIsMine(fIsMine) {}
};

#endif // NAMETABLEMODEL_H
