#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

const QString MainWindow::SUPPORTED_FORMATS =
    "JPEG (*.jpg *.jpeg);; Bitmap (*.bmp);; PNG (*.png);; All files (*.*)";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadButton_clicked()
{
    QString filename;
    filename = getImageLocation();
    QImage image;
    if (filename != NULL)
    {
        image = loadImage(filename);
        showLoadedImage(image);
    }
}

QString MainWindow::getImageLocation()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                "Open",
                NULL,
                SUPPORTED_FORMATS);
    return filename;
}

QImage MainWindow::loadImage(QString filename)
{
    return QImage(filename);
}

void MainWindow::showLoadedImage(QImage image)
{
    this->originalImage = image;
    this->origScene.clear();
    this->origScene.addPixmap(QPixmap::fromImage(image));
    ui->imageView->setScene(&this->origScene);
    ui->imageView->fitInView(this->origScene.itemsBoundingRect(), Qt::KeepAspectRatio);
}
