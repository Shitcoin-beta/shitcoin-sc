// Copyright (c) 2016-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SHITCOIN_WALLET_RPCWALLET_H
#define SHITCOIN_WALLET_RPCWALLET_H

#include <string>

class CRPCTable;
class CWallet;
class JSONRPCRequest;
class UniValue;
struct PartiallySignedTransaction;
class CTransaction;

void RegisterWalletRPCCommands(CRPCTable &t);

/**
 * Figures out what wallet, if any, to use for a JSONRPCRequest.
 *
 * @param[in] request JSONRPCRequest that wishes to access a wallet
 * @return nullptr if no wallet should be used, or a pointer to the CWallet
 */
std::shared_ptr<CWallet> GetWalletForJSONRPCRequest(const JSONRPCRequest& request);

std::string HelpRequiringPassphrase(CWallet *);
void EnsureWalletIsUnlocked(CWallet *);
bool EnsureWalletIsAvailable(CWallet *, bool avoidException);

UniValue getaddressinfo(const JSONRPCRequest& request);
UniValue signrawtransactionwithwallet(const JSONRPCRequest& request);
bool FillPSBT(const CWallet* pwallet, PartiallySignedTransaction& psbtx, int sighash_type = 1 /* SIGHASH_ALL */, bool sign = true, bool bip32derivs = false);
#endif //SHITCOIN_WALLET_RPCWALLET_H
