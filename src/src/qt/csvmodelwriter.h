// Copyright (c) 2009-2017 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Developers
// Copyright (c) 2017 Entanglement Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ENTANGLEMENT_QT_CSVMODELWRITER_H
#define ENTANGLEMENT_QT_CSVMODELWRITER_H

#include <QList>
#include <QObject>

QT_BEGIN_NAMESPACE
class QAbstractItemModel;
QT_END_NAMESPACE

/** Export a Qt table model to a CSV file. This is useful for analyzing or post-processing the data in
    a spreadsheet.
 */
class CSVModelWriter : public QObject
{
    Q_OBJECT

public:
    explicit CSVModelWriter(const QString &filename, QObject *parent = 0);

    void setModel(const QAbstractItemModel *model);
    void addColumn(const QString &title, int column, int role=Qt::EditRole);

    /** Perform export of the model to CSV.
        @returns true on success, false otherwise
    */
    bool write();

private:
    QString filename;
    const QAbstractItemModel *model;

    struct Column
    {
        QString title;
        int column;
        int role;
    };
    QList<Column> columns;
};

#endif // ENTANGLEMENT_QT_CSVMODELWRITER_H
