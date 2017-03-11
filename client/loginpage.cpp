#include "loginpage.h"
#include "ui_loginpage.h"
#include "ibsss_server_connection_handler.hh"
#include <QMessageBox>
#include <unistd.h>

LoginPage::LoginPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_loginButton_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    //mattsLoginFunction(username.toStdString(), password.toStdString());

    int success = connection.connect();
    //QMessageBox::information(this, "resulty", QString::number(success));

    if (connection.operationLogin(username.toStdString(), password.toStdString())){
        //QMessageBox::information(this, "Login", "YAY");

        QPixmap file("cereal.jpeg"); //
        QPixmap file2("bowlofcereal.jpeg");

        streamView = new StreamView(this);

        streamView->show();

        this->hide(); //hide login dialog box
        streamView->LoadImage(file2);
        //streamView->LoadImage(file);
        //sleep(1);
        //streamView->LoadImage(file2);
    }
    else{
        QMessageBox::information(this, "Login", "WRONG TRY AGAIN");
    }

}

void LoginPage::on_newUserButton_clicked()
{
    //connection.operationCreateUser()
}
