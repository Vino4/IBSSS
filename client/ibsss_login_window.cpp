#include "ibsss_login_window.h"
#include "ui_ibsss_login_window.h"
#include "ibsss_server_connection_handler.hh"
#include <QMessageBox>
#include <unistd.h>
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QObject>
#include "ibsss_state_machine_event.h"

IBSSS_Login_Window::IBSSS_Login_Window(__attribute__((unused)) QApplication *parent, Server_Connection_Handle * connection_ptr, QStateMachine * state_machine_ptr) :
    QDialog(NULL),
    ui(new Ui::IBSSS_Login_Window_Layout)
{
    ui->setupUi(this);
    connection = connection_ptr;
    state_machine = state_machine_ptr;

}

IBSSS_Login_Window::~IBSSS_Login_Window()
{
    delete ui;
}

void IBSSS_Login_Window::on_loginButton_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    //mattsLoginFunction(username.toStdString(), password.toStdString());

    if (!connection->isConnected()){
        if (!connection->connect()){
            QMessageBox::information(this, "Error", "Unable to establish connection to server");
            return;
        }
    }

    if (connection->operationLogin(username.toStdString(), password.toStdString())){
        //QMessageBox::information(this, "Login", "YAY");

        QPixmap file("cereal.jpeg"); //
        QPixmap file2("bowlofcereal.jpeg");
        /*
        streamView = new StreamView(this);

        streamView->show();
        */
        state_machine->postEvent(new State_Machine_Event("Login"));
        this->hide(); //hide login dialog box
        //streamView->LoadImage(file2);
        //streamView->LoadImage(file);
        //sleep(1);
        //streamView->LoadImage(file2);
    }
    else{
        QMessageBox::information(this, "Login", "WRONG TRY AGAIN");
    }

}

void IBSSS_Login_Window::on_CreateUserButton_clicked()
{
    if (!connection->isConnected()){
        if (!connection->connect()){
            QMessageBox::information(this, "Error", "Unable to establish connection to server");
            return;
        }
    }

    if(ui->cu_email->text()!=ui->cu_confirm_em->text()){
        QMessageBox::information(this, "Error", "E-mails must match");
        return;
    }
    if(ui->cu_password->text()!=ui->cu_confirm_pw->text()){
        QMessageBox::information(this, "Error", "Passwords must match");
        return;
    }
    if (!connection->usernameIsValid(ui->cu_username->text().toStdString())){
        QMessageBox::information(this, "Error",
                                    QString("Invalid username: \n - Must be letters and numbers \n - Must be no less than %1 characters \n - Must be no more than %2 characters")
                                     .arg(IBSSS_GLOBAL_MINIMUM_USERNAME_LENGTH).arg(IBSSS_GLOBAL_MAXIMUM_USERNAME_LENGTH));
        return;
    }
    if (!connection->passwordIsValid(ui->cu_password->text().toStdString())){
        QMessageBox::information(this, "Error",
                                    QString("Invalid password: \n - Must be letters and numbers \n - Must be no less than %1 characters \n - Must be no more than %2 characters")
                                     .arg(IBSSS_GLOBAL_MINIMUM_PASSWORD_LENGTH).arg(IBSSS_GLOBAL_MAXIMUM_PASSWORD_LENGTH));
        return;
    }
    if (!connection->operationCreateUser(ui->cu_username->text().toStdString(), ui->cu_password->text().toStdString(), ui->cu_email->text().toStdString())){
        QMessageBox::information(this, "Error",
                                 "Could not create account");
        return;
    }

    QMessageBox::information(this, "Success", "Account successfully created");

    QPixmap file("cereal.jpeg"); //
    QPixmap file2("bowlofcereal.jpeg");
    /*
    streamView = new StreamView(this, connection);

    streamView->show();
    */
    this->hide(); //hide login dialog box
    //streamView->LoadImage(file2);
    //streamView->LoadImage(file);
    //sleep(1);
    //streamView->LoadImage(file2);
}
