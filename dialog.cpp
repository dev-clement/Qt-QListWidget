#include <QMessageBox>
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    for (int i = 0; i < 9; ++i)
        ui->listWidget->addItem(QString::number(i) + " Item here");

    connect(ui->btn, &QPushButton::clicked, this, &Dialog::onPushButtonClicked);
}

void Dialog::onPushButtonClicked()
{
    QListWidgetItem *listWidgetItem = ui->listWidget->currentItem();

    listWidgetItem->setIcon(QIcon(":/resources/question_mark.svg"));
    listWidgetItem->setText("After fuzzy bunny !!");
    listWidgetItem->setForeground(Qt::red);
    listWidgetItem->setBackground(Qt::yellow);
}

Dialog::~Dialog()
{
    delete ui;
}
