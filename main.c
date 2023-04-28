#include <stdio.h>
#include <stdlib.h>
#include "producao.h"

int main() {
    int n, m;
    scanf("%i", &n); // quantidade de produtos
    scanf("%i", &m); // quantidade de compostos

    int* precos = malloc(n * sizeof(int));
    int** compostos = malloc(m * sizeof(int*));
    float** quantidades = malloc(n * sizeof(float*));

    for (int j = 0; j < m; j++)
        compostos[j] = malloc(2 * sizeof(int));

    for (int i = 0; i < n; i++)
        quantidades[i] = malloc(m * sizeof(float));


    for (int i = 0; i < n; i++)
        scanf("%i", &precos[i]); // preços de venda (v_i) de cada produto

    for (int j = 0; j < m; j++) // cada composto j
        for (int k = 0; k < 2; k++) // custo p_j e limite de produção q_j
            scanf("%i", &compostos[j][k]);
    
    for (int i = 0; i < n; i++) // para cada produto
        for (int j = 0; j < m; j++) // e composto j
            scanf("%f", &quantidades[i][j]); // quantidade de j em i (c_ij)

    lp_solve_format(n, m, precos, compostos, quantidades); // passa para o formato lp_solve
}