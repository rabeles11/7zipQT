#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "stdio.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::on_ChooseFileButton_clicked()
{
    QString directory = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                       QCoreApplication::applicationDirPath(),
                                                       QFileDialog::ShowDirsOnly
                                                       | QFileDialog::DontResolveSymlinks);
    this->ui->SourceDirLabel->setText(directory);
    dir = directory;
}


void MainWindow::on_StartButton_clicked()
{
     if(dir!=""){
         QFileInfoList archives;
         QDir directory(dir);
         if(this->ui->checkBoxRecursive->isChecked()){
             QDirIterator it(dir, QStringList() << "*.7z" << "*.zip", QDir::Files, QDirIterator::Subdirectories);
             while (it.hasNext()) {
                 QString dir = it.next();
                 qDebug() << dir;
             }

         }
         else{
            archives = directory.entryInfoList(QStringList() << "*.7z" << "*.zip",QDir::Files);

            QFileInfo file = archives.takeFirst();
            QProcess extractionProcess;
            QString extractProgram = "7z2107-x64.exe";
            QStringList extractArguments;
            extractArguments << "e"; // extract files and directories
            extractArguments << "-y"; // suppress questions
            extractArguments << "-o" + file.absolutePath() + "/" + file.baseName(); // extract to installdir
            std::cout << extractProgram.toStdString() << " " << extractArguments.join(" ").toStdString() << std::endl;
            extractArguments << file.absolutePath();

            extractionProcess.start(extractProgram, extractArguments);
            extractionProcess.waitForFinished(-1);
         }
     }
     else{
         QMessageBox msgBox;
         msgBox.setText("U didnt select folder yet!!");
         msgBox.exec();
     }
}

