#include "mode.h"

Mode::Mode(const QString &_name, int _maxPower, bool _left, QObject *parent)
: QObject{parent},
  name(_name),
  maxPower(_maxPower  > 0 ? _maxPower : 1),
  currentPower(1),
  isLeft(_left)
{
}

QString Mode::getName() const
{
    return name;
}

void Mode::setName(const QString &newName)
{
    name = newName;
}

int Mode::getMaxPower() const
{
    return maxPower;
}

void Mode::setMaxPower(int newMaxPower)
{
    if (newMaxPower > 0 && newMaxPower < 400)
        maxPower = newMaxPower;
}

int Mode::getCurrentPower() const
{
    return currentPower;
}

void Mode::setCurrentPower(int newCurrentPower)
{
    if (newCurrentPower <= maxPower)
        currentPower = newCurrentPower;
    else
        currentPower = maxPower;

}

bool Mode::getIsLeft() const
{
    return isLeft;
}

void Mode::setIsLeft(bool newIsLeft)
{
    isLeft = newIsLeft;
}
