#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    row = 0;
    TableInit();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::TableInit()
{
    ui->tableWidget->setColumnCount(5);//设置4列
    ui->tableWidget->setRowCount(10);
    row = 10-1;
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<< "X轴" << "Y轴" << "Z1轴" << "Z2轴" << "扫码");
    QStringList reset;
    reset << "0" << "0" << "0" << "0" << "0";
    addDataRow(reset);
}

void Dialog::on_addRow_clicked()
{
    row++;
    ui->tableWidget->insertRow(row);
     QMessageLogger().debug()<< "row = " << (row+1);
}


void Dialog::on_rmRow_clicked()
{
    ui->tableWidget->removeRow(row);
    QMessageLogger().debug()<< "row = " << row;
    row--;
}

void Dialog::addDataRow(QStringList str)
{
    for(int i=0;i<str.size();i++)
    {
        ui->tableWidget->setItem(0,i,new QTableWidgetItem(str.at(i)));
    }
}

void Dialog::on_send_clicked()
{
    //指令解析//把所有指令解析一遍
}

void Dialog::productProtocol()
{
    //判断下一个指令
    //发送下一个指令
}

void Dialog::on_export_2_clicked()
{

    QString str = nullptr;
    QTableWidgetItem *item;
    int rowCount = ui->tableWidget->rowCount(); // 获取行数
    int colCount = ui->tableWidget->columnCount(); // 获取列数

    str = "X轴,Y轴,Z1轴,Z2轴,扫码\n";

    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < colCount; ++col) {
            item = ui->tableWidget->item(row, col); // 获取QTableWidgetItem对象
             if(item)
             {
                str.append(item->text());
             }
             else
             {
                 str.append("");
             }
              str.append(",");
        }
        str = str.left(str.size()-1);
        str.append("\n");
    }


    QString path = QFileDialog::getExistingDirectory(this, tr("选择文件"), QDir::currentPath());
    path += "/流程.csv"; // 文件路径
    QString content = str; // 要写入的字符串

    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << content;
        file.close();
        QMessageBox::information(this, "Tips", "文件已保存");
    } else {
        // 打开文件失败
    }



}
