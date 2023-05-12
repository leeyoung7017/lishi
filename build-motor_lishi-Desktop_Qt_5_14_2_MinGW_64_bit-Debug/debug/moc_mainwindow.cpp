/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../motor_lishi_v3_2/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[36];
    char stringdata0[478];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "infoinit"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "infostore"
QT_MOC_LITERAL(4, 31, 3), // "str"
QT_MOC_LITERAL(5, 35, 9), // "motorinit"
QT_MOC_LITERAL(6, 45, 10), // "motorstore"
QT_MOC_LITERAL(7, 56, 8), // "timStart"
QT_MOC_LITERAL(8, 65, 2), // "ms"
QT_MOC_LITERAL(9, 68, 11), // "tubexystore"
QT_MOC_LITERAL(10, 80, 2), // "ID"
QT_MOC_LITERAL(11, 83, 13), // "sendScanSlide"
QT_MOC_LITERAL(12, 97, 4), // "data"
QT_MOC_LITERAL(13, 102, 12), // "sendScanTube"
QT_MOC_LITERAL(14, 115, 10), // "sendSerial"
QT_MOC_LITERAL(15, 126, 12), // "sendToDialog"
QT_MOC_LITERAL(16, 139, 13), // "MotorNameInit"
QT_MOC_LITERAL(17, 153, 19), // "on_protocol_clicked"
QT_MOC_LITERAL(18, 173, 16), // "sendTubesxyStore"
QT_MOC_LITERAL(19, 190, 13), // "SerialReceive"
QT_MOC_LITERAL(20, 204, 8), // "location"
QT_MOC_LITERAL(21, 213, 3), // "loc"
QT_MOC_LITERAL(22, 217, 22), // "ScanSlideSerialReceive"
QT_MOC_LITERAL(23, 240, 9), // "str_slide"
QT_MOC_LITERAL(24, 250, 21), // "ScanTubeSerialReceive"
QT_MOC_LITERAL(25, 272, 14), // "on_run_clicked"
QT_MOC_LITERAL(26, 287, 16), // "on_reset_clicked"
QT_MOC_LITERAL(27, 304, 16), // "step_textChanged"
QT_MOC_LITERAL(28, 321, 22), // "on_SlideButton_clicked"
QT_MOC_LITERAL(29, 344, 21), // "on_TubeBotton_clicked"
QT_MOC_LITERAL(30, 366, 17), // "on_fpga_triggered"
QT_MOC_LITERAL(31, 384, 18), // "on_slide_triggered"
QT_MOC_LITERAL(32, 403, 17), // "on_tube_triggered"
QT_MOC_LITERAL(33, 421, 15), // "on_save_clicked"
QT_MOC_LITERAL(34, 437, 19), // "on_action_triggered"
QT_MOC_LITERAL(35, 457, 20) // "sendProtocoltoSerial"

    },
    "MainWindow\0infoinit\0\0infostore\0str\0"
    "motorinit\0motorstore\0timStart\0ms\0"
    "tubexystore\0ID\0sendScanSlide\0data\0"
    "sendScanTube\0sendSerial\0sendToDialog\0"
    "MotorNameInit\0on_protocol_clicked\0"
    "sendTubesxyStore\0SerialReceive\0location\0"
    "loc\0ScanSlideSerialReceive\0str_slide\0"
    "ScanTubeSerialReceive\0on_run_clicked\0"
    "on_reset_clicked\0step_textChanged\0"
    "on_SlideButton_clicked\0on_TubeBotton_clicked\0"
    "on_fpga_triggered\0on_slide_triggered\0"
    "on_tube_triggered\0on_save_clicked\0"
    "on_action_triggered\0sendProtocoltoSerial"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  149,    2, 0x06 /* Public */,
       3,    1,  150,    2, 0x06 /* Public */,
       5,    0,  153,    2, 0x06 /* Public */,
       6,    0,  154,    2, 0x06 /* Public */,
       7,    1,  155,    2, 0x06 /* Public */,
       9,    1,  158,    2, 0x06 /* Public */,
      11,    1,  161,    2, 0x06 /* Public */,
      13,    1,  164,    2, 0x06 /* Public */,
      14,    1,  167,    2, 0x06 /* Public */,
      15,    0,  170,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,  171,    2, 0x08 /* Private */,
      17,    0,  172,    2, 0x08 /* Private */,
      18,    1,  173,    2, 0x08 /* Private */,
      19,    2,  176,    2, 0x08 /* Private */,
      22,    1,  181,    2, 0x08 /* Private */,
      24,    0,  184,    2, 0x08 /* Private */,
      25,    0,  185,    2, 0x08 /* Private */,
      26,    0,  186,    2, 0x08 /* Private */,
      27,    0,  187,    2, 0x08 /* Private */,
      28,    0,  188,    2, 0x08 /* Private */,
      29,    0,  189,    2, 0x08 /* Private */,
      30,    0,  190,    2, 0x08 /* Private */,
      31,    0,  191,    2, 0x08 /* Private */,
      32,    0,  192,    2, 0x08 /* Private */,
      33,    0,  193,    2, 0x08 /* Private */,
      34,    0,  194,    2, 0x08 /* Private */,
      35,    1,  195,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QByteArray,   12,
    QMetaType::Void, QMetaType::QByteArray,   12,
    QMetaType::Void, QMetaType::QByteArray,   12,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 20,   12,   21,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   12,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->infoinit(); break;
        case 1: _t->infostore((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->motorinit(); break;
        case 3: _t->motorstore(); break;
        case 4: _t->timStart((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->tubexystore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->sendScanSlide((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->sendScanTube((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->sendSerial((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 9: _t->sendToDialog(); break;
        case 10: _t->MotorNameInit(); break;
        case 11: _t->on_protocol_clicked(); break;
        case 12: _t->sendTubesxyStore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->SerialReceive((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< location(*)>(_a[2]))); break;
        case 14: _t->ScanSlideSerialReceive((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->ScanTubeSerialReceive(); break;
        case 16: _t->on_run_clicked(); break;
        case 17: _t->on_reset_clicked(); break;
        case 18: _t->step_textChanged(); break;
        case 19: _t->on_SlideButton_clicked(); break;
        case 20: _t->on_TubeBotton_clicked(); break;
        case 21: _t->on_fpga_triggered(); break;
        case 22: _t->on_slide_triggered(); break;
        case 23: _t->on_tube_triggered(); break;
        case 24: _t->on_save_clicked(); break;
        case 25: _t->on_action_triggered(); break;
        case 26: _t->sendProtocoltoSerial((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::infoinit)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::infostore)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::motorinit)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::motorstore)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::timStart)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::tubexystore)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendScanSlide)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendScanTube)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendSerial)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendToDialog)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::infoinit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::infostore(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::motorinit()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::motorstore()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MainWindow::timStart(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::tubexystore(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::sendScanSlide(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::sendScanTube(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::sendSerial(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::sendToDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
