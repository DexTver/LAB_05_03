#include <stdio.h>

int main() {
    char delimiters[100];
    char text[1000];
    int length, ln, count = 0, fl;

    printf("Enter delimiter characters:\n");
    fgets(delimiters, sizeof(delimiters), stdin);

    printf("Enter a line of text:\n");
    fgets(text, sizeof(text), stdin);

    printf("Enter the length of the word to count:\n");
    scanf("%i", &length);

    char *start = text;
    char *end = text;
    char *x;

    while (*end != '\n') {
        fl = 0;
        x = delimiters;
        while (*x != '\n') {
            if (*end == *x) {
                fl = 1;
            }
            ++x;
        }
        if (fl == 1) {
            ln = end - start;
            if (ln == length) {
                ++count;
            }
            start = end + 1;
        }
        ++end;
    }
    ln = end - start;
    if (ln == length) {
        ++count;
    }

    printf("Number of words of length %i: %i", length, count);
    return 0;
}
