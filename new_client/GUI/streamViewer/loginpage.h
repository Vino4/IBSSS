#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>
#include "streamview.h"

namespace Ui {
class LoginPage;
}

class LoginPage : public QDialog
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = 0);
    ~LoginPage();

private slots:
    void on_loginButton_clicked();

private:
    Ui::LoginPage *ui;
    StreamView *streamView;
};

#endif // LOGINPAGE_H
