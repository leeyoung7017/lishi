/****************************************************************************
** Meta object code from reading C++ file 'serialthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../motor_lishi_v3_2/serialthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialThread_t {
    QByteArrayData data[9];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialThread_t qt_meta_stringdata_SerialThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SerialThread"
QT_MOC_LITERAL(1, 13, 4), // "send"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "data"
QT_MOC_LITERAL(4, 24, 8), // "location"
QT_MOC_LITERAL(5, 33, 3), // "loc"
QT_MOC_LITERAL(6, 37, 10), // "SerialOpen"
QT_MOC_LITERAL(7, 48, 13), // "SerialReceive"
QT_MOC_LITERAL(8, 62, 10) // "SerialSend"

    },
    "SerialThread\0send\0\0data\0location\0loc\0"
    "SerialOpen\0SerialReceive\0SerialSend"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   39,    2, 0x0a /* Public */,
       7,    0,   40,    2, 0x0a /* Public */,
       8,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    3,

       0        // eod
};

void SerialThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< location(*)>(_a[2]))); break;
        case 1: _t->SerialOpen(); break;
        case 2: _t->SerialReceive(); break;
        case 3: _t->SerialSend((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SerialThread::*)(QByteArray , location );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialThread::send)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SerialThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SerialThread.data,
    qt_meta_data_SerialThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SerialThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SerialThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void SerialThread::send(QByteArray _t1, location _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_ScanTubeThread_t {
    QByteArrayData data[9];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScanTubeThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScanTubeThread_t qt_meta_stringdata_ScanTubeThread = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ScanTubeThread"
QT_MOC_LITERAL(1, 15, 4), // "send"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "tubexystore"
QT_MOC_LITERAL(4, 33, 2), // "ID"
QT_MOC_LITERAL(5, 36, 12), // "ScanTubeOpen"
QT_MOC_LITERAL(6, 49, 21), // "ScanTubeSerialReceive"
QT_MOC_LITERAL(7, 71, 18), // "ScanTubeSerialSend"
QT_MOC_LITERAL(8, 90, 4) // "data"

    },
    "ScanTubeThread\0send\0\0tubexystore\0ID\0"
    "ScanTubeOpen\0ScanTubeSerialReceive\0"
    "ScanTubeSerialSend\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScanTubeThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    8,

       0        // eod
};

void ScanTubeThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScanTubeThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send(); break;
        case 1: _t->tubexystore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ScanTubeOpen(); break;
        case 3: _t->ScanTubeSerialReceive(); break;
        case 4: _t->ScanTubeSerialSend((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ScanTubeThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScanTubeThread::send)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ScanTubeThread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScanTubeThread::tubexystore)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ScanTubeThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ScanTubeThread.data,
    qt_meta_data_ScanTubeThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScanTubeThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScanTubeThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScanTubeThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ScanTubeThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ScanTubeThread::send()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ScanTubeThread::tubexystore(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_ScanSlideThread_t {
    QByteArrayData data[8];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScanSlideThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScanSlideThread_t qt_meta_stringdata_ScanSlideThread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ScanSlideThread"
QT_MOC_LITERAL(1, 16, 4), // "send"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 3), // "str"
QT_MOC_LITERAL(4, 26, 13), // "ScanSlideOpen"
QT_MOC_LITERAL(5, 40, 22), // "ScanSlideSerialReceive"
QT_MOC_LITERAL(6, 63, 19), // "ScanSlideSerialSend"
QT_MOC_LITERAL(7, 83, 4) // "data"

    },
    "ScanSlideThread\0send\0\0str\0ScanSlideOpen\0"
    "ScanSlideSerialReceive\0ScanSlideSerialSend\0"
    "data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScanSlideThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   37,    2, 0x0a /* Public */,
       5,    0,   38,    2, 0x0a /* Public */,
       6,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    7,

       0        // eod
};

void ScanSlideThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScanSlideThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->ScanSlideOpen(); break;
        case 2: _t->ScanSlideSerialReceive(); break;
        case 3: _t->ScanSlideSerialSend((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ScanSlideThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScanSlideThread::send)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ScanSlideThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ScanSlideThread.data,
    qt_meta_data_ScanSlideThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScanSlideThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScanSlideThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScanSlideThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ScanSlideThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ScanSlideThread::send(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
