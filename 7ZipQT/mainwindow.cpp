#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "stdio.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&extractionProcess, &QProcess::readyReadStandardOutput, this, &MainWindow::readyReadStandardOutput);
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
                 QFileInfo file = dir;
                 QString extractProgram = "./7za";
                 QStringList extractArguments;
                 extractArguments << "e " + file.absolutePath() + "/" + file.fileName();
                 extractArguments << "-o" + file.absolutePath() + "/"; // extract to installdir
                 std::cout << extractProgram.toStdString() << " " << extractArguments.join(" ").toStdString() << std::endl;

                 extractionProcess.start(extractProgram, extractArguments);
                 extractionProcess.waitForFinished(-1);

             }

         }
         else{
            archives = directory.entryInfoList(QStringList() << "*.7z" << "*.zip",QDir::Files);

            QFileInfo file = archives.takeFirst();
            QString extractProgram = "./7za";
            QStringList extractArguments;
            extractArguments << "e " + file.absolutePath() + "/" + file.fileName();
            extractArguments << "-o" + file.absolutePath() + "/"; // extract to installdir
            std::cout << extractProgram.toStdString() << " " << extractArguments.join(" ").toStdString() << std::endl;

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

void MainWindow::readyReadStandardOutput()
{
    ui->plainTextEditLogs->appendPlainText(extractionProcess.readAllStandardOutput());
}

