#ifndef SPD_H
#define SPD_H

/**
 * @brief 
 * 
 */
typedef struct audio_data {
    int sample_rate;
    int has_metadata;
    int bitrate;
} audio_data_t;

/**
 * @brief 
 * 
 * @param path 
 * @return audio_data 
 */
audio_data_t read_audio_file(char* path);

/**
 * @brief 
 * 
 * @param data 
 * @return int 
 */
int valid_spd(audio_data_t data);

#endif