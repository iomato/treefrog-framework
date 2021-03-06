#ifndef THTTPSENDBUFFER_H
#define THTTPSENDBUFFER_H

#include <QByteArray>
#include <TGlobal>
#include <TAccessLog>

class QFile;
class QFileInfo;
class QHostAddress;
class THttpHeader;


class T_CORE_EXPORT THttpSendBuffer
{
public:
    THttpSendBuffer(const QByteArray &header, const QFileInfo &file, bool autoRemove, const TAccessLogger &logger);
    THttpSendBuffer(int statusCode, const QHostAddress &address, const QByteArray &method);
    ~THttpSendBuffer();

    bool atEnd() const;
    int read(char *data, int maxSize);
    int prepend(const char *data, int maxSize);
    TAccessLogger &accessLogger() { return accesslogger; }
    const TAccessLogger &accessLogger() const { return accesslogger; }
    void release();

private:
    QByteArray arrayBuffer;
    QFile* bodyFile;
    bool fileRemove;
    TAccessLogger accesslogger;
    int arraySentSize;

    THttpSendBuffer();
    Q_DISABLE_COPY(THttpSendBuffer)
};

#endif // THTTPSENDBUFFER_H
