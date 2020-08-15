#include "copyStream.h"

void copyStream(AXI_STREAM_24& video_in, AXI_STREAM_24& video_out1, AXI_STREAM_24& video_out2)
{
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis port=video_out2
#pragma HLS INTERFACE axis port=video_out1
#pragma HLS INTERFACE axis port=video_in
	static Pixel pix;
#pragma HLS PIPELINE
	video_in   >> pix;
	video_out1 << pix;
	video_out2 << pix;
}
