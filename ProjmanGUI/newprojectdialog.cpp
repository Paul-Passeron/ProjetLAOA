#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"

#include <QFileDialog>
#include <iostream>

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
 // ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

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

QString NewProjectDialog::getProjectName() { return ui->lineEdit->text(); }

void NewProjectDialog::on_pushButton_clicked() {
  directory = QFileDialog::getExistingDirectory(
      this, tr("Open Directory"), "/home",
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
  ui->lineEdit_2->clear();
  ui->lineEdit_2->setText(directory);
}

void NewProjectDialog::on_lineEdit_2_textChanged(const QString &arg1) {
  directory = arg1;
}

QString NewProjectDialog::getDir() { return directory; }

/*
void NewProjectDialog::on_lineEdit_textChanged(const QString &arg1) {
  if (arg1.isEmpty()) {
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
  }
  std::cout << "ARG ONE IS " << arg1.toStdString();
  ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
}
*/
/*
void NewProjectDialog::on_lineEdit_textEdited(const QString &arg1)
{
    if (arg1.isEmpty()) {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
    std::cout << "ARG ONE IS " << arg1.toStdString();
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
}*/

