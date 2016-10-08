#include <opencv2/opencv.hpp> // how we import opencv2
#include <iostream> // strings
#include <string>

using namespace cv;


int main()
{

std::string fileLocation = "320px-Flag_of_Japansvg.png";

//std: string fileLocation = argv[1];

Mat img = imread(fileLocation);

cv::Mat img_HSV;
cv::cvtColor(img,img_HSV,CV_BGR2HSV); //converting from rgb to hsv


std::vector<cv::Mat> channels;
cv:split(img_HSV,channels);

cv::Mat hueOrig = channels.at(0).clone();
cv::Mat threshLower,threshHigher,result;

cv::threshold(hueOrig,threshLower,60,255, CV_THRESH_BINARY);
cv::threshold(hueOrig,threshHigher,180,255,CV_THRESH_BINARY_INV);
result = threshLower & threshHigher;

//std::vector<cv::Mat> channels;



Mat edge;
Canny(img_HSV,edge,100,200);
vector<vector<Point>> contourvector;   //vector inside a vector

findContours(edge,countourvector,CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE, Point(0,0));

Mat alreadyContoured = Mat::zeros(img.rows,img.cols,CV_8UC3); //not sure if it's supposed to be rows and cols?


drawContours("Contours",alreadyContoured,-1,color);
imshow("Contours", alreadyCotoured);
imshow("Thesholded",result);
//cv:: imshow("Thresholded",result);
//cv::imshow("Hue",channels.at(0));
//cv::imshow("Saturation",channels.at(1));
//cv::imshow("Value",channels.at(2));
//imshow("Here is an amazing picture", img);

waitKey(0);







}
