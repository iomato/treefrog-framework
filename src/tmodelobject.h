#ifndef TMODELOBJECT_H
#define TMODELOBJECT_H

#include <QObject>
#include <QStringList>
#include <QVariant>
#include <QMap>
#include <TGlobal>


class T_CORE_EXPORT TModelObject : public QObject
{
public:
    TModelObject() : QObject() { }
    virtual ~TModelObject() { }
    virtual bool isNull() const = 0;
    virtual bool create() = 0;
    virtual bool update() = 0;
    virtual bool remove() = 0;
    virtual void setProperties(const QVariantMap &value);
    virtual QVariantMap toVariantMap() const;
    virtual QStringList propertyNames() const;

private:
    Q_DISABLE_COPY(TModelObject)
};

#endif // TMODELOBJECT_H
