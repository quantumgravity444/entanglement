// Copyright (c) 2009-2017 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Developers
// Copyright (c) 2017 Entanglement Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "entanglementunits.h"

#include "chainparams.h"
#include "primitives/transaction.h"

#include <QSettings>
#include <QStringList>

EntanglementUnits::EntanglementUnits(QObject *parent):
        QAbstractListModel(parent),
        unitlist(availableUnits())
{
}

QList<EntanglementUnits::Unit> EntanglementUnits::availableUnits()
{
    QList<EntanglementUnits::Unit> unitlist;
    unitlist.append(ETG);
    unitlist.append(mETG);
    unitlist.append(uETG);
    return unitlist;
}

bool EntanglementUnits::valid(int unit)
{
    switch(unit)
    {
    case ETG:
    case mETG:
    case uETG:
        return true;
    default:
        return false;
    }
}

QString EntanglementUnits::id(int unit)
{
    switch(unit)
    {
    case ETG: return QString("ETG");
    case mETG: return QString("mETG");
    case uETG: return QString("uETG");
    default: return QString("???");
    }
}

QString EntanglementUnits::name(int unit)
{
    if(Params().NetworkIDString() == CBaseChainParams::MAIN)
    {
        switch(unit)
        {
        case ETG: return QString("ETG");
        case mETG: return QString("mETG");
        case uETG: return QString::fromUtf8("μSEQ");
        default: return QString("???");
        }
    }
    else
    {
        switch(unit)
        {
            case ETG: return QString("tETG");
            case mETG: return QString("mtETG");
            case uETG: return QString::fromUtf8("μtETG");
            default: return QString("???");
        }
    }
}

QString EntanglementUnits::description(int unit)
{
    if(Params().NetworkIDString() == CBaseChainParams::MAIN)
    {
        switch(unit)
        {
        case ETG: return QString("Entanglement");
        case mETG: return QString("Milli-Entanglement (1 / 1" THIN_SP_UTF8 "000)");
        case uETG: return QString("Micro-Entanglement (1 / 1" THIN_SP_UTF8 "000" THIN_SP_UTF8 "000)");
        default: return QString("???");
        }
    }
    else
    {
        switch(unit)
        {
            case ETG: return QString("TestEntanglement");
            case mETG: return QString("Milli-TestEntanglement (1 / 1" THIN_SP_UTF8 "000)");
            case uETG: return QString("Micro-TestEntanglement (1 / 1" THIN_SP_UTF8 "000" THIN_SP_UTF8 "000)");
            default: return QString("???");
        }
    }
}

qint64 EntanglementUnits::factor(int unit)
{
    switch(unit)
    {
    case ETG:  return 100000000;
    case mETG: return 100000;
    case uETG: return 100;
    default:   return 100000000;
    }
}

int EntanglementUnits::decimals(int unit)
{
    switch(unit)
    {
    case ETG: return 8;
    case mETG: return 5;
    case uETG: return 2;
    default: return 0;
    }
}

QString EntanglementUnits::format(int unit, const CAmount& nIn, bool fPlus, SeparatorStyle separators)
{
    // Note: not using straight sprintf here because we do NOT want
    // localized number formatting.
    if(!valid(unit))
        return QString(); // Refuse to format invalid unit
    qint64 n = (qint64)nIn;
    qint64 coin = factor(unit);
    int num_decimals = decimals(unit);
    qint64 n_abs = (n > 0 ? n : -n);
    qint64 quotient = n_abs / coin;
    qint64 remainder = n_abs % coin;
    QString quotient_str = QString::number(quotient);
    QString remainder_str = QString::number(remainder).rightJustified(num_decimals, '0');

    // Use SI-style thin space separators as these are locale independent and can't be
    // confused with the decimal marker.
    QChar thin_sp(THIN_SP_CP);
    int q_size = quotient_str.size();
    if (separators == separatorAlways || (separators == separatorStandard && q_size > 4))
        for (int i = 3; i < q_size; i += 3)
            quotient_str.insert(q_size - i, thin_sp);

    if (n < 0)
        quotient_str.insert(0, '-');
    else if (fPlus && n > 0)
        quotient_str.insert(0, '+');

    if (num_decimals <= 0)
        return quotient_str;

    return quotient_str + QString(".") + remainder_str;
}


