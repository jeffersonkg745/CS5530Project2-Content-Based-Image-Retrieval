#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <cstdio>
#include "readfiles.cpp"
#include "filtersFromA1.h"
#include "filtersFromA1.cpp"
#include "matchingFunctions.h"
#include "matchingFunctions.cpp"

using namespace cv;

int main(int argc, char *argv[])
{
    //comes in order of target, database, feature type, matching method, num of images
    std::string target = argv[1];
    std::string database = argv[2];
    std::string featureType = argv[3];
    std::string matchingMethod = argv[4];
    int numImages = atoi(argv[5]);

    if (matchingMethod == "baseline") //QUESTION 1
    {
        baselineOne(target, database, numImages);
    }
    else if (matchingMethod == "histogram") // QUESTION 2
    {
        histogramMatching(target, database, numImages);
    }
    else if (matchingMethod == "multihistogram") //QUESTION 3
    {
        std::string target2 = "pic.0274.jpg";
        multiHistogramMatching(target, target2, database, numImages);
    }
    else if (matchingMethod == "texture")
    {
        std::string targetTexture = "pic.0038.jpg";
        texture(target, targetTexture, database, numImages);
    }
    else if (matchingMethod == "xsobeltexture") //do this for extension maybe
    {
        int xOry = 0;
        sobeltexture(target, database, numImages, xOry);
    }
    else if (matchingMethod == "ysobeltexture") //do this for extension maybe
    {
        int xOry = 1;
        sobeltexture(target, database, numImages, xOry);
    }
    else if (matchingMethod == "custom")
    {
        //example used: first image = pic.0.0747; second image below = pic.0.0748
        std::string target2 = "pic.0748.jpg";
        custom(target, target2, database, numImages);
    }

    return 0;
}
