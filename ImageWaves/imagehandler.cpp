#include "imagehandler.h"
#include <QFileDialog>

const QString ImageHandler::SUPPORTED_FORMATS =
    "JPEG (*.jpg *.jpeg);; Bitmap (*.bmp);; PNG (*.png);; All files (*.*)";

ImageHandler::ImageHandler()
{

}

QString ImageHandler::getImageLocation()
{
    QString filename = QFileDialog::getOpenFileName(
                NULL,
                "Open",
                NULL,
                SUPPORTED_FORMATS);
    return filename;
}

QImage ImageHandler::loadImage(QString filename)
{
    return QImage(filename);
}
