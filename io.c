#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"
#include "io.h"

void preencheArvore(char nomeArquivo[], ARVOREBIN *raiz){
	FILE *arquivo;
	int valor;

	arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL){
        printf("Nao foi possivel ler o arquivo!\n");
        return;
    }
    else{
    	while(fscanf(arquivo, " %d\n", &valor) != EOF){
    		insereNo(raiz, valor);
        }
    }
}