#include <stdio.h>
#include <string.h>

int main() {
    int num;
    char word[100];
    char plural[120]; // result buffer

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Enter a word: ");
    scanf("%s", word);

    if (num == 1) { // singular case
        printf("%d %s\n", num, word);
        return 0;
    }

    int len = strlen(word); // word length

    strcpy(plural, word); // base copy

    // ends with "ife"
    if (len >= 3 && strcmp(word + len - 3, "ife") == 0) {
        plural[len - 3] = '\0'; // trim ife
        strcat(plural, "ives"); // add ives
    }

    // ends with sh/ch
    else if (len >= 2 &&
            (strcmp(word + len - 2, "sh") == 0 ||
             strcmp(word + len - 2, "ch") == 0)) {
        strcat(plural, "es"); // add es
    }

    // ends with "us"
    else if (len >= 2 && strcmp(word + len - 2, "us") == 0) {
        plural[len - 2] = '\0'; // trim us
        strcat(plural, "i"); // add i
    }

    // vowel + y
    else if (len >= 2 && word[len - 1] == 'y' &&
             strchr("aeiouAEIOU", word[len - 2])) {
        strcat(plural, "s"); // add s
    }

    // ends with y
    else if (len >= 1 && word[len - 1] == 'y') {
        plural[len - 1] = '\0'; // trim y
        strcat(plural, "ies"); // add ies
    }

    // default case
    else {
        strcat(plural, "s"); // add s
    }

    printf("RESULT: %d %s\n", num, plural);
    fflush(stdout);

    return 0;
}