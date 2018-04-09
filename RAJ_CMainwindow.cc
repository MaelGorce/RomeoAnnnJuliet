#include "RAJ_CMainwindow.hh"
#include "RAJ_Traces.hh"

#include <time.h>
#include <unistd.h>

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    trace_debug("Construction de MainWindow");

    trace_info("Taille de la fenêtre = " << C_WINDOW_LENGTH << "x" << C_WINDOW_HIGHT );
    setFixedSize(C_WINDOW_LENGTH, C_WINDOW_HIGHT);

    m_poMenuBar = new CMenuBar(C_WINDOW_LENGTH,this);
    connect(m_poMenuBar,&CMenuBar::SigOutMenuBar,
            this,&CMainWindow::SfnInMenuBar);
    m_uiHightMenuBar = m_poMenuBar->height();
    trace_debug("Hauteur de la barre de menu : " << m_uiHightMenuBar);

    srand(time(NULL));

    trace_debug("Fin Construction de MainWindow");
}

CMainWindow::~CMainWindow()
{
    trace_debug("Destruction de MainWindow");

    trace_debug("Fin Destruction de MainWindow");
}

void CMainWindow::SfnInMenuBar(EMenuBarPossibility eInputMenuBar)
{
    switch (eInputMenuBar)
    {
        case ENew:
            trace_debug("New");
            CUnit* poRandomUnit;
            fnCreateRandomUnit(poRandomUnit);
            m_vpoUnitVector.push_back(poRandomUnit);
            break;
        case ESave:
            trace_debug("Save");
            break;
        case ELoad:
            trace_debug("Load");
            break;
        default:
            trace_debug("Cas " << eInputMenuBar << " non traité ici");
    }
}

void CMainWindow::fnCreateRandomUnit(CUnit* poRandomUnit)
{
    //temporary for testing
    static uint32_t s_uiCountUnit=0;
    trace_debug("Création aléatoire d'unité no : " << ++s_uiCountUnit);
    poRandomUnit = new CUnit(EMaxUnitType,
                                  rand()%100,
                                  rand()%20,
                                  rand()%(C_WINDOW_LENGTH - C_NORMAL_UNIT_DIAMETRE),
                                  m_uiHightMenuBar + rand()%(C_WINDOW_HIGHT - C_NORMAL_UNIT_DIAMETRE - m_uiHightMenuBar),
                                  this);
    poRandomUnit->fnDump();
}
