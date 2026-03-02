#ifndef AAC_ENCODER_H
#define AAC_ENCODER_H

#include <stdint.h>
#include "codec.h"

void *aac_encoder_create(uint32_t sample_rate,
                         uint32_t channels,
                         int adts,
                         int aot);

int aac_encoder_encode(void *encoder,
                       uint8_t *pcm,
                       uint32_t pcm_size,
                       uint8_t *aac_buffer,
                       uint32_t aac_buffer_size);

void aac_encoder_destroy(void *encoder);

#endif