/****************************************************************************
** Meta object code from reading C++ file 'UDPServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../UDPServer/UDPServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UDPServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UDPServer_t {
    QByteArrayData data[12];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UDPServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UDPServer_t qt_meta_stringdata_UDPServer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "UDPServer"
QT_MOC_LITERAL(1, 10, 12), // "ErrorMessage"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "function"
QT_MOC_LITERAL(4, 33, 10), // "strMessage"
QT_MOC_LITERAL(5, 44, 9), // "RecvedUdp"
QT_MOC_LITERAL(6, 54, 5), // "bytes"
QT_MOC_LITERAL(7, 60, 6), // "qsFrom"
QT_MOC_LITERAL(8, 67, 4), // "port"
QT_MOC_LITERAL(9, 72, 7), // "SendUdp"
QT_MOC_LITERAL(10, 80, 8), // "qsSendTo"
QT_MOC_LITERAL(11, 89, 2) // "em"

    },
    "UDPServer\0ErrorMessage\0\0function\0"
    "strMessage\0RecvedUdp\0bytes\0qsFrom\0"
    "port\0SendUdp\0qsSendTo\0em"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UDPServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    3,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    3,   56,    2, 0x0a /* Public */,
       9,    2,   63,    2, 0x2a /* Public | MethodCloned */,
       9,    1,   68,    2, 0x2a /* Public | MethodCloned */,
      11,    2,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QString, QMetaType::UShort,    6,    7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QString, QMetaType::UShort,    6,   10,    8,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QString,    6,   10,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

       0        // eod
};

void UDPServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UDPServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ErrorMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->RecvedUdp((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const quint16(*)>(_a[3]))); break;
        case 2: _t->SendUdp((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 3: _t->SendUdp((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->SendUdp((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 5: _t->em((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UDPServer::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPServer::ErrorMessage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UDPServer::*)(const QByteArray & , const QString & , const quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPServer::RecvedUdp)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UDPServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_UDPServer.data,
    qt_meta_data_UDPServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UDPServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UDPServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UDPServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UDPServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void UDPServer::ErrorMessage(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UDPServer::RecvedUdp(const QByteArray & _t1, const QString & _t2, const quint16 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
