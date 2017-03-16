#ifndef IBSSS_UI_LOGIN_PAGE_H
#define IBSSS_UI_LOGIN_PAGE_H

#include <QDialog>
#include "ibsss_server_connection_handler.hh"
#include "ui_ibsss_login_window.h"
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QObject>
#include "ibsss_state_machine_event.h"

namespace Ui {
class IBSSS_Login_Window_Layout;
}

class IBSSS_Login_Window : public QDialog
{
    Q_OBJECT

public:
    explicit IBSSS_Login_Window(QApplication *parent = 0,  Server_Connection_Handle * connection = NULL, QStateMachine * state_machine_ptr = NULL);
    ~IBSSS_Login_Window();

private slots:
    void on_loginButton_clicked();

    void on_CreateUserButton_clicked();

private:
    Ui::IBSSS_Login_Window_Layout *ui;
    Server_Connection_Handle * connection;
    QStateMachine * state_machine;
};

#endif // IBSSS_UI_LOGIN_PAGE_H
