DIST_SUBDIRS = secp256k1 univalue

AM_LDFLAGS = $(PTHREAD_CFLAGS) $(LIBTOOL_LDFLAGS) $(HARDENED_LDFLAGS)
AM_CXXFLAGS = $(HARDENED_CXXFLAGS)
AM_CPPFLAGS = $(HARDENED_CPPFLAGS)
EXTRA_LIBRARIES =

ENTANGLEMENT_CONFIG_INCLUDES=-I$(builddir)/config
ENTANGLEMENT_INCLUDES=-I$(builddir) -I$(builddir)/obj $(BDB_CPPFLAGS) $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS) $(CRYPTO_CFLAGS) $(SSL_CFLAGS)

ENTANGLEMENT_INCLUDES += -I$(srcdir)/secp256k1/include
ENTANGLEMENT_INCLUDES += $(UNIVALUE_CFLAGS)

LIBENTANGLEMENT_SERVER=libentanglement_server.a
LIBENTANGLEMENT_WALLET=libentanglement_wallet.a
LIBENTANGLEMENT_COMMON=libentanglement_common.a
LIBENTANGLEMENT_CLI=libentanglement_cli.a
LIBENTANGLEMENT_UTIL=libentanglement_util.a
LIBENTANGLEMENT_CRYPTO=crypto/libentanglement_crypto.a
LIBENTANGLEMENT_UNIVALUE=univalue/libentanglement_univalue.a
LIBENTANGLEMENTQT=qt/libentanglementqt.a
LIBSECP256K1=secp256k1/libsecp256k1.la
LIBUNIVALUE=univalue/libunivalue.la

