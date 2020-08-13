#ifndef _MTYPE_H_
#define _MTYPE_H_

#include "hls_video.h"
#include "ap_fixed.h"
#include "hls_stream.h"
#include "ap_axi_sdata.h"

typedef ap_axiu<24,1,1,1> Pixel;
typedef hls::stream<Pixel> AXI_STREAM_24;


#endif
