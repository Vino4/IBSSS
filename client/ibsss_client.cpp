#include "ibsss_server_connection_handler.hh"
#include "ibsss_client.h"
#include <QStateMachine>
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QObject>
#include "ibsss_state_machine_event.h"


void IBSSS_Client::init(QApplication *application_ptr){

    // Initializing main pointers
    application = application_ptr;
    connection = new Server_Connection_Handle();
    state_machine = new QStateMachine();

    // Creating Windows
    login_window = new IBSSS_Login_Window(application, connection, state_machine);
    stream_view_window = new IBSSS_Stream_View_Window(application, connection, state_machine);

    // Creating States
    running_state =  new QState();
    logging_in_state = new QState(running_state);
    viewing_streams_state = new QState(running_state);
    exited_state = new QFinalState();

    // Setting state transitions
    ibsssLinkStatesByEvent(logout_transition, running_state, logging_in_state, "Logout");
    ibsssLinkStatesByEvent(login_transition, running_state, viewing_streams_state, "Login");
    ibsssLinkStatesByEvent(exit_transition, running_state, exited_state, "Exit");

    // set initial running state
    running_state->setInitialState(logging_in_state);

    // add running state to the state machine
    state_machine->addState(running_state);

    // set initial state macine state
    state_machine->setInitialState(running_state);

    // connect states with slots
    QObject::connect(state_machine, SIGNAL(finished()), QApplication::instance(), SLOT(quit()));
    QObject::connect(viewing_streams_state, SIGNAL(entered()), this, SLOT(login()));
    QObject::connect(logging_in_state, SIGNAL(entered()), this, SLOT(logout()));

    // add exited state to state machine
    state_machine->addState(exited_state);

    // state state machine
    state_machine->start();
}

int IBSSS_Client::run(){
    login_window->show();
    return application->exec();

}

void IBSSS_Client::login(){
    stream_view_window->show();
}

void IBSSS_Client::logout(){
    std::cout << "HERE " << std::endl;
    login_window->show();

}

Server_Connection_Handle * IBSSS_Client::getConnection(){
    return connection;
}

