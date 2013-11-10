#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include <QString>
#include <QImage>

class ImageHandler
{

public:
    ImageHandler();

    const static QString SUPPORTED_FORMATS;

    static QString  getImageLocation();
    static QImage   loadImage(QString filename);
};

#endif // IMAGEHANDLER_H