// TODO: Review all remaining calls to EntanglementUnits::formatWithUnit to
// TODO: determine whether the output is used in a plain text context
// TODO: or an HTML context (and replace with
// TODO: EntanglementUnits::formatHtmlWithUnit in the latter case). Hopefully
// TODO: there aren't instances where the result could be used in
// TODO: either context.

// NOTE: Using formatWithUnit in an HTML context risks wrapping
// quantities at the thousands separator. More subtly, it also results
// in a standard space rather than a thin space, due to a bug in Qt's
// XML whitespace canonicalisation
//
// Please take care to use formatHtmlWithUnit instead, when
// appropriate.

QString EntanglementUnits::formatWithUnit(int unit, const CAmount& amount, bool plussign, SeparatorStyle separators)
{
    return format(unit, amount, plussign, separators) + QString(" ") + name(unit);
}

QString EntanglementUnits::formatHtmlWithUnit(int unit, const CAmount& amount, bool plussign, SeparatorStyle separators)
{
    QString str(formatWithUnit(unit, amount, plussign, separators));
    str.replace(QChar(THIN_SP_CP), QString(THIN_SP_HTML));
    return QString("<span style='white-space: nowrap;'>%1</span>").arg(str);
}

QString EntanglementUnits::floorWithUnit(int unit, const CAmount& amount, bool plussign, SeparatorStyle separators)
{
    QSettings settings;
    int digits = settings.value("digits").toInt();

    QString result = format(unit, amount, plussign, separators);
    if(decimals(unit) > digits) result.chop(decimals(unit) - digits);

    return result + QString(" ") + name(unit);
}

QString EntanglementUnits::floorHtmlWithUnit(int unit, const CAmount& amount, bool plussign, SeparatorStyle separators)
{
    QString str(floorWithUnit(unit, amount, plussign, separators));
    str.replace(QChar(THIN_SP_CP), QString(THIN_SP_HTML));
    return QString("<span style='white-space: nowrap;'>%1</span>").arg(str);
}

bool EntanglementUnits::parse(int unit, const QString &value, CAmount *val_out)
{
    if(!valid(unit) || value.isEmpty())
        return false; // Refuse to parse invalid unit or empty string
    int num_decimals = decimals(unit);

    // Ignore spaces and thin spaces when parsing
    QStringList parts = removeSpaces(value).split(".");

    if(parts.size() > 2)
    {
        return false; // More than one dot
    }
    QString whole = parts[0];
    QString decimals;

    if(parts.size() > 1)
    {
        decimals = parts[1];
    }
    if(decimals.size() > num_decimals)
    {
        return false; // Exceeds max precision
    }
    bool ok = false;
    QString str = whole + decimals.leftJustified(num_decimals, '0');

    if(str.size() > 18)
    {
        return false; // Longer numbers will exceed 63 bits
    }
    CAmount retvalue(str.toLongLong(&ok));
    if(val_out)
    {
        *val_out = retvalue;
    }
    return ok;
}

QString EntanglementUnits::getAmountColumnTitle(int unit)
{
    QString amountTitle = QObject::tr("Amount");
    if (EntanglementUnits::valid(unit))
    {
        amountTitle += " ("+EntanglementUnits::name(unit) + ")";
    }
    return amountTitle;
}

int EntanglementUnits::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return unitlist.size();
}

QVariant EntanglementUnits::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row >= 0 && row < unitlist.size())
    {
        Unit unit = unitlist.at(row);
        switch(role)
        {
        case Qt::EditRole:
        case Qt::DisplayRole:
            return QVariant(name(unit));
        case Qt::ToolTipRole:
            return QVariant(description(unit));
        case UnitRole:
            return QVariant(static_cast<int>(unit));
        }
    }
    return QVariant();
}

CAmount EntanglementUnits::maxMoney()
{
    return MAX_MONEY;
}