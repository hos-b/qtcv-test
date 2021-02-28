#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QImageReader>

ImageViewer::ImageViewer(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::ImageViewer) {
    ui_->setupUi(this);
    connect(ui_->add_button, &QPushButton::clicked, this, &ImageViewer::UpdateImage);

    // read placeholder image
    QImageReader reader("../opencv-test/resources/placeholder.png");
    reader.setAutoTransform(true);
    qimage_ = reader.read();
    ui_->image_container->setPixmap(QPixmap::fromImage(qimage_));
}

ImageViewer::~ImageViewer() {
    delete ui_;
}

void ImageViewer::UpdateImage(bool update) {
    qDebug() << "clicked!";
}
