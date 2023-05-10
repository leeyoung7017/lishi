#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

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
private slots:
    void on_addRow_clicked();

    void on_rmRow_clicked();

    void on_send_clicked();

    void on_export_2_clicked();

public slots:
    void productProtocol();
signals:
    void sendProtocolToMainWindow(QByteArray data);

private:
    Ui::Dialog *ui;
    int row;
    int seq;
};

#endif // DIALOG_H
