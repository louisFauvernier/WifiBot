/****************************************************************************
** Meta object code from reading C++ file 'viewergl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Wifibot/viewergl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewergl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ViewerGl_t {
    QByteArrayData data[8];
    char stringdata[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ViewerGl_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ViewerGl_t qt_meta_stringdata_ViewerGl = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ViewerGl"
QT_MOC_LITERAL(1, 9, 16), // "imageSizeChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "outW"
QT_MOC_LITERAL(4, 32, 4), // "outH"
QT_MOC_LITERAL(5, 37, 9), // "showImage"
QT_MOC_LITERAL(6, 47, 7), // "cv::Mat"
QT_MOC_LITERAL(7, 55, 5) // "image"

    },
    "ViewerGl\0imageSizeChanged\0\0outW\0outH\0"
    "showImage\0cv::Mat\0image"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewerGl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   29,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 6,    7,

       0        // eod
};

void ViewerGl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ViewerGl *_t = static_cast<ViewerGl *>(_o);
        switch (_id) {
        case 0: _t->imageSizeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: { bool _r = _t->showImage((*reinterpret_cast< cv::Mat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ViewerGl::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ViewerGl::imageSizeChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ViewerGl::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_ViewerGl.data,
      qt_meta_data_ViewerGl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ViewerGl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewerGl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ViewerGl.stringdata))
        return static_cast<void*>(const_cast< ViewerGl*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int ViewerGl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ViewerGl::imageSizeChanged(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
