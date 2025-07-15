#include <stdio.h>
#include <string.h>

int ocorre(const char *str1, const char *str2) {
    while (*str1) {
        const char *p1 = str1;
        const char *p2 = str2;

        while (*p1 && *p2 && *p1 == *p2) {
            p1++;
            p2++;
        }

        if (*p2 == '\0') return 1;
        str1++;
    }
    return 0;
}

int main() {
    char s1[100], s2[100];
    printf("Digite a string principal: ");
    fgets(s1, sizeof(s1), stdin);
    printf("Digite a substring: ");
    fgets(s2, sizeof(s2), stdin);

    // Remover o \n
    s1[strcspn(s1, "\n")] = 0;
    s2[strcspn(s2, "\n")] = 0;

    if (ocorre(s1, s2))
        printf("Substring encontrada!\n");
    else
        printf("Substring não encontrada.\n");

    return 0;
}
