#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "RAJ_CMenubar.hh"
#include "RAJ_CUnit.hh"
#include "RAJ_Configuration.hh"

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = 0);
    ~CMainWindow();

public slots:
    void SfnInMenuBar(EMenuBarPossibility);

private:

    void fnCreateRandomUnit(CUnit *);

    CMenuBar* m_poMenuBar;
    uint32_t m_uiHightMenuBar;
    std::vector<CUnit*> m_vpoUnitVector;

};

#endif // MAINWINDOW_H
