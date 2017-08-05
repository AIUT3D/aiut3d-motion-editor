#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <QWidget>

namespace Ui {
class CreditWindow;
}

class CreditWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CreditWindow(QWidget *parent = 0);
    ~CreditWindow();

private:
    Ui::CreditWindow *ui;
};

#endif // CREDITWINDOW_H
