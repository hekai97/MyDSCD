QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminwindow.cpp \
    binarytreesort.cpp \
    encryption.cpp \
    insertpersondialog.cpp \
    insertvoterdialog.cpp \
    main.cpp \
    loginwindow.cpp \
    myarray.cpp \
    person.cpp \
    personarray.cpp \
    tree.cpp \
    updatepersondialog.cpp \
    userwindow.cpp \
    voter.cpp

HEADERS += \
    adminwindow.h \
    binarytreesort.h \
    encryption.h \
    insertpersondialog.h \
    insertvoterdialog.h \
    loginwindow.h \
    myarray.h \
    person.h \
    personarray.h \
    tree.h \
    updatepersondialog.h \
    userwindow.h \
    voter.h

FORMS += \
    adminwindow.ui \
    insertpersondialog.ui \
    insertvoterdialog.ui \
    loginwindow.ui \
    updatepersondialog.ui \
    userwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
