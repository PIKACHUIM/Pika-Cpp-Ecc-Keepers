#-------------------------------------------------
#
# Project created by QtCreator 2019-07-01T10:13:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CFSS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    DATA.CPP \
    HEAD.CPP \
    MAIN.cpp \
    MD5E.CPP \
    READ.CPP \
    RSAE.CPP \
    UIPF/add_delete.cpp \
    UIPF/file_widget.cpp \
    UIPF/login_widget.cpp \
    UIPF/mainwidget.cpp \
    UIPF/modify_widget.cpp \
    UIPF/register_widget.cpp \
    UIPF/verify_widget.cpp

HEADERS += \
    DATA.HPP \
    MD5E.HPP \
    RSAE.HPP \
    OSSL/__DECC_INCLUDE_EPILOGUE.H \
    OSSL/__DECC_INCLUDE_PROLOGUE.H \
    OSSL/aes.h \
    OSSL/asn1.h \
    OSSL/asn1_mac.h \
    OSSL/asn1t.h \
    OSSL/async.h \
    OSSL/bio.h \
    OSSL/blowfish.h \
    OSSL/bn.h \
    OSSL/buffer.h \
    OSSL/camellia.h \
    OSSL/cast.h \
    OSSL/cmac.h \
    OSSL/cms.h \
    OSSL/comp.h \
    OSSL/conf.h \
    OSSL/conf_api.h \
    OSSL/crypto.h \
    OSSL/ct.h \
    OSSL/des.h \
    OSSL/dh.h \
    OSSL/dsa.h \
    OSSL/dtls1.h \
    OSSL/e_os2.h \
    OSSL/ebcdic.h \
    OSSL/ec.h \
    OSSL/ecdh.h \
    OSSL/ecdsa.h \
    OSSL/engine.h \
    OSSL/err.h \
    OSSL/evp.h \
    OSSL/hmac.h \
    OSSL/idea.h \
    OSSL/kdf.h \
    OSSL/lhash.h \
    OSSL/md2.h \
    OSSL/md4.h \
    OSSL/md5.h \
    OSSL/mdc2.h \
    OSSL/modes.h \
    OSSL/obj_mac.h \
    OSSL/objects.h \
    OSSL/ocsp.h \
    OSSL/opensslconf.h \
    OSSL/opensslv.h \
    OSSL/ossl_typ.h \
    OSSL/pem.h \
    OSSL/pem2.h \
    OSSL/pkcs7.h \
    OSSL/pkcs12.h \
    OSSL/rand.h \
    OSSL/rc2.h \
    OSSL/rc4.h \
    OSSL/rc5.h \
    OSSL/ripemd.h \
    OSSL/rsa.h \
    OSSL/safestack.h \
    OSSL/seed.h \
    OSSL/sha.h \
    OSSL/srp.h \
    OSSL/srtp.h \
    OSSL/ssl.h \
    OSSL/ssl2.h \
    OSSL/ssl3.h \
    OSSL/stack.h \
    OSSL/symhacks.h \
    OSSL/tls1.h \
    OSSL/ts.h \
    OSSL/txt_db.h \
    OSSL/ui.h \
    OSSL/whrlpool.h \
    OSSL/x509.h \
    OSSL/x509_vfy.h \
    OSSL/x509v3.h \
    UIPF/add_delete.h \
    UIPF/file_widget.h \
    UIPF/login_widget.h \
    UIPF/mainwidget.h \
    UIPF/modify_widget.h \
    UIPF/register_widget.h \
    UIPF/verify_widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    OSSL/asn1.h.gch \
    OSSL/bio.h.gch \
    OSSL/crypto.h.gch \
    OSSL/e_os2.h.gch \
    OSSL/md5.h.gch

FORMS += \
    UIPF/add_delete.ui \
    UIPF/file_widget.ui \
    UIPF/login_widget.ui \
    UIPF/mainwidget.ui \
    UIPF/modify_widget.ui \
    UIPF/register_widget.ui \
    UIPF/verify_widget.ui

RESOURCES += \
    IMGS/pic.qrc \
    IMGS/pic.qrc
