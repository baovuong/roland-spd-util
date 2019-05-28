#include <stdio.h>
#include <stdlib.h>

#include <libavutil/opt.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswresample/swresample.h>

#include "spd.h"

audio_data_t read_audio_file(char* path) {

    av_register_all();


    // get audio format from file 
    AVFormatContext* format = avformat_alloc_context();

    if (avformat_open_input(&format, path, NULL, NULL) != 0) {
        printf("mm bad\n");
        return;
    }

    if (avformat_find_stream_info(format, NULL) < 0) {
        printf("Could not retrieve stream info from file '%s'\n", path);
        return;
    }


    audio_data_t out;

    out.bitrate = format->bit_rate;
    out.has_metadata = 0;
    out.sample_rate = 44100;

    return out; 
}

int valid_spd(audio_data_t data) {
    return data.bitrate == 16 && 
        data.sample_rate == 44100 &&
        !data.has_metadata;
}