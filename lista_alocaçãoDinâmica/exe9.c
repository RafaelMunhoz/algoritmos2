#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* inverteString(const char *s) {
    int len = strlen(s);
    char *inv = (char *)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        inv[i] = s[len - 1 - i];
    }
    inv[len] = '\0';
    return inv;
}

int main() {
    char str[100];
    printf("Digite a string: ");
    scanf("%s", str);
    char *invertida = inverteString(str);
    printf("Invertida: %s\n", invertida);
    free(invertida);
    return 0;
}
