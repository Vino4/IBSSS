/********************************************************************************
** Form generated from reading UI file 'ibsss_stream_view_window.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IBSSS_STREAM_VIEW_WINDOW_H
#define UI_IBSSS_STREAM_VIEW_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ibsss_stream_display.h"

QT_BEGIN_NAMESPACE

class Ui_IBSSS_Stream_View_Window_Layout
{
public:
    QAction *actionManage_Streams;
    QAction *actionLog_out;
    QAction *actionAdd_Stream;
    QAction *actionManage_Users;
    QAction *actionChange_Password;
    QAction *actionQuit;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *changeImageButton;
    Stream_Display *Display_1;
    Stream_Display *Display_2;
    Stream_Display *Display_3;
    Stream_Display *Display_4;
    QLabel *label_3;
    QWidget *page_5;
    QLabel *streamLink_label;
    QPushButton *back;
    QLineEdit *streamLink;
    QLineEdit *PIN;
    QLabel *PIN_label;
    QLabel *addStreams_label;
    QWidget *page_2;
    QPushButton *back1;
    QLabel *ManageStreams_label;
    QListWidget *userList;
    QPushButton *mu_promote_button;
    QPushButton *mu_demote_button;
    QPushButton *mu_deleteuser_button;
    QPushButton *lmu_pwreset_button;
    QPushButton *mu_email_button;
    QWidget *page_4;
    QLabel *ManageUsers_label;
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
    QPushButton *changePasswordButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *settingsMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *IBSSS_Stream_View_Window_Layout)
    {
        if (IBSSS_Stream_View_Window_Layout->objectName().isEmpty())
            IBSSS_Stream_View_Window_Layout->setObjectName(QStringLiteral("IBSSS_Stream_View_Window_Layout"));
        IBSSS_Stream_View_Window_Layout->resize(800, 600);
        actionManage_Streams = new QAction(IBSSS_Stream_View_Window_Layout);
        actionManage_Streams->setObjectName(QStringLiteral("actionManage_Streams"));
        actionLog_out = new QAction(IBSSS_Stream_View_Window_Layout);
        actionLog_out->setObjectName(QStringLiteral("actionLog_out"));
        actionAdd_Stream = new QAction(IBSSS_Stream_View_Window_Layout);
        actionAdd_Stream->setObjectName(QStringLiteral("actionAdd_Stream"));
        actionManage_Users = new QAction(IBSSS_Stream_View_Window_Layout);
        actionManage_Users->setObjectName(QStringLiteral("actionManage_Users"));
        actionChange_Password = new QAction(IBSSS_Stream_View_Window_Layout);
        actionChange_Password->setObjectName(QStringLiteral("actionChange_Password"));
        actionQuit = new QAction(IBSSS_Stream_View_Window_Layout);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralwidget = new QWidget(IBSSS_Stream_View_Window_Layout);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(40, 0, 751, 511));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        changeImageButton = new QPushButton(page);
        changeImageButton->setObjectName(QStringLiteral("changeImageButton"));
        changeImageButton->setGeometry(QRect(110, 240, 131, 29));
        Display_1 = new Stream_Display(page);
        Display_1->setObjectName(QStringLiteral("Display_1"));
        Display_1->setGeometry(QRect(50, 60, 251, 171));
        Display_2 = new Stream_Display(page);
        Display_2->setObjectName(QStringLiteral("Display_2"));
        Display_2->setGeometry(QRect(50, 290, 251, 191));
        Display_3 = new Stream_Display(page);
        Display_3->setObjectName(QStringLiteral("Display_3"));
        Display_3->setGeometry(QRect(390, 60, 251, 181));
        Display_4 = new Stream_Display(page);
        Display_4->setObjectName(QStringLiteral("Display_4"));
        Display_4->setGeometry(QRect(390, 290, 251, 191));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(300, 20, 111, 21));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        stackedWidget->addWidget(page);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        streamLink_label = new QLabel(page_5);
        streamLink_label->setObjectName(QStringLiteral("streamLink_label"));
        streamLink_label->setGeometry(QRect(210, 150, 211, 19));
        back = new QPushButton(page_5);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(20, 470, 71, 29));
        streamLink = new QLineEdit(page_5);
        streamLink->setObjectName(QStringLiteral("streamLink"));
        streamLink->setGeometry(QRect(210, 180, 421, 41));
        PIN = new QLineEdit(page_5);
        PIN->setObjectName(QStringLiteral("PIN"));
        PIN->setGeometry(QRect(210, 260, 181, 29));
        PIN_label = new QLabel(page_5);
        PIN_label->setObjectName(QStringLiteral("PIN_label"));
        PIN_label->setGeometry(QRect(210, 230, 51, 19));
        addStreams_label = new QLabel(page_5);
        addStreams_label->setObjectName(QStringLiteral("addStreams_label"));
        addStreams_label->setGeometry(QRect(280, 20, 161, 20));
        addStreams_label->setFont(font);
        stackedWidget->addWidget(page_5);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        back1 = new QPushButton(page_2);
        back1->setObjectName(QStringLiteral("back1"));
        back1->setGeometry(QRect(0, 480, 71, 29));
        ManageStreams_label = new QLabel(page_2);
        ManageStreams_label->setObjectName(QStringLiteral("ManageStreams_label"));
        ManageStreams_label->setGeometry(QRect(260, 10, 211, 41));
        ManageStreams_label->setFont(font);
        userList = new QListWidget(page_2);
        userList->setObjectName(QStringLiteral("userList"));
        userList->setGeometry(QRect(150, 70, 421, 341));
        userList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        userList->setAlternatingRowColors(true);
        userList->setSortingEnabled(true);
        mu_promote_button = new QPushButton(page_2);
        mu_promote_button->setObjectName(QStringLiteral("mu_promote_button"));
        mu_promote_button->setEnabled(false);
        mu_promote_button->setGeometry(QRect(240, 420, 31, 29));
        mu_demote_button = new QPushButton(page_2);
        mu_demote_button->setObjectName(QStringLiteral("mu_demote_button"));
        mu_demote_button->setEnabled(false);
        mu_demote_button->setGeometry(QRect(280, 420, 31, 29));
        mu_deleteuser_button = new QPushButton(page_2);
        mu_deleteuser_button->setObjectName(QStringLiteral("mu_deleteuser_button"));
        mu_deleteuser_button->setEnabled(false);
        mu_deleteuser_button->setGeometry(QRect(400, 420, 31, 29));
        lmu_pwreset_button = new QPushButton(page_2);
        lmu_pwreset_button->setObjectName(QStringLiteral("lmu_pwreset_button"));
        lmu_pwreset_button->setEnabled(false);
        lmu_pwreset_button->setGeometry(QRect(320, 420, 31, 29));
        mu_email_button = new QPushButton(page_2);
        mu_email_button->setObjectName(QStringLiteral("mu_email_button"));
        mu_email_button->setEnabled(false);
        mu_email_button->setGeometry(QRect(360, 420, 31, 29));
        stackedWidget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        ManageUsers_label = new QLabel(page_4);
        ManageUsers_label->setObjectName(QStringLiteral("ManageUsers_label"));
        ManageUsers_label->setGeometry(QRect(270, 10, 171, 41));
        ManageUsers_label->setFont(font);
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

        changePasswordButton = new QPushButton(verticalLayoutWidget);
        changePasswordButton->setObjectName(QStringLiteral("changePasswordButton"));

        horizontalLayout_4->addWidget(changePasswordButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        label = new QLabel(page_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 10, 221, 41));
        label->setFont(font);
        stackedWidget->addWidget(page_3);
        IBSSS_Stream_View_Window_Layout->setCentralWidget(centralwidget);
        menubar = new QMenuBar(IBSSS_Stream_View_Window_Layout);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        settingsMenu = new QMenu(menubar);
        settingsMenu->setObjectName(QStringLiteral("settingsMenu"));
        IBSSS_Stream_View_Window_Layout->setMenuBar(menubar);
        statusbar = new QStatusBar(IBSSS_Stream_View_Window_Layout);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        IBSSS_Stream_View_Window_Layout->setStatusBar(statusbar);

        menubar->addAction(settingsMenu->menuAction());
        settingsMenu->addAction(actionAdd_Stream);
        settingsMenu->addAction(actionManage_Streams);
        settingsMenu->addAction(actionManage_Users);
        settingsMenu->addAction(actionChange_Password);
        settingsMenu->addSeparator();
        settingsMenu->addAction(actionLog_out);

        retranslateUi(IBSSS_Stream_View_Window_Layout);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(IBSSS_Stream_View_Window_Layout);
    } // setupUi

    void retranslateUi(QMainWindow *IBSSS_Stream_View_Window_Layout)
    {
        IBSSS_Stream_View_Window_Layout->setWindowTitle(QApplication::translate("IBSSS_Stream_View_Window_Layout", "MainWindow", 0));
        actionManage_Streams->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Manage Streams", 0));
        actionLog_out->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Log out", 0));
        actionAdd_Stream->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Add Stream", 0));
        actionManage_Users->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Manage Users", 0));
        actionChange_Password->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Change Password", 0));
        actionQuit->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Quit", 0));
        changeImageButton->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Change Image", 0));
        label_3->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Streams", 0));
        streamLink_label->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Paste Stream link below:", 0));
        back->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Back", 0));
        PIN_label->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "PIN:", 0));
        addStreams_label->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Add Streams", 0));
        back1->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Back", 0));
        ManageStreams_label->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Manage Streams", 0));
#ifndef QT_NO_TOOLTIP
        mu_promote_button->setToolTip(QApplication::translate("IBSSS_Stream_View_Window_Layout", "<html><head/><body><p>promote</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        mu_promote_button->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "^", 0));
#ifndef QT_NO_TOOLTIP
        mu_demote_button->setToolTip(QApplication::translate("IBSSS_Stream_View_Window_Layout", "<html><head/><body><p>demote</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        mu_demote_button->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "v", 0));
#ifndef QT_NO_TOOLTIP
        mu_deleteuser_button->setToolTip(QApplication::translate("IBSSS_Stream_View_Window_Layout", "<html><head/><body><p>delete user</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        mu_deleteuser_button->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "X", 0));
#ifndef QT_NO_TOOLTIP
        lmu_pwreset_button->setToolTip(QApplication::translate("IBSSS_Stream_View_Window_Layout", "<html><head/><body><p>reset password</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        lmu_pwreset_button->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "#", 0));
#ifndef QT_NO_TOOLTIP
        mu_email_button->setToolTip(QApplication::translate("IBSSS_Stream_View_Window_Layout", "<html><head/><body><p>change email</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        mu_email_button->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "@", 0));
        ManageUsers_label->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Manage Users", 0));
        back2->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Back", 0));
        back3->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Back", 0));
        oldPW_label->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Old password:", 0));
        newPW_label->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "New password:", 0));
        confirmPW_label->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Confirm password:", 0));
        changePasswordButton->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Change", 0));
        label->setText(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Change Password", 0));
        settingsMenu->setTitle(QApplication::translate("IBSSS_Stream_View_Window_Layout", "Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class IBSSS_Stream_View_Window_Layout: public Ui_IBSSS_Stream_View_Window_Layout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IBSSS_STREAM_VIEW_WINDOW_H
