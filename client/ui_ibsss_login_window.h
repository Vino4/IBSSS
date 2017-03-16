/********************************************************************************
** Form generated from reading UI file 'ibsss_login_window.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IBSSS_LOGIN_WINDOW_H
#define UI_IBSSS_LOGIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IBSSS_Login_Window_Layout
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
    QFrame *line;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *cu_userLabel;
    QLabel *cu_passLabel;
    QLabel *cu_conf_pwLabel;
    QLabel *cu_emailLabel;
    QLabel *cu_conf_emLabel;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *cu_username;
    QLineEdit *cu_password;
    QLineEdit *cu_confirm_pw;
    QLineEdit *cu_email;
    QLineEdit *cu_confirm_em;
    QPushButton *CreateUserButton;

    void setupUi(QDialog *IBSSS_Login_Window_Layout)
    {
        if (IBSSS_Login_Window_Layout->objectName().isEmpty())
            IBSSS_Login_Window_Layout->setObjectName(QStringLiteral("IBSSS_Login_Window_Layout"));
        IBSSS_Login_Window_Layout->resize(544, 300);
        signInBox = new QGroupBox(IBSSS_Login_Window_Layout);
        signInBox->setObjectName(QStringLiteral("signInBox"));
        signInBox->setGeometry(QRect(290, 30, 251, 231));
        horizontalLayoutWidget_2 = new QWidget(signInBox);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 100, 231, 51));
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
        horizontalLayoutWidget->setGeometry(QRect(10, 50, 231, 51));
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
        loginButton->setGeometry(QRect(10, 150, 231, 29));
        line = new QFrame(IBSSS_Login_Window_Layout);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(270, 20, 21, 231));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setBold(false);
        font.setWeight(50);
        line->setFont(font);
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(1);
        line->setMidLineWidth(0);
        line->setFrameShape(QFrame::VLine);
        groupBox = new QGroupBox(IBSSS_Login_Window_Layout);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 251, 251));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 30, 91, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        cu_userLabel = new QLabel(verticalLayoutWidget);
        cu_userLabel->setObjectName(QStringLiteral("cu_userLabel"));

        verticalLayout->addWidget(cu_userLabel);

        cu_passLabel = new QLabel(verticalLayoutWidget);
        cu_passLabel->setObjectName(QStringLiteral("cu_passLabel"));

        verticalLayout->addWidget(cu_passLabel);

        cu_conf_pwLabel = new QLabel(verticalLayoutWidget);
        cu_conf_pwLabel->setObjectName(QStringLiteral("cu_conf_pwLabel"));
        cu_conf_pwLabel->setInputMethodHints(Qt::ImhNone);
        cu_conf_pwLabel->setWordWrap(true);

        verticalLayout->addWidget(cu_conf_pwLabel);

        cu_emailLabel = new QLabel(verticalLayoutWidget);
        cu_emailLabel->setObjectName(QStringLiteral("cu_emailLabel"));

        verticalLayout->addWidget(cu_emailLabel);

        cu_conf_emLabel = new QLabel(verticalLayoutWidget);
        cu_conf_emLabel->setObjectName(QStringLiteral("cu_conf_emLabel"));
        cu_conf_emLabel->setWordWrap(true);

        verticalLayout->addWidget(cu_conf_emLabel);

        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(90, 29, 161, 181));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        cu_username = new QLineEdit(verticalLayoutWidget_2);
        cu_username->setObjectName(QStringLiteral("cu_username"));

        verticalLayout_2->addWidget(cu_username);

        cu_password = new QLineEdit(verticalLayoutWidget_2);
        cu_password->setObjectName(QStringLiteral("cu_password"));

        verticalLayout_2->addWidget(cu_password);

        cu_confirm_pw = new QLineEdit(verticalLayoutWidget_2);
        cu_confirm_pw->setObjectName(QStringLiteral("cu_confirm_pw"));

        verticalLayout_2->addWidget(cu_confirm_pw);

        cu_email = new QLineEdit(verticalLayoutWidget_2);
        cu_email->setObjectName(QStringLiteral("cu_email"));

        verticalLayout_2->addWidget(cu_email);

        cu_confirm_em = new QLineEdit(verticalLayoutWidget_2);
        cu_confirm_em->setObjectName(QStringLiteral("cu_confirm_em"));

        verticalLayout_2->addWidget(cu_confirm_em);

        CreateUserButton = new QPushButton(groupBox);
        CreateUserButton->setObjectName(QStringLiteral("CreateUserButton"));
        CreateUserButton->setGeometry(QRect(50, 220, 141, 29));
        QWidget::setTabOrder(username, password);
        QWidget::setTabOrder(password, loginButton);
        QWidget::setTabOrder(loginButton, cu_username);
        QWidget::setTabOrder(cu_username, cu_password);
        QWidget::setTabOrder(cu_password, cu_confirm_pw);
        QWidget::setTabOrder(cu_confirm_pw, cu_email);
        QWidget::setTabOrder(cu_email, cu_confirm_em);
        QWidget::setTabOrder(cu_confirm_em, CreateUserButton);

        retranslateUi(IBSSS_Login_Window_Layout);

        QMetaObject::connectSlotsByName(IBSSS_Login_Window_Layout);
    } // setupUi

    void retranslateUi(QDialog *IBSSS_Login_Window_Layout)
    {
        IBSSS_Login_Window_Layout->setWindowTitle(QApplication::translate("IBSSS_Login_Window_Layout", "LoginPage", 0));
        signInBox->setTitle(QApplication::translate("IBSSS_Login_Window_Layout", "SignIn", 0));
        passLabel->setText(QApplication::translate("IBSSS_Login_Window_Layout", "Password:", 0));
        userLabel->setText(QApplication::translate("IBSSS_Login_Window_Layout", "Username:", 0));
        loginButton->setText(QApplication::translate("IBSSS_Login_Window_Layout", "Login", 0));
        groupBox->setTitle(QApplication::translate("IBSSS_Login_Window_Layout", "New User", 0));
        cu_userLabel->setText(QApplication::translate("IBSSS_Login_Window_Layout", "Username:", 0));
        cu_passLabel->setText(QApplication::translate("IBSSS_Login_Window_Layout", "Password:", 0));
        cu_conf_pwLabel->setText(QApplication::translate("IBSSS_Login_Window_Layout", "Confirm Password:", 0));
        cu_emailLabel->setText(QApplication::translate("IBSSS_Login_Window_Layout", "E-mail:", 0));
        cu_conf_emLabel->setText(QApplication::translate("IBSSS_Login_Window_Layout", "Confirm    e-mail:", 0));
        CreateUserButton->setText(QApplication::translate("IBSSS_Login_Window_Layout", "Create Account", 0));
    } // retranslateUi

};

namespace Ui {
    class IBSSS_Login_Window_Layout: public Ui_IBSSS_Login_Window_Layout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IBSSS_LOGIN_WINDOW_H
