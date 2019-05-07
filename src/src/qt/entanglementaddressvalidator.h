// Copyright (c) 2009-2017 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Developers
// Copyright (c) 2017 Entanglement Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ENTANGLEMENT_QT_ENTANGLEMENTADDRESSVALIDATOR_H
#define ENTANGLEMENT_QT_ENTANGLEMENTADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class EntanglementAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit EntanglementAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Entanglement address widget validator, checks for a valid Entanglement address.
 */
class EntanglementAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit EntanglementAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // ENTANGLEMENT_QT_ENTANGLEMENTADDRESSVALIDATOR_H
