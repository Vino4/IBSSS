#include "ibsss_stream_display.h"
#include <QWidget>
#include <QImage>
#include <QEvent>
#include <QPainter>
#include <QString>
#include <QImageReader>
#include <QMessageBox>
#include <QDir>
bool testing_bool = true;

// We tried multiple ways of rendering the footage, this is the fastest we managed to create
// the we decided not to use ::scaled do to it's slow performance, this decided was inspired by the following stackoverflow post
// http://stackoverflow.com/questions/22353080/efficient-way-of-displaying-a-continuous-stream-of-qimages

Stream_Display::Stream_Display(QWidget *parent) : QWidget(parent) {
  frame_buffer = new QImage();
  frame = 0;
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void Stream_Display::displayFrameFromBuffer() {
  frame = frame_buffer;
  //repaint();
}

void Stream_Display::paintEvent(QPaintEvent*) {
    testing_bool = (!testing_bool);
    if(testing_bool){
        loadFrameToBuffer("bowlofcereal.jpeg");
        displayFrameFromBuffer();
    } else {
        loadFrameToBuffer("cereal.jpeg");
        displayFrameFromBuffer();
    }
  if (!frame) { return; }
  QPainter painter(this);
  painter.drawImage(rect(), *frame, frame->rect());
}

bool Stream_Display::loadFrameToBuffer(const QString &fileName){
	QImageReader reader(fileName);
    reader.setAutoTransform(true);
    reader.read(frame_buffer);
    if (frame_buffer->isNull()) {
		QMessageBox::information(this, "Ooops", 
		QString("Unable to load %1: %2")
		.arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return false;
	}
    return true;
}
