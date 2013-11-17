#include "imagehandler.h"
#include <QRgb>

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

// NOT TESTED VVVVVVVVVVV

char* ImageHandler::getSingleValuePerPixel(QImage image)
{
	if (! image.isGrayscale())
	{
		transformToGrayscale(&image);
	}
    char *values = new char[image.width() * image.height()];
	
	for (int i = 0; i < image.height(); i ++)
	{
		for (int j = 0; j < image.width(); j++)
		{
            values[i*image.width() + j] = qRed(image.pixel(i,j));
		}
	}
	return values;
}

void ImageHandler::transformToGrayscale(QImage *image)
{
	for (int i = 0; i < image->height(); i ++)
	{
		for (int j = 0; j < image->width(); j++)
		{

			QRgb px = image->pixel(i,j);

			// L = 0.299*R + 0.587*G + 0.114*B
            int luminance = 0.299 * qRed(px) + 0.587 * qGreen(px) +
                0.114 * qBlue(px);
            px = qRed(luminance) + qGreen(luminance) + qBlue(luminance) + qAlpha(255);
			image->setPixel(i, j, px);
		}
	}
	
}
