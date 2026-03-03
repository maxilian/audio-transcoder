#ifndef OPUS_DECODER_WRAPPER_H
#define OPUS_DECODER_WRAPPER_H

#include <stdint.h>   // uint8_t, int16_t, etc.
#include "codec.h"    // defines audio_codec_t
#include "opus.h"     // OpusDecoder, opus_decode, opus_strerror, OPUS_OK

#ifdef __cplusplus
extern "C" {
#endif

// Create Opus decoder wrapper. Returns audio_codec_t* or NULL on failure.
void *opus_decoder_create2(int sample_rate, int channels);

// Decode one Opus packet to PCM (16-bit). 
// Returns number of output bytes (samples * channels * 2), or 0 on error.
int opus_decoder_decode(void *dec,
                        const uint8_t *data,
                        int data_size,
                        uint8_t *pcm,
                        int frame_size);

// Destroy and free.
void opus_decoder_destroy2(void *dec);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // OPUS_DECODER_WRAPPER_H