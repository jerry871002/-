#include "qcvwidget.h"
#include "ui_qcvwidget.h"

QCvWidget::QCvWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCvWidget)
{
    ui->setupUi(this);
}

QCvWidget::~QCvWidget()
{
    thread->quit();
    while (!thread->isFinished());

    delete thread;
    delete ui;
}
