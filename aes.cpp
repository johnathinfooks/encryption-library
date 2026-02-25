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


void multiplicative_inverse(Key* pK)
{
    for (int i = 0; i < 254; i++) 
    {

    }
}


void rotate(Key* pK)
{
    int tmpBin[32];

    for (int i = 0; i < 32; i++)
    {
        tmpBin[i] = pK->pValBin[i];
        pK->pValBin[i] = pK->pValBin[i + 32];
        pK->pValBin[i + 32] = pK->pValBin[i + 64];
        pK->pValBin[i + 64] = pK->pValBin[i + 96];
        pK->pValBin[i + 96] = tmpBin[i];
    }

    int tmpDec[4];

    for (int i = 0; i < 4; i++)
    {
        tmpDec[i] = pK->pValDec[i];
        pK->pValDec[i] = pK->pValDec[i + 4];
        pK->pValDec[i + 4] = pK->pValDec[i + 8];
        pK->pValDec[i + 8] = pK->pValDec[i + 12];
        pK->pValDec[i + 12] = tmpDec[i];
    }
}

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
    k.pValDec = new uint8_t[type / 8];
    k.pValBin = new uint8_t[type];

    std::memcpy(k.pValDec, pDecValue, type / 8);
    decimalBinary(pDecValue, k.pValBin);

    return k;
}

int terminateKey(Key pK)
{
    delete[] pK.pValBin;
    pK.pValBin = nullptr;
    pK.pValDec = nullptr;
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

    // REPRESENTING THE INFORMATION DURING THE KEY SCHEDULING

    printf("== K0\n");
    for (int i = 0; i < 128; i++) {
        if ((i % 32) == 0 && i != 0) {
            printf("\n");
        }
        if ((i % 8) == 0) {
            printf("%5d: ", key.pValDec[i / 8]);
        }
        printf("%d", key.pValBin[i]);
    }
    printf("\n==\n");

    rotate(&key);

    printf("== K1\n");
    for (int i = 0; i < 128; i++) {
        if ((i % 32) == 0 && i != 0) {
            printf("\n");
        }
        if ((i % 8) == 0) {
            printf("%5d: ", key.pValDec[i / 8]);
        }
        printf("%d", key.pValBin[i]);
    }
    printf("\n==\n");

    rotate(&key);

    printf("== K2\n");
    for (int i = 0; i < 128; i++) {
        if ((i % 32) == 0 && i != 0) {
            printf("\n");
        }
        if ((i % 8) == 0) {
            printf("%5d: ", key.pValDec[i / 8]);
        }
        printf("%d", key.pValBin[i]);
    }
    printf("\n==\n");

    rotate(&key);

    printf("== K3\n");
    for (int i = 0; i < 128; i++) {
        if ((i % 32) == 0 && i != 0) {
            printf("\n");
        }
        if ((i % 8) == 0) {
            printf("%5d: ", key.pValDec[i / 8]);
        }
        printf("%d", key.pValBin[i]);
    }
    printf("\n==\n");

    rotate(&key);

    printf("== K4\n");
    for (int i = 0; i < 128; i++) {
        if ((i % 32) == 0 && i != 0) {
            printf("\n");
        }
        if ((i % 8) == 0) {
            printf("%5d: ", key.pValDec[i / 8]);
        }
        printf("%d", key.pValBin[i]);
    }
    printf("\n==\n");

    terminateKey(key);
}
