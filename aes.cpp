#include <cstdint>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "aes.h"

const uint8_t SBOX_AFFINE[8][8] =
{
    {1,0,0,0,1,1,1,1},
    {1,1,0,0,0,1,1,1},
    {1,1,1,0,0,0,1,1},
    {1,1,1,1,0,0,0,1},
    {1,1,1,1,1,0,0,0},
    {0,1,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,0},
    {0,0,0,1,1,1,1,1},
};

const uint8_t SBOX_AFFINE_CONSTV[8] =
{
    0,1,1,0,0,0,1,1
};











void decimalBinary(uint8_t in[16], uint8_t out[16 * 8])
{
    for (int i = 0; i < 16; i++) {
        for (int bit = 0; bit < 8; bit++) {
            out[i * 8 + bit] = (in[i] >> (7 - bit)) & 1;
        }
    }
}

Key initKey(KeyType type, uint8_t* pDecValue)
{
    Key k;
    k.type = type;
    k.pVal = new uint8_t[type];

    decimalBinary(pDecValue, k.pVal);

    return k;
}

int terminateKey(Key pKey)
{
    // delete[] pKey.pVal;
    // pKey.pVal = nullptr;
    return 0;
}

int main()
{
    uint8_t input[16] =
    {
        12, 243, 87, 154,
        201, 33, 99, 176,
        45, 172, 29, 134,
        208, 91, 3, 160,
    };

    Key key = initKey(k_128, input);

    printf("== K0\n");
    for (int i = 0; i < 128; i++) {
        if ((i % 32) == 0 && i != 0) {
            printf("\n");
        }
        if ((i % 8) == 0) {
            printf("\t%3d: ", input[i / 8]);
        }
        printf("%d", key.pVal[i]);
    }
    printf("\n==\n");

    terminateKey(key);
}
