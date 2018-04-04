#include "RAJ_CMainwindow.hh"
#include "RAJ_Traces.hh"

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    trace_debug("Construction de MainWindow");

    int iHightMenuBar;

    trace_info("Taille de la fenêtre = " << C_WINDOW_LENGTH << "x" << C_WINDOW_HIGHT );
    setFixedSize(C_WINDOW_LENGTH, C_WINDOW_HIGHT);

    m_poMenuBar = new CMenuBar(C_WINDOW_LENGTH,this);
    connect(m_poMenuBar,&CMenuBar::SigOutMenuBar,
            this,&CMainWindow::SfnInMenuBar);
    iHightMenuBar = m_poMenuBar->height();
    trace_debug("Hauteur de la barre de menu : " << iHightMenuBar);

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
            break;
        case ESave:
            trace_debug("Save");
            break;
        case ELoad:
            trace_debug("Load");
            break;
        case EHelp:
            trace_debug("Help");
            break;
        default:
            trace_debug("Cas " << eInputMenuBar << " non traité ici");
    }
}
