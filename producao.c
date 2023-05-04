#include <stdio.h>

void lp_solve_format(int n, int m, double* precos, double** compostos, double** quantidades) {
    // escreve o problema no formato lp_solve
    double soma = 0;
    
    printf("max: ");
    for (int i = 0; i < n; i++) {
        soma = precos[i];
        for (int j = 0; j < m; j++) {
            soma -= compostos[j][0] * quantidades[i][j];
        }
        printf("%lfx%i", soma, i + 1);
        if (i < n - 1)
            printf(" + ");
    }
    printf(";\n");

    // restrições de produção
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            printf("%lfx%i", quantidades[i][j], i + 1);
            if (i < n - 1)
                printf(" + ");
        }
        printf(" <= %lf;\n", compostos[j][1]);
    }

    // restrições de não-negatividade
    for (int i = 0; i < n; i++) {
        printf("x%i >= 0;\n", i + 1);
    }
}