/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_1;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_plusMinus;
    QPushButton *pushButton_2;
    QPushButton *pushButton_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton_percent;
    QPushButton *pushButton_3;
    QPushButton *pushButton_9;
    QPushButton *pushButton_6;
    QPushButton *pushButton_divide;
    QPushButton *pushButton_multiply;
    QPushButton *pushButton_add;
    QPushButton *pushButton_substract;
    QPushButton *pushButton_0;
    QPushButton *pushButton_equals;
    QPushButton *pushButton_dot;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(240, 360);
        MainWindow->setStyleSheet(QLatin1String("Qlabel {\n"
"	qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"background-color : white;"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 240, 60));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("QLabel{\n"
"	qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"background-color :  white;"));
        pushButton_clear = new QPushButton(centralWidget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(0, 60, 60, 60));
        pushButton_clear->setStyleSheet(QLatin1String("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_1 = new QPushButton(centralWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setGeometry(QRect(0, 120, 60, 60));
        pushButton_1->setStyleSheet(QLatin1String("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(0, 180, 60, 60));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(0, 240, 60, 60));
        pushButton_7->setStyleSheet(QLatin1String("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_plusMinus = new QPushButton(centralWidget);
        pushButton_plusMinus->setObjectName(QStringLiteral("pushButton_plusMinus"));
        pushButton_plusMinus->setGeometry(QRect(60, 60, 60, 60));
        pushButton_plusMinus->setStyleSheet(QLatin1String("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 120, 60, 60));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(60, 240, 60, 60));
        pushButton_8->setStyleSheet(QLatin1String("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(60, 180, 60, 60));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_percent = new QPushButton(centralWidget);
        pushButton_percent->setObjectName(QStringLiteral("pushButton_percent"));
        pushButton_percent->setGeometry(QRect(120, 60, 60, 60));
        pushButton_percent->setStyleSheet(QLatin1String("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 120, 60, 60));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(120, 240, 60, 60));
        pushButton_9->setStyleSheet(QLatin1String("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(120, 180, 60, 60));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_divide = new QPushButton(centralWidget);
        pushButton_divide->setObjectName(QStringLiteral("pushButton_divide"));
        pushButton_divide->setGeometry(QRect(180, 60, 60, 60));
        pushButton_divide->setStyleSheet(QLatin1String("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_multiply = new QPushButton(centralWidget);
        pushButton_multiply->setObjectName(QStringLiteral("pushButton_multiply"));
        pushButton_multiply->setGeometry(QRect(180, 120, 60, 60));
        pushButton_multiply->setStyleSheet(QLatin1String("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_add = new QPushButton(centralWidget);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));
        pushButton_add->setGeometry(QRect(180, 240, 60, 60));
        pushButton_add->setStyleSheet(QLatin1String("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_substract = new QPushButton(centralWidget);
        pushButton_substract->setObjectName(QStringLiteral("pushButton_substract"));
        pushButton_substract->setGeometry(QRect(180, 180, 60, 60));
        pushButton_substract->setStyleSheet(QLatin1String("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_0 = new QPushButton(centralWidget);
        pushButton_0->setObjectName(QStringLiteral("pushButton_0"));
        pushButton_0->setGeometry(QRect(0, 300, 120, 60));
        pushButton_0->setStyleSheet(QLatin1String("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_equals = new QPushButton(centralWidget);
        pushButton_equals->setObjectName(QStringLiteral("pushButton_equals"));
        pushButton_equals->setGeometry(QRect(180, 300, 60, 60));
        pushButton_equals->setStyleSheet(QLatin1String("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_dot = new QPushButton(centralWidget);
        pushButton_dot->setObjectName(QStringLiteral("pushButton_dot"));
        pushButton_dot->setGeometry(QRect(120, 300, 60, 60));
        pushButton_dot->setStyleSheet(QLatin1String("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "0", nullptr));
        pushButton_clear->setText(QApplication::translate("MainWindow", "C", nullptr));
        pushButton_1->setText(QApplication::translate("MainWindow", "1", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "4", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "7", nullptr));
        pushButton_plusMinus->setText(QApplication::translate("MainWindow", "+/-", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "2", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "8", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "5", nullptr));
        pushButton_percent->setText(QApplication::translate("MainWindow", "%", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "3", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "9", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "6", nullptr));
        pushButton_divide->setText(QApplication::translate("MainWindow", "\303\267", nullptr));
        pushButton_multiply->setText(QApplication::translate("MainWindow", "x", nullptr));
        pushButton_add->setText(QApplication::translate("MainWindow", "+", nullptr));
        pushButton_substract->setText(QApplication::translate("MainWindow", "-", nullptr));
        pushButton_0->setText(QApplication::translate("MainWindow", "0", nullptr));
        pushButton_equals->setText(QApplication::translate("MainWindow", "=", nullptr));
        pushButton_dot->setText(QApplication::translate("MainWindow", ".", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
