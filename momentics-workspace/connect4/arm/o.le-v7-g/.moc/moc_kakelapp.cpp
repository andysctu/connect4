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
       7,   14, // methods
       1,   49, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,   26,    9,    9, 0x08,

 // methods: signature, parameters, type, tag, flags
      71,    9,    9,    9, 0x02,
      93,   84,    9,    9, 0x02,
     114,  110,    9,    9, 0x02,
     138,  133,    9,    9, 0x02,
     158,  151,    9,    9, 0x02,

 // properties: name, type, flags
     181,  173, 0x0a495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

static const char qt_meta_stringdata_KakelApp[] = {
    "KakelApp\0\0vicMsgChanged()\0event\0"
    "onTileTouch(bb::cascades::TouchEvent*)\0"
    "resetTiles()\0numTiles\0setNumTiles(int)\0"
    "msg\0setVicMsg(QString)\0mode\0setMode(int)\0"
    "player\0setPlayer(int)\0QString\0vicMsg\0"
};

void KakelApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        KakelApp *_t = static_cast<KakelApp *>(_o);
        switch (_id) {
        case 0: _t->vicMsgChanged(); break;
        case 1: _t->onTileTouch((*reinterpret_cast< bb::cascades::TouchEvent*(*)>(_a[1]))); break;
        case 2: _t->resetTiles(); break;
        case 3: _t->setNumTiles((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setVicMsg((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setPlayer((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = vicMsg(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setVicMsg(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void KakelApp::vicMsgChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
