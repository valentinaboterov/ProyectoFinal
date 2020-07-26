QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cargar.cpp \
    creditos.cpp \
    friccion.cpp \
    ganador.cpp \
    main.cpp \
    modojuego.cpp \
    niveles.cpp \
    paredes.cpp \
    pendulo.cpp \
    perdedor.cpp \
    personaje.cpp \
    pesos.cpp \
    plataforma.cpp \
    polea.cpp \
    polea_ventana.cpp \
    puente.cpp \
    registro.cpp \
    resorte.cpp \
    widget.cpp

HEADERS += \
    cargar.h \
    creditos.h \
    friccion.h \
    ganador.h \
    modojuego.h \
    niveles.h \
    paredes.h \
    pendulo.h \
    perdedor.h \
    personaje.h \
    pesos.h \
    plataforma.h \
    polea.h \
    polea_ventana.h \
    puente.h \
    registro.h \
    resorte.h \
    widget.h

FORMS += \
    cargar.ui \
    creditos.ui \
    ganador.ui \
    modojuego.ui \
    niveles.ui \
    perdedor.ui \
    polea_ventana.ui \
    registro.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Imagenes.qrc

DISTFILES += \
    Archivos/Partidas.txt \
    Archivos/Usuarios.txt \
    Archivos/temporal.txt \
    Imagenes/c_izqu.jpeg \
    Imagenes/station.png
