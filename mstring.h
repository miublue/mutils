#ifndef MSTRING_H
#define MSTRING_H

#include <stdlib.h>
#include "mlist.h"

#define L_STRING (string_t) LIST_ALLOC(char)

#define STR_FMT "%.*s"
#define STR_ARG(str)  str.size, str.data
#define STR_ARGP(str) str->size, str->data

typedef struct string_t {
    char *data;
    int size, alloc;
} string_t;

int streqs(string_t *s0, string_t *s1);
int streqp(string_t *s0, char *s1);

#endif
