/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[321];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "update_comport_list"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "new_port_selection"
QT_MOC_LITERAL(4, 51, 5), // "index"
QT_MOC_LITERAL(5, 57, 15), // "open_serialport"
QT_MOC_LITERAL(6, 73, 15), // "closeSerialPort"
QT_MOC_LITERAL(7, 89, 14), // "updateSettings"
QT_MOC_LITERAL(8, 104, 9), // "writeData"
QT_MOC_LITERAL(9, 114, 4), // "data"
QT_MOC_LITERAL(10, 119, 8), // "readData"
QT_MOC_LITERAL(11, 128, 11), // "handleError"
QT_MOC_LITERAL(12, 140, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(13, 169, 5), // "error"
QT_MOC_LITERAL(14, 175, 15), // "updatePidValues"
QT_MOC_LITERAL(15, 191, 12), // "sendPidValue"
QT_MOC_LITERAL(16, 204, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(17, 226, 20), // "on_Robot_sel_clicked"
QT_MOC_LITERAL(18, 247, 7), // "checked"
QT_MOC_LITERAL(19, 255, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(20, 275, 25), // "on_lineEdit_returnPressed"
QT_MOC_LITERAL(21, 301, 19) // "on_asc_show_clicked"

    },
    "MainWindow\0update_comport_list\0\0"
    "new_port_selection\0index\0open_serialport\0"
    "closeSerialPort\0updateSettings\0writeData\0"
    "data\0readData\0handleError\0"
    "QSerialPort::SerialPortError\0error\0"
    "updatePidValues\0sendPidValue\0"
    "on_pushButton_clicked\0on_Robot_sel_clicked\0"
    "checked\0on_checkBox_clicked\0"
    "on_lineEdit_returnPressed\0on_asc_show_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    1,   90,    2, 0x08 /* Private */,
       5,    0,   93,    2, 0x08 /* Private */,
       6,    0,   94,    2, 0x08 /* Private */,
       7,    0,   95,    2, 0x08 /* Private */,
       8,    1,   96,    2, 0x08 /* Private */,
      10,    0,   99,    2, 0x08 /* Private */,
      11,    1,  100,    2, 0x08 /* Private */,
      14,    0,  103,    2, 0x08 /* Private */,
      15,    0,  104,    2, 0x08 /* Private */,
      16,    0,  105,    2, 0x08 /* Private */,
      17,    1,  106,    2, 0x08 /* Private */,
      19,    1,  109,    2, 0x08 /* Private */,
      20,    0,  112,    2, 0x08 /* Private */,
      21,    1,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_comport_list(); break;
        case 1: _t->new_port_selection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->open_serialport(); break;
        case 3: _t->closeSerialPort(); break;
        case 4: _t->updateSettings(); break;
        case 5: _t->writeData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 6: _t->readData(); break;
        case 7: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 8: _t->updatePidValues(); break;
        case 9: _t->sendPidValue(); break;
        case 10: _t->on_pushButton_clicked(); break;
        case 11: _t->on_Robot_sel_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_lineEdit_returnPressed(); break;
        case 14: _t->on_asc_show_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
