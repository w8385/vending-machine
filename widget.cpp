#include "widget.h"
#include "./ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeMoney(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int amount)
{
    money += amount;
    ui->lcdNumber->display(money);

    ui->pbCoffee->setEnabled(100 <= money);
    ui->pbMilk->setEnabled(150 <= money);
    ui->pbMango->setEnabled(500 <= money);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbMango_clicked()
{
    changeMoney(-500);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbReset_clicked()
{
    int coin500 = money / 500;
    money -= 500 * coin500;

    int coin100 = money / 100;
    money -= 100 * coin100;

    int coin50  = money / 50;
    money -= 50 * coin50;

    int coin10  = money / 10;
    money -= 10 * coin10;

    QMessageBox msg;
    msg.information(nullptr, "잔돈 반환", "500원\t: " + QString::number(coin500) \
                    + "\n100원\t: " + QString::number(coin100)\
                    + "\n50원\t: " + QString::number(coin50)\
                    + "\n10원\t: " + QString::number(coin10));
    ui->lcdNumber->display(money);
}

