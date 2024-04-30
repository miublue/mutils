#include <stdio.h>
#include <stdlib.h>

#include "mfile.h"

char*
read_file(const char *path)
{
    char *text;
    size_t size;

    FILE *file = fopen(path, "r");
    if (!file)
        goto read_file_fail;

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    if (size == 0)
        goto read_file_fail;

    text = malloc(size * sizeof(char) + 1);
    fread(text, sizeof(char), size, file);
    text[size] = '\0';

    fclose(file);
    return text;

read_file_fail:
    if (file) fclose(file);
    if (text) free(text);
    fprintf(stderr, "ERROR: could not read file '%s'", path);
    return NULL;
}

int
write_file(const char *path, char *text)
{
    FILE *file = fopen(path, "w");
    if (!file)
        goto write_file_fail;

    fprintf(file, "%s", text);
    return 0;

write_file_fail:
    if (file) fclose(file);
    fprintf(stderr, "ERROR: could not write file '%s'", path);
    return 1;
}

