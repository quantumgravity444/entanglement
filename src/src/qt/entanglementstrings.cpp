// Copyright (c) 2009-2017 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Developers
// Copyright (c) 2017 Entanglement Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <QtGlobal>

// Automatically generated by extract_strings.py
#ifdef __GNUC__
#define UNUSED __attribute__((unused))
#else
#define UNUSED
#endif
static const char UNUSED *sequence_strings[] = {
QT_TRANSLATE_NOOP("entanglement", ""
"(1 = keep tx meta data e.g. account owner and payment request information, 2 "
"= drop tx meta data)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Allow JSON-RPC connections from specified source. Valid for <ip> are a "
"single IP (e.g. 1.2.3.4), a network/netmask (e.g. 1.2.3.4/255.255.255.0) or "
"a network/CIDR (e.g. 1.2.3.4/24). This option can be specified multiple times"),
QT_TRANSLATE_NOOP("entanglement", ""
"An error occurred while setting up the RPC address %s port %u for listening: "
"%s"),
QT_TRANSLATE_NOOP("entanglement", ""
"Bind to given address and always listen on it. Use [host]:port notation for "
"IPv6"),
QT_TRANSLATE_NOOP("entanglement", ""
"Bind to given address and whitelist peers connecting to it. Use [host]:port "
"notation for IPv6"),
QT_TRANSLATE_NOOP("entanglement", ""
"Bind to given address to listen for JSON-RPC connections. Use [host]:port "
"notation for IPv6. This option can be specified multiple times (default: "
"bind to all interfaces)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Cannot obtain a lock on data directory %s. Entanglement is probably already "
"running."),
QT_TRANSLATE_NOOP("entanglement", ""
"Continuously rate-limit free transactions to <n>*1000 bytes per minute "
"(default:%u)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Create new files with system default permissions, instead of umask 077 (only "
"effective with disabled wallet functionality)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Delete all wallet transactions and only recover those parts of the "
"blockchain through -rescan on startup"),
QT_TRANSLATE_NOOP("entanglement", ""
"Distributed under the MIT software license, see the accompanying file "
"COPYING or <http://www.opensource.org/licenses/mit-license.php>."),
QT_TRANSLATE_NOOP("entanglement", ""
"Enter regression test mode, which uses a special chain in which blocks can "
"be solved instantly."),
QT_TRANSLATE_NOOP("entanglement", ""
"Error: Listening for incoming connections failed (listen returned error %s)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Error: Unsupported argument -socks found. Setting SOCKS version isn't "
"possible anymore, only SOCKS5 proxies are supported."),
QT_TRANSLATE_NOOP("entanglement", ""
"Execute command when a relevant alert is received or we see a really long "
"fork (%s in cmd is replaced by message)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Execute command when a wallet transaction changes (%s in cmd is replaced by "
"TxID)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Execute command when the best block changes (%s in cmd is replaced by block "
"hash)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Fees (in ETG/Kb) smaller than this are considered zero fee for relaying "
"(default: %s)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Fees (in ETG/Kb) smaller than this are considered zero fee for transaction "
"creation (default: %s)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Flush database activity from memory pool to disk log every <n> megabytes "
"(default: %u)"),
QT_TRANSLATE_NOOP("entanglement", ""
"How thorough the block verification of -checkblocks is (0-4, default: %u)"),
QT_TRANSLATE_NOOP("entanglement", ""
"If paytxfee is not set, include enough fee so transactions begin "
"confirmation on average within n blocks (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", ""
"In this mode -genproclimit controls how many blocks are generated "
"immediately."),
QT_TRANSLATE_NOOP("entanglement", ""
"Invalid amount for -maxtxfee=<amount>: '%s' (must be at least the minrelay "
"fee of %s to prevent stuck transactions)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Log transaction priority and fee per kB when mining blocks (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Maintain a full transaction index, used by the getrawtransaction rpc call "
"(default: %u)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Maximum size of data in data carrier transactions we relay and mine "
"(default: %u)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Maximum total fees to use in a single wallet transaction, setting too low "
"may abort large transactions (default: %s)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Number of seconds to keep misbehaving peers from reconnecting (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Output debugging information (default: %u, supplying <category> is optional)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Query for peer addresses via DNS lookup, if low on addresses (default: 1 "
"unless -connect)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Require high priority for relaying free or low-fee transactions (default:%u)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Set maximum size of high-priority/low-fee transactions in bytes (default: %d)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Set the number of script verification threads (%u to %d, 0 = auto, <0 = "
"leave that many cores free, default: %d)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Set the number of threads for coin generation if enabled (-1 = all cores, "
"default: %d)"),
QT_TRANSLATE_NOOP("entanglement", ""
"This is a pre-release test build - use at your own risk - do not use for "
"mining or merchant applications"),
QT_TRANSLATE_NOOP("entanglement", ""
"This product includes software developed by the OpenSSL Project for use in "
"the OpenSSL Toolkit <https://www.openssl.org/> and cryptographic software "
"written by Eric Young and UPnP software written by Thomas Bernard."),
QT_TRANSLATE_NOOP("entanglement", ""
"To use entanglementd, or the -server option to entanglement-qt, you must set an "
"rpcpassword in the configuration file:\n"
"%s\n"
"It is recommended you use the following random password:\n"
"rpcuser=entanglementrpc\n"
"rpcpassword=%s\n"
"(you do not need to remember this password)\n"
"The username and password MUST NOT be the same.\n"
"If the file does not exist, create it with owner-readable-only file "
"permissions.\n"
"It is also recommended to set alertnotify so you are notified of problems;\n"
"for example: alertnotify=echo %%s | mail -s \"Entanglement Alert\" admin@foo.com\n"),
QT_TRANSLATE_NOOP("entanglement", ""
"Unable to bind to %s on this computer. Entanglement is probably already "
"running."),
QT_TRANSLATE_NOOP("entanglement", ""
"Use separate SOCKS5 proxy to reach peers via Tor hidden services (default: "
"%s)"),
QT_TRANSLATE_NOOP("entanglement", ""
"Warning: -maxtxfee is set very high! Fees this large could be paid on a "
"single transaction."),
QT_TRANSLATE_NOOP("entanglement", ""
"Warning: -paytxfee is set very high! This is the transaction fee you will "
"pay if you send a transaction."),
QT_TRANSLATE_NOOP("entanglement", ""
"Warning: Please check that your computer's date and time are correct! If "
"your clock is wrong Entanglement will not work properly."),
QT_TRANSLATE_NOOP("entanglement", ""
"Warning: The network does not appear to fully agree! Some miners appear to "
"be experiencing issues."),
QT_TRANSLATE_NOOP("entanglement", ""
"Warning: We do not appear to fully agree with our peers! You may need to "
"upgrade, or other nodes may need to upgrade."),
QT_TRANSLATE_NOOP("entanglement", ""
"Warning: error reading wallet.dat! All keys read correctly, but transaction "
"data or address book entries might be missing or incorrect."),
QT_TRANSLATE_NOOP("entanglement", ""
"Warning: wallet.dat corrupt, data salvaged! Original wallet.dat saved as "
"wallet.{timestamp}.bak in %s; if your balance or transactions are incorrect "
"you should restore from a backup."),
QT_TRANSLATE_NOOP("entanglement", ""
"Whitelist peers connecting from the given netmask or IP address. Can be "
"specified multiple times."),
QT_TRANSLATE_NOOP("entanglement", ""
"Whitelisted peers cannot be DoS banned and their transactions are always "
"relayed, even if they are already in the mempool, useful e.g. for a gateway"),
QT_TRANSLATE_NOOP("entanglement", "(default: %s)"),
QT_TRANSLATE_NOOP("entanglement", "(default: 1)"),
QT_TRANSLATE_NOOP("entanglement", "<category> can be:"),
QT_TRANSLATE_NOOP("entanglement", "Accept command line and JSON-RPC commands"),
QT_TRANSLATE_NOOP("entanglement", "Accept connections from outside (default: 1 if no -proxy or -connect)"),
QT_TRANSLATE_NOOP("entanglement", "Accept public REST requests (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Acceptable ciphers (default: %s)"),
QT_TRANSLATE_NOOP("entanglement", "Add a node to connect to and attempt to keep the connection open"),
QT_TRANSLATE_NOOP("entanglement", "Allow DNS lookups for -addnode, -seednode and -connect"),
QT_TRANSLATE_NOOP("entanglement", "Always query for peer addresses via DNS lookup (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Attempt to recover private keys from a corrupt wallet.dat"),
QT_TRANSLATE_NOOP("entanglement", "Block creation options:"),
QT_TRANSLATE_NOOP("entanglement", "Cannot downgrade wallet"),
QT_TRANSLATE_NOOP("entanglement", "Cannot resolve -bind address: '%s'"),
QT_TRANSLATE_NOOP("entanglement", "Cannot resolve -externalip address: '%s'"),
QT_TRANSLATE_NOOP("entanglement", "Cannot resolve -whitebind address: '%s'"),
QT_TRANSLATE_NOOP("entanglement", "Cannot write default address"),
QT_TRANSLATE_NOOP("entanglement", "Connect only to the specified node(s)"),
QT_TRANSLATE_NOOP("entanglement", "Connect through SOCKS5 proxy"),
QT_TRANSLATE_NOOP("entanglement", "Connect to a node to retrieve peer addresses, and disconnect"),
QT_TRANSLATE_NOOP("entanglement", "Connection options:"),
QT_TRANSLATE_NOOP("entanglement", "Copyright (c) 2016-%i Entanglement Developers"),
QT_TRANSLATE_NOOP("entanglement", "Corrupted block database detected"),
QT_TRANSLATE_NOOP("entanglement", "Could not parse -rpcbind value %s as network address"),
QT_TRANSLATE_NOOP("entanglement", "Debugging/Testing options:"),
QT_TRANSLATE_NOOP("entanglement", "Disable safemode, override a real safe mode event (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Discover own IP address (default: 1 when listening and no -externalip)"),
QT_TRANSLATE_NOOP("entanglement", "Do not load the wallet and disable wallet RPC calls"),
QT_TRANSLATE_NOOP("entanglement", "Do you want to rebuild the block database now?"),
QT_TRANSLATE_NOOP("entanglement", "Done loading"),
QT_TRANSLATE_NOOP("entanglement", "Error initializing block database"),
QT_TRANSLATE_NOOP("entanglement", "Error initializing wallet database environment %s!"),
QT_TRANSLATE_NOOP("entanglement", "Error loading block database"),
QT_TRANSLATE_NOOP("entanglement", "Error loading wallet.dat"),
QT_TRANSLATE_NOOP("entanglement", "Error loading wallet.dat: Wallet corrupted"),
QT_TRANSLATE_NOOP("entanglement", "Error loading wallet.dat: Wallet requires newer version of Entanglement"),
QT_TRANSLATE_NOOP("entanglement", "Error opening block database"),
QT_TRANSLATE_NOOP("entanglement", "Error reading from database, shutting down."),
QT_TRANSLATE_NOOP("entanglement", "Error"),
QT_TRANSLATE_NOOP("entanglement", "Error: A fatal internal error occured, see debug.log for details"),
QT_TRANSLATE_NOOP("entanglement", "Error: Disk space is low!"),
QT_TRANSLATE_NOOP("entanglement", "Error: Unsupported argument -tor found, use -onion."),
QT_TRANSLATE_NOOP("entanglement", "Failed to listen on any port. Use -listen=0 if you want this."),
QT_TRANSLATE_NOOP("entanglement", "Fee (in ETG/kB) to add to transactions you send (default: %s)"),
QT_TRANSLATE_NOOP("entanglement", "Force safe mode (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Generate coins (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "How many blocks to check at startup (default: %u, 0 = all)"),
QT_TRANSLATE_NOOP("entanglement", "If <category> is not supplied, output all debugging information."),
QT_TRANSLATE_NOOP("entanglement", "Importing..."),
QT_TRANSLATE_NOOP("entanglement", "Imports blocks from external blk000??.dat file"),
QT_TRANSLATE_NOOP("entanglement", "Include IP addresses in debug output (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Incorrect or no genesis block found. Wrong datadir for network?"),
QT_TRANSLATE_NOOP("entanglement", "Information"),
QT_TRANSLATE_NOOP("entanglement", "Initialization sanity check failed. Entanglement is shutting down."),
QT_TRANSLATE_NOOP("entanglement", "Insufficient funds"),
QT_TRANSLATE_NOOP("entanglement", "Invalid -onion address: '%s'"),
QT_TRANSLATE_NOOP("entanglement", "Invalid -proxy address: '%s'"),
QT_TRANSLATE_NOOP("entanglement", "Invalid amount for -maxtxfee=<amount>: '%s'"),
QT_TRANSLATE_NOOP("entanglement", "Invalid amount for -minrelaytxfee=<amount>: '%s'"),
QT_TRANSLATE_NOOP("entanglement", "Invalid amount for -mintxfee=<amount>: '%s'"),
QT_TRANSLATE_NOOP("entanglement", "Invalid amount for -paytxfee=<amount>: '%s' (must be at least %s)"),
QT_TRANSLATE_NOOP("entanglement", "Invalid amount for -paytxfee=<amount>: '%s'"),
QT_TRANSLATE_NOOP("entanglement", "Invalid netmask specified in -whitelist: '%s'"),
QT_TRANSLATE_NOOP("entanglement", "Keep at most <n> unconnectable transactions in memory (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Limit size of signature cache to <n> entries (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Listen for JSON-RPC connections on <port> (default: %u or testnet: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Listen for connections on <port> (default: %u or testnet: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Loading addresses..."),
QT_TRANSLATE_NOOP("entanglement", "Loading block index..."),
QT_TRANSLATE_NOOP("entanglement", "Loading wallet..."),
QT_TRANSLATE_NOOP("entanglement", "Maintain at most <n> connections to peers (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Maximum per-connection receive buffer, <n>*1000 bytes (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Maximum per-connection send buffer, <n>*1000 bytes (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Need to specify a port with -whitebind: '%s'"),
QT_TRANSLATE_NOOP("entanglement", "Node relay options:"),
QT_TRANSLATE_NOOP("entanglement", "Not enough file descriptors available."),
QT_TRANSLATE_NOOP("entanglement", "Only accept block chain matching built-in checkpoints (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Only connect to nodes in network <net> (ipv4, ipv6 or onion)"),
QT_TRANSLATE_NOOP("entanglement", "Options:"),
QT_TRANSLATE_NOOP("entanglement", "Password for JSON-RPC connections"),
QT_TRANSLATE_NOOP("entanglement", "Prepend debug output with timestamp (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "RPC SSL options: (see the entanglement Wiki for SSL setup instructions)"),
QT_TRANSLATE_NOOP("entanglement", "RPC server options:"),
QT_TRANSLATE_NOOP("entanglement", "RPC support for HTTP persistent connections (default: %d)"),
QT_TRANSLATE_NOOP("entanglement", "Randomly drop 1 of every <n> network messages"),
QT_TRANSLATE_NOOP("entanglement", "Randomly fuzz 1 of every <n> network messages"),
QT_TRANSLATE_NOOP("entanglement", "Rebuild block chain index from current blk000??.dat files"),
QT_TRANSLATE_NOOP("entanglement", "Relay and mine data carrier transactions (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Relay non-P2SH multisig (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Rescan the block chain for missing wallet transactions"),
QT_TRANSLATE_NOOP("entanglement", "Rescanning..."),
QT_TRANSLATE_NOOP("entanglement", "Run a thread to flush wallet periodically (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Run in the background as a daemon and accept commands"),
QT_TRANSLATE_NOOP("entanglement", "Send trace/debug info to console instead of debug.log file"),
QT_TRANSLATE_NOOP("entanglement", "Send transactions as zero-fee transactions if possible (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Server certificate file (default: %s)"),
QT_TRANSLATE_NOOP("entanglement", "Server private key (default: %s)"),
QT_TRANSLATE_NOOP("entanglement", "Set database cache size in megabytes (%d to %d, default: %d)"),
QT_TRANSLATE_NOOP("entanglement", "Set key pool size to <n> (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Set maximum block size in bytes (default: %d)"),
QT_TRANSLATE_NOOP("entanglement", "Set minimum block size in bytes (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Set the number of threads to service RPC calls (default: %d)"),
QT_TRANSLATE_NOOP("entanglement", "Sets the DB_PRIVATE flag in the wallet db environment (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Show all debugging options (usage: --help -help-debug)"),
QT_TRANSLATE_NOOP("entanglement", "Shrink debug.log file on client startup (default: 1 when no -debug)"),
QT_TRANSLATE_NOOP("entanglement", "Signing transaction failed"),
QT_TRANSLATE_NOOP("entanglement", "Specify configuration file (default: %s)"),
QT_TRANSLATE_NOOP("entanglement", "Specify connection timeout in milliseconds (minimum: 1, default: %d)"),
QT_TRANSLATE_NOOP("entanglement", "Specify data directory"),
QT_TRANSLATE_NOOP("entanglement", "Specify pid file (default: %s)"),
QT_TRANSLATE_NOOP("entanglement", "Specify wallet file (within data directory)"),
QT_TRANSLATE_NOOP("entanglement", "Specify your own public address"),
QT_TRANSLATE_NOOP("entanglement", "Spend unconfirmed change when sending transactions (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Stop running after importing blocks from disk (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "This help message"),
QT_TRANSLATE_NOOP("entanglement", "This is experimental software."),
QT_TRANSLATE_NOOP("entanglement", "This is intended for regression testing tools and app development."),
QT_TRANSLATE_NOOP("entanglement", "Threshold for disconnecting misbehaving peers (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Transaction amount too small"),
QT_TRANSLATE_NOOP("entanglement", "Transaction amounts must be positive"),
QT_TRANSLATE_NOOP("entanglement", "Transaction too large for fee policy"),
QT_TRANSLATE_NOOP("entanglement", "Transaction too large"),
QT_TRANSLATE_NOOP("entanglement", "Unable to bind to %s on this computer (bind returned error %s)"),
QT_TRANSLATE_NOOP("entanglement", "Unknown network specified in -onlynet: '%s'"),
QT_TRANSLATE_NOOP("entanglement", "Upgrade wallet to latest format"),
QT_TRANSLATE_NOOP("entanglement", "Use OpenSSL (https) for JSON-RPC connections"),
QT_TRANSLATE_NOOP("entanglement", "Use UPnP to map the listening port (default: %u)"),
QT_TRANSLATE_NOOP("entanglement", "Use UPnP to map the listening port (default: 1 when listening)"),
QT_TRANSLATE_NOOP("entanglement", "Use the test network"),
QT_TRANSLATE_NOOP("entanglement", "Username for JSON-RPC connections"),
QT_TRANSLATE_NOOP("entanglement", "Verifying blocks..."),
QT_TRANSLATE_NOOP("entanglement", "Verifying wallet..."),
QT_TRANSLATE_NOOP("entanglement", "Wallet %s resides outside data directory %s"),
QT_TRANSLATE_NOOP("entanglement", "Wallet needed to be rewritten: restart Entanglement to complete"),
QT_TRANSLATE_NOOP("entanglement", "Wallet options:"),
QT_TRANSLATE_NOOP("entanglement", "Warning"),
QT_TRANSLATE_NOOP("entanglement", "Warning: This version is obsolete, upgrade required!"),
QT_TRANSLATE_NOOP("entanglement", "Warning: Unsupported argument -benchmark ignored, use -debug=bench."),
QT_TRANSLATE_NOOP("entanglement", "Warning: Unsupported argument -debugnet ignored, use -debug=net."),
QT_TRANSLATE_NOOP("entanglement", "You need to rebuild the database using -reindex to change -txindex"),
QT_TRANSLATE_NOOP("entanglement", "Zapping all transactions from wallet..."),
QT_TRANSLATE_NOOP("entanglement", "on startup"),
QT_TRANSLATE_NOOP("entanglement", "wallet.dat corrupt, salvage failed"),
};
