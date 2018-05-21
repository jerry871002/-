#ifndef QCVWIDGET_H
#define QCVWIDGET_H

#include <QWidget>

namespace Ui {
class QCvWidget;
}

class QCvWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QCvWidget(QWidget *parent = 0);
    ~QCvWidget();

private:
    Ui::QCvWidget *ui;
};

#endif // QCVWIDGET_H
