#include "mainprojectview.h"
#include "ui_mainprojectview.h"

MainProjectView::MainProjectView(QWidget *parent)
    : QScrollArea(parent)
    , ui(new Ui::MainProjectView)
{
    ui->setupUi(this);
}

MainProjectView::~MainProjectView()
{
    delete ui;
}
