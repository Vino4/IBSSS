#ifndef STREAMVIEW_H
#define STREAMVIEW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "ibsss_server_connection_handler.hh"
#include "ui_ibsss_stream_view_window.h"
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QObject>
#include "ibsss_state_machine_event.h"

class QActionGroup;
class QButtonGroup;
class QStringList;

namespace Ui {
class IBSSS_Stream_View_Window_Layout;
}

class IBSSS_Stream_View_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit IBSSS_Stream_View_Window(QApplication *parent = 0, Server_Connection_Handle * connection_ptr = NULL, QStateMachine * state_machine_ptr = NULL);
    ~IBSSS_Stream_View_Window();
    void LoadImage(QPixmap file);

private slots:
    void on_actionLog_out_triggered();

    //void on_actionManage_Streams_triggered();
    void showSection(QAction* a);
    void backToStreamview();
    //void on_back_clicked();

    void on_changeImageButton_clicked();

private:
    Ui::IBSSS_Stream_View_Window_Layout *ui;

    QActionGroup* sections;
    QButtonGroup* backs;
    QStringList listy;

    QGraphicsScene *scene;

    Server_Connection_Handle * connection;
    QStateMachine * state_machine;

};

#endif // STREAMVIEW_H
