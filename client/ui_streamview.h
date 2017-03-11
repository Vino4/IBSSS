/********************************************************************************
** Form generated from reading UI file 'streamview.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STREAMVIEW_H
#define UI_STREAMVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StreamView
{
public:
    QAction *actionManage_Streams;
    QAction *actionLog_out;
    QAction *actionAdd_Stream;
    QAction *actionManage_Users;
    QAction *actionChange_Password;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_3;
    QGraphicsView *graphicsView_2;
    QGraphicsView *graphicsView_4;
    QPushButton *changeImageButton;
    QWidget *page_5;
    QLabel *label_3;
    QPushButton *back;
    QWidget *page_2;
    QPushButton *back1;
    QTableWidget *tableWidget;
    QWidget *page_4;
    QLabel *label_2;
    QPushButton *back2;
    QWidget *page_3;
    QPushButton *back3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *oldPW_label;
    QLineEdit *old_pw;
    QHBoxLayout *horizontalLayout;
    QLabel *newPW_label;
    QLineEdit *new_pw;
    QHBoxLayout *horizontalLayout_3;
    QLabel *confirmPW_label;
    QLineEdit *confirm_pw;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *settingsMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StreamView)
    {
        if (StreamView->objectName().isEmpty())
            StreamView->setObjectName(QStringLiteral("StreamView"));
        StreamView->resize(800, 600);
        actionManage_Streams = new QAction(StreamView);
        actionManage_Streams->setObjectName(QStringLiteral("actionManage_Streams"));
        actionLog_out = new QAction(StreamView);
        actionLog_out->setObjectName(QStringLiteral("actionLog_out"));
        actionAdd_Stream = new QAction(StreamView);
        actionAdd_Stream->setObjectName(QStringLiteral("actionAdd_Stream"));
        actionManage_Users = new QAction(StreamView);
        actionManage_Users->setObjectName(QStringLiteral("actionManage_Users"));
        actionChange_Password = new QAction(StreamView);
        actionChange_Password->setObjectName(QStringLiteral("actionChange_Password"));
        centralwidget = new QWidget(StreamView);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(30, 10, 751, 511));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        graphicsView = new QGraphicsView(page);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(50, 30, 256, 192));
        graphicsView_3 = new QGraphicsView(page);
        graphicsView_3->setObjectName(QStringLiteral("graphicsView_3"));
        graphicsView_3->setGeometry(QRect(50, 280, 256, 192));
        graphicsView_2 = new QGraphicsView(page);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(390, 30, 256, 192));
        graphicsView_4 = new QGraphicsView(page);
        graphicsView_4->setObjectName(QStringLiteral("graphicsView_4"));
        graphicsView_4->setGeometry(QRect(390, 280, 256, 192));
        changeImageButton = new QPushButton(page);
        changeImageButton->setObjectName(QStringLiteral("changeImageButton"));
        changeImageButton->setGeometry(QRect(110, 220, 131, 29));
        stackedWidget->addWidget(page);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        label_3 = new QLabel(page_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 90, 121, 19));
        back = new QPushButton(page_5);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(20, 470, 71, 29));
        stackedWidget->addWidget(page_5);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        back1 = new QPushButton(page_2);
        back1->setObjectName(QStringLiteral("back1"));
        back1->setGeometry(QRect(0, 480, 71, 29));
        tableWidget = new QTableWidget(page_2);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 10, 591, 431));
        stackedWidget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        label_2 = new QLabel(page_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(230, 70, 251, 51));
        back2 = new QPushButton(page_4);
        back2->setObjectName(QStringLiteral("back2"));
        back2->setGeometry(QRect(10, 470, 71, 29));
        stackedWidget->addWidget(page_4);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        back3 = new QPushButton(page_3);
        back3->setObjectName(QStringLiteral("back3"));
        back3->setGeometry(QRect(10, 470, 61, 29));
        verticalLayoutWidget = new QWidget(page_3);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(89, 79, 491, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        oldPW_label = new QLabel(verticalLayoutWidget);
        oldPW_label->setObjectName(QStringLiteral("oldPW_label"));

        horizontalLayout_2->addWidget(oldPW_label);

        old_pw = new QLineEdit(verticalLayoutWidget);
        old_pw->setObjectName(QStringLiteral("old_pw"));

        horizontalLayout_2->addWidget(old_pw);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        newPW_label = new QLabel(verticalLayoutWidget);
        newPW_label->setObjectName(QStringLiteral("newPW_label"));

        horizontalLayout->addWidget(newPW_label);

        new_pw = new QLineEdit(verticalLayoutWidget);
        new_pw->setObjectName(QStringLiteral("new_pw"));

        horizontalLayout->addWidget(new_pw);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        confirmPW_label = new QLabel(verticalLayoutWidget);
        confirmPW_label->setObjectName(QStringLiteral("confirmPW_label"));

        horizontalLayout_3->addWidget(confirmPW_label);

        confirm_pw = new QLineEdit(verticalLayoutWidget);
        confirm_pw->setObjectName(QStringLiteral("confirm_pw"));

        horizontalLayout_3->addWidget(confirm_pw);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        label = new QLabel(page_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 0, 151, 41));
        stackedWidget->addWidget(page_3);
        StreamView->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StreamView);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        settingsMenu = new QMenu(menubar);
        settingsMenu->setObjectName(QStringLiteral("settingsMenu"));
        StreamView->setMenuBar(menubar);
        statusbar = new QStatusBar(StreamView);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        StreamView->setStatusBar(statusbar);

        menubar->addAction(settingsMenu->menuAction());
        settingsMenu->addAction(actionAdd_Stream);
        settingsMenu->addAction(actionManage_Streams);
        settingsMenu->addAction(actionManage_Users);
        settingsMenu->addAction(actionChange_Password);
        settingsMenu->addSeparator();
        settingsMenu->addAction(actionLog_out);

        retranslateUi(StreamView);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StreamView);
    } // setupUi

    void retranslateUi(QMainWindow *StreamView)
    {
        StreamView->setWindowTitle(QApplication::translate("StreamView", "MainWindow", 0));
        actionManage_Streams->setText(QApplication::translate("StreamView", "Manage Streams", 0));
        actionLog_out->setText(QApplication::translate("StreamView", "Log out", 0));
        actionAdd_Stream->setText(QApplication::translate("StreamView", "Add Stream", 0));
        actionManage_Users->setText(QApplication::translate("StreamView", "Manage Users", 0));
        actionChange_Password->setText(QApplication::translate("StreamView", "Change Password", 0));
        changeImageButton->setText(QApplication::translate("StreamView", "Change Image", 0));
        label_3->setText(QApplication::translate("StreamView", "Add Stream", 0));
        back->setText(QApplication::translate("StreamView", "Back", 0));
        back1->setText(QApplication::translate("StreamView", "Back", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("StreamView", "ajl;asdf;jladsf", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("StreamView", "jasjsadjl;adsf", 0));
        label_2->setText(QApplication::translate("StreamView", "Manage Users", 0));
        back2->setText(QApplication::translate("StreamView", "Back", 0));
        back3->setText(QApplication::translate("StreamView", "Back", 0));
        oldPW_label->setText(QApplication::translate("StreamView", "Old password:", 0));
        newPW_label->setText(QApplication::translate("StreamView", "New password:", 0));
        confirmPW_label->setText(QApplication::translate("StreamView", "Confirm password:", 0));
        pushButton_2->setText(QApplication::translate("StreamView", "Change", 0));
        label->setText(QApplication::translate("StreamView", "Change Password", 0));
        settingsMenu->setTitle(QApplication::translate("StreamView", "Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class StreamView: public Ui_StreamView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STREAMVIEW_H
