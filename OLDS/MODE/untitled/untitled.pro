TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    HEAD.CPP \
    main.cpp \
    MD5E.CPP \
    RSAE.CPP

HEADERS += \
    MD5E.HPP \
    RSAE.HPP \
    openssl/__DECC_INCLUDE_EPILOGUE.H \
    openssl/__DECC_INCLUDE_PROLOGUE.H \
    openssl/aes.h \
    openssl/asn1.h \
    openssl/asn1_mac.h \
    openssl/asn1t.h \
    openssl/async.h \
    openssl/bio.h \
    openssl/blowfish.h \
    openssl/bn.h \
    openssl/buffer.h \
    openssl/camellia.h \
    openssl/cast.h \
    openssl/cmac.h \
    openssl/cms.h \
    openssl/comp.h \
    openssl/conf.h \
    openssl/conf_api.h \
    openssl/crypto.h \
    openssl/ct.h \
    openssl/des.h \
    openssl/dh.h \
    openssl/dsa.h \
    openssl/dtls1.h \
    openssl/e_os2.h \
    openssl/ebcdic.h \
    openssl/ec.h \
    openssl/ecdh.h \
    openssl/ecdsa.h \
    openssl/engine.h \
    openssl/err.h \
    openssl/evp.h \
    openssl/hmac.h \
    openssl/idea.h \
    openssl/kdf.h \
    openssl/lhash.h \
    openssl/md2.h \
    openssl/md4.h \
    openssl/md5.h \
    openssl/mdc2.h \
    openssl/modes.h \
    openssl/obj_mac.h \
    openssl/objects.h \
    openssl/ocsp.h \
    openssl/opensslconf.h \
    openssl/opensslv.h \
    openssl/ossl_typ.h \
    openssl/pem.h \
    openssl/pem2.h \
    openssl/pkcs7.h \
    openssl/pkcs12.h \
    openssl/rand.h \
    openssl/rc2.h \
    openssl/rc4.h \
    openssl/rc5.h \
    openssl/ripemd.h \
    openssl/rsa.h \
    openssl/safestack.h \
    openssl/seed.h \
    openssl/sha.h \
    openssl/srp.h \
    openssl/srtp.h \
    openssl/ssl.h \
    openssl/ssl2.h \
    openssl/ssl3.h \
    openssl/stack.h \
    openssl/symhacks.h \
    openssl/tls1.h \
    openssl/ts.h \
    openssl/txt_db.h \
    openssl/ui.h \
    openssl/whrlpool.h \
    openssl/x509.h \
    openssl/x509_vfy.h \
    openssl/x509v3.h

DISTFILES += \
    openssl/asn1.h.gch \
    openssl/bio.h.gch \
    openssl/crypto.h.gch \
    openssl/e_os2.h.gch \
    openssl/md5.h.gch
