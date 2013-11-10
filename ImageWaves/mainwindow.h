#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    const static QString SUPPORTED_FORMATS;
private slots:
    void on_loadButton_clicked();

private:
    QString getImageLocation();
    QImage loadImage(QString filename);

    QGraphicsScene origScene;
    QGraphicsScene editScene;
    QImage originalImage;
    QImage editedImage;

    void showLoadedImage(QImage image);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
