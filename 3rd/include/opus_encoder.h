#ifndef OPUS_ENCODER_WRAPPER_H
#define OPUS_ENCODER_WRAPPER_H

#include <stdint.h>   // uint8_t, etc.
#include "codec.h"    // your audio_codec_t or shared types (if needed later)
#include "opus.h"     // OpusEncoder, opus_encode, OPUS_* macros, opus_strerror

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create and initialize an Opus encoder.
 *
 * @param sample_rate  Sampling rate in Hz (e.g., 48000).
 * @param channels     Number of channels (1=mono, 2=stereo).
 * @param application  OPUS_APPLICATION_VOIP / OPUS_APPLICATION_AUDIO / OPUS_APPLICATION_RESTRICTED_LOWDELAY.
 * @return             Pointer to OpusEncoder on success, NULL on failure.
 */
OpusEncoder *opus_encoder_create2(int sample_rate, int channels, int application);

/**
 * Encode 16-bit PCM to Opus.
 *
 * @param enc         OpusEncoder* created by opus_encoder_create2.
 * @param pcm         Pointer to interleaved 16-bit PCM samples (little-endian).
 * @param frame_size  Number of samples per channel in this frame (e.g., 960 for 20 ms @ 48 kHz).
 * @param data        Output buffer for encoded packet.
 * @param data_size   Size (bytes) of the output buffer.
 * @return            Number of bytes written to 'data' (>0) on success, 0 on error.
 */
int opus_encoder_encode(OpusEncoder *enc,
                        uint8_t *pcm,
                        int frame_size,
                        uint8_t *data,
                        int data_size);

/**
 * Destroy an Opus encoder created by opus_encoder_create2.
 *
 * @param enc  OpusEncoder* to destroy (safe to pass NULL).
 */
void opus_encoder_destroy2(OpusEncoder *enc);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // OPUS_ENCODER_WRAPPER_H