#include <stdio.h>
#include <stdlib.h>

#include "io.h"

int main() {
    char* s = read_line();

    puts(s);

    free(s);
}
