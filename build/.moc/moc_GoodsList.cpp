/****************************************************************************
** Meta object code from reading C++ file 'GoodsList.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/GoodsList.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GoodsList.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GoodsList_t {
    QByteArrayData data[13];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GoodsList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GoodsList_t qt_meta_stringdata_GoodsList = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GoodsList"
QT_MOC_LITERAL(1, 10, 8), // "doAccept"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "calcNet"
QT_MOC_LITERAL(4, 28, 9), // "readGoods"
QT_MOC_LITERAL(5, 38, 16), // "comboBox1Changed"
QT_MOC_LITERAL(6, 55, 1), // "x"
QT_MOC_LITERAL(7, 57, 11), // "displayData"
QT_MOC_LITERAL(8, 69, 13), // "lv1selChanged"
QT_MOC_LITERAL(9, 83, 10), // "displayNet"
QT_MOC_LITERAL(10, 94, 5), // "index"
QT_MOC_LITERAL(11, 100, 11), // "spinChanged"
QT_MOC_LITERAL(12, 112, 1) // "a"

    },
    "GoodsList\0doAccept\0\0calcNet\0readGoods\0"
    "comboBox1Changed\0x\0displayData\0"
    "lv1selChanged\0displayNet\0index\0"
    "spinChanged\0a"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GoodsList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    1,   57,    2, 0x0a /* Public */,
       7,    1,   60,    2, 0x0a /* Public */,
       8,    0,   63,    2, 0x0a /* Public */,
       9,    1,   64,    2, 0x0a /* Public */,
      11,    1,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void GoodsList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GoodsList *_t = static_cast<GoodsList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doAccept(); break;
        case 1: _t->calcNet(); break;
        case 2: _t->readGoods(); break;
        case 3: _t->comboBox1Changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->displayData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->lv1selChanged(); break;
        case 6: _t->displayNet((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->spinChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GoodsList::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GoodsList.data,
      qt_meta_data_GoodsList,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GoodsList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GoodsList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GoodsList.stringdata0))
        return static_cast<void*>(const_cast< GoodsList*>(this));
    if (!strcmp(_clname, "Ui::GoodsList"))
        return static_cast< Ui::GoodsList*>(const_cast< GoodsList*>(this));
    return QDialog::qt_metacast(_clname);
}

int GoodsList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
