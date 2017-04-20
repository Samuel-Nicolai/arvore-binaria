/*
 * Criacao de uma arvore binaria basica
 * Preenchimento aleatorio e ordenado
 * Comparacao do tempo de busca do maior elemento
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "arvoreBinaria.h"
#include "io.h"

int main(){
	ARVOREBIN *raiz;

	char nomeArquivo[20];

	int comp = 0, maior;
	struct timeval inicio, fim;
	float tempoExecucao = 0.0;
	// fim das declaracoes

	raiz = criaArvoreBinaria();

	printf("Digite o nome do arquivo de entrada: \n");
	scanf("%s", nomeArquivo);

	preencheArvore(nomeArquivo, raiz);
	removeNo(raiz, 7);

	gettimeofday(&inicio, NULL);
	maior = encontraMaior(raiz, &comp);
	gettimeofday(&fim, NULL);
	tempoExecucao = (float) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1);

	printf("O maior no tem valor: %d.\n", maior);
	printf("Foram realizadas %d comparacoes.\n", comp);
	printf("O tempo de busca foi de %f uSegundos\n", tempoExecucao);

	liberaArvoreBinaria(raiz);

	return 0;
}