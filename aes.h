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
    uint8_t* pVal;
} Key;

#endif // AES_H
