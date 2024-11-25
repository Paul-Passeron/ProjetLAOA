#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>

namespace Ui {
class NewProjectDialog;
}

class NewProjectDialog : public QDialog {
  Q_OBJECT

public:
  explicit NewProjectDialog(QWidget *parent = nullptr);
  ~NewProjectDialog();

private slots:
  void on_comboBox_activated(int index);

  void on_pushButton_clicked();

  void on_lineEdit_2_textChanged(const QString &arg1);

  private:
  Ui::NewProjectDialog *ui;
  QString directory;

public:
  QString getProjectName();

  QString getLang();

  QString getBuildSystem();

  QString getDir();

  bool getGit();
};

#endif // NEWPROJECTDIALOG_H
