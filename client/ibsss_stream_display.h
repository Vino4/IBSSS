#ifndef IBSSS_STREAM_DISPLAY_H
#define IBSSS_STREAM_DISPLAY_H

#include <QWidget>
#include <QImage>
#include <QEvent>
#include <QPainter>
#include <QImageReader>
#include <QMessageBox>
#include <QDir>

// We tried multiple ways of rendering the footage, this is the fastest we found
// inspired by the following stackoverflow post 
// http://stackoverflow.com/questions/22353080/efficient-way-of-displaying-a-continuous-stream-of-qimages

class Stream_Display : public QWidget {
	
	Q_OBJECT
	
	public:
		Stream_Display(QWidget* parent = 0);
		void setFrame(QImage* image);
		QImage * loadFrameImage(const QString &fileName);
	private:
		QImage* frame;

	protected:
		void paintEvent(QPaintEvent* event);
};

#endif // IBSSS_STREAM_DISPLAY_H
