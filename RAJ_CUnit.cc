#include "RAJ_CUnit.hh"
#include "RAJ_Traces.hh"

CUnit::CUnit(EUnitType eUnitType,
             uint32_t uiHP,
             uint32_t uiAP,
             uint32_t uiPosX,
             uint32_t uiPosY,
             QWidget* parent) : QPushButton(parent),
    m_eUnitType(eUnitType),
    m_uiHealthPoint(uiHP),
    m_uiAttackPoint(uiAP),
    m_uiPosX(uiPosX),
    m_uiPosY(uiPosY),
    m_uiDiametre(C_NORMAL_UNIT_DIAMETRE),
    m_bIsSelected(false)
{

    m_qoPalette.setColor(QPalette::Button,QColor(0,255,255));
    this->setPalette(m_qoPalette);

    this->setGeometry( m_uiPosX,m_uiPosY,m_uiDiametre,m_uiDiametre);
    QRect *pqoRectangle = new QRect(0,0,m_uiDiametre,m_uiDiametre);
    QRegion *pqoRegion = new QRegion(*pqoRectangle,QRegion::Ellipse);

    this->setBackgroundRole(QPalette::Button);
    this->setForegroundRole(QPalette::NoRole);
    this->setAutoFillBackground(true);
    this->setFlat(true);
    this->setCursor(Qt::PointingHandCursor);

    this->setMask(*pqoRegion);

    this->show();

}

void CUnit::fnDump()
{
    trace_debug("m_eUnitType      = " << m_eUnitType);
    trace_debug("m_uiHealthPoint  = " << m_uiHealthPoint);
    trace_debug("m_uiAttackPoint  = " << m_uiAttackPoint);
    trace_debug("m_uiPosX         = " << m_uiPosX);
    trace_debug("m_uiPosY         = " << m_uiPosY);
    trace_debug("m_uiDiametre     = " << m_uiDiametre);
    trace_debug("m_bIsSelected    = " << m_bIsSelected);
}
