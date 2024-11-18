#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"

QList<QString> getBuildSystemForLanguage(std::string lang) {
  if (lang == "C++") {
    return {"CMake", "Ninja", "Makefile"};
  } else if (lang == "C") {
    return {"Makefile"};
  } else if (lang == "Python") {
    return {"Hatchling"};
  } else if (lang == "Java") {
    return {"Gradle"};
  }
  return {};
}

NewProjectDialog::NewProjectDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::NewProjectDialog) {
  ui->setupUi(this);
  ui->comboBox->addItem("C");
  ui->comboBox->addItem("C++");
  ui->comboBox->addItem("Python");
  ui->comboBox->addItem("Java");

  std::string txt = ui->comboBox->itemText(0).toStdString();
  ui->comboBox_2->addItems(getBuildSystemForLanguage(txt));
}

NewProjectDialog::~NewProjectDialog() { delete ui; }

void NewProjectDialog::on_comboBox_activated(int index) {
  std::string txt = ui->comboBox->itemText(index).toStdString();
  ui->comboBox_2->clear();
  ui->comboBox_2->addItems(getBuildSystemForLanguage(txt));
}

QString NewProjectDialog::getLang() { return ui->comboBox->currentText(); }

QString NewProjectDialog::getBuildSystem() {
  return ui->comboBox_2->currentText();
}

bool NewProjectDialog::getGit() { return ui->checkBox->isChecked(); }

QString NewProjectDialog::getProjectName(){
    return ui->lineEdit->text();
}
