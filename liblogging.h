#ifndef LOGGING_LIB_H
#define LOGGING_LIB_H

#include <stdio.h>
#include <unistd.h>

#define stderr_set(x)                    \
    {                                    \
        FILE *fp = fopen(x, "w");        \
        dup2(fileno(fp), STDERR_FILENO); \
        fclose(fp);                      \
    }

#define stdout_set(x)                    \
    {                                    \
        FILE *fp = fopen(x, "w");        \
        dup2(fileno(fp), STDOUT_FILENO); \
        fclose(fp);                      \
    }

#define printf(x, ...)                                   \
    {                                                    \
        fprintf(stderr, "%s:%d:  ", __FILE__, __LINE__); \
        fprintf(stderr, x, __VA_ARGS__);                 \
        fprintf(stderr, "\n");                           \
    }

void *calloc_wrapper(size_t count, size_t size, const char *file, int line);
void *realloc_wrapper(void *ptr, size_t size, const char *file, int line);
void *malloc_wrapper(size_t size, const char *file, int line);
void free_wrapper(void *ptr, const char *file, int line);

#define malloc(size) malloc_wrapper(size, __FILE__, __LINE__);
#define realloc(ptr, size) realloc_wrapper(ptr, size, __FILE__, __LINE__);
#define calloc(count, size) calloc_wrapper(count, size, __FILE__, __LINE__);
#define free(ptr) free_wrapper(ptr, __FILE__, __LINE__);

#endif // !LOGGING_LIB_H