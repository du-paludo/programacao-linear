#include <stdio.h>

void lp_solve_format(int n, int m, int* precos, int** compostos, float** quantidades) {
    // escreve o problema no formato lp_solve
    printf("max: ");
    for (int i = 0; i < n; i++) {
        printf("%ix%i", precos[i], i + 1);
        for (int j = 0; j < m; j++) {
            printf(" - %fx%i", compostos[j][0] * quantidades[i][j], i + 1);
        }
        if (i < n - 1)
            printf(" + ");
    }
    printf(";\n");

    // restrições de produção
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            printf("%fx%i", quantidades[i][j], i + 1);
            if (i < n - 1)
                printf(" + ");
        }
        printf(" <= %i;\n", compostos[j][1]);
    }

    // restrições de não-negatividade
    for (int i = 0; i < n; i++) {
        printf("x%i >= 0;\n", i + 1);
    }
}