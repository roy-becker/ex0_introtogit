#include "AsciiArtTool.h"


#define NULL 0


RLEList asciiArtRead(FILE* in_stream)
{
    char value;

    RLEList list = RLEListCreate();

    while (fscanf(in_stream, "%c", &value) == 1)
    {
        if (RLEListAppend(list, value) != RLE_LIST_SUCCESS)
        {
            RLEListDestroy(list);

            return NULL;
        }
    }

    return list;
}


RLEListResult asciiArtPrint(RLEList list, FILE *out_stream)
{
    if (list == NULL || out_stream == NULL)
    {
        return RLE_LIST_NULL_ARGUMENT;
    }

    while (list != NULL)
    {
        for (int i = 0; i < list->num; i++)
        {
            fprintf(out_stream, "%c", list->val);
        }
        
        list = list->next;
    }

    return RLE_LIST_SUCCESS;
}


RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream)
{
    if (list == NULL || out_stream == NULL)
    {
        return RLE_LIST_NULL_ARGUMENT;
    }

    RLEListResult* result;

    char* temp = RLEListExportToString(list, result);

    if (*result != RLE_LIST_SUCCESS)
    {
        return *result;
    }

    fprintf(out_stream, "%s", temp);

    free(temp);

    return RLE_LIST_SUCCESS;
}