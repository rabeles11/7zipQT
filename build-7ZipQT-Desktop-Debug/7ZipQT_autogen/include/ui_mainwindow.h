/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QLabel *label;
    QCheckBox *checkBoxRecursive;
    QPushButton *StartButton;
    QLabel *SourceDirLabel;
    QLabel *label_3;
    QCheckBox *checkBoxCmakeGeneration;
    QPlainTextEdit *plainTextEditLogs;
    QPushButton *ChooseFileButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(490, 543);
        MainWindow->setMaximumSize(QSize(490, 543));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 61, 73, 17));
        checkBoxRecursive = new QCheckBox(centralwidget);
        checkBoxRecursive->setObjectName(QString::fromUtf8("checkBoxRecursive"));
        checkBoxRecursive->setGeometry(QRect(30, 130, 92, 23));
        StartButton = new QPushButton(centralwidget);
        StartButton->setObjectName(QString::fromUtf8("StartButton"));
        StartButton->setGeometry(QRect(200, 160, 111, 31));
        SourceDirLabel = new QLabel(centralwidget);
        SourceDirLabel->setObjectName(QString::fromUtf8("SourceDirLabel"));
        SourceDirLabel->setGeometry(QRect(30, 100, 391, 21));
        SourceDirLabel->setFrameShape(QFrame::Box);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 210, 67, 17));
        checkBoxCmakeGeneration = new QCheckBox(centralwidget);
        checkBoxCmakeGeneration->setObjectName(QString::fromUtf8("checkBoxCmakeGeneration"));
        checkBoxCmakeGeneration->setGeometry(QRect(30, 460, 241, 23));
        plainTextEditLogs = new QPlainTextEdit(centralwidget);
        plainTextEditLogs->setObjectName(QString::fromUtf8("plainTextEditLogs"));
        plainTextEditLogs->setGeometry(QRect(30, 250, 441, 191));
        ChooseFileButton = new QPushButton(centralwidget);
        ChooseFileButton->setObjectName(QString::fromUtf8("ChooseFileButton"));
        ChooseFileButton->setGeometry(QRect(420, 100, 41, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 490, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
        label->setText(QApplication::translate("MainWindow", "Source dir:", nullptr));
        checkBoxRecursive->setText(QApplication::translate("MainWindow", "Recursive", nullptr));
        StartButton->setText(QApplication::translate("MainWindow", "START", nullptr));
        SourceDirLabel->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Log:", nullptr));
        checkBoxCmakeGeneration->setText(QApplication::translate("MainWindow", "Generate CMAKE configuration", nullptr));
        ChooseFileButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
