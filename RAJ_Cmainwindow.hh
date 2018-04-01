#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define C_WINDOW_HIGHT 720
#define C_WINDOW_LENGTH 1280

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = 0);
    ~CMainWindow();
};

#endif // MAINWINDOW_H
