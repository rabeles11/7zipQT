#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDirIterator>
#include <QString>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
   QString dir = "";

private slots:
    void on_actionQuit_triggered();

    void on_ChooseFileButton_clicked();

    void on_StartButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
