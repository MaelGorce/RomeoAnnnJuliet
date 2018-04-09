#ifndef RAJ_CUNIT_H
#define RAJ_CUNIT_H

#include <QObject>
#include <QPushButton>
#include "RAJ_Configuration.hh"

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
