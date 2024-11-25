#include "mainprojectview.h"
#include "ui_mainprojectview.h"

MainProjectView::MainProjectView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainProjectView)
{
    ui->setupUi(this);
}

MainProjectView::~MainProjectView()
{
    delete ui;
}
