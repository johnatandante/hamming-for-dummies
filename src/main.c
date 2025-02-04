#include <stdio.h>
#include <math.h>

int getParity(char *code, int step)
{
    int zero = '0', bit;
    int p = 0;
    int l = sizeof(code);
    int flag = 0;
    char parity[100];
    int iParity = 0;
    parity[iParity++] = '_';
    printf("Posizioni protette: ");
    for (int i = -1 + step; i < l && code[i] != '\0'; i++)
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
    parity[iParity] = '\0';
    printf(" Parity: %s\n", parity);
    return p;
}

int checkBits(char *bits)
{

    int i = 0;
    int l = sizeof(bits);
    while (i < l && bits[i] != '\0')
    {
        if (bits[i] != '0' && bits[i] != '1')
        {
            return 1;
        }
        i++;
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    // Create a string
    char firstName[30];

    // Ask the user to input some text
    printf("Enter your first name: \n");

    // Get and save the text
    scanf("%s", firstName);

    // Output the text
    char *input;

    printf("Ciao %s, inserisci una sequenza di 4 bit:", firstName);
    scanf("%4s", input);

    if (checkBits(input) != 0)
    {
        printf("La sequenza inserita %s non è una sequenza di bit\n", input);
        return 1;
    }

    printf("\nOttimo! Hai inserito la sequenza %s; ora ti calcolo i bit di parita'\n", input);

    char hamming[8];
    int j = 0, k = 0, zero = '0';
    hamming[j++] = '_';
    hamming[j++] = '_';
    hamming[j++] = input[k++];
    hamming[j++] = '_';
    hamming[j++] = input[k++];
    hamming[j++] = input[k++];
    hamming[j++] = input[k++];
    hamming[j] = '\0';

    int i = 0, step;
    int parity0, parity1, parity2; //, parity3 = '_';
    printf("I bit di parità sono i seguenti:\n");

    j = pow(2, i);
    step = (int)pow(2, i++);
    hamming[j - 1] = getParity(hamming, step) + zero;
    //printf("Codework aggiornata: %s\n", hamming);

    j = pow(2, i);
    step = (int)pow(2, i++);
    hamming[j - 1] = getParity(hamming, step) + zero;
    //printf("Codework aggiornata: %s\n", hamming);

    j = pow(2, i);
    step = (int)pow(2, i++);
    hamming[j - 1] = getParity(hamming, step) + zero;
    //printf("Codework aggiornata: %s\n", hamming);
    
    printf("\nLa codeword finale è: %s\n", hamming);

    return 0;
}
