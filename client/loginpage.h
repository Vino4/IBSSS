#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>
#include "streamview.h"
#include "ibsss_server_connection_handler.hh"

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

    void on_newUserButton_clicked();

private:
    Ui::LoginPage *ui;
    StreamView *streamView;
    Server_Connection_Handle connection;
};

#endif // LOGINPAGE_H
