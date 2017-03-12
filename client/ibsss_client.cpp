#include "ibsss_server_connection_handler.hh"
#include "ibsss_client.h"
#include <QStateMachine>
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QObject>
#include "ibsss_state_machine_event.h"


void IBSSS_Client::init(QApplication *application_ptr){

    application = application_ptr;
    connection = new Server_Connection_Handle();

    state_machine = new QStateMachine();

    login_window = new IBSSS_Login_Window(application, connection, state_machine);
    stream_view_window = new IBSSS_Stream_View_Window(application, connection, state_machine);

    running_state =  new QState();
    logging_in_state = new QState(running_state);
    viewing_streams_state = new QState(running_state);
    exited_state = new QFinalState();

    State_Machine_Transition * transition_to_logging_in_state = new State_Machine_Transition("Loggin_In");
    transition_to_logging_in_state->setTargetState(logging_in_state);
    running_state->addTransition(transition_to_logging_in_state);

    State_Machine_Transition * transition_to_logged_in_state = new State_Machine_Transition("Logged_In");
    transition_to_logged_in_state->setTargetState(viewing_streams_state);
    running_state->addTransition(transition_to_logged_in_state);

    State_Machine_Transition * transition_to_exited_state = new State_Machine_Transition("Exited");
    transition_to_exited_state->setTargetState(exited_state);
    running_state->addTransition(transition_to_exited_state);

    running_state->setInitialState(logging_in_state);

    state_machine->addState(running_state);

    //running_state->addTransition(stream_view_window->getQuitActionPointer(), SIGNAL(&QAction::triggered), exited_state);

    state_machine->setInitialState(running_state);
    QObject::connect(state_machine, SIGNAL(finished()), QApplication::instance(), SLOT(quit()));
    QObject::connect(viewing_streams_state, SIGNAL(entered()), this, SLOT(login()));
    QObject::connect(logging_in_state, SIGNAL(entered()), this, SLOT(logout()));


    state_machine->addState(exited_state);

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

