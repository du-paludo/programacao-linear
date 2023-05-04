#include <stdio.h>
#include <stdlib.h>
#include "producao.h"

int main() {
    int n, m;
    scanf("%i", &n); // quantidade de produtos
    scanf("%i", &m); // quantidade de compostos

    double* precos = malloc(n * sizeof(double));
    double** compostos = malloc(m * sizeof(double*));
    double** quantidades = malloc(n * sizeof(double*));

    for (int j = 0; j < m; j++)
        compostos[j] = malloc(2 * sizeof(double));

    for (int i = 0; i < n; i++)
        quantidades[i] = malloc(m * sizeof(double));

    for (int i = 0; i < n; i++)
        scanf("%lf", &precos[i]); // preços de venda (v_i) de cada produto

    for (int j = 0; j < m; j++) // cada composto j
        for (int k = 0; k < 2; k++) // custo p_j e limite de produção q_j
            scanf("%lf", &compostos[j][k]);
    
    for (int i = 0; i < n; i++) // para cada produto
        for (int j = 0; j < m; j++) // e composto j
            scanf("%lf", &quantidades[i][j]); // quantidade de j em i (c_ij)

    lp_solve_format(n, m, precos, compostos, quantidades); // passa para o formato lp_solve
}