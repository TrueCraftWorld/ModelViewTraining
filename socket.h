#ifndef SOCKET_H
#define SOCKET_H

#include <QMetaType>
#include <QObject>
#include <QSharedPointer>
#include <mode.h>

class Socket : public QObject
{
    Q_OBJECT
public:
    enum Statuses {
        SockDisabled = 0,
        SockOff,
        SockEnabled,
        SockLeftActive,
        SockRightActive
    };
    enum SocketType{
        NO_SOCKET = 0,
        MONOPOLAR_SOCKET_1,
        MONOPOLAR_SOCKET_2,
        BIPOLAR_SOCKET_1,
        BIPOLAR_SOCKET_2
    };

    // Socket() = default;
    // ~Socket() = default;
    // Socket(const Socket &) = default;
    // Socket &operator=(const Socket &) = default;

    explicit Socket(QObject *parent = nullptr);

    int socketStatus() const;
    void setSocketStatus(int newSocketStatus);

    QString socketName() const;
    void setSocketName(const QString &newSocketName);

    Mode* currentLeftMode();
    Mode* currentRightMode();

    int currentLeftModeIndex();
    int currentRightModeIndex();

    int currentLeftModePower();
    int currentRightModePower();

    int currentLeftModeMaxPower();
    int currentRightModeMaxPower();

    QString currentLeftModeName();
    QString currentRightModeName();

    void init(int type);

    QList<QSharedPointer<Mode> > getLeftModes() const;

    QList<QSharedPointer<Mode> > getRightModes() const;

signals:
    void socketStatusChanged();

    void socketNameChanged();

private:
    int m_socketStatus = SockDisabled;
    int m_socketType = NO_SOCKET;
    QString m_socketName;

    int m_currentLeftModeIndex = 0;
    int m_currentRightModeIndex = 0;

    QList<QSharedPointer<Mode>> leftModes;
    QList<QSharedPointer<Mode>> rightModes;
};

// Q_DECLARE_METATYPE(Socket)

#endif // SOCKET_H
