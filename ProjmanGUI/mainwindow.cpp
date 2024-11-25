#include "mainwindow.h"
#include "Project.h"
#include "newprojectdialog.h"
#include "ui_mainwindow.h"
#include "Globals.h"

#include <QFileSystemModel>
#include <iostream>
#include <mainprojectview.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void initGit(std::filesystem::path project){
    std::string cmd = "git init ";
    cmd += std::filesystem::absolute(project).string();
    exec(cmd.c_str());
}

void MainWindow::on_actionNew_Project_triggered() {
  auto diag = NewProjectDialog();
    diag.setWindowTitle(QString("New Project"));
  diag.setModal(true);
  if (diag.exec() == QDialog::Accepted) {
    QString lang = diag.getLang();
    QString buildSystem = diag.getBuildSystem();
    QString projectName = diag.getProjectName();
    QString dir = diag.getDir();
    bool git = diag.getGit();
    std::filesystem::path p = std::filesystem::path(dir.toStdString());
    Project *new_proj = Project::projectFromSpecs(
        projectName.toStdString(), p, lang.toStdString(), buildSystem.toStdString());
    new_proj->initFileSystem();
    if(git){
        initGit(new_proj->getProjectPath());
    }
    QFileSystemModel *model = new QFileSystemModel;
    QString path = QString::fromStdString(p.string());
    std::cout << path.toStdString() << std::endl;
    ui->label->setText(projectName);
    model->setRootPath(QDir::currentPath());
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(QString::fromStdString(std::string(p / new_proj->getProjectName()))));
    ui->projView->setLayout(new QGridLayout(ui->projView));
    MainProjectView *v = new MainProjectView(ui->projView);
    ui->projView->layout()->addWidget(v);
  }
}

void MainWindow::on_actionOpen_Project_triggered() {}
