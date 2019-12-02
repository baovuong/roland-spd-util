#ifndef SPD_H
#define SPD_H

/**
 * @brief 
 * 
 */
typedef struct audio_data {
    int sample_rate;
    int has_metadata;
    int format;
} audio_data_t;

/**
 * @brief 
 * 
 * @param data 
 * @param path 
 * @return int 
 */
int read_audio_file(char* path, audio_data_t* data);

/**
 * @brief 
 * 
 * @param data 
 * @return int 
 */
int valid_spd(audio_data_t data);


int extract_format();

int extract_samplerate();

// int extract_metadata_count(AVFormatContext* context);

#endif