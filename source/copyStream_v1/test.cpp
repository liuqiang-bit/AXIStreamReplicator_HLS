#include "hls_opencv.h"
#include "copyStream.h"

int main(int argc, char** argv)
{

 	AXI_STREAM_24 src_axi;
 	AXI_STREAM_24 copy1;
 	AXI_STREAM_24 copy2;

	cv::Mat src = cv::imread("C:/Users/GUDONG/Desktop/copyStream/common/images/1.png");
	cv::Mat copy1_M(src.rows, src.cols, CV_8UC3), copy2_M(src.rows, src.cols, CV_8UC3);

	cvMat2AXIvideo(src, src_axi);

	copyStream(src_axi, copy1, copy2, src.rows, src.cols);

	AXIvideo2cvMat(copy1, copy1_M);
	AXIvideo2cvMat(copy2, copy2_M);
	cv::imwrite("C:/Users/GUDONG/Desktop/copyStream/common/OutputFile/O1.png", copy1_M);
	cv::imwrite("C:/Users/GUDONG/Desktop/copyStream/common/OutputFile/O2.png", copy2_M);

	std::cout << "done";

	return 0;
}
