/****************************************************************************
** Meta object code from reading C++ file 'ibsss_stream_view_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ibsss_stream_view_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ibsss_stream_view_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IBSSS_Stream_View_Window_t {
    QByteArrayData data[10];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IBSSS_Stream_View_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IBSSS_Stream_View_Window_t qt_meta_stringdata_IBSSS_Stream_View_Window = {
    {
QT_MOC_LITERAL(0, 0, 24), // "IBSSS_Stream_View_Window"
QT_MOC_LITERAL(1, 25, 26), // "on_actionLog_out_triggered"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 11), // "showSection"
QT_MOC_LITERAL(4, 65, 8), // "QAction*"
QT_MOC_LITERAL(5, 74, 1), // "a"
QT_MOC_LITERAL(6, 76, 16), // "backToStreamview"
QT_MOC_LITERAL(7, 93, 28), // "on_changeImageButton_clicked"
QT_MOC_LITERAL(8, 122, 31), // "on_changePasswordButton_clicked"
QT_MOC_LITERAL(9, 154, 13) // "enableOptions"

    },
    "IBSSS_Stream_View_Window\0"
    "on_actionLog_out_triggered\0\0showSection\0"
    "QAction*\0a\0backToStreamview\0"
    "on_changeImageButton_clicked\0"
    "on_changePasswordButton_clicked\0"
    "enableOptions"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IBSSS_Stream_View_Window[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    1,   45,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IBSSS_Stream_View_Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IBSSS_Stream_View_Window *_t = static_cast<IBSSS_Stream_View_Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionLog_out_triggered(); break;
        case 1: _t->showSection((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 2: _t->backToStreamview(); break;
        case 3: _t->on_changeImageButton_clicked(); break;
        case 4: _t->on_changePasswordButton_clicked(); break;
        case 5: _t->enableOptions(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject IBSSS_Stream_View_Window::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_IBSSS_Stream_View_Window.data,
      qt_meta_data_IBSSS_Stream_View_Window,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IBSSS_Stream_View_Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IBSSS_Stream_View_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IBSSS_Stream_View_Window.stringdata0))
        return static_cast<void*>(const_cast< IBSSS_Stream_View_Window*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int IBSSS_Stream_View_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
