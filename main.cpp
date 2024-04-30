#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

int countNumberOfRice1(cv::Mat input) {
    // Threshold image:
    cv::threshold(input, input, 128, 255, cv::THRESH_BINARY);
    // Remove noise in the binary imageusing  morphological  operations:
    cv::morphologyEx(input, input, cv::MORPH_OPEN, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5)));
    // Apply the connected components algorithm and return the number of classes:
    return cv::connectedComponents(input, input);
}

int main(int argc, char* argv[]){
    if(argc != 2){
        std::cout << "Usage: ./main <imageFile>" << std::endl;
        return -1;
    }
    
    cv::Mat src = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    cv::namedWindow("Input image",cv::WINDOW_FULLSCREEN);
    cv::imshow("Input image", src);
    cv::waitKey(1);
    
    // There are N-1 rice grains since one class is background
    std::cout << "Number of objects: ";
    std::cout << countNumberOfRice1(src) - 1;
    std::cout << std::endl; 
    
    return 0;
}
