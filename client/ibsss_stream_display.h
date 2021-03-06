#ifndef IBSSS_STREAM_DISPLAY_H
#define IBSSS_STREAM_DISPLAY_H

#include <QWidget>
#include <QImage>
#include <QEvent>
#include <QPainter>
#include <QImageReader>
#include <QMessageBox>
#include <QDir>
#include <QTcpSocket>

// We tried multiple ways of rendering the footage, this is the fastest we managed to create
// the we decided not to use ::scaled do to it's slow performance, this decided was inspired by the following stackoverflow post
// http://stackoverflow.com/questions/22353080/efficient-way-of-displaying-a-continuous-stream-of-qimages

class Stream_Display : public QWidget {
	
	Q_OBJECT
	
	public:
		Stream_Display(QWidget* parent = 0);
        void displayFrameFromBuffer();
        bool loadFrameToBuffer(const QString &fileName);
        QTcpSocket * connection;
    public slots:
        void gotcha();
        void isReadReady();

    private:
        QImage* frame;
        QImage* frame_buffer;

	protected:
		void paintEvent(QPaintEvent* event);
};

#endif // IBSSS_STREAM_DISPLAY_H
