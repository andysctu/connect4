/****************************************************************************
** Meta object code from reading C++ file 'kakelapp.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/kakelapp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kakelapp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KakelApp[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x08,

 // methods: signature, parameters, type, tag, flags
      55,    9,    9,    9, 0x02,
      77,   68,    9,    9, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_KakelApp[] = {
    "KakelApp\0\0event\0onTileTouch(bb::cascades::TouchEvent*)\0"
    "resetTiles()\0numTiles\0setNumTiles(int)\0"
};

void KakelApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        KakelApp *_t = static_cast<KakelApp *>(_o);
        switch (_id) {
        case 0: _t->onTileTouch((*reinterpret_cast< bb::cascades::TouchEvent*(*)>(_a[1]))); break;
        case 1: _t->resetTiles(); break;
        case 2: _t->setNumTiles((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData KakelApp::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject KakelApp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KakelApp,
      qt_meta_data_KakelApp, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KakelApp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KakelApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KakelApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KakelApp))
        return static_cast<void*>(const_cast< KakelApp*>(this));
    return QObject::qt_metacast(_clname);
}

int KakelApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
