#include "./tools.h"

int compute_parity_bit(char *code, int step);

void calcola_code_word(char *hamming, int  workLoadSize, char* input, int *parityArray, int parityArraySize);

int get_numero_bit_di_controllo(int num_bit_dati);

void *populate_parity_array(int *parity_array, int parity_array_size);