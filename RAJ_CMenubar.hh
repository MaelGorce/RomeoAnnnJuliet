#ifndef RAJ_CMENUBAR_H
#define RAJ_CMENUBAR_H

#include <QWidget>
#include <QMenuBar>
#include <QAction>

enum EMenuBarPossibility
{
    ENew=0,
    ESave,
    ELoad,
    EHelp,
    EMax
};

class CMenuBar : public QMenuBar
{
    Q_OBJECT
public:
    explicit CMenuBar(uint32_t uiLenght ,QWidget *parent = nullptr);

signals:
    void SigOutMenuBar(EMenuBarPossibility);

private slots:
    void SfnNew();
    void SfnSave();
    void SfnLoad();
    void SfnHelp();

private:
    void fnCreateActions();
    void fnCreateMenus();

    QMenu * m_pQMenuFile;
    QMenu * m_pQMenuHelp;
    QAction * m_pQActionSave;
    QAction * m_pQActionLoad;
    QAction * m_pQActionNew;
    QAction * m_pQActionHelp;
};

#endif // RAJ_CMENUBAR_H
