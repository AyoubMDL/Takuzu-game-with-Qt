QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
INCLUDEPATH += include/
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/presenter/MenuPresenter.cpp \
    src/main.cpp \
    src/presenter/TakuzuPresenter.cpp \
    src/model/Model.cpp \
    src/model/Grid.cpp \
    src/view/chronometerWidget.cpp \
    src/view/gameView.cpp \
    src/view/menuView.cpp \
    src/view/takuzuWidget.cpp


HEADERS += \
    include/presenter/MenuPresenter.hpp \
    include/presenter/TakuzuPresenter.hpp \
    include/model/Model.hpp \
    include/model/Grid.hpp \
    include/view/chronometerWidget.hpp \
    include/view/gameView.hpp \
    include/view/menuView.hpp \
    include/view/takuzuWidget.hpp

FORMS += \
    UI/gameView.ui \
    UI/menuView.ui

TRANSLATIONS += \
    Takuzu_en.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources/grids.qrc \
    ressources/translation.qrc
