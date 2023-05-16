#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    protocol = new Protocol();
    scancodegun = new ScanCodeGun();
    row = 0;
    seq = 0;
    TableInit();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::TableInit()
{
    ui->tableWidget->setColumnCount(COL);//设置4列
    ui->tableWidget->setRowCount(10);
    row = 10-1;
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<< "X轴" << "Y轴" << "Z1轴" << "Z2轴" << "玻片扫码" << "试管扫码");
    QStringList reset;
    reset << "0" << "0" << "0" << "0" << "0" << "0";
    addDataRow(reset);
    for(int i=0;i<8;i++)
    {
        reset << "" << "" << "" << "" << "" << "1";
        addDataRow(reset);
    }
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
    QTableWidgetItem *item;
    int rowCount = ui->tableWidget->rowCount(); // 获取行数
    int colCount = ui->tableWidget->columnCount(); // 获取列数
    loc_ctrl = new location_ctrl[rowCount];
    for (int row = 0; row < rowCount; ++row)
    {
        loc_ctrl[row].x = -1;
        loc_ctrl[row].y = -1;
        loc_ctrl[row].z1 = -1;
        loc_ctrl[row].z2 = -1;
        loc_ctrl[row].scan = -1;
    }

    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < colCount-1; ++col) {//不读取最后一列
            item = ui->tableWidget->item(row, col); // 获取QTableWidgetItem对象
             if(item){
                 switch (col)
                 {
                    case 0:     loc_ctrl[row].x = item->text().toInt();         break;
                    case 1:     loc_ctrl[row].y = item->text().toInt();         break;
                    case 2:     loc_ctrl[row].z1 = item->text().toInt();        break;
                    case 3:     loc_ctrl[row].z2 = item->text().toInt();        break;
                    case 4:     loc_ctrl[row].scan = item->text().toInt();      break;
                    default:    break;
                 }
             }
             else
             {
                 continue;
             }
        }
        QMessageLogger().debug() << row+1 << "\t" << loc_ctrl[row].x << "\t" << loc_ctrl[row].y << "\t" << loc_ctrl[row].z1 << "\t" << loc_ctrl[row].z2 << "\t" << loc_ctrl[row].scan << "\n";
    }
//    delete loc;
    //发送复位指令
    sendProtocolToMainWindow(protocol->Protocol_Config(CMD_RESET,0,0));
    seq = 1;
//    getNextState(seq);
    state = STATE_IDLE;
    ui->stateProtocol->setText("指令传输中...");
}

void Dialog::productProtocol()
{
    QByteArray data;
    QTableWidgetItem *item;
    uint32_t motornum = 0;

    if(tubescan_flag!=0)
    {
        ui->stateProtocol->setText("******");
        if(tubescan_flag == 9)
        {
            tubescan_flag = 0;
            ui->stateProtocol->setText("试管扫码完成");
            return;
        }
        if(flag_crc)
        {
            item = ui->tableWidget->item(tubescan_flag-1,5); // 获取QTableWidgetItem对象
            flag_crc = 0;
        }
        else
            item = ui->tableWidget->item(tubescan_flag++,5); // 获取QTableWidgetItem对象
        QByteArray data = protocol->Protocol_Config(CMD_MOTORXZ,0,item->text().toUInt());
        sendProtocolToMainWindow(data);

        QMessageLogger().debug() << item->text().toUInt();
        return;
    }

    QMessageLogger().debug() << "flag_crc = " << flag_crc;
    //发送下一个指令
    if(flag_crc)
    {

        flag_crc = 0;
    }
    else
        getNextState(seq);
    if(state == STATE_IDLE)
    {
        seq++;
        //判断指令
        if(loc_ctrl[seq].x == -1)
        {
            //结束发送
            ui->stateProtocol->setText("指令传输完成");
            seq = 1;
            state = STATE_IDLE;
            delete loc_ctrl;
            return;
        }
        getNextState(seq);
    }

    switch(state)
    {
        case STATE_X:
            motornum = 0x02;
            data = protocol->Protocol_Config(CMD_MOTORXZ,motornum,(uint32_t)loc_ctrl[seq].x);
            break;
        case STATE_Y:
            data = protocol->Protocol_Config(CMD_MOTORY,motornum,(uint32_t)loc_ctrl[seq].y);
            break;
        case STATE_Z1:
            motornum = 0x04;
            data = protocol->Protocol_Config(CMD_MOTORXZ,motornum,(uint32_t)loc_ctrl[seq].z1);
            break;
        case STATE_Z2:
            motornum = 0x08;
            data = protocol->Protocol_Config(CMD_MOTORXZ,motornum,(uint32_t)loc_ctrl[seq].z2);
            break;
        case STATE_SCAN:
            data = scancodegun->Scan_Decode_Start();
            break;
        case STATE_IDLE:

        default:
            break;
    }
    sendProtocolToMainWindow(data);
}

//判断下一状态
void Dialog::getNextState(int seq)
{
    if(loc_ctrl[seq].x != loc_ctrl[seq-1].x && state < STATE_X && loc_ctrl[seq].x != -1)
    {
        state = STATE_X;
        return;
    }

    if(loc_ctrl[seq].y != loc_ctrl[seq-1].y && state < STATE_Y)
    {
        state = STATE_Y;
        return;
    }

    if(loc_ctrl[seq].z1 != loc_ctrl[seq-1].z1  && state < STATE_Z1)
    {
        state = STATE_Z1;
        return;
    }
    if(loc_ctrl[seq].z2 != loc_ctrl[seq-1].z2  && state < STATE_Z2)
    {
        state = STATE_Z2;
        return;
    }
    if(loc_ctrl[seq].scan != loc_ctrl[seq-1].scan  && state < STATE_SCAN)
    {
        state = STATE_SCAN;
        return;
    }
    if(state == STATE_IDLE)
    {
        state = STATE_X;
        return;
    }
    state = STATE_IDLE;
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

void Dialog::on_import_2_clicked()
{
    static int row=0;
    QStringList list;
    QString filePath = QFileDialog::getOpenFileName(this, tr("选择文件"), ".", tr("所有文件(*.csv*)"));

    if(!filePath.isEmpty())
    {
        QFile file(filePath);
        if(file.open(QIODevice::ReadOnly))
        {
            ui->tableWidget->setRowCount(0);
            // 内容读取
            while(!file.atEnd())
            {
                QString line = file.readLine();
                QStringList elements = line.split(",");
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                for(int i=0; i<elements.size(); i++){
                    if(row!=0)
                    {
                        if(i==4) elements[i].remove("\r\n");
                        QTableWidgetItem *item = new QTableWidgetItem(elements[i]);
                        ui->tableWidget->setItem(row-1, i, item);
                    }
                }
                row++;
            }
        }
        ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);
        row = 0;
        file.close();
    }

}

void Dialog::on_scantube_clicked()
{
    tubescan_flag = 0;
    QTableWidgetItem *item;
    QByteArray data;
    item = ui->tableWidget->item( tubescan_flag++,5); // 获取QTableWidgetItem对象
    data = protocol->Protocol_Config(CMD_MOTORXZ,0,item->text().toUInt());
    sendProtocolToMainWindow(data);
    QMessageLogger().debug() << item->text().toUInt();
}



void Dialog::closeEvent(QCloseEvent *event)
{
    flag_dialog = 0;
    QMessageLogger().debug() << "flag_dialog closed";
    event->accept();
}
