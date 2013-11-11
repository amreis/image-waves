#include "imagehandler.h"



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
	char *values = (char*) malloc(image.width() * image.height() * sizeof(char));
	
	for (int i = 0; i < image.height(); i ++)
	{
		for (int j = 0; j < image.width(); j++)
		{
			values[i*image.width() + j] = image.pixel(i,j).red();
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
			int luminance = 0.299 * px.red() + 0.587 * px.green() +
				0.114 * px.blue();
			px.setRed(luminance); px.setGreen(luminance); px.setBlue(luminance);
			image->setPixel(i, j, px);
		}
	}
	
}
