#ifndef IBSSS_STATE_MACHINE_EVENT_H
#define IBSSS_STATE_MACHINE_EVENT_H

#include "ibsss_server_connection_handler.hh"
#include "ibsss_login_window.h"
#include "ibsss_stream_view_window.h"
#include <QApplication>
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QAbstractTransition>
#include <QString>
#include <QEvent>


#define IBSSS_Global_Default_Event_ID 4

struct State_Machine_Event: public QEvent
{
    State_Machine_Event(const QString &input)
    : QEvent(QEvent::Type(QEvent::User+IBSSS_Global_Default_Event_ID)),
      event(input) {}

    QString event;
};


// based on the qt documentation recommendation:
// http://doc.qt.io/qt-5.8/statemachine-api.html
class State_Machine_Transition: public QAbstractTransition
{
    Q_OBJECT


public:
    State_Machine_Transition(const QString &input)
        : transition(input) {}

    virtual ~State_Machine_Transition() {};

protected:
    virtual bool eventTest(QEvent * event)
    {
        if (event->type() != QEvent::Type(QEvent::User+IBSSS_Global_Default_Event_ID))
            return false;
        State_Machine_Event *state_machine_event = static_cast<State_Machine_Event*>(event);
        return (transition == state_machine_event->event);
    }

    virtual void onTransition(QEvent *) {}

private:
    QString transition;
};

#endif // IBSSS_STATE_MACHINE_EVENT_H
