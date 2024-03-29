#include <iostream>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/opencv.hpp>
#include <math.h>
using namespace std;
using namespace cv;
Mat rotate(Mat src, double angle)   //rotate function returning mat object with parametres imagefile and angle    
{
	Mat dst;      //Mat object for output image file
	Point2f pt(src.cols / 2., src.rows / 2.);          //point from where to rotate    
	Mat r = getRotationMatrix2D(pt, angle, 1.0);      //Mat object for storing after rotation
	warpAffine(src, dst, r, Size(src.cols, src.rows));  ///applie an affine transforation to image.
	return dst;         //returning Mat object for output image file
}
int main(int argc, char** argv)
{
	Mat image, gray_image, edges;
	image = imread("exp2.jpg");
	cvtColor(image, gray_image, CV_BGR2GRAY);
	Canny(gray_image, edges, 500, 100);
	vector<Vec4i>lines;
	HoughLinesP(edges, lines, 1, CV_PI / 180, 250, 200, 10);
	double max = 0;
	int place = 0, y, x;
	for (int i = 0; i < lines.size(); i++) {
		y = pow(lines[i][3] - lines[i][1], 2);
		x = pow(lines[i][2] - lines[i][0], 2);
		if (max < x + y) {
			max = x + y;
			place = i;
		}
	}
	double m = double(lines[place][3] - lines[place][1]) / double(lines[place][2] - lines[place][0]);
	if (m > 0)
		image = rotate(image, atan(m) * 180 / CV_PI - 90);
	else 
		image = rotate(image, 90 + atan(m) * 180 / CV_PI);
	namedWindow("answer", WINDOW_NORMAL);
	imshow("answer", image);
	waitKey();
	//imwrite(argv[2], image);
}