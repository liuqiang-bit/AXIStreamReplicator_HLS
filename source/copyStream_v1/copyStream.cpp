#include "copyStream.h"

void copyStream(AXI_STREAM_24& video_in, AXI_STREAM_24& video_out1, AXI_STREAM_24& video_out2, int ROW, int COL)
{
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE ap_stable port=COL
#pragma HLS INTERFACE s_axilite port=COL
#pragma HLS INTERFACE ap_stable port=ROW
#pragma HLS INTERFACE s_axilite port=ROW
#pragma HLS INTERFACE axis port=video_out2
#pragma HLS INTERFACE axis port=video_out1
#pragma HLS INTERFACE axis port=video_in
	static Pixel pix;

	streamCopy_label1:for(int i = 0; i < ROW; i++)
	{
#pragma HLS LOOP_TRIPCOUNT min=1 max=600
		streamCopy_label0:streamCopy_label2:for(int j = 0; j < COL; j++)
		{
#pragma HLS LOOP_TRIPCOUNT min=1 max=800
#pragma HLS PIPELINE
			video_in   >> pix;
			video_out1 << pix;
			video_out2 << pix;
		}
	}
}
