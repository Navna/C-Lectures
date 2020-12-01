#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strtok(char* str, const char* delim) {
    static char* context = NULL;
    if (str == NULL)
        str = context;
    if (str == NULL) {
        return NULL;
    }

    // TODO
    context = NULL;
    return NULL;
}

int main(void) {
    char c = 13;

    // Демонстрация strtok
    const char* srcSentence = "Don't tease! Well, and what has been decided about No - vosiltsev's dispatch? You know everything.";
    const char* delimiters = "!, -?";
    char* sentence = malloc(strlen(srcSentence) + (size_t)1);
    if (sentence == NULL)
        return EXIT_FAILURE;
    strcpy(sentence, srcSentence);
    printf("%s\n\n", sentence);

    char* r = strtok(sentence, delimiters);
    while (r != NULL)
    {
        printf("%s\n", r);
        r = strtok(NULL, delimiters);
    }
    printf("\n");

    // Пример переполнения
    const char* str = "2147483648";
    errno = 0;
    const long value = strtol(str, NULL, 0);
    printf("%d\n", errno == ERANGE);
    printf("%ld", value);
}
