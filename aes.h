#ifndef AES_H
#define AES_H

#include <stddef.h>
#include <stdint.h>

typedef enum {
    k_128 = 128,
    k_192 = 192,
    k_256 = 256,
} KeyType;

typedef struct {
    KeyType type;
    size_t bit_size;
    uint8_t* pValue;
} Key;

#endif // AES_H
