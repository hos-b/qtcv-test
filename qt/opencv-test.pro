QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/../include

SOURCES += \
    ../src/main.cpp \
    ../src/mainwindow.cpp

HEADERS += \
    ../include/mainwindow.h

FORMS += \
    ../ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# opencv include
win32: contains(QT_ARCH, i386) {
    error("open-cv is not compiled for 32-bit")
} 
win32: else {
    LIBS += -LC:/lib/opencv/build/install/x64/mingw/staticlib \
        -lopencv_core410 \
        -lopencv_highgui410 \
        -lopencv_calib3d410 \
        -lzlib
    INCLUDEPATH += C:/lib/opencv/build/install/include
    DEPENDPATH += C:/lib/opencv/build/install/include
}