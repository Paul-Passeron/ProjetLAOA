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

private:
  Ui::NewProjectDialog *ui;

public:
  QString getProjectName();

  QString getLang();

  QString getBuildSystem();

  bool getGit();
};

#endif // NEWPROJECTDIALOG_H
