#ifndef FILTERS_FROM_A1_H
#define FILTERS_FROM_A1_H

int sobelX3x3(cv::Mat &src, cv::Mat &dst);
int sobelY3x3(cv::Mat &src, cv::Mat &dst);
int magnitude(cv::Mat &sx, cv::Mat &sy, cv::Mat &dst);

#endif /* FILTERS_FROM_A1_H */