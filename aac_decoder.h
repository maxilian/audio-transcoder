#ifndef AAC_DECODER_H
#define AAC_DECODER_H

#include <stdint.h>
#include "codec.h"

void *aac_decoder_create(uint8_t *adts,
                         uint32_t adts_size,
                         uint8_t *audio_config,
                         uint32_t config_size);

int aac_decoder_decode(void *decoder,
                       uint8_t *frame,
                       uint32_t size,
                       uint8_t *pcm);

void aac_decoder_destroy(void *decoder);

#endif