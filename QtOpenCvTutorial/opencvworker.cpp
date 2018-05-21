#include "opencvworker.h"
#include <opencv2/imgproc/imgproc.hpp>

OpenCvWorker::OpenCvWorker(QObject *parent) :
    QObject(parent),
    status(false),
    toggleStream(false),
    binaryThresholdEnable(false),
    binaryThreshold(127)
{
    cap = new cv::VideoCapture();
}

OpenCvWorker::~OpenCvWorker()
{
    if(cap->isOpened())
        cap->release();

    delete cap;
}

void OpenCvWorker::receiveGrabFrame()
{
    if(!toggleStream)
        return;

    (*cap) >> _frameOriginal;
    if(_frameOriginal.empty())
        return;

    process();

    QImage output((const unsigned char*)_frameProssed.data, _frameProssed.cols, _frameProssed.rows, QImage::Format_Indexed8);

    emit sendFrame(output);
}

void OpenCvWorker::process()
{

}
