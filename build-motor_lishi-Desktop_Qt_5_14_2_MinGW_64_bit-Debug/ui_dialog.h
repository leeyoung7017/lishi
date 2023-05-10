/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QTableWidget *tableWidget;
    QPushButton *addRow;
    QPushButton *rmRow;
    QPushButton *send;
    QPushButton *export_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(778, 499);
        tableWidget = new QTableWidget(Dialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(60, 30, 621, 381));
        addRow = new QPushButton(Dialog);
        addRow->setObjectName(QString::fromUtf8("addRow"));
        addRow->setGeometry(QRect(60, 440, 75, 23));
        rmRow = new QPushButton(Dialog);
        rmRow->setObjectName(QString::fromUtf8("rmRow"));
        rmRow->setGeometry(QRect(140, 440, 75, 23));
        send = new QPushButton(Dialog);
        send->setObjectName(QString::fromUtf8("send"));
        send->setGeometry(QRect(220, 440, 75, 23));
        export_2 = new QPushButton(Dialog);
        export_2->setObjectName(QString::fromUtf8("export_2"));
        export_2->setGeometry(QRect(300, 440, 75, 23));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        addRow->setText(QCoreApplication::translate("Dialog", "\346\267\273\345\212\240\347\251\272\350\241\214", nullptr));
        rmRow->setText(QCoreApplication::translate("Dialog", "\345\210\240\351\231\244\347\251\272\350\241\214", nullptr));
        send->setText(QCoreApplication::translate("Dialog", "\345\217\221\351\200\201\346\214\207\344\273\244", nullptr));
        export_2->setText(QCoreApplication::translate("Dialog", "\345\257\274\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
