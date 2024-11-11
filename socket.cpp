#include "socket.h"
#include "mode.h"

namespace {
    const QStringList modesNames = { "NO MODE", "BI BLEND",
                           "BI TUR", "BI ARTRO", "BI GISTERO",
                           "BI COAG", "BI COAG DISSECT", "TERMOSHOV",
                           "CUT", "BLEND", "BLEND1", "TUR", "VAP",
                           "ENDO KNIFE1", "ENDO KNIFE2", "ENDO KNIFE3",
                           "ENDO LOOP1", "ENDO LOOP2", "ENDO LOOP3",
                           "FORCE", "FULGUR", "SOFT", "SPRAY",
                           "FULGUR ARGON", "SPRAY ARGON",
                           "FULGUR PULSE ARGON", "SPRAY PULSE ARGON",
                           };
    const QList<int> modesMaxPowers	{ 1, 75,
                                8, 8, 8,
                                150, 150, 5,
                                400, 400, 150, 400, 400,
                                27, 27, 27,
                                27, 27, 27,
                                150, 150, 300, 70,
                                150, 70,
                                70, 70,
                                };

    QList<QSharedPointer<Mode>> createModes(int type, bool left, Socket* parent = nullptr)
    {
        QList<QSharedPointer<Mode>> res;
        int start = 0;
        int stop = 0;
        switch (type) {
        case Socket::NO_SOCKET:
            if (left) {
                start = 0;  stop = 0;
            } else {
                start = 0;   stop = 0;
            }
            break;
        case Socket::BIPOLAR_SOCKET_1:
            if (left) {
                start = 1;  stop = 4+1;
            } else {
                start = 5;   stop = 6+1;
            }
            break;
        case Socket::BIPOLAR_SOCKET_2:
            if (left) {
                start = 1;  stop = 4+1;
            } else {
                start = 5;   stop = 7+1;
            }
            break;
        case Socket::MONOPOLAR_SOCKET_1:
            if (left) {
                start = 8;   stop = 18+1;
            } else {
                start = 19;   stop = 26+1;
            }
            break;
        case Socket::MONOPOLAR_SOCKET_2:
            if (left) {
                start = 8;  stop = 18+1;
            } else {
                start = 19;   stop = 22+1;
            }

            break;
        }
        QSharedPointer<Mode> ptr(new Mode(modesNames.at(0), modesMaxPowers.at(0), false, parent));
        res.append(ptr);

        for (int i = start; i < stop; ++i) {
            QSharedPointer<Mode> ptr(new Mode(modesNames.at(i), modesMaxPowers.at(i), false, parent));
            res.append(ptr);
        }
        return res;
    }
    QList<QSharedPointer<Mode>> createLeftModes(int type, Socket* parent= nullptr)
    {
        return createModes(type,true,parent);
    }
    QList<QSharedPointer<Mode>> createRightModes(int type, Socket* parent= nullptr)
    {
        return createModes(type,false,parent);
    }
}

Socket::Socket(QObject *parent)
    : QObject{parent}
{
    qDebug("i'm born");
}

int Socket::socketStatus() const
{
    return m_socketStatus;
}

void Socket::setSocketStatus(int newSocketStatus)
{
    if (m_socketStatus == newSocketStatus)
        return;
    m_socketStatus = newSocketStatus;
    emit socketStatusChanged();
}

QString Socket::socketName() const
{
    return m_socketName;
}

void Socket::setSocketName(const QString &newSocketName)
{
    if (m_socketName == newSocketName)
        return;
    m_socketName = newSocketName;
    emit socketNameChanged();
}

Mode *Socket::currentLeftMode()
{
    return leftModes.at(m_currentLeftModeIndex).data();
}

Mode *Socket::currentRightMode()
{
    return rightModes.at(m_currentRightModeIndex).data();
}

int Socket::currentLeftModeIndex()
{
    return m_currentLeftModeIndex;
}

int Socket::currentRightModeIndex()
{
    return m_currentRightModeIndex;
}

int Socket::currentLeftModePower()
{
    return leftModes.at(m_currentLeftModeIndex)->getCurrentPower();
}

int Socket::currentRightModePower()
{
    return rightModes.at(m_currentRightModeIndex)->getCurrentPower();
}

int Socket::currentLeftModeMaxPower()
{
    return leftModes.at(m_currentLeftModeIndex)->getMaxPower();
}

int Socket::currentRightModeMaxPower()
{
    return rightModes.at(m_currentRightModeIndex)->getMaxPower();
}

QString Socket::currentLeftModeName()
{
    return leftModes.at(m_currentLeftModeIndex)->getName();
}

QString Socket::currentRightModeName()
{
    return rightModes.at(m_currentRightModeIndex)->getName();
}

void Socket::init(int type)
{
    if (type < MONOPOLAR_SOCKET_1 || type > BIPOLAR_SOCKET_2)
        return;
    leftModes =  createLeftModes(type, (this));
    rightModes =  createRightModes(type,(this));
    switch (type) {
    case MONOPOLAR_SOCKET_1:
        m_socketName = "MONOPOLAR_SOCKET_1";
        break;
    case MONOPOLAR_SOCKET_2:
        m_socketName = "MONOPOLAR_SOCKET_2";
        break;
    case BIPOLAR_SOCKET_1:
        m_socketName = "BIPOLAR_SOCKET_1";
        break;
    case BIPOLAR_SOCKET_2:
        m_socketName = "BIPOLAR_SOCKET_2";
        break;
    default:
        break;
    }
    m_socketStatus = SockEnabled;
    m_socketType = type;
}

QList<QSharedPointer<Mode> > Socket::getLeftModes() const
{
    return leftModes;
}

QList<QSharedPointer<Mode> > Socket::getRightModes() const
{
    return rightModes;
}
