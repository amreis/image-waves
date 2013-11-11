#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include <QFileDialog>
#include <QString>
#include <QImage>

class ImageHandler
{

public:
    ImageHandler();

    const static QString SUPPORTED_FORMATS;

	static char*	getSingleValuePerPixel(QImage image);
	static void		transformToGrayscale(QImage *image);
    static QString  getImageLocation();
    static QImage   loadImage(QString filename);
};

#endif // IMAGEHANDLER_H
