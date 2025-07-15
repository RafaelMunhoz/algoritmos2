#include <stdio.h>

int main() {
    float mat[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            printf("Endereço de mat[%d][%d]: %p\n", i, j, (void*)&mat[i][j]);

    return 0;
}
