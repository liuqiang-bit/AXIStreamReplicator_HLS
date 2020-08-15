#include "hls_opencv.h"
#include "copyStream.h"

int main(int argc, char** argv)
{

 	AXI_STREAM_24 src_axi;
 	AXI_STREAM_24 copy1;
 	AXI_STREAM_24 copy2;

	cv::Mat src = cv::imread("C:/Users/GUDONG/Desktop/copyStream/common/images/1.png");
	cv::Mat copy1_M(src.rows, src.cols, CV_8UC3), copy2_M(src.rows, src.cols, CV_8UC3);

	ap_uint<24> srcPixVal, cpy1PixVal, cpy2PixVal;
	ap_axiu<24,1,1,1> srcPixAXIVal, cpy1PixAXIVal, cpy2PixAXIVal;

	for(int i = 0; i < src.rows; i++)
	{
		for(int j = 0; j < src.cols; j++)
		{
			srcPixVal.range(7,0) = src.at<cv::Vec3b>(i,j)[0];
			srcPixVal.range(15,8) = src.at<cv::Vec3b>(i,j)[1];
			srcPixVal.range(23,16) = src.at<cv::Vec3b>(i,j)[2];
			srcPixAXIVal.data = srcPixVal;
			src_axi << srcPixAXIVal;

			copyStream(src_axi, copy1, copy2);

			copy1 >> cpy1PixAXIVal;
			copy2 >> cpy2PixAXIVal;

			cpy1PixVal = cpy1PixAXIVal.data;
			cpy2PixVal = cpy2PixAXIVal.data;

			copy1_M.at<cv::Vec3b>(i,j)[0] = cpy1PixVal.range(7,0);
			copy1_M.at<cv::Vec3b>(i,j)[1] = cpy1PixVal.range(15,8);
			copy1_M.at<cv::Vec3b>(i,j)[2] = cpy1PixVal.range(23,16);

			copy2_M.at<cv::Vec3b>(i,j)[0] = cpy2PixVal.range(7,0);
			copy2_M.at<cv::Vec3b>(i,j)[1] = cpy2PixVal.range(15,8);
			copy2_M.at<cv::Vec3b>(i,j)[2] = cpy2PixVal.range(23,16);
		}
	}
	cv::imwrite("C:/Users/GUDONG/Desktop/copyStream/common/OutputFile/O1.png", copy1_M);
	cv::imwrite("C:/Users/GUDONG/Desktop/copyStream/common/OutputFile/O2.png", copy2_M);

	std::cout << "done";

	return 0;
}
