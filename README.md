# c-logging-lib
Collection of macros and wrappers to make logging and memory leak spotting easier.

## Installation
Default location is `/usr/local/include` and `/usr/local/lib`
```shell
git clone https://github.com/stefanTrawicki/c-logging-lib.git
cd c-logging-lib
make
```

## Usage

```shell
clang test.c -o test -llogging
```

```c
#include <liblogging.h>

int main(int argc, char **argv)
{
    stderr_set("mem.log");
    stdout_set("out.log);
    printf("hello, world! %d", 5);

    int *x = malloc(sizeof(int));

    int *y = malloc(sizeof(int));
    y = realloc(y, sizeof(int) * 2);

    free(x);
    free(y);

    return 0;
}
```

## Output
in mem.log:
```log
test.c:8: malloc 0x7f85fbc05840 4B
test.c:10: malloc 0x7f85fbc05850 4B
test.c:11:  realloc 0x7f85fbc05850 -> 0x7f85fbc05850 8B
test.c:13:  free 0x7f85fbc05840
test.c:14:  free 0x7f85fbc05850
```

in out.log:
```log
test.c:6:  hello, world! 5
```
