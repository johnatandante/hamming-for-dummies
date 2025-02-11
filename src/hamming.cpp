#include <stdio.h>
#include <math.h>

#include "./tools.h"
#include "./hamming.h"

const char null_char = '\0';

int getParity(char *code, int step)
{
    int zero = zero_char, bit;
    int p = 0;
    int l = getArrayLength(code);
    int flag = 0;
    char parity[l];
    int iParity = 0;
    parity[iParity++] = '_';
    printf("Posizioni protette: ");
    for (int i = -1 + step; i < l && code[i] != null_char; i++)
    {
        if ((i + 1) % step == 0)
        {
            flag = (flag + 1) % 2;
        }
        if (flag == 1)
        {
            if (code[i] != '_')
            {
                parity[iParity++] = code[i];
                bit = code[i] - zero;
                p = p ^ bit;
            }
            printf("[%d]", i);
        }
    }
    parity[0] = p + zero;
    parity[iParity] = null_char;
    printf(" Parity: %s\n", parity);
    return p;
}

void calcolaCodeWord(char *hamming, int *parityArray, int parityArraySize){
    int pzero = zero_char;
    for (int h = 0, j = 0, step = 0 ;h<parityArraySize;h++) {
        j = parityArray[h];
        step = (int)pow(2, h);
        hamming[j] = getParity(hamming, step) + pzero;
    }
}

int getNumeroBitDiControllo(int num_bit_dati) {
    int num_bit_controllo = 0;
    while (pow(2, num_bit_controllo) <= num_bit_dati + num_bit_controllo)
    {
        num_bit_controllo++;
    }
    
    return num_bit_controllo;
}

void *populateParityArray(int *parity_array, int parity_array_size) {
    for (int i = 0; i < parity_array_size; i++)
    {
        parity_array[i] = (int)pow(2, i) -1;
    }
    
}