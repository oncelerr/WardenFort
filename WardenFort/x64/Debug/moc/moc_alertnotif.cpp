/****************************************************************************
** Meta object code from reading C++ file 'alertnotif.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../GITHUB-FETCHED/updated-login/login/alertnotif.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'alertnotif.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSalertnotifENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSalertnotifENDCLASS = QtMocHelpers::stringData(
    "alertnotif",
    "toggleButtons",
    "",
    "toggleButtonVisibility",
    "QPushButton*",
    "buttonToHide",
    "buttonToShow"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSalertnotifENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[23];
    char stringdata4[13];
    char stringdata5[13];
    char stringdata6[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSalertnotifENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSalertnotifENDCLASS_t qt_meta_stringdata_CLASSalertnotifENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "alertnotif"
        QT_MOC_LITERAL(11, 13),  // "toggleButtons"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 22),  // "toggleButtonVisibility"
        QT_MOC_LITERAL(49, 12),  // "QPushButton*"
        QT_MOC_LITERAL(62, 12),  // "buttonToHide"
        QT_MOC_LITERAL(75, 12)   // "buttonToShow"
    },
    "alertnotif",
    "toggleButtons",
    "",
    "toggleButtonVisibility",
    "QPushButton*",
    "buttonToHide",
    "buttonToShow"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSalertnotifENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x08,    1 /* Private */,
       3,    2,   27,    2, 0x08,    2 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject alertnotif::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSalertnotifENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSalertnotifENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSalertnotifENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<alertnotif, std::true_type>,
        // method 'toggleButtons'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleButtonVisibility'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPushButton *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPushButton *, std::false_type>
    >,
    nullptr
} };

void alertnotif::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<alertnotif *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->toggleButtons(); break;
        case 1: _t->toggleButtonVisibility((*reinterpret_cast< std::add_pointer_t<QPushButton*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPushButton*>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject *alertnotif::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *alertnotif::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSalertnotifENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int alertnotif::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
