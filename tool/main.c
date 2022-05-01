#include <stdio.h>
#include <stdbool.h>
#include "AsciiArtTool.h"


#define FILENAME_SIZE 100


char invert(char value)
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


int main(int argc, char **argv)
{
    bool inverted = false;
    bool encoded = false;

    for (int i = 1; i < argc - 2; i++)
    {
        char* flag = argv[i];

        if (flag[0] != '-')
        {
            printf("\n%s Illegal flag", flag);
            return 1;
        }
        
        switch (flag[1])
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

    char* source = argv[argc - 2];

    FILE* in_stream = fopen(source, "r");

    if (in_stream == NULL)
    {
        printf("\n%s File not found!", source);
        return 2;
    }

    char* target = argv[argc - 1];

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