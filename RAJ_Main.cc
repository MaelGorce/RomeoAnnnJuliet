#include "RAJ_CMainwindow.hh"
#include "RAJ_Traces.hh"
#include <QApplication>

int main(int argc, char *argv[])
{
    trace_info("********** Début de Roméo and Juliet **********");
    QApplication oApplication(argc, argv);
    CMainWindow oMainWindow;
    trace_debug("Affichage de MainWindow");
    oMainWindow.show();

    return oApplication.exec();
}
