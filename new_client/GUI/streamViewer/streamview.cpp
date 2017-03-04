#include "streamview.h"
#include "ui_streamview.h"
#include <QMessageBox>
#include <QPixmap>
//#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

StreamView::StreamView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StreamView),
    sections(new QActionGroup(this)),
    backs(new QButtonGroup(this))
{
    ui->setupUi(this);

    QPixmap file("cereal.jpeg"); //

    /*if (file.isNull()){
        QMessageBox::information(this, "titly", "OHNOITSGONE");
    }
    else
        QMessageBox::information(this, "titly", "THEN WHAT THE HELL IS WRONG");
    */

//    int width = ui->graphicsView->geometry().width();
//    int height = ui->graphicsView->geometry().height();
    scene = new QGraphicsScene();
    //scene = new QGraphicsScene(QRectF(0,0, width, height),0);

//    QGraphicsPixmapItem *item = scene->addPixmap(file.scaled(QSize()))
 //   ui->graphicsView->fitInView(QRectF(0,0,width,height),Qt::KeepAspectRatio);
    ui->graphicsView->setScene(scene);
    //QGraphicsPixmapItem img(file);
    scene->addPixmap(file);

    QPixmap file2("bowlofcereal.jpeg");

    scene->addPixmap(file2);

/*    QWidget *centralWidget = new QWidget(this);
    QMenuBar *menu = new QMenuBar(centralWidget);

    QMenu *settings = new QMenu("Settings");
    //settings->addAction(stuff);
    menu->addMenu(settings);

    this->setCentralWidget(centralWidget);*/


    ui->actionAdd_Stream->setData(1);
    ui->actionManage_Streams->setData(2);
    ui->actionManage_Users->setData(3);
    ui->actionChange_Password->setData(4);

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

    //I guess do it here? for whichever streams the viewer has, add them to graphics views on [page0] and to the listView [page2]
    //    ui->streamsList->addItem(stream);


    //QStringList listy; // = new QStringList();
    listy<<"hello"<<"is this working?"<<"Idontknow"<<"1"<<"2"<<"3";
    //QString county = QString::number(listy.count());
    //QMessageBox::information(this, "titlee", county);
    //ui->tableWidget->insertColumn(1);
    //ui->tableWidget->se

    //QCheckBox *me = new QCheckBox();

    int i;
    for(i=0; i<listy.count(); i++){
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(listy[i]));
        //QString name = "checkbox"+i;
        //ui->tableWidget->setItem(i, 1, new QTableWidgetItem(new QCheckBox));
    }
    //listy.count()

    //ui->streamsList->setAlternatingRowColors(true); //alternating colors for items in streamsList in Manage Streams page
    //ui->streamsList->setSelectionBehavior(QAbstractItemView::SelectionBehavior behavior);
    //ui->tableWidget->setAlternatingRowColors();
}

StreamView::~StreamView()
{
    delete ui;
}

void StreamView::on_actionLog_out_triggered()
{
    //parent->show();
    this->close();
    //logout
}

void StreamView::showSection(QAction *a){
    ui->stackedWidget->setCurrentIndex(a->data().toInt());

}
/*
void StreamView::on_actionManage_Streams_triggered()
{
    //go to stream manager

}
*/
void StreamView::backToStreamview()
{
    ui->stackedWidget->setCurrentIndex(0); //back to stream view
}
/*
void StreamView::on_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); //back to stream view
}
*/
