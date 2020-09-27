#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void *malloc_wrapper(size_t size, const char *file, int line)
{
    void *ptr = malloc(size);
    fprintf(stderr, "%s:%d: malloc %p %zuB\n", file, line, ptr, size);
    return ptr;
}

void *realloc_wrapper(void *ptr, size_t size, const char *file, int line)
{
    void *ptr_old = ptr;
    void *ptr_new = realloc(ptr, size);
    fprintf(stderr, "%s:%d:  realloc %p -> %p %zuB\n", file, line, ptr_old, ptr_new, size);
    return ptr_new;
}

void *calloc_wrapper(size_t count, size_t size, const char *file, int line)
{
    void *ptr = calloc(count, size);
    fprintf(stderr, "%s:%d:  calloc %p %zuB\n", file, line, ptr, size);
    return ptr;
}

void free_wrapper(void *ptr, const char *file, int line)
{
    fprintf(stderr, "%s:%d:  free %p\n", file, line, ptr);
    free(ptr);
}