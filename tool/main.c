#include <stdio.h>
#include <stdbool.h>
#include "AsciiArtTool.h"


#define NULL 0
#define FILENAME_SIZE 100


MapFunction invert(char value)
{
    switch (value)
    {
    case ' ':
        return '@';
    
    case '@':
        return ' ';
    
    default:
        return value;
    }
}


int main()
{
    bool inverted = false;
    bool encoded = false;

    char flag;

    while (scanf("-%c ", &flag) == 1)
    {
        switch (flag)
        {
        case 'i':
            inverted = true;
            break;
        
        case 'e':
            encoded = true;
            break;
        
        default:
            break;
        }
    }

    char source[FILENAME_SIZE];

    if (scanf("%s ", &source) != 1)
    {
        return 1;
    }

    FILE* in_stream = fopen(source, "r");

    if (in_stream == NULL)
    {
        printf("\n%s File not found!", source);
        return 2;
    }

    char target[FILENAME_SIZE];

    if (scanf("%s\n", &target) != 1)
    {
        return 3;
    }

    FILE* out_stream = fopen(target, "w");

    if (out_stream == NULL)
    {
        printf("\n%s File not found!", target);
        return 4;
    }

    RLEList list = asciiArtRead(in_stream);

    if (inverted)
    {
        RLEListMap(list, invert);
    }

    if (!encoded)
    {
        asciiArtPrint(list, out_stream);
    }
    else
    {
        asciiArtPrintEncoded(list, out_stream);
    }

    RLEListDestroy(list);
}