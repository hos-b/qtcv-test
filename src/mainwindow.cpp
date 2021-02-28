#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImageReader>
#include <QDebug>
#include <QImage>
#include <string>

#include <opencv2/opencv.hpp>

ImageViewer::ImageViewer(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::ImageViewer) {
    ui_->setupUi(this);
    connect(ui_->add_button, &QPushButton::clicked, this, &ImageViewer::UpdateImage);

    // read placeholder image
    QImageReader reader("../opencv-test/resources/placeholder.png");
    reader.setAutoTransform(true);
    QImage q_image = reader.read();
    ui_->image_container->setPixmap(QPixmap::fromImage(q_image));

}

ImageViewer::~ImageViewer() {
    delete ui_;
}

void ImageViewer::UpdateImage(bool update) {
    static size_t counter = 0;
    cv::Mat cv_image = cv::Mat::zeros(cv::Size(600, 400), CV_8UC3);
    cv_image = cv::Scalar(70, 70, 70);
    cv::putText(cv_image, "clicked " + std::to_string(counter) + " times",
                cv::Point(180, 180), cv::FONT_HERSHEY_COMPLEX, 1.0, cv::Scalar(255, 127, 0));
    cv::cvtColor(cv_image, cv_image,cv::COLOR_BGR2RGB);
    QImage image((uchar*)cv_image.data, cv_image.cols, cv_image.rows, QImage::Format_RGB888);
    ui_->image_container->setPixmap(QPixmap::fromImage(image));
    counter += 1;
}
