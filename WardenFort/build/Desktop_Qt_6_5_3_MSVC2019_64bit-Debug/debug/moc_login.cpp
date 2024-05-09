/****************************************************************************
** Meta object code from reading C++ file 'login.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../login.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'login.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSloginENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSloginENDCLASS = QtMocHelpers::stringData(
    "login",
    "enterPasswordClicked",
    "",
    "on_loginButton_clicked",
    "on_eye_open_clicked",
    "on_eye_closed_clicked",
    "on_signup_button_clicked",
    "on_forgot_pass_clicked",
    "on_typePASS_box_returnPressed",
    "openAlertNotif"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSloginENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[6];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[23];
    char stringdata4[20];
    char stringdata5[22];
    char stringdata6[25];
    char stringdata7[23];
    char stringdata8[30];
    char stringdata9[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSloginENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSloginENDCLASS_t qt_meta_stringdata_CLASSloginENDCLASS = {
    {
        QT_MOC_LITERAL(0, 5),  // "login"
        QT_MOC_LITERAL(6, 20),  // "enterPasswordClicked"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 22),  // "on_loginButton_clicked"
        QT_MOC_LITERAL(51, 19),  // "on_eye_open_clicked"
        QT_MOC_LITERAL(71, 21),  // "on_eye_closed_clicked"
        QT_MOC_LITERAL(93, 24),  // "on_signup_button_clicked"
        QT_MOC_LITERAL(118, 22),  // "on_forgot_pass_clicked"
        QT_MOC_LITERAL(141, 29),  // "on_typePASS_box_returnPressed"
        QT_MOC_LITERAL(171, 14)   // "openAlertNotif"
    },
    "login",
    "enterPasswordClicked",
    "",
    "on_loginButton_clicked",
    "on_eye_open_clicked",
    "on_eye_closed_clicked",
    "on_signup_button_clicked",
    "on_forgot_pass_clicked",
    "on_typePASS_box_returnPressed",
    "openAlertNotif"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSloginENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    0,   69,    2, 0x08,    8 /* Private */,

 // signals: parameters
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

Q_CONSTINIT const QMetaObject login::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSloginENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSloginENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSloginENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<login, std::true_type>,
        // method 'enterPasswordClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_loginButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_eye_open_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_eye_closed_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_signup_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_forgot_pass_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_typePASS_box_returnPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openAlertNotif'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void login::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<login *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->enterPasswordClicked(); break;
        case 1: _t->on_loginButton_clicked(); break;
        case 2: _t->on_eye_open_clicked(); break;
        case 3: _t->on_eye_closed_clicked(); break;
        case 4: _t->on_signup_button_clicked(); break;
        case 5: _t->on_forgot_pass_clicked(); break;
        case 6: _t->on_typePASS_box_returnPressed(); break;
        case 7: _t->openAlertNotif(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (login::*)();
            if (_t _q_method = &login::enterPasswordClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *login::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *login::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSloginENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int login::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void login::enterPasswordClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
