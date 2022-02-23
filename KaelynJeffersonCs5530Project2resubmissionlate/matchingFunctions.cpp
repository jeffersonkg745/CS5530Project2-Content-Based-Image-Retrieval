
#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/mat.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <cstdio>

using namespace cv;

//gets the cv mat object of the image
cv::Mat getImage(std::string photo, std::string database)
{
    std::string photoPath = "/Users/kaelynjefferson/Documents/NEU/MSCS/MSCS semesters/2022 Spring/project2-cs5330/" +
                            database + "/" + photo;
    cv::Mat image = imread(photoPath, IMREAD_COLOR);
    return image;
}

//gets the image path manually
std::string getImagePath(std::string photo, int picNum)
{
    std::string secondImage;
    if (picNum < 10)
    {
        secondImage = "pic.000" + std::to_string(picNum) + ".jpg";
    }
    else if (picNum == 420)
    {
        secondImage = "pic.0021.jpg";
    }
    else if (picNum >= 10 && picNum < 100)
    {
        secondImage = "pic.00" + std::to_string(picNum) + ".jpg";
    }
    else if (picNum >= 100 && picNum < 1000)
    {
        secondImage = "pic.0" + std::to_string(picNum) + ".jpg";
    }
    else if (picNum >= 1000)
    {
        secondImage = "pic." + std::to_string(picNum) + ".jpg";
    }
    return secondImage;
}

//prints the top matches (used for baselineOne function)
int printTopMatches(std::string arrOfSumsTotal[][2], int numImages, std::string topNum)
{
    //sort the array by the total numbers
    std::string cl1[2] = {topNum, "0"};
    std::string cl2[2] = {topNum, "0"};
    std::string cl3[2] = {topNum, "0"};

    for (int z = 1; z < numImages; z++)
    {

        int currentNum;
        currentNum = stoi(arrOfSumsTotal[z][0]);
        if (currentNum == 0)
        {
            continue;
        }
        if (currentNum < stoi(cl1[0]))
        {
            //set 2nd to third
            cl3[0] = cl2[0];
            cl3[1] = cl2[1];
            //set first to second
            cl2[0] = cl1[0];
            cl2[1] = cl1[1];
            //set the new one equal to first place
            cl1[0] = arrOfSumsTotal[z][0];
            cl1[1] = arrOfSumsTotal[z][1];
        }
        else if (currentNum < stoi(cl2[0]))
        {
            //set 2nd to third
            cl3[0] = cl2[0];
            cl3[1] = cl2[1];
            //set the new one equal to first place
            cl2[0] = arrOfSumsTotal[z][0];
            cl2[1] = arrOfSumsTotal[z][1];
        }
        else if (currentNum < stoi(cl3[0]))
        {
            //set the new one equal to first place
            cl3[0] = arrOfSumsTotal[z][0];
            cl3[1] = arrOfSumsTotal[z][1];
        }
    }
    std::cout << "\nTop similar photos: " << std::endl;
    std::string s1 = "\nMost similar: " + cl1[1] + " has value of " + cl1[0];
    std::string s2 = "Second similar: " + cl2[1] + " has value of " + cl2[0];
    std::string s3 = "Third similar: " + cl3[1] + " has value of " + cl3[0] + "\n";
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    return 0;
}

