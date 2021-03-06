#ifndef TMONGOQUERY_H
#define TMONGOQUERY_H

#include <QVariant>
#include <QStringList>
#include <TGlobal>
#include <TKvsDatabase>

class TMongoDriver;


class T_CORE_EXPORT TMongoQuery
{
public:
    TMongoQuery(const QString &collection);
    TMongoQuery(const TMongoQuery &other);
    virtual ~TMongoQuery() { }

    void setLimit(int limit);
    void setOffset(int offset);
    int find(const QVariantMap &criteria = QVariantMap(), const QStringList &fields = QStringList());
    bool next();
    QVariantMap value() const;

    QVariantMap findOne(const QVariantMap &criteria = QVariantMap(), const QStringList &fields = QStringList());
    QVariantMap findById(const QString &id, const QStringList &fields = QStringList());
    bool insert(QVariantMap &document);
    bool update(const QVariantMap &criteria, const QVariantMap &document, bool upsert = false);
    bool updateById(const QVariantMap &document);
    bool updateMulti(const QVariantMap &criteria, const QVariantMap &document);
    bool remove(const QVariantMap &criteria = QVariantMap());
    bool removeById(const QVariantMap &document);
    int numDocsAffected() const;
    int lastErrorCode() const;
    QString lastErrorString() const;

    TMongoQuery &operator=(const TMongoQuery &other);

private:
    TMongoDriver *driver();
    const TMongoDriver *driver() const;

private:
    TKvsDatabase database;
    QString nameSpace;
    int queryLimit;
    int queryOffset;
    QVariantMap lastWriteStatus;
};


inline void TMongoQuery::setLimit(int limit)
{
    queryLimit = limit;
}

inline void TMongoQuery::setOffset(int offset)
{
    queryOffset = offset;
}

#endif // TMONGOQUERY_H
