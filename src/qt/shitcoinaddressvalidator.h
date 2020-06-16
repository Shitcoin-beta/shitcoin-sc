// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SHITCOIN_QT_SHITCOINADDRESSVALIDATOR_H
#define SHITCOIN_QT_SHITCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class ShitcoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ShitcoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Shitcoin address widget validator, checks for a valid shitcoin address.
 */
class ShitcoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ShitcoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // SHITCOIN_QT_SHITCOINADDRESSVALIDATOR_H
