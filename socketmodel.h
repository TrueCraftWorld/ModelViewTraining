#ifndef SOCKETMODEL_H
#define SOCKETMODEL_H

#include <QAbstractListModel>
#include <QObject>

#include <QtCore>
#include <QQmlEngine>

#include "socket.h"

class SocketModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum RoleNames
    {
        SocketNameRole = Qt::UserRole + 1,
        SocketStatusRole,
        SocketLeftModeRole,
        SocketLeftModeIndexRole,
        SocketLeftModeNameRole,
        SocketLeftModePowerRole,
        SocketLeftModeMaxPowerRole,
        SocketRightModeRole,
        SocketRightModeIndexRole,
        SocketRightModeNameRole,
        SocketRightModePowerRole,
        SocketRightModeMaxPowerRole

    };
    static void registerMe();

    explicit SocketModel(QObject* parent = nullptr);

    virtual ~SocketModel() = default;

    virtual int rowCount(const QModelIndex& parent) const override;

    virtual QVariant data(const QModelIndex& index, int role) const override;

    void setSockets(QList<QSharedPointer<Socket>>&& sockets);


protected:
    virtual QHash<int, QByteArray> roleNames() const override;

private:
    void createSockets();
    QHash<int, QByteArray> roles;
    QList<QSharedPointer<Socket>> m_sokets;
};

#endif // SOCKETMODEL_H
