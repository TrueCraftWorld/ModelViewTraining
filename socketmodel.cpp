#include "socketmodel.h"

void SocketModel::registerMe()
{
    qmlRegisterType<SocketModel>("DarkSide", 1, 0, "TheMightySocketModel");
}

SocketModel::SocketModel(QObject *parent)
    : QAbstractListModel(parent)
{

    roles[SocketNameRole] = "socketName";
    roles[SocketStatusRole] = "socketStatus";

    roles[SocketLeftModeRole] = "socketLeftMode";
    roles[SocketLeftModeIndexRole] = "socketLeftModeIndex";
    roles[SocketLeftModeNameRole] = "socketLeftModeName";
    roles[SocketLeftModePowerRole] = "socketLeftModePower";
    roles[SocketLeftModeMaxPowerRole] = "socketLeftModeMaxPower";

    roles[SocketRightModeRole] = "socketRightMode";
    roles[SocketRightModeIndexRole] = "socketRightModeIndex";
    roles[SocketRightModeNameRole] = "socketRightModeName";
    roles[SocketRightModePowerRole] = "socketRightModePower";
    roles[SocketRightModeMaxPowerRole] = "socketRightModeMaxPower";
    createSockets();
}


int SocketModel::rowCount(const QModelIndex &parent) const
{
    return m_sokets.size();
}

QVariant SocketModel::data(const QModelIndex &index, int role) const
{
    if (m_sokets.isEmpty() || index.row() >= m_sokets.size())
        return QVariant();

    switch (role) {
    case SocketNameRole:
        return m_sokets.at(index.row())->socketName();
    case SocketStatusRole:
        return m_sokets.at(index.row())->socketStatus();

    case SocketLeftModeRole:
        return m_sokets.at(index.row())->currentLeftModeIndex();
    case SocketLeftModeIndexRole:
        return m_sokets.at(index.row())->currentLeftModeIndex();
    case SocketLeftModeNameRole:
        return m_sokets.at(index.row())->currentLeftModeName();
    case SocketLeftModePowerRole:
        return m_sokets.at(index.row())->currentLeftModePower();
    case SocketLeftModeMaxPowerRole:
        return m_sokets.at(index.row())->currentLeftModeMaxPower();

    case SocketRightModeRole:
        return m_sokets.at(index.row())->currentRightModeIndex();
    case SocketRightModeIndexRole:
        return m_sokets.at(index.row())->currentRightModeIndex();
    case SocketRightModeNameRole:
        return m_sokets.at(index.row())->currentRightModeName();
    case SocketRightModePowerRole:
        return m_sokets.at(index.row())->currentRightModePower();
    case SocketRightModeMaxPowerRole:
        return m_sokets.at(index.row())->currentRightModeMaxPower();
    default:
        return QVariant();
    }
}

void SocketModel::setSockets(QList<QSharedPointer<Socket> > &&sockets)
{
    beginResetModel();
    m_sokets = sockets;
    endResetModel();
}

QHash<int, QByteArray> SocketModel::roleNames() const
{
    return roles;
}

void SocketModel::createSockets()
{
    beginResetModel();

    for (int i = 1; i <=4 ; ++i){
        m_sokets.append(QSharedPointer<Socket>(new Socket));
        m_sokets[i-1]->init(i);
    }

    endResetModel();
}

