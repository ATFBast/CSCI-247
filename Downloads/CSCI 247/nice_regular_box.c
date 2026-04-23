#include <stdio.h>
#include <string.h>

#define MAX 1000
#define MAX_LENGTH 1000

void trim(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    char lin[MAX][MAX_LENGTH];
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        fgets(lin[i], MAX_LENGTH, stdin);

        trim(lin[i]);

        int length = strlen(lin[i]);
        if (length > maxLength) {
            maxLength = length;
        }
    }

    int borderlength = maxLength + 4;

    for (int i = 0; i < borderlength; i++) {
        printf("+");
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("+ ");
        printf("%s", lin[i]);

        int pad = maxLength - strlen(lin[i]);
        for (int j = 0; j < pad; j++) {
            printf(" ");
        }

        printf(" +\n");
    }

    for (int i = 0; i < borderlength; i++) {
        printf("+");
    }
    printf("\n");

    return 0;
}