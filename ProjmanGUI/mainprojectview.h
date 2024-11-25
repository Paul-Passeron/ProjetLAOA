#ifndef MAINPROJECTVIEW_H
#define MAINPROJECTVIEW_H

#include <QWidget>

namespace Ui {
class MainProjectView;
}

class MainProjectView : public QWidget
{
    Q_OBJECT

public:
    explicit MainProjectView(QWidget *parent = nullptr);
    ~MainProjectView();

private:
    Ui::MainProjectView *ui;
};

#endif // MAINPROJECTVIEW_H
