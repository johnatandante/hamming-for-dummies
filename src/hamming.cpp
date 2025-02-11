#include <stdio.h>
#include <math.h>

#include "./tools.h"
#include "./hamming.h"

const char null_char = '\0';

int compute_parity_bit(char *code, int step)
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

void calcola_code_word(char* hamming, int work_load_size, char *input, int *parity_array, int parity_array_size){

    int num_bit_dati = work_load_size - parity_array_size;
    int j = 0;
    for (int k = 0, l = 0; 
            j<work_load_size; 
            j++)
    {
        if( l<parity_array_size && j == parity_array[l]){
            l++;
            hamming[j] = '_';
        } else if( k<num_bit_dati) {
            hamming[j] = input[k++];
        }
        printf("hamming[%d]: %c\n", j, hamming[j]);
    }
    hamming[j] = null_char;

    int pzero = zero_char;
    for (int h = 0, j = 0, step = 0 ;h<parity_array_size;h++) {
        j = parity_array[h];
        step = (int)pow(2, h);
        hamming[j] = compute_parity_bit(hamming, step) + pzero;
    }
}

int get_numero_bit_di_controllo(int num_bit_dati) {
    int num_bit_controllo = 0;
    while (pow(2, num_bit_controllo) <= num_bit_dati + num_bit_controllo)
    {
        num_bit_controllo++;
    }
    
    return num_bit_controllo;
}

void *populate_parity_array(int *parity_array, int parity_array_size) {
    for (int i = 0; i < parity_array_size; i++)
    {
        parity_array[i] = (int)pow(2, i) -1;
    }
    
}