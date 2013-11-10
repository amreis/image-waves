#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imagehandler.h"



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
    filename = ImageHandler::getImageLocation();
    QImage image;
    if (filename != NULL)
    {
        image = ImageHandler::loadImage(filename);
        showLoadedImage(image);
    }
}


void MainWindow::showLoadedImage(QImage image)
{
    this->originalImage = image;
    this->origScene.clear();
    this->origScene.addPixmap(QPixmap::fromImage(image));
    ui->imageView->setScene(&this->origScene);
    ui->imageView->fitInView(this->origScene.itemsBoundingRect(), Qt::KeepAspectRatio);
}
