#include "ibsss_stream_display.h"
#include <QWidget>
#include <QImage>
#include <QEvent>
#include <QPainter>
#include <QString>
#include <QImageReader>
#include <QMessageBox>
#include <QDir>
#include <QTcpSocket>
#include <QDataStream>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

bool testing_bool = true;

// We tried multiple ways of rendering the footage, this is the fastest we managed to create
// the we decided not to use ::scaled do to it's slow performance, this decided was inspired by the following stackoverflow post
// http://stackoverflow.com/questions/22353080/efficient-way-of-displaying-a-continuous-stream-of-qimages

Stream_Display::Stream_Display(QWidget *parent) : QWidget(parent) {
  connection = new QTcpSocket();

  connect(connection, SIGNAL(connected()), this, SLOT(gotcha()));
  connect(connection, SIGNAL(readyRead()), this, SLOT(isReadReady()));

  frame_buffer = new QImage();
  frame = 0;
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void Stream_Display::displayFrameFromBuffer() {
  frame = frame_buffer;
  //repaint();
}

void Stream_Display::paintEvent(QPaintEvent*) {
  /*  testing_bool = (!testing_bool);
    if(testing_bool){
        loadFrameToBuffer("bowlofcereal.jpeg");
        displayFrameFromBuffer();
    } else {
        loadFrameToBuffer("cereal.jpeg");
        displayFrameFromBuffer();
    }*/
  if (!frame) { return; }
  QPainter painter(this);
  painter.drawImage(rect(), *frame, frame->rect());
}

void Stream_Display::gotcha(){
    QMessageBox::information(this, "KENNACTED",
    QString("FAK YEEE"));
}

void Stream_Display::isReadReady(){
    //QByteArray bytearray = new QByteArray;
    QDataStream stream(connection);

    //qint16
    //int
//    char* fs;
//    unsigned int jenny;
//    stream.readBytes(fs,jenny);


    unsigned long long jen;
    char frame_[921600];
    stream.readRawData((char*)&jen, sizeof(jen));
    //for (unsigned long long i = 0; i < jen; i++){
    //    stream.readRawData(&frame[i], 1);
    //}

    QByteArray array;

    unsigned long long red = stream.readRawData(frame_, jen);
    std::cout << "Read: " << red << std::endl;
    //std::cout << "size:: "<< jen << std::endl;
    while (red < jen){
        red += stream.readRawData(&frame_[red], jen - red);
        //std::cout << "Read: " << red << std::endl;
    }

    std::cout << "Total Read: " << red << std::endl;

    Mat LoadedBuf = Mat(480,640, CV_8U, frame_);
    Mat decodedImage = imdecode(LoadedBuf, CV_LOAD_IMAGE_COLOR);

    cvtColor(decodedImage, decodedImage, CV_BGR2RGB);

    imwrite("picturey.jpg", decodedImage);



    //if (frame_buffer!=NULL){
    //    delete frame_buffer;
    //    frame_buffer = new QImage(decodedImage.data, decodedImage.cols, decodedImage.rows, decodedImage.step, QImage::Format_RGB888);
    //    connection->close();

    //}
    //frame = frame_buffer;

    //    stream>>framesize;

    //while (connection->bytesAvailable()){
        //buffer.append(connection->readAll());
        //int numBytes = getPacketSize(buffer);
        //while(packetSize>0)
        //{
        //    handlePacket(buffer.left(sizeOfPacket));
        //    buffer.remove(0,packetSize);
        //    sizeOfPacket = getPacketSize(buffer);
        //}

      //  bytearray = connection->readAll();
    //}
    //QString stringy = bytearray.toStdString();

    //std::cout<<fs<<std::endl;

    std::cout<<"size:   "<<std::endl<<jen<<std::endl;
    //std::cout<<"data:   "<<std::endl<<frame<<std::endl;

//    QMessageBox::information(this, "read data size?", QString::number(framesize));
}

bool Stream_Display::loadFrameToBuffer(const QString &fileName){
	QImageReader reader(fileName);
    reader.setAutoTransform(true);
    reader.read(frame_buffer);
    if (frame_buffer->isNull())


    {
		QMessageBox::information(this, "Ooops", 
		QString("Unable to load %1: %2")
		.arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return false;
	}
    return true;
}


