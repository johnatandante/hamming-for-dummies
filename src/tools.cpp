#include "./tools.h";

const char null_char = '\0';

int getArrayLength(char *array) {
    int i = 0;
    while (array[i] != null_char) i++;
    
    return i;
}

int checkBits(char *bits)
{
    int i = 0;
    int l = getArrayLength(bits);
    while (i < l)
    {
        if (bits[i] != zero_char && bits[i] != uno_char)
        {
            return 1;
        }
        i++;
    }

    return 0;
}
