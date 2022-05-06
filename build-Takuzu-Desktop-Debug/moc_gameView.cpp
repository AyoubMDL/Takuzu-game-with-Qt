/****************************************************************************
** Meta object code from reading C++ file 'gameView.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Takuzu/include/view/gameView.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameView.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_gameView_t {
    QByteArrayData data[11];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gameView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gameView_t qt_meta_stringdata_gameView = {
    {
QT_MOC_LITERAL(0, 0, 8), // "gameView"
QT_MOC_LITERAL(1, 9, 22), // "changeShowErrorsStatus"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15), // "changeCellsType"
QT_MOC_LITERAL(4, 49, 14), // "onCheckPressed"
QT_MOC_LITERAL(5, 64, 12), // "returnToMenu"
QT_MOC_LITERAL(6, 77, 16), // "showErrorChecked"
QT_MOC_LITERAL(7, 94, 14), // "changeToCircle"
QT_MOC_LITERAL(8, 109, 14), // "changeToSquare"
QT_MOC_LITERAL(9, 124, 8), // "quitGame"
QT_MOC_LITERAL(10, 133, 14) // "onAboutPressed"

    },
    "gameView\0changeShowErrorsStatus\0\0"
    "changeCellsType\0onCheckPressed\0"
    "returnToMenu\0showErrorChecked\0"
    "changeToCircle\0changeToSquare\0quitGame\0"
    "onAboutPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gameView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void gameView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<gameView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeShowErrorsStatus(); break;
        case 1: _t->changeCellsType(); break;
        case 2: _t->onCheckPressed(); break;
        case 3: _t->returnToMenu(); break;
        case 4: _t->showErrorChecked(); break;
        case 5: _t->changeToCircle(); break;
        case 6: _t->changeToSquare(); break;
        case 7: _t->quitGame(); break;
        case 8: _t->onAboutPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (gameView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameView::changeShowErrorsStatus)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (gameView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameView::changeCellsType)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject gameView::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_gameView.data,
    qt_meta_data_gameView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *gameView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gameView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gameView.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int gameView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void gameView::changeShowErrorsStatus()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void gameView::changeCellsType()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
