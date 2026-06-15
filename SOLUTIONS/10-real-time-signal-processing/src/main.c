#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define DURATION 2

void write_wav(const char* filename, int16_t* data, int num_samples) {
    FILE *f = fopen(filename, "wb");
    if (!f) return;
    
    uint32_t byte_rate = SAMPLE_RATE * 2;
    uint32_t data_chunk_size = num_samples * 2;
    uint32_t chunk_size = 36 + data_chunk_size;
    
    fwrite("RIFF", 1, 4, f);
    fwrite(&chunk_size, 4, 1, f);
    fwrite("WAVE", 1, 4, f);
    fwrite("fmt ", 1, 4, f);
    
    uint32_t subchunk1_size = 16;
    uint16_t audio_format = 1;
    uint16_t num_channels = 1;
    uint32_t sample_rate = SAMPLE_RATE;
    uint16_t block_align = 2;
    uint16_t bits_per_sample = 16;
    
    fwrite(&subchunk1_size, 4, 1, f);
    fwrite(&audio_format, 2, 1, f);
    fwrite(&num_channels, 2, 1, f);
    fwrite(&sample_rate, 4, 1, f);
    fwrite(&byte_rate, 4, 1, f);
    fwrite(&block_align, 2, 1, f);
    fwrite(&bits_per_sample, 2, 1, f);
    
    fwrite("data", 1, 4, f);
    fwrite(&data_chunk_size, 4, 1, f);
    fwrite(data, 2, num_samples, f);
    
    fclose(f);
}

int main(void) {
    printf("Real-Time Signal Processing Demo\n");
    int num_samples = SAMPLE_RATE * DURATION;
    int16_t *buffer = (int16_t *)malloc(num_samples * sizeof(int16_t));
    
    double frequency = 440.0; // A4
    for (int i = 0; i < num_samples; i++) {
        double t = (double)i / SAMPLE_RATE;
        buffer[i] = (int16_t)(32767.0 * sin(2.0 * M_PI * frequency * t));
    }
    
    write_wav("out.wav", buffer, num_samples);
    printf("Generated sine wave at %g Hz to out.wav\n", frequency);
    
    free(buffer);
    return 0;
}
