SOURCES +=xsocket.cpp
HEADERS += xsocket.h \
    xglobal.h

TEMPLATE=lib
DEFINES += LIBDLL_LIB
DESTDIR = "../../lib"
DLLDESTDIR = "../../bin"
#CONFIG +=staticlib
#CONFIG +=console

CONFIG(debug,debug|release){
    TARGET = libdll_d
}else{
    TARGET=libdll
}
message($$TARGET)
