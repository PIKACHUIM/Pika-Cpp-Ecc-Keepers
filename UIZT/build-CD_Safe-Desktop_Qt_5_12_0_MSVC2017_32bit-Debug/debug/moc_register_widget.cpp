/****************************************************************************
** Meta object code from reading C++ file 'register_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CD_Safe/register_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'register_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Register_Widget_t {
    QByteArrayData data[7];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Register_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Register_Widget_t qt_meta_stringdata_Register_Widget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Register_Widget"
QT_MOC_LITERAL(1, 16, 18), // "on_search_released"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 19), // "on_confirm_released"
QT_MOC_LITERAL(4, 56, 31), // "on_recode_input_editingFinished"
QT_MOC_LITERAL(5, 88, 29), // "on_name_input_editingFinished"
QT_MOC_LITERAL(6, 118, 29) // "on_code_input_editingFinished"

    },
    "Register_Widget\0on_search_released\0\0"
    "on_confirm_released\0on_recode_input_editingFinished\0"
    "on_name_input_editingFinished\0"
    "on_code_input_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Register_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Register_Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Register_Widget *_t = static_cast<Register_Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_search_released(); break;
        case 1: _t->on_confirm_released(); break;
        case 2: _t->on_recode_input_editingFinished(); break;
        case 3: _t->on_name_input_editingFinished(); break;
        case 4: _t->on_code_input_editingFinished(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Register_Widget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Register_Widget.data,
    qt_meta_data_Register_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Register_Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Register_Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Register_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Register_Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
