#include "RAJ_CMenubar.hh"
#include "RAJ_Traces.hh"

#include <QMessageBox>

CMenuBar::CMenuBar(uint32_t uiLenght, QWidget *parent) : QMenuBar(parent)
{
    trace_debug("Construction de CMenuBar");

    fnCreateActions();
    fnCreateMenus();

    this->setMinimumWidth(uiLenght);

    trace_debug("Fin Construction de CMenuBar");
}

void CMenuBar::fnCreateActions()
{
    trace_debug("Création de l'action Save");
    m_pQActionSave = new QAction(tr("&Save"), this);
    m_pQActionSave->setShortcuts(QKeySequence::Save);
    connect(m_pQActionSave,&QAction::triggered, this,&CMenuBar::SfnSave);

    trace_debug("Création de l'action Load");
    m_pQActionLoad = new QAction(tr("&Load"), this);
    m_pQActionLoad->setShortcuts(QKeySequence::Open);
    connect(m_pQActionLoad,&QAction::triggered, this,&CMenuBar::SfnLoad);

    trace_debug("Création de l'action New");
    m_pQActionNew = new QAction(tr("&New"), this);
    m_pQActionNew->setShortcuts(QKeySequence::New);
    connect(m_pQActionNew,&QAction::triggered, this,&CMenuBar::SfnNew);

    trace_debug("Création de l'action Help");
    m_pQActionHelp = new QAction(tr("&Help"), this);
    m_pQActionHelp->setShortcuts(QKeySequence::HelpContents);
    connect(m_pQActionHelp,&QAction::triggered, this,&CMenuBar::SfnHelp);
}

void CMenuBar::fnCreateMenus()
{
    trace_debug("Création du Menu");

    trace_debug("Création du menu File");
    m_pQMenuFile = this->addMenu(tr("&File"));
    m_pQMenuFile->addAction(m_pQActionNew);
    m_pQMenuFile->addAction(m_pQActionLoad);
    m_pQMenuFile->addAction(m_pQActionSave);

    trace_debug("Création du menu Help");
    m_pQMenuHelp = this->addMenu(tr("&Help"));
    m_pQMenuHelp->addAction(m_pQActionHelp);
}

void CMenuBar::SfnNew()
{
    trace_info("Fonction New");
    emit SigOutMenuBar(ENew);
}

void CMenuBar::SfnSave()
{
    trace_info("Fonction Save");
    emit SigOutMenuBar(ESave);
}

void CMenuBar::SfnLoad()
{
    trace_info("Fonction Load");
    emit SigOutMenuBar(ELoad);
}

void CMenuBar::SfnHelp()
{
    trace_info("Fonction Help");
    const QString strHelpText =
            "\"Go wisely and slowly. Those who rush stumble and fall.\"\n"
            "\tWilliam Shakespeare, Romeo and Juliet";
    QMessageBox *poQMesgBox = new QMessageBox(QMessageBox::Information,
                                              "Help",
                                              strHelpText,
                                              QMessageBox::Ok,
                                              this);
    poQMesgBox->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    poQMesgBox->exec();
}
