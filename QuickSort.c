#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"
/*
 * Estratégia Iterativa do Quicksort
 *
 * Faz sentido usar a estratégia iterativa do algoritmo Quicksort porque ela traz várias vantagens em comparação à versão recursiva tradicional.
 * Ao limitar o tamanho da pilha para O(log(n)), essa abordagem melhora a eficiência da memória e evita possíveis problemas de estouro de pilha 
 * quando lidamos com grandes volumes de dados.
 * 
 * A ideia de adicionar os índices da partição maior antes dos da menor é inteligente, pois garante que a partição menor seja processada primeiro, 
 * mantendo a pilha de execução controlada.
 * 
 * Implementamos essa estratégia no código a seguir.
 */
// Função principal
int main() {
    int n;
    printf("Digite o número de elementos: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Erro ao ler o número de elementos.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite os elementos do vetor: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Erro ao ler o elemento %d.\n", i + 1);
            free(arr);
            return 1;
        }
    }

    quickSortIterative(arr, 0, n - 1);

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
