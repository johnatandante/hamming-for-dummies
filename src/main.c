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


int getArrayLength(char *array) {
    int i = 0;
    while (array[i] != '\0')
    {
        i++;
    }
    return i;
}

int checkBits(char *bits)
{

    int i = 0;
    int l = getArrayLength(bits);
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

void calcolaCodeWord(char *hamming, int *parityArray){
    int parityArraySize = sizeof(parityArray);
    for (int h = 0, j = 0, step = 0, pzero = '0' ;h<parityArraySize;h++) {
        j = parityArray[h];
        step = (int)pow(2, h);
        hamming[j] = getParity(hamming, step) + pzero;
    }
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

    int sizeOfInput = getArrayLength(input);
    int parityArraySize = ((int)log2(sizeOfInput)) + 1;

    int parityArray[parityArraySize];
    for (int i = 0; i < parityArraySize; i++)
    {
        parityArray[i] = (int)pow(2, i) -1;
        printf("parityArray[%d]: %d\n", i, parityArray[i]);
    }

    int workLoadSize = parityArraySize + sizeOfInput;
    printf("workLoadSize Array Size: %d\n", workLoadSize);

    char hamming[workLoadSize];
    int j = 0;
    int step;
    for (int k = 0, l = 0; 
            j<workLoadSize ; 
            j++)
    {
        if( l<parityArraySize && j == parityArray[l]){
            l++;
            hamming[j] = '_';
        } else if( k<sizeOfInput) {
            hamming[j] = input[k++];
        }
        printf("hamming[%d]: %c\n", j, hamming[j]);

    }
    hamming[j] = '\0';

    printf("I bit di parità sono i seguenti:\n");
    calcolaCodeWord(hamming, parityArray);

    printf("\nLa codeword finale è: %s\n", hamming);

    return 0;
}
