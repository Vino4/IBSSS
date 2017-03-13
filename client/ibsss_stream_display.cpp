#include "ibsss_stream_display.h"
#include <QWidget>
#include <QImage>
#include <QEvent>
#include <QPainter>
#include <QString>
#include <QImageReader>
#include <QMessageBox>
#include <QDir>

// We tried multiple ways of rendering the footage, this is the fastest we found
// inspired by the following stackoverflow post 
// http://stackoverflow.com/questions/22353080/efficient-way-of-displaying-a-continuous-stream-of-qimages

Stream_Display::Stream_Display(QWidget *parent) : QWidget(parent) {
  frame = 0;
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void Stream_Display::setFrame(QImage *image) {
  frame = image;
  repaint();
}

void Stream_Display::paintEvent(QPaintEvent*) {
  if (!frame) { return; }
  QPainter painter(this);
  painter.drawImage(rect(), *frame, frame->rect());
}

QImage * Stream_Display::loadFrameImage(const QString &fileName){
	QImageReader reader(fileName);
	reader.setAutoTransform(true);
	QImage * loaded_image = new QImage(); 
	reader.read(loaded_image);
	if (loaded_image->isNull()) {
		QMessageBox::information(this, "Ooops", 
		QString("Unable to load %1: %2")
		.arg(QDir::toNativeSeparators(fileName), reader.errorString()));
	}
	return loaded_image;
}
