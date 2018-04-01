#include "RAJ_Cmainwindow.hh"
#include "RAJ_traces.hh"

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    trace_debug("Construction de MainWindow");

    trace_info("Taille de la fenêtre = " << C_WINDOW_LENGTH << "x" << C_WINDOW_HIGHT );
    setFixedSize(C_WINDOW_LENGTH, C_WINDOW_HIGHT);

    trace_debug("Fin Construction de MainWindow");
}

CMainWindow::~CMainWindow()
{
    trace_debug("Destruction de MainWindow");

    trace_debug("Fin Destruction de MainWindow");
}
