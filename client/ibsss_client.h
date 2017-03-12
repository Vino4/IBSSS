#ifndef IBSSS_CLIENT_H
#define IBSSS_CLIENT_H

#include "ibsss_server_connection_handler.hh"
#include "ibsss_login_window.h"
#include "ibsss_stream_view_window.h"
#include <QApplication>
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include "ibsss_state_machine_event.h"
#include <QObject>


class IBSSS_Client : public QObject {

    Q_OBJECT

    public:
        IBSSS_Client(){}
        void init(QApplication * application);
        int run();
		Server_Connection_Handle * getConnection();	

    public slots:
        void login();
        void logout();

    signals:

    private:
        QApplication * application;
        QStateMachine * state_machine;
        QState * running_state;
        QState * logging_in_state;
        QState * viewing_streams_state;
        QFinalState * exited_state;
        IBSSS_Login_Window * login_window;
        IBSSS_Stream_View_Window * stream_view_window;
        Server_Connection_Handle * connection;

};
#endif // IBSSS_CLIENT_H