//prints the top matches (used for comparing histograms)
int printTopMatchesHist(std::string arr[][2], int numImages, std::string topNum)
{

    //sort the array by the total numbers
    std::string cl1[2] = {topNum, "0"};
    std::string cl2[2] = {topNum, "0"};
    std::string cl3[2] = {topNum, "0"};
    std::string cl4[2] = {topNum, "0"};
    std::string cl5[2] = {topNum, "0"};
    std::string cl6[2] = {topNum, "0"};
    std::string cl7[2] = {topNum, "0"};
    std::string cl8[2] = {topNum, "0"};
    std::string cl9[2] = {topNum, "0"};
    std::string cl10[2] = {topNum, "0"};

    for (int z = 1; z < numImages; z++)
    {

        //std::cout << arr[z][0];
        //std::cout << z << std::endl;
        float currentNum;
        currentNum = stof(arr[z][0]);

        if (currentNum == 0)
        {
            continue;
        }
        //SETTING TO FIRST PLACE
        else if (currentNum < stof(cl1[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];
            //set 8 to 9th
            cl9[0] = cl8[0];
            cl9[1] = cl8[1];
            //set 7 to 8th
            cl8[0] = cl7[0];
            cl8[1] = cl7[1];
            //set 6 to 7th
            cl7[0] = cl6[0];
            cl7[1] = cl6[1];
            //set 5th to 6
            cl6[0] = cl5[0];
            cl6[1] = cl5[1];
            //set 3rd to fourth
            cl5[0] = cl4[0];
            cl5[1] = cl4[1];
            //set 3rd to fourth
            cl4[0] = cl3[0];
            cl4[1] = cl3[1];
            //set 2nd to third
            cl3[0] = cl2[0];
            cl3[1] = cl2[1];
            //set first to second
            cl2[0] = cl1[0];
            cl2[1] = cl1[1];
            //set the new one equal to first place
            cl1[0] = arr[z][0];
            cl1[1] = arr[z][1];
            continue;
        }
        //SETTING TO 2ND PLACE
        else if (currentNum < stof(cl2[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];
            //set 8 to 9th
            cl9[0] = cl8[0];
            cl9[1] = cl8[1];
            //set 7 to 8th
            cl8[0] = cl7[0];
            cl8[1] = cl7[1];
            //set 6 to 7th
            cl7[0] = cl6[0];
            cl7[1] = cl6[1];
            //set 5th to 6
            cl6[0] = cl5[0];
            cl6[1] = cl5[1];
            //set 4th to fifth
            cl5[0] = cl4[0];
            cl5[1] = cl4[1];
            //set 3rd to fourth
            cl4[0] = cl3[0];
            cl4[1] = cl3[1];
            //set 2nd to third
            cl3[0] = cl2[0];
            cl3[1] = cl2[1];
            //set the new one equal to second place
            cl2[0] = arr[z][0];
            cl2[1] = arr[z][1];
            continue;
        }
        //SETTING TO 3RD PLACE
        else if (currentNum < stof(cl3[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];
            //set 8 to 9th
            cl9[0] = cl8[0];
            cl9[1] = cl8[1];
            //set 7 to 8th
            cl8[0] = cl7[0];
            cl8[1] = cl7[1];
            //set 6 to 7th
            cl7[0] = cl6[0];
            cl7[1] = cl6[1];
            //set 5th to 6
            cl6[0] = cl5[0];
            cl6[1] = cl5[1];
            //set 4th to fifth
            cl5[0] = cl4[0];
            cl5[1] = cl4[1];
            //set 3rd to fourth
            cl4[0] = cl3[0];
            cl4[1] = cl3[1];

            //set the new one equal to third place
            cl3[0] = arr[z][0];
            cl3[1] = arr[z][1];
            continue;
        }

        //SETTING TO 4TH PLACE
        else if (currentNum < stof(cl4[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];
            //set 8 to 9th
            cl9[0] = cl8[0];
            cl9[1] = cl8[1];
            //set 7 to 8th
            cl8[0] = cl7[0];
            cl8[1] = cl7[1];
            //set 6 to 7th
            cl7[0] = cl6[0];
            cl7[1] = cl6[1];
            //set 5th to 6
            cl6[0] = cl5[0];
            cl6[1] = cl5[1];
            //set 4th to fifth
            cl5[0] = cl4[0];
            cl5[1] = cl4[1];
            //set the new one equal to third place
            cl4[0] = arr[z][0];
            cl4[1] = arr[z][1];
        }
        //SETTING TO 5TH PLACE
        else if (currentNum < stof(cl5[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];
            //set 8 to 9th
            cl9[0] = cl8[0];
            cl9[1] = cl8[1];
            //set 7 to 8th
            cl8[0] = cl7[0];
            cl8[1] = cl7[1];
            //set 6 to 7th
            cl7[0] = cl6[0];
            cl7[1] = cl6[1];
            //set 5th to 6
            cl6[0] = cl5[0];
            cl6[1] = cl5[1];
            //set the new one equal to third place
            cl5[0] = arr[z][0];
            cl5[1] = arr[z][1];
        }
        // SETTING TO 6TH PLACE
        else if (currentNum < stof(cl5[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];
            //set 8 to 9th
            cl9[0] = cl8[0];
            cl9[1] = cl8[1];
            //set 7 to 8th
            cl8[0] = cl7[0];
            cl8[1] = cl7[1];
            //set 6 to 7th
            cl7[0] = cl6[0];
            cl7[1] = cl6[1];
            //set the new one equal to third place
            cl6[0] = arr[z][0];
            cl6[1] = arr[z][1];
        }
        // SETTING TO 7TH PLACE
        else if (currentNum < stof(cl5[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];
            //set 8 to 9th
            cl9[0] = cl8[0];
            cl9[1] = cl8[1];
            //set 7 to 8th
            cl8[0] = cl7[0];
            cl8[1] = cl7[1];
            //set the new one equal to third place
            cl7[0] = arr[z][0];
            cl7[1] = arr[z][1];
        }
        // SETTING TO 8TH PLACE
        else if (currentNum < stof(cl5[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];
            //set 8 to 9th
            cl9[0] = cl8[0];
            cl9[1] = cl8[1];
            //set the new one equal to third place
            cl8[0] = arr[z][0];
            cl8[1] = arr[z][1];
        }
        // SETTING TO 9TH PLACE
        else if (currentNum < stof(cl5[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];

            //set the new one equal to third place
            cl9[0] = arr[z][0];
            cl9[1] = arr[z][1];
        }
        // SETTING TO 10TH PLACE
        else if (currentNum < stof(cl5[0]))
        {
            //set the new one equal to third place
            cl10[0] = arr[z][0];
            cl10[1] = arr[z][1];
        }
    }
    std::cout << "\nTop similar photos: " << std::endl;
    std::string s1 = "\nMost similar: " + cl1[1] + " has value of " + cl1[0];
    std::string s2 = "Second similar: " + cl2[1] + " has value of " + cl2[0];
    std::string s3 = "Third similar: " + cl3[1] + " has value of " + cl3[0];
    std::string s4 = "Fourth similar: " + cl4[1] + " has value of " + cl4[0];
    std::string s5 = "Fifth similar: " + cl5[1] + " has value of " + cl5[0] + "\n";
    std::string s6 = "Sixth similar: " + cl6[1] + " has value of " + cl6[0];
    std::string s7 = "Seventh similar: " + cl7[1] + " has value of " + cl7[0];
    std::string s8 = "Eighth similar: " + cl8[1] + " has value of " + cl8[0];
    std::string s9 = "Ninth similar: " + cl9[1] + " has value of " + cl9[0];
    std::string s10 = "Tenth similar: " + cl10[1] + " has value of " + cl10[0] + "\n";

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;
    std::cout << s5 << std::endl;
    std::cout << s6 << std::endl;
    std::cout << s7 << std::endl;
    std::cout << s8 << std::endl;
    std::cout << s9 << std::endl;
    std::cout << s10 << std::endl;
    return 0;
}

//PROBLEM 1: BASELINE
int baselineOne(std::string target, std::string database, int numImages)
{
    cv::Mat targetImage = getImage(target, database);
    cv::Mat currentImage;
    std::string arrOfSumsTotal[numImages][2];

    for (int p = 1; p < numImages; p++)
    {

        std::string secondImage;
        int picNum = 0 + p;
        secondImage = getImagePath(secondImage, picNum);
        currentImage = getImage(secondImage, database);
        int sumSquaredDiff = 0;

        //loop over every pixel in the image and convert each RGB to an index
        for (int i = 252; i < 261; i++)
        {
            for (int j = 316; j < 325; j++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int diff = currentImage.at<cv::Vec3b>(i, j)[c] - targetImage.at<cv::Vec3b>(i, j)[c];
                    sumSquaredDiff = sumSquaredDiff + (diff * diff);
                }
            }
        }
        sumSquaredDiff /= 81;

        //put the answer into an array
        std::string arrOfSums[2] = {};
        arrOfSums[0] = std::to_string(sumSquaredDiff);
        arrOfSums[1] = secondImage;
        arrOfSumsTotal[p][0] = arrOfSums[0];
        arrOfSumsTotal[p][1] = arrOfSums[1];
    }

    printTopMatches(arrOfSumsTotal, numImages, "100000");
    return 0;
}

//PROBLEM 2: HISTOGRAM MATCHING
int histogramMatching(std::string target, std::string database, int numImages)
{
    cv::Mat targetImage = getImage(target, database);
    cv::Mat currentImage;
    std::string arrOfHistImages[numImages][2];

    for (int p = 1; p < numImages; p++)
    {
        std::string secondImage;
        int picNum = p;
        secondImage = getImagePath(secondImage, picNum);
        currentImage = getImage(secondImage, database);

        //make an empty 3d RGB histogram
        cv::Mat hist3d;
        const int Hsize = 32;
        int dim3[3] = {Hsize, Hsize, Hsize};
        hist3d = cv::Mat::zeros(3, dim3, CV_32F);

        //for the compared image
        cv::Mat hist3dComp;
        int dim3c[3] = {Hsize, Hsize, Hsize};
        hist3dComp = cv::Mat::zeros(3, dim3c, CV_32F);

        //loop over every pixel in the image and convert each RGB to an index
        cv::Vec3i targetImagePix = {0, 0, 0};
        cv::Vec3i comparedImage = {0, 0, 0};

        for (int i = 0; i < currentImage.rows; i++)
        {
            for (int j = 0; j < currentImage.cols; j++)
            {
                for (int c = 0; c < 3; c++)
                {
                    //get each pixel for target image
                    //get each pixel for the compared image
                    targetImagePix[c] = targetImage.at<cv::Vec3b>(i, j)[c];
                    comparedImage[c] = currentImage.at<cv::Vec3b>(i, j)[c];

                    //divide all by 29 so we only get values from 0 to 9
                    targetImagePix[c] /= 32;
                    comparedImage[c] /= 32;
                }

                //once out of the loop, increment BOTH histograms (target, and compared)
                hist3dComp.at<float>(comparedImage[0], comparedImage[1], comparedImage[2])++;

                //increment the indexes for r, g, b in the histogram
                hist3d.at<float>(targetImagePix[0], targetImagePix[1], targetImagePix[2])++;
            }
        }
        //once we have the histograms, take the minimum values of each spot and add up for each of
        //the 81 values / 327680 to get a value closer/not close to one
        float totalCompared = 0;
        float totalTarget = 0;
        for (int l = 0; l < 10; l++)
        {
            for (int m = 0; m < 10; m++)
            {
                for (int n = 0; n < 10; n++)
                {
                    totalCompared += std::min(hist3dComp.at<float>(l, m, n), hist3d.at<float>(l, m, n)) / 327680;
                    totalTarget += hist3d.at<float>(l, m, n) / 327680;
                }
            }
        }

        //make an array of values to keep track of distance metrics
        float diffBwImages = totalTarget - totalCompared;
        arrOfHistImages[p][0] = std::to_string(diffBwImages);
        arrOfHistImages[p][1] = secondImage;
    }
    printTopMatchesHist(arrOfHistImages, numImages, "1");
    return 0;
}

//PROBLEM 3: MULTIHISTOGRAM MATCHING
int multiHistogramMatching(std::string target, std::string target2, std::string database, int numImages)
{
    cv::Mat targetImage = getImage(target, database);
    cv::Mat currentImage;
    std::string arrOfHistImages[numImages][2];

    for (int p = 1; p < numImages; p++)
    {
        int picNum = p;
        std::string secondImage;
        secondImage = getImagePath(secondImage, picNum);
        currentImage = getImage(secondImage, database);

        //make 4 histograms here: top and bottom for both target and current images
        cv::Mat targetTopHist;
        const int Hsize = 32;
        int dimtt[3] = {Hsize, Hsize, Hsize};
        targetTopHist = cv::Mat::zeros(3, dimtt, CV_32F);

        cv::Mat targetBottomHist;
        int dimtb[3] = {Hsize, Hsize, Hsize};
        targetBottomHist = cv::Mat::zeros(3, dimtb, CV_32F);

        cv::Mat currentTopHist;
        int dimct[3] = {Hsize, Hsize, Hsize};
        currentTopHist = cv::Mat::zeros(3, dimct, CV_32F);

        cv::Mat currentBottomHist;
        int dimcb[3] = {Hsize, Hsize, Hsize};
        currentBottomHist = cv::Mat::zeros(3, dimcb, CV_32F);

        //loop over every pixel in the image and convert each RGB to an index
        cv::Vec3i targetImagePix = {0, 0, 0};
        cv::Vec3i currentImagePix = {0, 0, 0};

        for (int i = 0; i < currentImage.rows; i++)
        {
            for (int j = 0; j < currentImage.cols; j++)
            {
                for (int c = 0; c < 3; c++)
                {
                    targetImagePix[c] = targetImage.at<cv::Vec3b>(i, j)[c];
                    currentImagePix[c] = currentImage.at<cv::Vec3b>(i, j)[c];

                    //divide all by 29 so we only get values from 0 to 9
                    targetImagePix[c] /= 32;
                    currentImagePix[c] /= 32;
                }

                //if the pixel is in the top half, add respective pixels to the histograms for top half
                if (i < 256)
                {
                    currentTopHist.at<float>(currentImagePix[0], currentImagePix[1], currentImagePix[2])++;
                    targetTopHist.at<float>(targetImagePix[0], targetImagePix[1], targetImagePix[2])++;
                }
                else if (i >= 256)
                {
                    currentBottomHist.at<float>(currentImagePix[0], currentImagePix[1], currentImagePix[2])++;
                    targetBottomHist.at<float>(targetImagePix[0], targetImagePix[1], targetImagePix[2])++;
                }
            }
        }

        float totalTargetTop = 0;
        float totalTargetBottom = 0;
        float totalCurrentTop = 0;
        float totalCurrentBottom = 0;

        for (int l = 0; l < 10; l++)
        {
            for (int m = 0; m < 10; m++)
            {
                for (int n = 0; n < 10; n++)
                {
                    totalCurrentTop += std::min(targetTopHist.at<float>(l, m, n), currentTopHist.at<float>(l, m, n)) / 327680;
                    totalTargetTop += targetTopHist.at<float>(l, m, n) / 327680;

                    totalCurrentBottom += std::min(targetBottomHist.at<float>(l, m, n), currentBottomHist.at<float>(l, m, n)) / 327680;
                    totalTargetBottom += targetBottomHist.at<float>(l, m, n) / 327680;
                }
            }
        }

        //get the difference between the currentTop and targetTop
        float topDiff = totalTargetTop - totalCurrentTop;

        //get the difference between the currentBottom and targetBottom
        float botDiff = totalTargetBottom - totalCurrentBottom;

        //get the final distance between the images
        float diffBwImages = topDiff * 0.5 + botDiff * 0.5;

        arrOfHistImages[p][0] = std::to_string(diffBwImages); //+ diffBwImages2);
        arrOfHistImages[p][1] = secondImage;
    }
    printTopMatchesHist(arrOfHistImages, numImages, "1");
    return 0;
}

//PROBLEM 4: TEXTURE AND COLOR MATCHING
int texture(std::string target, std::string target2, std::string database, int numImages)
{
    cv::Mat targetImage = getImage(target, database);
    cv::Mat currentImage;

    //get the magnitude version of that image
    cv::Mat targetImageFilterX;
    cv::Mat targetImageFilterY;
    cv::Mat targetImageFilterNoAbs;
    cv::Mat targetImageFilter;
    sobelX3x3(targetImage, targetImageFilterX);
    sobelY3x3(targetImage, targetImageFilterY);
    magnitude(targetImageFilterX, targetImageFilterY, targetImageFilterNoAbs);
    cv::convertScaleAbs(targetImageFilterNoAbs, targetImageFilter);
    std::string arrOfHistImages[numImages][2];

    for (int p = 1; p < numImages; p++)
    {
        std::string secondImage;
        int picNum = p;
        secondImage = getImagePath(secondImage, picNum);
        currentImage = getImage(secondImage, database);

        //get the magnitude version of the current image
        cv::Mat currentImageFilterX;
        cv::Mat currentImageFilterY;
        cv::Mat currentImageFilterNoAbs;
        cv::Mat currentImageFilter;
        sobelX3x3(currentImage, currentImageFilterX);
        sobelY3x3(currentImage, currentImageFilterY);
        magnitude(currentImageFilterX, currentImageFilterY, currentImageFilterNoAbs);
        cv::convertScaleAbs(currentImageFilterNoAbs, currentImageFilter);

        //make color and texture histograms for the targetimage1 and currentImage
        cv::Mat targetColorHist;
        const int Hsize = 32;
        int dimtt[3] = {Hsize, Hsize, Hsize};
        targetColorHist = cv::Mat::zeros(3, dimtt, CV_32F);

        cv::Mat targetTextureHist;
        int dimtb[3] = {Hsize, Hsize, Hsize};
        targetTextureHist = cv::Mat::zeros(3, dimtb, CV_32F);

        cv::Mat currentColorHist;
        int dimct[3] = {Hsize, Hsize, Hsize};
        currentColorHist = cv::Mat::zeros(3, dimct, CV_32F);

        cv::Mat currentTextureHist;
        int dimcb[3] = {Hsize, Hsize, Hsize};
        currentTextureHist = cv::Mat::zeros(3, dimcb, CV_32F);

        cv::Vec3i targetColorPix = {0, 0, 0};
        cv::Vec3i targetTextPix = {0, 0, 0};
        cv::Vec3i currentColorPix = {0, 0, 0};
        cv::Vec3i currentTextPix = {0, 0, 0};

        for (int i = 0; i < currentImage.rows; i++)
        {
            for (int j = 0; j < currentImage.cols; j++)
            {
                for (int c = 0; c < 3; c++)
                {

                    targetColorPix[c] = targetImage.at<cv::Vec3b>(i, j)[c];
                    targetTextPix[c] = targetImageFilter.at<cv::Vec3b>(i, j)[c];
                    currentColorPix[c] = currentImage.at<cv::Vec3b>(i, j)[c];
                    currentTextPix[c] = currentImageFilter.at<cv::Vec3b>(i, j)[c];

                    targetColorPix[c] /= 32;
                    targetTextPix[c] /= 32;
                    currentColorPix[c] /= 32;
                    currentTextPix[c] /= 32;
                }

                currentColorHist.at<float>(currentColorPix[0], currentColorPix[1], currentColorPix[2])++;
                currentTextureHist.at<float>(currentTextPix[0], currentTextPix[1], currentTextPix[2])++;
                targetColorHist.at<float>(targetColorPix[0], targetColorPix[1], targetColorPix[2])++;
                targetTextureHist.at<float>(targetTextPix[0], targetTextPix[1], targetTextPix[2])++;
            }
        }

        float totalTargetColor = 0;
        float totalTargetText = 0;
        float totalCurrentColor = 0;
        float totalCurrentText = 0;

        for (int l = 0; l < 10; l++)
        {
            for (int m = 0; m < 10; m++)
            {
                for (int n = 0; n < 10; n++)
                {
                    totalCurrentColor += std::min(targetColorHist.at<float>(l, m, n), currentColorHist.at<float>(l, m, n)) / 327680;
                    totalTargetColor += targetColorHist.at<float>(l, m, n) / 327680;

                    totalCurrentText += std::min(targetTextureHist.at<float>(l, m, n), currentTextureHist.at<float>(l, m, n)) / 327680;
                    totalTargetText += targetTextureHist.at<float>(l, m, n) / 327680;
                }
            }
        }

        float diffColor = totalTargetColor - totalCurrentColor;
        float diffTexture = totalTargetText - totalCurrentText;

        float totalDiff = diffColor * 0.5 + diffTexture * 0.5;

        arrOfHistImages[p][0] = std::to_string(totalDiff);
        arrOfHistImages[p][1] = secondImage;
    }
    printTopMatchesHist(arrOfHistImages, numImages, "1");
    return 0;
}

//PROBLEM 5: CUSTOM- MATCHING GREEN TRASHCANS
int custom(std::string target, std::string target2, std::string database, int numImages)
{
    //first green trashcan
    cv::Mat targetImage = getImage(target, database);
    cv::Mat currentImage;
    //second green trashcan
    cv::Mat targetImage2 = getImage(target2, database);
    std::string arrOfHistImages[numImages][2];

    for (int p = 1; p < numImages; p++)
    {
        std::string secondImage;
        int picNum = p;
        secondImage = getImagePath(secondImage, picNum);
        currentImage = getImage(secondImage, database);

        //make histograms for first target image, second target image, and current image
        cv::Mat firstGreenTrashHist;
        const int Hsize = 32;
        int dim3[3] = {Hsize, Hsize, Hsize};
        firstGreenTrashHist = cv::Mat::zeros(3, dim3, CV_32F);

        cv::Mat secondGreenTrashHist;
        int dim32[3] = {Hsize, Hsize, Hsize};
        secondGreenTrashHist = cv::Mat::zeros(3, dim32, CV_32F);

        cv::Mat currentImageHist;
        int dim3c[3] = {Hsize, Hsize, Hsize};
        currentImageHist = cv::Mat::zeros(3, dim3c, CV_32F);

        //loop over every pixel in the image and convert each RGB to an index
        cv::Vec3i targetImagePix = {0, 0, 0};
        cv::Vec3i targetImagePix2 = {0, 0, 0};
        cv::Vec3i currentImagePix = {0, 0, 0};

        //the trashcans are generally in the bottom 2/3 of the photo so only compare pixels from there
        for (int i = 170; i < currentImage.rows; i++)
        {
            for (int j = 0; j < currentImage.cols; j++)
            {
                for (int c = 0; c < 3; c++)
                {
                    targetImagePix[c] = targetImage.at<cv::Vec3b>(i, j)[c];
                    targetImagePix2[c] = targetImage2.at<cv::Vec3b>(i, j)[c];
                    currentImagePix[c] = currentImage.at<cv::Vec3b>(i, j)[c];

                    //divide all by 29 so we only get values from 0 to 9
                    targetImagePix[c] /= 32;
                    currentImagePix[c] /= 32;
                    targetImagePix2[c] /= 32;
                }

                currentImageHist.at<float>(currentImagePix[0], currentImagePix[1], currentImagePix[2])++;
                firstGreenTrashHist.at<float>(targetImagePix[0], targetImagePix[1], targetImagePix[2])++;
                secondGreenTrashHist.at<float>(targetImagePix2[0], targetImagePix2[1], targetImagePix2[2])++;
            }
        }

        float totalCurrentFirstGreen = 0;
        float totalTargetFirstGreen = 0;
        float totalCurrentSecondGreen = 0;
        float totalTargetSecondGreen = 0;
        for (int l = 0; l < 10; l++)
        {
            for (int m = 0; m < 10; m++)
            {
                for (int n = 0; n < 10; n++)
                {
                    //total pixels here = 342 (bottom 2/3 rows of photo) * 640 = 218880
                    totalCurrentFirstGreen += std::min(currentImageHist.at<float>(l, m, n), firstGreenTrashHist.at<float>(l, m, n)) / 218880;
                    totalTargetFirstGreen += firstGreenTrashHist.at<float>(l, m, n) / 218880;
                    totalCurrentSecondGreen += std::min(currentImageHist.at<float>(l, m, n), secondGreenTrashHist.at<float>(l, m, n)) / 218880;
                    totalTargetSecondGreen += secondGreenTrashHist.at<float>(l, m, n) / 218880;
                }
            }
        }

        float diffFirstGreen = totalTargetFirstGreen - totalCurrentFirstGreen;
        float diffSecondGreen = totalTargetSecondGreen - totalCurrentSecondGreen;

        float finalDiff = diffFirstGreen * 0.5 + diffSecondGreen * 0.5;

        arrOfHistImages[p][0] = std::to_string(finalDiff);
        arrOfHistImages[p][1] = secondImage;
    }
    printTopMatchesHist(arrOfHistImages, numImages, "1");
    return 0;
}

//EXTENSIONS
int sobeltexture(std::string target, std::string database, int numImages, int xOry)
{
    cv::Mat targetImage = getImage(target, database);
    cv::Mat currentImage;

    cv::Mat targetImageFilterX;
    cv::Mat targetImageFilter;

    if (xOry == 0)
    {
        sobelX3x3(targetImage, targetImageFilterX);
    }
    else if (xOry == 1)
    {
        sobelY3x3(targetImage, targetImageFilterX);
    }
    cv::convertScaleAbs(targetImageFilterX, targetImageFilter);
    std::string arrOfHistImages[numImages][2];

    for (int p = 1; p < numImages; p++)
    {
        std::string secondImage;
        int picNum = p;
        secondImage = getImagePath(secondImage, picNum);
        currentImage = getImage(secondImage, database);
        cv::Mat secondImageFilterX;
        cv::Mat secondImageFilter;
        if (xOry == 0)
        {
            sobelX3x3(currentImage, secondImageFilterX);
        }
        else if (xOry == 1)
        {
            sobelY3x3(currentImage, secondImageFilterX);
        }
        cv::convertScaleAbs(secondImageFilterX, secondImageFilter);

        //make an empty 3d RGB histogram
        cv::Mat hist3d;
        const int Hsize = 32;
        int dim3[3] = {Hsize, Hsize, Hsize};
        hist3d = cv::Mat::zeros(3, dim3, CV_32F);

        //for the compared image
        cv::Mat hist3dComp;
        int dim3Comp[3] = {Hsize, Hsize, Hsize};
        hist3dComp = cv::Mat::zeros(3, dim3Comp, CV_32F);

        //loop over every pixel in the image and convert each RGB to an index
        cv::Vec3i targetImagePix = {0, 0, 0};
        //cv::Vec3i targetImagePix2 = {0, 0, 0};
        cv::Vec3i comparedImage = {0, 0, 0};

        for (int i = 0; i < currentImage.rows; i++)
        {
            for (int j = 0; j < currentImage.cols; j++)
            {
                for (int c = 0; c < 3; c++)
                {
                    //get each pixel for target image
                    //get each pixel for the compared image
                    targetImagePix[c] = targetImage.at<cv::Vec3b>(i, j)[c];
                    comparedImage[c] = currentImage.at<cv::Vec3b>(i, j)[c];
                    //targetImagePix2[c] = targetImage2Filter.at<cv::Vec3b>(i, j)[c];

                    //divide all by 29 so we only get values from 0 to 9
                    targetImagePix[c] /= 29;
                    comparedImage[c] /= 29;
                    //targetImagePix2[c] /= 29;
                }

                //once out of the loop, increment BOTH histograms (target, and compared)
                hist3dComp.at<float>(comparedImage[0], comparedImage[1], comparedImage[2])++;

                //increment the indexes for r, g, b in the histogram
                hist3d.at<float>(targetImagePix[0], targetImagePix[1], targetImagePix[2])++;

                //increment the indexes for r, g, b in the histogram
                //hist3d2.at<float>(targetImagePix2[0], targetImagePix2[1], targetImagePix2[2])++;
            }
        }

        //once we have the histograms, take the minimum values of each spot and add up for each of
        //the 81 values / 327680 to get a value closer/not close to one
        float totalCompared = 0;
        float totalTarget = 0;
        float totalCompared2 = 0;
        float totalTarget2 = 0;
        for (int l = 0; l < 10; l++)
        {
            for (int m = 0; m < 10; m++)
            {
                for (int n = 0; n < 10; n++)
                {

                    totalCompared += std::min(hist3dComp.at<float>(l, m, n), hist3d.at<float>(l, m, n)) / 327680;
                    totalTarget += hist3d.at<float>(l, m, n) / 327680;
                }
            }
        }
        //make an array of values to keep track of distance metrics AND weight them
        float diffBwImages = (totalTarget - totalCompared) * 0.5;
        //float diffBwImages2 = (totalTarget2 - totalCompared2) * 0.5;

        arrOfHistImages[p][0] = std::to_string(diffBwImages); //+ diffBwImages2);
        arrOfHistImages[p][1] = secondImage;
    }
    printTopMatchesHist(arrOfHistImages, numImages, "1");
    return 0;
}
