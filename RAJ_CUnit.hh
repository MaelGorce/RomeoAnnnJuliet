#ifndef RAJ_CUNIT_H
#define RAJ_CUNIT_H

#include <QObject>
#include <QPushButton>
#include "RAJ_Configuration.hh"

#define C_NORMAL_DIAMETRE 10

enum EUnitType
{
    ERomeo=0,
    EJuliet,
    EPeasant,
    ESoldier,
    EArcher,
    EWitch,
    EMaxUnitType
};

class CUnit : public QPushButton
{
    Q_OBJECT

public:
    CUnit(EUnitType eUnitType,
              uint32_t uiHP,
              uint32_t uiAP,
              uint32_t uiPosX,
              uint32_t uiPosY,
              QWidget* parent);

    void fnDump();

private:
    EUnitType m_eUnitType;
    uint32_t m_uiHealthPoint;
    uint32_t m_uiAttackPoint;
    uint32_t m_uiPosX;
    uint32_t m_uiPosY;
    uint32_t m_uiDiametre;
    QPalette m_qoPalette;
    bool m_bIsSelected;

};

#endif // RAJ_CUNIT_H
