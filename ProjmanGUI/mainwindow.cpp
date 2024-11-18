#include "Project.h"
#include "mainwindow.h"
#include "newprojectdialog.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_actionNew_Project_triggered() {
  auto diag = NewProjectDialog();
  diag.setModal(true);
  if (diag.exec() == QDialog::Accepted) {
    QString lang = diag.getLang();
    QString buildSystem = diag.getBuildSystem();
    QString projectName = diag.getProjectName();
    bool git = diag.getGit();
    CProject tmp = CProject(projectName.toStdString(), std::filesystem::path("./"));
    std::cout << "Project name is: " << tmp.getProjectName() << std::endl;
  }
}

void MainWindow::on_actionOpen_Project_triggered() {}
