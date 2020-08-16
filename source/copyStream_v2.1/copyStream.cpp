#include "copyStream.h"

void copyStream(AXI_STREAM_24& video_in, AXI_STREAM_24& video_out1, AXI_STREAM_24& video_out2)
{
#pragma HLS INTERFACE axis port=video_in
#pragma HLS STREAM variable=video_in depth=100 dim=1
#pragma HLS INTERFACE axis port=video_out1
#pragma HLS STREAM variable=video_out1 depth=100 dim=1
#pragma HLS INTERFACE axis port=video_out2
#pragma HLS STREAM variable=video_out2 depth=800 dim=1
#pragma HLS INTERFACE ap_ctrl_none port=return

	Pixel pix;
#pragma HLS PIPELINE
	video_in   >> pix;
	video_out1 << pix;
	video_out2 << pix;
}
