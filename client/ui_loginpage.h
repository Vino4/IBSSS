/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QGroupBox *signInBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passLabel;
    QLineEdit *password;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *userLabel;
    QLineEdit *username;
    QPushButton *loginButton;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QCommandLinkButton *newUserButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName(QStringLiteral("LoginPage"));
        LoginPage->resize(400, 300);
        signInBox = new QGroupBox(LoginPage);
        signInBox->setObjectName(QStringLiteral("signInBox"));
        signInBox->setGeometry(QRect(70, 40, 261, 211));
        horizontalLayoutWidget_2 = new QWidget(signInBox);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 80, 239, 50));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        passLabel = new QLabel(horizontalLayoutWidget_2);
        passLabel->setObjectName(QStringLiteral("passLabel"));

        horizontalLayout_2->addWidget(passLabel);

        password = new QLineEdit(horizontalLayoutWidget_2);
        password->setObjectName(QStringLiteral("password"));

        horizontalLayout_2->addWidget(password);

        horizontalLayoutWidget = new QWidget(signInBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 30, 239, 50));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        userLabel = new QLabel(horizontalLayoutWidget);
        userLabel->setObjectName(QStringLiteral("userLabel"));

        horizontalLayout->addWidget(userLabel);

        username = new QLineEdit(horizontalLayoutWidget);
        username->setObjectName(QStringLiteral("username"));

        horizontalLayout->addWidget(username);

        loginButton = new QPushButton(signInBox);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(10, 130, 239, 29));
        horizontalLayoutWidget_3 = new QWidget(signInBox);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 160, 241, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        newUserButton = new QCommandLinkButton(horizontalLayoutWidget_3);
        newUserButton->setObjectName(QStringLiteral("newUserButton"));

        horizontalLayout_3->addWidget(newUserButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        retranslateUi(LoginPage);

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QDialog *LoginPage)
    {
        LoginPage->setWindowTitle(QApplication::translate("LoginPage", "LoginPage", 0));
        signInBox->setTitle(QApplication::translate("LoginPage", "SignIn", 0));
        passLabel->setText(QApplication::translate("LoginPage", "Password:", 0));
        userLabel->setText(QApplication::translate("LoginPage", "Username:", 0));
        loginButton->setText(QApplication::translate("LoginPage", "Login", 0));
#ifndef QT_NO_TOOLTIP
        newUserButton->setToolTip(QApplication::translate("LoginPage", "<html><head/><body><p>Create new account</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        newUserButton->setText(QApplication::translate("LoginPage", "New user?", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
