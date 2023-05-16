#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "protocol.h"
#include "gv.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include "scancodegun.h"

#define COL 6

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void TableInit();
    void addDataRow(QStringList str);
    void getNextState(int seq);
    void closeEvent(QCloseEvent *event);//复写closeEvent函数
private slots:
    void on_addRow_clicked();

    void on_rmRow_clicked();

    void on_send_clicked();

    void on_export_2_clicked();

    void on_import_2_clicked();

    void on_scantube_clicked();

public slots:
    void productProtocol();
signals:
    void sendProtocolToMainWindow(QByteArray data);

private:
    Ui::Dialog *ui;
    Protocol *protocol;
    typedef struct{
        int x;
        int y;
        int z1;
        int z2;
        int scan;
    }location_ctrl;

    typedef enum{
        STATE_IDLE = 0,
        STATE_X = 1,
        STATE_Y,
        STATE_Z1,
        STATE_Z2,
        STATE_SCAN
    }StateProtocol;
    location_ctrl *loc_ctrl;
    int32_t tubeloc[9] = {0};
    StateProtocol state;
    ScanCodeGun *scancodegun;
    int tubescan_flag = 0;;//控制试管电机运动
    int row;
    int seq;
};

#endif // DIALOG_H
