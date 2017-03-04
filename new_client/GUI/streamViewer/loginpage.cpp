#include "loginpage.h"
#include "ui_loginpage.h"

#include <QMessageBox>

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


    if(username=="" && password == ""){
        //QMessageBox::information(this, "Login", "YAY");
        streamView = new StreamView(this);
        streamView->show();
        this->hide(); //hide login dialog box
    }
    else{
        QMessageBox::information(this, "Login", "WRONG TRY AGAIN");
    }

}
