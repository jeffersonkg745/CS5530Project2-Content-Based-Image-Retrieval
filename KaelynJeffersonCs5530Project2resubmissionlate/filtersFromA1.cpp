#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/mat.hpp>
#include "filtersFromA1.h"
#include <iostream>

//taken from my Assignment 1
int sobelX3x3(cv::Mat &src, cv::Mat &dst)
{
    //sobel x should multiply [-1 0 1] by
    //[1
    // 2
    // 1]

    //create intermediate and dst objects with type CV_16SC3
    cv::Mat intermed;
    intermed.create(src.size(), CV_16SC3);
    dst.create(src.size(), CV_16SC3);

    //make our own initialized color channel
    //vec3s works for intermed and dst
    cv::Vec3s result = {0, 0, 0};

    //applying 3x1 filter
    for (int i = 1; i < src.rows - 1; i++)
    {
        for (int j = 1; j < src.cols - 1; j++)
        {
            for (int c = 0; c < 3; c++)
            {
                result[c] = src.at<cv::Vec3b>(i - 1, j - 1)[c] * -1 + src.at<cv::Vec3b>(i - 1, j)[c] * 0 + src.at<cv::Vec3b>(i - 1, j + 1)[c];
            }
            intermed.at<cv::Vec3s>(i, j) = result;
        }
    }

    //applying 1x3 filter
    for (int i = 1; i < intermed.rows - 1; i++)
    {
        for (int j = 1; j < intermed.cols - 1; j++)
        {
            for (int c = 0; c < 3; c++)
            {
                result[c] = intermed.at<cv::Vec3s>(i - 1, j - 1)[c] + intermed.at<cv::Vec3s>(i, j - 1)[c] * 2 + intermed.at<cv::Vec3s>(i + 1, j - 1)[c];
                result[c] /= 4;
            }
            dst.at<cv::Vec3s>(i, j) = result;
        }
    }
    return 0;
}

int sobelY3x3(cv::Mat &src, cv::Mat &dst)
{
    //sobel y should multiply [1 2 1] by
    //[1
    // 0
    //-1]

    cv::Mat intermed;
    intermed.create(src.size(), CV_16SC3);
    dst.create(src.size(), CV_16SC3);

    //make our own initialized color channel
    cv::Vec3s result = {0, 0, 0};

    //applying 3x1 filter
    for (int i = 1; i < src.rows - 1; i++)
    {
        for (int j = 1; j < src.cols - 1; j++)
        {
            for (int c = 0; c < 3; c++)
            {
                result[c] = src.at<cv::Vec3b>(i - 1, j - 1)[c] + src.at<cv::Vec3b>(i - 1, j)[c] * 2 + src.at<cv::Vec3b>(i - 1, j + 1)[c];

                result[c] /= 4;
            }
            intermed.at<cv::Vec3s>(i, j) = result;
        }
    }

    //applying 1x3 filter
    for (int i = 1; i < intermed.rows - 1; i++)
    {
        for (int j = 1; j < intermed.cols - 1; j++)
        {
            for (int c = 0; c < 3; c++)
            {
                result[c] = intermed.at<cv::Vec3s>(i - 1, j - 1)[c] + intermed.at<cv::Vec3s>(i, j - 1)[c] * 0 + intermed.at<cv::Vec3s>(i + 1, j - 1)[c] * -1;
            }
            dst.at<cv::Vec3s>(i, j) = result;
        }
    }
    return 0;
}

int magnitude(cv::Mat &sx, cv::Mat &sy, cv::Mat &dst)
{

    dst.create(sx.size(), sx.type());

    //sx and sy come in as vec3s
    cv::Vec3s result = {0, 0, 0};

    //only need to go through one image since sy should be the same
    for (int i = 0; i < sx.rows; i++)
    {
        for (int j = 0; j < sx.cols; j++)
        {
            //go pixel by pixel for x and y
            for (int c = 0; c < 3; c++)
            {
                //find the euclidian distance with formula to find the new pixel values
                result[c] = sqrt(pow(sx.at<cv::Vec3s>(i, j)[c], 2) + pow(sy.at<cv::Vec3s>(i, j)[c], 2));
            }
            dst.at<cv::Vec3s>(i, j) = result;
        }
    }

    return 0;
}
