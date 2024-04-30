#ifndef MLIST_H
#define MLIST_H

#include <stdlib.h>
#include <string.h>

#define LIST_DEFAULT_SIZE 1024/4

#define LIST_DEFINE(type, name) \
    typedef struct name { \
        type *data; \
        size_t size, alloc; \
    } name


#define LIST_EMPTY(type) (type) { .data = NULL, .size = 0, .alloc = 0 }

#define LIST_ALLOC(type) \
    { \
        .data = calloc(sizeof(type), LIST_DEFAULT_SIZE), \
        .size = 0, \
        .alloc = LIST_DEFAULT_SIZE, \
    }

#define LIST_FREE(list) \
    { \
        if (list.alloc) \
            free(list.data); \
        list.size = 0; \
        list.alloc = 0; \
    }

#define LIST_FREEP(list) \
    { \
        if (list->alloc) \
            free(list->data); \
        list->size = 0; \
        list->alloc = 0; \
    }

#define LIST_ADD(list, pos, item) \
    { \
        if (list.size+1 >= list.alloc) { \
            list.alloc += LIST_DEFAULT_SIZE; \
            list.data = realloc(list.data, sizeof(list.data[0]) * list.alloc); \
        } \
        if (pos >= list.size) { \
            list.data[list.size++] = item; \
        } \
        else {\
            list.size++; \
            for (size_t i = list.size; i > pos; --i) { \
                list.data[i] = list.data[i-1]; \
            } \
            list.data[pos] = item; \
        } \
    }

#define LIST_ADDP(list, pos, item) \
    { \
        if (list->size+1 >= list->alloc) { \
            list->alloc += LIST_DEFAULT_SIZE; \
            list->data = realloc(list->data, sizeof(list->data[0]) * list->alloc); \
        } \
        if (pos >= list->size) { \
            list->data[list->size++] = item; \
        } \
        else {\
            list->size++; \
            for (size_t i = list->size; i > pos; --i) { \
                list->data[i] = list->data[i-1]; \
            } \
            list->data[pos] = item; \
        } \
    }

#define LIST_POP(list, pos) \
    { \
        if (pos <= list.size && list.size > 0) { \
            list.size--; \
            for (size_t i = pos; i < list.size; ++i) { \
                list.data[i] = list.data[i+1]; \
            } \
        } \
    }

#define LIST_POPP(list, pos) \
    { \
        if (pos <= list->size && list->size > 0) { \
            list->size--; \
            for (size_t i = pos; i < list->size; ++i) { \
                list->data[i] = list->data[i+1]; \
            } \
        } \
    }
#endif
