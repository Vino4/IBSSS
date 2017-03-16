#include "ibsss_stream_view_window.h"
#include "ui_ibsss_stream_view_window.h"
#include <QMessageBox>
#include <QPixmap>
//#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <ctime>
#include <thread>
#include <QTimer>
#include "ibsss_server_connection_handler.hh"
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QObject>
#include "ibsss_state_machine_event.h"
#include "ibsss_stream_display.h"

bool thing = true;

IBSSS_Stream_View_Window::IBSSS_Stream_View_Window(QApplication *parent, Server_Connection_Handle * connection_ptr, QStateMachine * state_machine_ptr) :
    QMainWindow(NULL),
    ui(new Ui::IBSSS_Stream_View_Window_Layout),
    sections(new QActionGroup(this)),
    backs(new QButtonGroup(this))
{
    ui->setupUi(this);
    connection = connection_ptr;
    state_machine = state_machine_ptr;

/*    QWidget *centralWidget = new QWidget(this);
    QMenuBar *menu = new QMenuBar(centralWidget);

    QMenu *settings = new QMenu("Settings");
    //settings->addAction(stuff);
    menu->addMenu(settings);

    this->setCentralWidget(centralWidget);*/


    ui->actionAdd_Stream->setData(1);
    ui->actionManage_Streams->setData(2);
    ui->actionManage_Users->setData(4);
    ui->actionChange_Password->setData(5);



    sections->addAction(ui->actionAdd_Stream);
    sections->addAction(ui->actionManage_Streams);
    sections->addAction(ui->actionManage_Users);
    sections->addAction(ui->actionChange_Password);

    connect(sections, SIGNAL(triggered(QAction*)), this, SLOT(showSection(QAction*)));

    backs->addButton(ui->back);
    backs->addButton(ui->back1);
    backs->addButton(ui->back2);
    backs->addButton(ui->back3);

    connect(backs, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(backToStreamview()));


    /*
     * MANAGE USERS
     *
     */

    //hard-coded sample list of users to fill list view in Manage Users page
    userlist << "user1" << "user2" << "user3" << "user4" << "user5" << "user6";

    int i;
    for(i=0; i<userlist.count(); i++){

        //fill list with users
        ui->userList->insertItem(i, userlist[i]);

        //fill permissions list with users
        ui->permissions_userList->insertItem(i, userlist[i]);
    }
    connect(ui->userList, SIGNAL(itemSelectionChanged()), this, SLOT(enableOptions()));

    /*
     * MANAGE STREAMS
     *
     */

    //fill ui->streamsList with list of streams
    //This is a hard-coded example of a list of streams, for demonstrational purposes

    ui->streamsList->insertItem(0, "stream 1");
    ui->streamsList->insertItem(1, "stream 2");
    ui->streamsList->insertItem(2, "stream 3");

    connect(ui->streamsList, SIGNAL(itemSelectionChanged()), this, SLOT(enableStreamOptions()));

    //connect(ui->ms_mngUsers_button, SIGNAL(clicked(bool)), this, SLOT(toggle_MS_MUS(int)));
}

IBSSS_Stream_View_Window::~IBSSS_Stream_View_Window()
{
    delete ui;
}

void IBSSS_Stream_View_Window::LoadImage(QPixmap file){

//    QPixmap file("cereal.jpeg"); //
//    QPixmap file2("bowlofcereal.jpeg");

    /*if (file.isNull()){
        QMessageBox::information(this, "titly", "OHNOITSGONE");
    }
    else
        QMessageBox::information(this, "titly", "THEN WHAT THE HELL IS WRONG");
    */

//    int width = ui->graphicsView->geometry().width();
//    int height = ui->graphicsView->geometry().height();
    //scene = new QGraphicsScene();
    //scene = new QGraphicsScene(QRectF(0,0, width, height),0);

//    QGraphicsPixmapItem *item = scene->addPixmap(file.scaled(QSize()))
 //   ui->graphicsView->fitInView(QRectF(0,0,width,height),Qt::KeepAspectRatio);
    //ui->graphicsView->setScene(scene);

    //QGraphicsPixmapItem img(file);
    //clock_t start_time = clock();

    //scene->addPixmap(file);
    //sleep(3);
    //scene->addPixmap(file2);
}

