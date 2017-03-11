/****************************************************************************
** Meta object code from reading C++ file 'streamview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "streamview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'streamview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StreamView_t {
    QByteArrayData data[8];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StreamView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StreamView_t qt_meta_stringdata_StreamView = {
    {
QT_MOC_LITERAL(0, 0, 10), // "StreamView"
QT_MOC_LITERAL(1, 11, 26), // "on_actionLog_out_triggered"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 11), // "showSection"
QT_MOC_LITERAL(4, 51, 8), // "QAction*"
QT_MOC_LITERAL(5, 60, 1), // "a"
QT_MOC_LITERAL(6, 62, 16), // "backToStreamview"
QT_MOC_LITERAL(7, 79, 28) // "on_changeImageButton_clicked"

    },
    "StreamView\0on_actionLog_out_triggered\0"
    "\0showSection\0QAction*\0a\0backToStreamview\0"
    "on_changeImageButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StreamView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    1,   35,    2, 0x08 /* Private */,
       6,    0,   38,    2, 0x08 /* Private */,
       7,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StreamView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StreamView *_t = static_cast<StreamView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionLog_out_triggered(); break;
        case 1: _t->showSection((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 2: _t->backToStreamview(); break;
        case 3: _t->on_changeImageButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject StreamView::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_StreamView.data,
      qt_meta_data_StreamView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StreamView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StreamView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StreamView.stringdata0))
        return static_cast<void*>(const_cast< StreamView*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int StreamView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
