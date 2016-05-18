#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
	cv::Mat img = cv::imread("../lena.jpg");
	
	//cv::namedWindow("image", CV_WINDOW_AUTOSIZE);

	cv::Mat dst;
	cv::Sobel(img, dst, CV_32F, 1, 1);

	cv::imwrite("../lena_sobel.png", dst);

	cv::VideoCapture input("../car.mp4");

	cv::VideoWriter output(
			"../car_sobel.avi",
			CV_FOURCC('X', 'V', 'I', 'D'),
			30,
			cv::Size(input.get(CV_CAP_PROP_FRAME_WIDTH),
							 input.get(CV_CAP_PROP_FRAME_HEIGHT)));

	for(;;)
	{
		if(!input.read(img))
			break;

		cv::Sobel(img, dst, CV_8U, 1, 1);
		
		output.write(dst);

		cv::imshow("video", img);
		char c = cv::waitKey(30);

		if(c == ' ')
			break;
	}
}