void IBSSS_Stream_View_Window::on_actionLog_out_triggered()
{
    connection->operationLogout();
    connection->killSession();
    connection->establishDisonnectedStatus();
    state_machine->postEvent(new State_Machine_Event("Logout"));
    this->hide(); //hide streamview window
}

void IBSSS_Stream_View_Window::showSection(QAction *a){
    ui->stackedWidget->setCurrentIndex(a->data().toInt());
}
/*
void StreamView::on_actionManage_Streams_triggered()
{
    //go to stream manager

}
*/
void IBSSS_Stream_View_Window::backToStreamview()
{
    ui->stackedWidget->setCurrentIndex(0); //back to stream view
}
/*
void StreamView::on_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); //back to stream view
}
*/


void IBSSS_Stream_View_Window::on_changeImageButton_clicked()
{
    //make new thread
    //pass address of this class to the thread
    //this->loadImage(file) in the background?
    //std::thread *namee = new std::thread(&StreamViewThreadHandler, this);
    //QThread thready = new QThread(ui->graphicsView);
    /*
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=] () {
        QPixmap file;
        if (thing){
        file = QPixmap("cereal.jpeg");
        }
        else
            file = QPixmap("bowlofcereal.jpeg");
        LoadImage(file);
        thing = (!thing);

    });
    timer->start(250);
    */
/*
    while (1){
        ui->Display_1->repaint();
    }
*/
    ui->Display_1->connection->connectToHost("10.111.69.51", 4774);
}


void IBSSS_Stream_View_Window::setMainPage(){
    ui->stackedWidget->setCurrentIndex(0);
}

void IBSSS_Stream_View_Window::on_changePasswordButton_clicked()
{
    if (!connection->passwordIsValid(ui->old_pw->text().toStdString())){
        QMessageBox::information(this, "Failed", QString("Invalid old password - Try Again!"));
        return;
    }
    if (!connection->passwordIsValid(ui->new_pw->text().toStdString())){
        QMessageBox::information(this, "Error",
                                    QString("Invalid new password: \n - Must be letters and numbers \n - Must be no less than %1 characters \n - Must be no more than %2 characters")
                                     .arg(IBSSS_GLOBAL_MINIMUM_PASSWORD_LENGTH).arg(IBSSS_GLOBAL_MAXIMUM_PASSWORD_LENGTH));
        return;
    }
    if(ui->new_pw->text()!=ui->confirm_pw->text()){
        QMessageBox::information(this, "Failed", QString("New Password must match Confirm Password, Dummy!\n Can't believe i have to tell you this..."));
        return;
    }


    if (!connection->operationChangePassword(connection->getUsername(), ui->old_pw->text().toStdString(), ui->new_pw->text().toStdString())){
        QMessageBox::information(this, "Failed",
                                 QString("Invalid old password - Try Again!"));
        return;
    }

    QMessageBox::information(this, "Success", "Password Changed Successfully!");

}

void IBSSS_Stream_View_Window::enableOptions()
{
    if(ui->userList->currentItem()->isSelected())
    {
        ui->mu_promote_button->setEnabled(true);
        ui->mu_deleteuser_button->setEnabled(true);
        ui->mu_demote_button->setEnabled(true);
        ui->mu_email_button->setEnabled(true);
        ui->lmu_pwreset_button->setEnabled(true);

    }
    else
    {
        ui->mu_promote_button->setEnabled(false);
        ui->mu_deleteuser_button->setEnabled(false);
        ui->mu_demote_button->setEnabled(false);
        ui->mu_email_button->setEnabled(false);
        ui->lmu_pwreset_button->setEnabled(false);
    }

}

void IBSSS_Stream_View_Window::enableStreamOptions()
{
    if(ui->streamsList->currentItem()->isSelected()){
        ui->ms_mngUsers_button->setEnabled(true);
        ui->ms_off_button->setEnabled(true);
        ui->ms_on_button->setEnabled(true);
        ui->ms_remove_button->setEnabled(true);
    }
    else
    {
        ui->ms_mngUsers_button->setEnabled(false);
        ui->ms_off_button->setEnabled(false);
        ui->ms_on_button->setEnabled(false);
        ui->ms_remove_button->setEnabled(false);
    }

}

void IBSSS_Stream_View_Window::on_ms_mngUsers_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void IBSSS_Stream_View_Window::on_mup_toMS_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
