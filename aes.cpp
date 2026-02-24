#include "aes.h"
#include <cstdint>
#include <stdio.h>

Key initKey(KeyType type, uint8_t* pValue)
{
    Key k;
    k.type = type;

    switch (type) {
        case 128: k.bit_size = 128; break;
        case 192: k.bit_size = 192; break;
        case 256: k.bit_size = 256; break;
    }

    k.pValue = pValue;

    return k;
}

int rotateWord(Key k)
{
    if (k.type == k_128)
    {
        uint8_t* pV = k.pValue;

        uint8_t tmp[4];

        for (int i = 0; i < 4; i++)
        {
            tmp[i] = pV[i];
            pV[i] = pV[i + 4];
            pV[i + 4] = pV[i + 8];
            pV[i + 8] = pV[i + 12];
            pV[i + 12] = tmp[i];
        }

        for (int i = 0; i < 16; i++) {
            k.pValue[i] = pV[i];
        }

        return 0;
    }
    else {
        return 1;
    }
}

int substituteWord(Key k)
{
    return 0;
}

void keySchedule(Key k)
{
    rotateWord(k);
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

    printf("== K0 ==========\n");
    for (int i = 0; i < 16; i++) {
        printf(" %d ", key.pValue[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
    printf("================\n");

    keySchedule(key);

    printf("== K1 ==========\n");
    for (int i = 0; i < 16; i++) {
        printf(" %d ", key.pValue[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
    printf("================\n");

    keySchedule(key);

    printf("== K3 ==========\n");
    for (int i = 0; i < 16; i++) {
        printf(" %d ", key.pValue[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
    printf("================\n");

    keySchedule(key);

    printf("== K4 ==========\n");
    for (int i = 0; i < 16; i++) {
        printf(" %d ", key.pValue[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
    printf("================\n");

    keySchedule(key);

    printf("== K5 ==========\n");
    for (int i = 0; i < 16; i++) {
        printf(" %d ", key.pValue[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
    printf("================\n");
}


