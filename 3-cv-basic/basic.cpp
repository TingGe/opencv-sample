#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
	cv::Mat img = cv::imread("../lena.jpg");

	cv::Mat img_processed;
	cv::resize(img, img_processed, cv::Size(img.cols / 2, img.rows / 2));

	cv::Mat R = cv::getRotationMatrix2D(cv::Point2f(img.cols / 2, img.rows / 2), 45, 1); 

	cv::warpAffine(img, img_processed, R, img.size());
	
	cv::Canny(img, img_processed, 200, 300);

	for(int i = 1; i < 20; i+=2)
	{
		cv:: Mat img_blurred;
		cv::blur(img, img_blurred, cv::Size(i, i));

		cv::Canny(img_blurred, img_processed, 100, 150);

		cv::imshow("img", img);
		cv::imshow("img_processed", img_processed);
		cv::imshow("img_blurred", img_blurred);
		cv::waitKey();
	}
	
}
