#include <string.h>
#include <stdbool.h>
#include "mstring.h"


int
streqs(string_t *s0, string_t *s1)
{
    if (s0->size != s1->size) return false;
    
    return strncmp(s0->data, s1->data, s0->size) == 0;
}

int
streqp(string_t *s0, char *s1)
{
    int sz = strlen(s1);
    if (s0->size != sz) return false;
    
    return strncmp(s0->data, s1, sz) == 0;
}
