#ifndef MODE_H
#define MODE_H

// #include <QMetaType>
#include <QObject>

class Mode : public QObject
{
    Q_OBJECT
public:
    enum eshfModes	{ NO_MODE = 0, BI_BLEND=1,
                    BI_TUR=2, BI_ARTRO=3, BI_GISTERO=4,
                    BI_COAG=5, BI_COAG_DISS=6, TERMOSHOV=7,
                    CUT=8, BLEND=9, BLEND1=10, TUR=11, VAP=12,
                    E_KNIFE1=13, E_KNIFE2=14, E_KNIFE3=15,
                    E_LOOP1=16, E_LOOP2=17, E_LOOP3=18,
                    FORCE=19, FULGUR=20, SOFT=21, SPRAY=22,
                    FULGUR_A=23, SPRAY_A=24,
                    FULGUR_P=25, SPRAY_P=26,
                                };

    // Mode() = default;
    // ~Mode() = default;
    // Mode(const Mode &) = default;
    // Mode &operator=(const Mode &) = default;


    explicit Mode(const QString& _name = "", int _maxPower = 1, bool _left = true, QObject *parent = nullptr);

    QString getName() const;
    void setName(const QString &newName);

    int getMaxPower() const;
    void setMaxPower(int newMaxPower);

    int getCurrentPower() const;
    void setCurrentPower(int newCurrentPower);

    bool getIsLeft() const;
    void setIsLeft(bool newIsLeft);

signals:

private:
    QString name;
    int maxPower;
    int currentPower;
    bool isLeft;

};

// Q_DECLARE_METATYPE(Mode)

#endif // MODE_H
