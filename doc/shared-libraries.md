Shared Libraries
================

## shitcoinconsensus

The purpose of this library is to make the verification functionality that is critical to Shitcoin's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `shitcoinconsensus.h` located in  `src/script/shitcoinconsensus.h`.

#### Version

`shitcoinconsensus_version` returns an `unsigned int` with the API version *(currently at an experimental `0`)*.

#### Script Validation

`shitcoinconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `shitcoinconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `shitcoinconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `shitcoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/shitcoin/bips/blob/master/bip-0016.mediawiki)) subscripts
- `shitcoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/shitcoin/bips/blob/master/bip-0066.mediawiki)) compliance
- `shitcoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY` - Enforce NULLDUMMY ([BIP147](https://github.com/shitcoin/bips/blob/master/bip-0147.mediawiki))
- `shitcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY` - Enable CHECKLOCKTIMEVERIFY ([BIP65](https://github.com/shitcoin/bips/blob/master/bip-0065.mediawiki))
- `shitcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY` - Enable CHECKSEQUENCEVERIFY ([BIP112](https://github.com/shitcoin/bips/blob/master/bip-0112.mediawiki))
- `shitcoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS` - Enable WITNESS ([BIP141](https://github.com/shitcoin/bips/blob/master/bip-0141.mediawiki))

##### Errors
- `shitcoinconsensus_ERR_OK` - No errors with input parameters *(see the return value of `shitcoinconsensus_verify_script` for the verification status)*
- `shitcoinconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `shitcoinconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `shitcoinconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`
- `shitcoinconsensus_ERR_AMOUNT_REQUIRED` - Input amount is required if WITNESS is used

### Example Implementations
- [NShitcoin](https://github.com/NicolasDorier/NShitcoin/blob/master/NShitcoin/Script.cs#L814) (.NET Bindings)
- [node-libshitcoinconsensus](https://github.com/bitpay/node-libshitcoinconsensus) (Node.js Bindings)
- [java-libshitcoinconsensus](https://github.com/dexX7/java-libshitcoinconsensus) (Java Bindings)
- [shitcoinconsensus-php](https://github.com/Bit-Wasp/shitcoinconsensus-php) (PHP Bindings)
