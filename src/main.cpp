#include <stdio.h>
#include <math.h>
#include "./tools.h"
#include "./hamming.h"

int main(int argc, char const *argv[])
{
    // Create a string
    char firstName[30];

    // Ask the user to input some text
    printf("Enter your first name: \n");
    scanf("%s", firstName);

    // Ask for some bytes
    char *input;
    printf("Ciao %s, inserisci una sequenza di bit:", firstName);
    scanf("%s", input);

    if (checkBits(input) != 0)
    {
        printf("La sequenza inserita %s non è una sequenza di bit\n", input);
        return 1;
    }

    printf("\nOttimo! Hai inserito la sequenza %s; ora ti calcolo i bit di parita'\n", input);

    // get data bit size
    int num_bit_dati = getArrayLength(input);
    printf("Input data size: %d \n", num_bit_dati);

    // calcola l'array dei bit di parità
    // num_bit_dati + num_bit_controllo + 1 = 2^bit_controllo
    int parity_array_size = get_numero_bit_di_controllo(num_bit_dati);
    printf("parity_array_size: %d\n",parity_array_size);

    int parity_array[parity_array_size];
    populate_parity_array(parity_array, parity_array_size);

    int workLoadSize = parity_array_size + num_bit_dati;
    printf("workLoadSize Array Size: %d\n", workLoadSize);

    printf("I bit di parità sono i seguenti:\n");
    char hamming[workLoadSize];
    calcola_code_word(hamming, workLoadSize, input, parity_array, parity_array_size);
    printf("\nLa codeword finale è: %s\n", hamming);

    return 0;
}
