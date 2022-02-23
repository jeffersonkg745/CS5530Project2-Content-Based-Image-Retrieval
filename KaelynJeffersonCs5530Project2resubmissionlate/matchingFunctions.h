
#ifndef MATCHING_FUNCTIONS
#define MATCHING_FUNCTIONS

int baselineOne(std::string target, std::string database, int numImages);
int histogramMatching(std::string target, std::string database, int numImages);
int multiHistogramMatching(std::string target, std::string target2, std::string database, int numImages);
int texture(std::string target, std::string target2, std::string database, int numImages);
int custom(std::string target, std::string target2, std::string database, int numImages);
int sobeltexture(std::string target, std::string database, int numImages, int xOry);

#endif /* MATCHING_FUNCTIONS */