$(LIBSECP256K1): $(wildcard secp256k1/src/*) $(wildcard secp256k1/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

$(LIBUNIVALUE): $(wildcard univalue/lib/*) $(wildcard univalue/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

# Make is not made aware of per-object dependencies to avoid limiting building parallelization
# But to build the less dependent modules first, we manually select their order here:
EXTRA_LIBRARIES = \
	crypto/libentanglement_crypto.a \
	libentanglement_util.a \
	libentanglement_common.a \
	libentanglement_server.a \
	libentanglement_cli.a
if ENABLE_WALLET
EXTRA_LIBRARIES += libentanglement_wallet.a
endif

if BUILD_ENTANGLEMENT_LIBS
lib_LTLIBRARIES = libentanglementconsensus.la
LIBENTANGLEMENT_CONSENSUS=libentanglementconsensus.la
else
LIBENTANGLEMENT_CONSENSUS=
endif

bin_PROGRAMS =
TESTS =

if BUILD_ENTANGLEMENTD
  bin_PROGRAMS += entanglementd
endif

if BUILD_ENTANGLEMENT_UTILS
  bin_PROGRAMS += entanglement-cli entanglement-tx
endif

.PHONY: FORCE
# Entanglement #
ENTANGLEMENT_CORE_H = \
	addrman.h \
	alert.h \
	amount.h \
	base58.h \
	bip39_english.h \
	bip39.h \
	bignum.h \
	bloom.h \
	chain.h \
	chainparams.h \
	chainparamsbase.h \
	chainparamsseeds.h \
	checkpoints.h \
	checkqueue.h \
	clientversion.h \
	coins.h \
	compat.h \
	compat/byteswap.h \
	compat/endian.h \
	compat/sanity.h \
	compressor.h \
	consensus/consensus.h \
	consensus/merkle.h \
	consensus/params.h \
	consensus/validation.h \
	core_io.h \
	dns/dns.h \
	dns/etgdns.h \
	eccryptoverify.h \
	ecwrapper.h \
	hash.h \
	hdchain.h \
	hooks.h \
	indirectmap.h \
	init.h \
	key.h \
	keystore.h \
	leveldbwrapper.h \
	limitedmap.h \
	main.h \
	memusage.h \
	merkleblock.h \
	miner.h \
	mruset.h \
	netbase.h \
	net.h \
	noui.h \
	ntp.h \
	primitives/block.h \
	primitives/transaction.h \
	protocol.h \
	pubkey.h \
	random.h \
	reverselock.h \
	rpc/rpcclient.h \
	rpc/rpcprotocol.h \
	rpc/rpcregister.h \
	rpc/rpcserver.h \
	scheduler.h \
	script/interpreter.h \
	script/script.h \
	script/sigcache.h \
	script/sign.h \
	script/standard.h \
	script/script_error.h \
	serialize.h \
	stake.h \
	streams.h \
	support/allocators/secure.h \
	support/allocators/zeroafterfree.h \
	support/cleanse.h \
	support/lockedpool.h \
	sync.h \
	threadsafety.h \
	threadinterrupt.h \
	timedata.h \
	tinyformat.h \
	torcontrol.h \
	txdb.h \
	txmempool.h \
	ui_interface.h \
	uint256.h \
	uint256hm.h \
	undo.h \
	util.h \
	utilstrencodings.h \
	utilmoneystr.h \
	utiltime.h \
	validationinterface.h \
	version.h \
	wallet/coincontrol.h \
	wallet/crypter.h \
	wallet/db.h \
	wallet/wallet.h \
	wallet/wallet_ismine.h \
	wallet/walletdb.h \
	work.h

obj/build.h: FORCE
	@$(MKDIR_P) $(builddir)/obj
	@$(top_srcdir)/share/genbuild.sh $(abs_top_builddir)/src/obj/build.h \
		$(abs_top_srcdir)
libentanglement_util_a-clientversion.$(OBJEXT): obj/build.h

# server: shared between entanglementd and entanglement-qt
libentanglement_server_a_CPPFLAGS = $(AM_CPPFLAGS) $(ENTANGLEMENT_INCLUDES) $(MINIUPNPC_CPPFLAGS) $(EVENT_CFLAGS) $(EVENT_PTHREADS_CFLAGS)
libentanglement_server_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libentanglement_server_a_SOURCES = \
	addrman.cpp \
	alert.cpp \
	bloom.cpp \
	chain.cpp \
	checkpoints.cpp \
	dns/dns.cpp \
	dns/etgdns.cpp \
	init.cpp \
	leveldbwrapper.cpp \
	main.cpp \
	merkleblock.cpp \
	miner.cpp \
	net.cpp \
	noui.cpp \
	ntp.cpp \
	rest.cpp \
	rpc/rpcblockchain.cpp \
	rpc/rpcmining.cpp \
	rpc/rpcmisc.cpp \
	rpc/rpcnet.cpp \
	rpc/rpcrawtransaction.cpp \
	rpc/rpcserver.cpp \
	script/sigcache.cpp \
	stake.cpp \
	torcontrol.cpp \
	txdb.cpp \
	txmempool.cpp \
	validationinterface.cpp \
	work.cpp \
	$(ENTANGLEMENT_CORE_H)

# wallet: shared between entanglementd and entanglement-qt, but only linked
# when wallet enabled
libentanglement_wallet_a_CPPFLAGS = $(AM_CPPFLAGS) $(ENTANGLEMENT_INCLUDES)
libentanglement_wallet_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libentanglement_wallet_a_SOURCES = \
	dns/dns.cpp \
	wallet/db.cpp \
	wallet/crypter.cpp \
	wallet/rpcdump.cpp \
	wallet/rpcwallet.cpp \
	wallet/wallet.cpp \
	wallet/wallet_ismine.cpp \
	wallet/walletdb.cpp \
	$(ENTANGLEMENT_CORE_H)

# crypto primitives library
crypto_libentanglement_crypto_a_CPPFLAGS = $(AM_CPPFLAGS) $(ENTANGLEMENT_CONFIG_INCLUDES)
crypto_libentanglement_crypto_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libentanglement_crypto_a_SOURCES = \
	crypto/aes.cpp \
	crypto/hmac_sha256.cpp \
	crypto/hmac_sha512.cpp \
	crypto/ripemd160.cpp \
	crypto/rfc6979_hmac_sha256.cpp \
	crypto/sha1.cpp \
	crypto/sha256.cpp \
	crypto/sha512.cpp \
	crypto/aes.h \
	crypto/common.h \
	crypto/hmac_sha256.h \
	crypto/hmac_sha512.h \
	crypto/ripemd160.h \
	crypto/rfc6979_hmac_sha256.h \
	crypto/sha1.h \
	crypto/sha256.h \
	crypto/sha512.h

# common: shared between entanglementd, and entanglement-qt and non-server tools
libentanglement_common_a_CPPFLAGS = $(AM_CPPFLAGS) $(ENTANGLEMENT_INCLUDES)
libentanglement_consensus_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libentanglement_common_a_SOURCES = \
	amount.cpp \
	base58.cpp \
	bip39.cpp \
	chainparams.cpp \
	coins.cpp \
	compressor.cpp \
	consensus/merkle.cpp \
	core_read.cpp \
	core_write.cpp \
	eccryptoverify.cpp \
	ecwrapper.cpp \
	hash.cpp \
	hdchain.cpp \
	key.cpp \
	keystore.cpp \
	netbase.cpp \
	primitives/block.cpp \
	primitives/transaction.cpp \
	protocol.cpp \
	pubkey.cpp \
	scheduler.cpp \
	script/interpreter.cpp \
	script/script.cpp \
	script/sign.cpp \
	script/standard.cpp \
	script/script_error.cpp \
	$(ENTANGLEMENT_CORE_H)

# util: shared between all executables.
# This library *must* be included to make sure that the glibc
# backward-compatibility objects and their sanity checks are linked.
libentanglement_util_a_CPPFLAGS = $(AM_CPPFLAGS) $(ENTANGLEMENT_INCLUDES)
libentanglement_util_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libentanglement_util_a_SOURCES = \
	chainparamsbase.cpp \
	clientversion.cpp \
	compat/strnlen.cpp \
	compat/glibc_sanity.cpp \
	compat/glibcxx_sanity.cpp \
	random.cpp \
	rpc/rpcprotocol.cpp \
	support/cleanse.cpp \
	support/lockedpool.cpp \
	sync.cpp \
	threadinterrupt.cpp \
	timedata.cpp \
	uint256.cpp \
	util.cpp \
	utilstrencodings.cpp \
	utilmoneystr.cpp \
	utiltime.cpp \
	$(ENTANGLEMENT_CORE_H)

if GLIBC_BACK_COMPAT
libentanglement_util_a_SOURCES += compat/glibc_compat.cpp
endif

# cli: shared between entanglement-cli and entanglement-qt
libentanglement_cli_a_CPPFLAGS = $(AM_CPPFLAGS) $(ENTANGLEMENT_INCLUDES)
libentanglement_cli_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libentanglement_cli_a_SOURCES = \
	rpc/rpcclient.cpp \
	$(ENTANGLEMENT_CORE_H)

nodist_libentanglement_util_a_SOURCES = $(srcdir)/obj/build.h
#

# entanglementd binary #
entanglementd_SOURCES = entanglementd.cpp
entanglementd_CPPFLAGS = $(AM_CPPFLAGS) $(ENTANGLEMENT_INCLUDES)
entanglementd_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
entanglementd_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
entanglementd_SOURCES += entanglementd-res.rc
endif

entanglementd_LDADD = \
	$(LIBENTANGLEMENT_SERVER) \
	$(LIBENTANGLEMENT_COMMON) \
	$(LIBUNIVALUE) \
	$(LIBENTANGLEMENT_UTIL) \
	$(LIBENTANGLEMENT_CRYPTO) \
	$(LIBLEVELDB) \
	$(LIBMEMENV) \
	$(LIBSECP256K1)

if ENABLE_WALLET
entanglementd_LDADD += libentanglement_wallet.a
endif

entanglementd_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS) $(MINIUPNPC_LIBS) $(EVENT_PTHREADS_LIBS) $(EVENT_LIBS)
#

# entanglement-cli binary #
entanglement_cli_SOURCES = entanglement-cli.cpp
entanglement_cli_CPPFLAGS = $(AM_CPPFLAGS) $(ENTANGLEMENT_INCLUDES) $(EVENT_CFLAGS)
entanglement_cli_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
entanglement_cli_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)


if TARGET_WINDOWS
entanglement_cli_SOURCES += entanglement-cli-res.rc
endif

entanglement_cli_LDADD = \
	$(LIBENTANGLEMENT_CLI) \
	$(LIBENTANGLEMENT_UTIL) \
	$(LIBUNIVALUE) \
	$(EVENT_LIBS)

entanglement_cli_LDADD += $(BOOST_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS)
#

# entanglement-tx binary #
entanglement_tx_SOURCES = entanglement-tx.cpp
entanglement_tx_CPPFLAGS = $(AM_CPPFLAGS) $(ENTANGLEMENT_INCLUDES)
entanglement_tx_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
entanglement_tx_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

entanglement_tx_LDADD = \
	$(LIBUNIVALUE) \
	$(LIBENTANGLEMENT_COMMON) \
	$(LIBENTANGLEMENT_UTIL) \
	$(LIBENTANGLEMENT_CRYPTO) \
	$(LIBSECP256K1)

entanglement_tx_LDADD += $(BOOST_LIBS) $(CRYPTO_LIBS)
#

# entanglementconsensus library #
if BUILD_ENTANGLEMENT_LIBS
include_HEADERS = script/entanglementconsensus.h
libentanglementconsensus_la_SOURCES = \
	crypto/hmac_sha512.cpp \
	crypto/ripemd160.cpp \
	crypto/sha1.cpp \
	crypto/sha256.cpp \
	crypto/sha512.cpp \
	eccryptoverify.cpp \
	ecwrapper.cpp \
	hash.cpp \
	primitives/transaction.cpp \
	pubkey.cpp \
	script/script.cpp \
	script/interpreter.cpp \
	script/entanglementconsensus.cpp \
	script/entanglementconsensus_dummy.cpp \
	uint256.cpp \
	utilstrencodings.cpp

if GLIBC_BACK_COMPAT
  libentanglementconsensus_la_SOURCES += compat/glibc_compat.cpp
endif

libentanglementconsensus_la_LDFLAGS = -no-undefined $(RELDFLAGS)		
libentanglementconsensus_la_LIBADD = $(CRYPTO_LIBS)		
libentanglementconsensus_la_CPPFLAGS = $(CRYPTO_CFLAGS) -I$(builddir)/obj -DBUILD_ENTANGLEMENT_INTERNAL		
if USE_LIBSECP256K1		
libentanglementconsensus_la_LIBADD += secp256k1/libsecp256k1.la		
endif		
endif

CLEANFILES = $(EXTRA_LIBRARIES)		

CLEANFILES = leveldb/libleveldb.a leveldb/libmemenv.a
CLEANFILES += *.gcda *.gcno
CLEANFILES += compat/*.gcda compat/*.gcno
CLEANFILES += consensus/*.gcda consensus/*.gcno
CLEANFILES += crypto/*.gcda crypto/*.gcno
CLEANFILES += policy/*.gcda policy/*.gcno
CLEANFILES += primitives/*.gcda primitives/*.gcno
CLEANFILES += script/*.gcda script/*.gcno
CLEANFILES += support/*.gcda support/*.gcno
CLEANFILES += univalue/*.gcda univalue/*.gcno
CLEANFILES += wallet/*.gcda wallet/*.gcno
CLEANFILES += wallet/test/*.gcda wallet/test/*.gcno

DISTCLEANFILES = obj/build.h

EXTRA_DIST = leveldb crypto/ctaes

clean-local:
	-$(MAKE) -C leveldb clean
	-$(MAKE) -C secp256k1 clean
	-$(MAKE) -C univalue clean
	-rm -rf .libs
	-rm -rf .deps
	-rm -f leveldb/*/*.gcda leveldb/*/*.gcno leveldb/helpers/memenv/*.gcda leveldb/helpers/memenv/*.gcno
	-rm -f config/entanglement-config.* config/stamp-h1
	-rm -rf compat/.deps && rm -rf compat/.libs && rm -f compat/.dirstamp
	-rm -rf crypto/.deps && rm -rf crypto/.libs && rm -f crypto/.dirstamp
	-rm -rf primitives/.deps && rm -rf primitives/.libs && rm -f primitives/.dirstamp
	-rm -rf qt/.deps && rm -rf qt/.libs && rm -f qt/.dirstamp && rm -rf qt/test/.deps
	-rm -rf script/.deps && rm -rf script/.libs && rm -f script/.dirstamp
	-rm -rf univalue/.deps && rm -rf univalue/.libs && rm -f univalue/.dirstamp
	-rm -rf test/.deps && rm -rf test/.libs && rm -f test/.dirstamp && rm	-f test/buildenv.py
	-rm -rf secp256k1/.deps && rm -rf secp256k1/.libs && rm -f secp256k1/.dirstamp
	-rm -f Makefile && rm -f Makefile.in
	-rm -f config/entanglement-config.h && rm -f config/entanglement-config.* && rm -f config/stamp-h1
.rc.o:
	@test -f $(WINDRES)
	$(AM_V_GEN) $(WINDRES) -DWINDRES_PREPROC -i $< -o $@

.mm.o:
	$(AM_V_CXX) $(OBJCXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
		$(CPPFLAGS) $(AM_CXXFLAGS) $(QT_INCLUDES) $(CXXFLAGS)  -c -o $@ $<

%.pb.cc %.pb.h: %.proto
	@test -f $(PROTOC)
	$(AM_V_GEN) $(PROTOC) --cpp_out=$(@D) --proto_path=$(abspath $(<D) $<)
# TODO (Amir) put back unit tests
#if ENABLE_TESTS
#include Makefile.test.include
#endif

if EMBEDDED_LEVELDB
include Makefile.leveldb.include
endif

if ENABLE_QT
include Makefile.qt.include
endif

#if ENABLE_QT_TESTS
#include Makefile.qttest.include
#endif
