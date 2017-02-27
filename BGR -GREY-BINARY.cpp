#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;
int main()
{
	Mat var1 = imread("logo.png",1);
	Mat var2(var1.rows, var1.cols, CV_8UC1, Scalar(0));
	Mat var3(var1.rows, var1.cols, CV_8UC1, Scalar(0));
	for (int i = 0; i < var1.rows; i++){
		for (int j = 0; j < var1.cols; j++)
		{
			var2.at<uchar>(i, j) = var1.at<Vec3b>(i, j)[0] + var1.at<Vec3b>(i, j)[1] + var1.at<Vec3b>(i, j)[2];
		}
	}
	for (int i = 0; i < var1.rows; i++){
		for (int j = 0; j < var1.cols; j++)
		{
			if (var2.at<uchar>(i, j) < 150)
				var3.at<uchar>(i, j) = 0;
			else
				var3.at<uchar>(i, j) = 255;
		}
	}
	namedWindow("windows1", 1);
	imshow("windows1", var1);
	namedWindow("windows2", 1);
	imshow("windows2", var2);
	namedWindow("windows3", 1);
	imshow("windows3", var3);
	waitKey(0);
	return(0);
}