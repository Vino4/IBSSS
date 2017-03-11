#ifndef STREAMVIEW_H
#define STREAMVIEW_H

#include <QMainWindow>
#include <QGraphicsScene>

class QActionGroup;
class QButtonGroup;
class QStringList;

namespace Ui {
class StreamView;
}

class StreamView : public QMainWindow
{
    Q_OBJECT

public:
    explicit StreamView(QWidget *parent = 0);
    ~StreamView();
    void LoadImage(QPixmap file);

private slots:
    void on_actionLog_out_triggered();

    //void on_actionManage_Streams_triggered();
    void showSection(QAction* a);
    void backToStreamview();
    //void on_back_clicked();

    void on_changeImageButton_clicked();

private:
    Ui::StreamView *ui;
    QActionGroup* sections;
    QButtonGroup* backs;
    QStringList listy;
    QGraphicsScene *scene;
};

#endif // STREAMVIEW_H
