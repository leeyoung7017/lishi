/********************************************************************************
** Form generated from reading UI file 'serial.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIAL_H
#define UI_SERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serial
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *ComLabel;
    QComboBox *Com;
    QLabel *BaudLabel;
    QComboBox *Baud;
    QLabel *DataLabel;
    QComboBox *Data;
    QLabel *StopLabel;
    QComboBox *Stop;
    QLabel *ParityLabel;
    QComboBox *Parity;
    QPushButton *ok;
    QPushButton *cancel;

    void setupUi(QDialog *serial)
    {
        if (serial->objectName().isEmpty())
            serial->setObjectName(QString::fromUtf8("serial"));
        serial->resize(245, 247);
        gridLayout = new QGridLayout(serial);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(serial);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 186, 151));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        ComLabel = new QLabel(formLayoutWidget);
        ComLabel->setObjectName(QString::fromUtf8("ComLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, ComLabel);

        Com = new QComboBox(formLayoutWidget);
        Com->setObjectName(QString::fromUtf8("Com"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Com->sizePolicy().hasHeightForWidth());
        Com->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::FieldRole, Com);

        BaudLabel = new QLabel(formLayoutWidget);
        BaudLabel->setObjectName(QString::fromUtf8("BaudLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, BaudLabel);

        Baud = new QComboBox(formLayoutWidget);
        Baud->addItem(QString());
        Baud->addItem(QString());
        Baud->setObjectName(QString::fromUtf8("Baud"));
        sizePolicy1.setHeightForWidth(Baud->sizePolicy().hasHeightForWidth());
        Baud->setSizePolicy(sizePolicy1);

        formLayout->setWidget(1, QFormLayout::FieldRole, Baud);

        DataLabel = new QLabel(formLayoutWidget);
        DataLabel->setObjectName(QString::fromUtf8("DataLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, DataLabel);

        Data = new QComboBox(formLayoutWidget);
        Data->addItem(QString());
        Data->addItem(QString());
        Data->addItem(QString());
        Data->addItem(QString());
        Data->setObjectName(QString::fromUtf8("Data"));
        sizePolicy1.setHeightForWidth(Data->sizePolicy().hasHeightForWidth());
        Data->setSizePolicy(sizePolicy1);

        formLayout->setWidget(2, QFormLayout::FieldRole, Data);

        StopLabel = new QLabel(formLayoutWidget);
        StopLabel->setObjectName(QString::fromUtf8("StopLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, StopLabel);

        Stop = new QComboBox(formLayoutWidget);
        Stop->addItem(QString());
        Stop->addItem(QString());
        Stop->addItem(QString());
        Stop->setObjectName(QString::fromUtf8("Stop"));
        sizePolicy1.setHeightForWidth(Stop->sizePolicy().hasHeightForWidth());
        Stop->setSizePolicy(sizePolicy1);

        formLayout->setWidget(3, QFormLayout::FieldRole, Stop);

        ParityLabel = new QLabel(formLayoutWidget);
        ParityLabel->setObjectName(QString::fromUtf8("ParityLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, ParityLabel);

        Parity = new QComboBox(formLayoutWidget);
        Parity->addItem(QString());
        Parity->addItem(QString());
        Parity->addItem(QString());
        Parity->setObjectName(QString::fromUtf8("Parity"));
        sizePolicy1.setHeightForWidth(Parity->sizePolicy().hasHeightForWidth());
        Parity->setSizePolicy(sizePolicy1);

        formLayout->setWidget(4, QFormLayout::FieldRole, Parity);

        ok = new QPushButton(groupBox);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(20, 180, 61, 23));
        cancel = new QPushButton(groupBox);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(80, 180, 61, 23));

        verticalLayout->addWidget(groupBox);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(serial);

        QMetaObject::connectSlotsByName(serial);
    } // setupUi

    void retranslateUi(QDialog *serial)
    {
        serial->setWindowTitle(QCoreApplication::translate("serial", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("serial", "\344\270\262\345\217\243\351\205\215\347\275\256", nullptr));
        ComLabel->setText(QCoreApplication::translate("serial", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        BaudLabel->setText(QCoreApplication::translate("serial", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        Baud->setItemText(0, QCoreApplication::translate("serial", "115200", nullptr));
        Baud->setItemText(1, QCoreApplication::translate("serial", "9600", nullptr));

        DataLabel->setText(QCoreApplication::translate("serial", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        Data->setItemText(0, QCoreApplication::translate("serial", "8", nullptr));
        Data->setItemText(1, QCoreApplication::translate("serial", "7", nullptr));
        Data->setItemText(2, QCoreApplication::translate("serial", "6", nullptr));
        Data->setItemText(3, QCoreApplication::translate("serial", "5", nullptr));

        StopLabel->setText(QCoreApplication::translate("serial", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        Stop->setItemText(0, QCoreApplication::translate("serial", "1", nullptr));
        Stop->setItemText(1, QCoreApplication::translate("serial", "1.5", nullptr));
        Stop->setItemText(2, QCoreApplication::translate("serial", "2", nullptr));

        ParityLabel->setText(QCoreApplication::translate("serial", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        Parity->setItemText(0, QCoreApplication::translate("serial", "\346\227\240", nullptr));
        Parity->setItemText(1, QCoreApplication::translate("serial", "\345\245\207", nullptr));
        Parity->setItemText(2, QCoreApplication::translate("serial", "\345\201\266", nullptr));

        ok->setText(QCoreApplication::translate("serial", "\347\241\256\345\256\232", nullptr));
        cancel->setText(QCoreApplication::translate("serial", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serial: public Ui_serial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIAL_H
