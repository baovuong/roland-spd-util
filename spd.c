#include <stdio.h>
#include <stdlib.h>

#include <libavutil/opt.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswresample/swresample.h>

#include "spd.h"

int read_audio_file(char* path, audio_data_t* data) {

    av_register_all();
    avcodec_register_all();

    // get audio format from file 
    AVFormatContext* format = NULL;
    AVDictionaryEntry *tag = NULL;

    if (avformat_open_input(&format, path, NULL, NULL) != 0) {
        printf("mm bad\n");
        return -1;
    }

    if (avformat_find_stream_info(format, NULL) < 0) {
        printf("Could not retrieve stream info from file '%s'\n", path);
        return -1;
    }

    if (format->nb_streams <= 0) {
        printf("no stream to read\n");
        return -1;
    }

    AVStream *stream = format->streams[0];
    AVCodec *dec = avcodec_find_decoder(stream->codecpar->codec_id);
    AVCodecContext *codec_ctx;

    if (!dec) {
        printf("failed to find decoder for stream\n");
        return -1;
    }

    codec_ctx = avcodec_alloc_context3(dec);
    if (!codec_ctx) {
        printf("Failed to allocate the decoder context for stream\n");
        return -1;
    }
    data->sample_rate = stream->codecpar->sample_rate;
    data->format = stream->codecpar->format;
    data->has_metadata = av_dict_count(format->metadata) > 0;

    return 0;
}

int valid_spd(audio_data_t data) {
    return data.format == 1 && 
        data.sample_rate == 44100 &&
        !data.has_metadata;
}