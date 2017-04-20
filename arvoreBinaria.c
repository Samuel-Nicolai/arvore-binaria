#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

// definindo o tipo no
typedef struct no{
	int valor;
	struct no *esq;
	struct no *dir;
}NO;

ARVOREBIN *criaArvoreBinaria(){
	ARVOREBIN *raiz = (ARVOREBIN*) malloc(sizeof(ARVOREBIN));
	if(raiz == NULL)
		printf("Nao foi possivel alocar raiz!\n");
	else
		*raiz = NULL;
	return raiz;
}

void liberaNO(NO *no){
	if(no == NULL)
		return;
	liberaNO(no->esq);
	liberaNO(no->dir);
	free(no);
	no = NULL;
}

void liberaArvoreBinaria(ARVOREBIN *raiz){
	if(raiz == NULL){
		printf("Arvore ja nao exixte!\n");
		return;
	}
	else{
		liberaNO(*raiz);
		free(raiz);
	}
}

void insereNo(ARVOREBIN *raiz, int valor){
	if(raiz == NULL){
		printf("A arvore ainda nao foi criada.\n");
		return;
	}
	NO *novoNo = (NO*) malloc(sizeof(NO));
	if(novoNo == NULL){
		printf("Nao foi possivel alocar no.\n");
		return;
	}
	novoNo->valor = valor;
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	if(*raiz == NULL)
		*raiz = novoNo;
	else{
		NO *ant = NULL;
		NO *atual = *raiz;
		while(atual != NULL){
			ant = atual;
			if(valor == atual->valor){
				printf("Ja existe no com valor %d.\n", valor);
				free(novoNo);
				return;
			}
			if(valor < atual->valor)
				atual = atual->esq;
			else
				atual = atual->dir;
		}
		if(valor < ant->valor)
			ant->esq = novoNo;
		else
			ant->dir = novoNo;
	}
}

NO *removeAtual(NO *atual){
	NO *aux1, *aux2;
	if(atual->esq == NULL){
		aux1 = atual->dir;
		free(atual);
		return aux1;
	}

	aux1 = atual;
	aux2 = atual->esq;
	while(aux2->dir != NULL){
		aux1 = aux2;
		aux2 = aux2->dir;
	}

	if(aux1 != atual){
		aux1->dir = aux2->esq;
		aux2->esq = atual->esq;
	}

	aux2->dir = atual->dir;
	free(atual);
	return aux2;
}

void removeNo(ARVOREBIN *raiz, int valor){
	if(raiz == NULL){
		printf("A arvore ainda nao foi criada.\n");
		return;
	}
	NO *ant = NULL;
	NO *atual = *raiz;
	while(atual != NULL){
		if(atual->valor == valor){
			if(atual == *raiz){
				*raiz = removeAtual(atual);
			}
			else{
				if(ant->esq == atual)
					ant->esq = removeAtual(atual);
				else
					ant->dir = removeAtual(atual);
			}
			return;
		}
		ant = atual;
		if(valor < atual->valor)
			atual = atual->esq;
		else
			atual = atual->dir;
	}
}

void preOrdem(ARVOREBIN *raiz){
	if(raiz == NULL)
		return;
	if(*raiz != NULL){
		printf("%d\t", (*raiz)->valor);
		preOrdem(&((*raiz)->esq));
		preOrdem(&((*raiz)->dir));
	}
}

void emOrdem(ARVOREBIN *raiz){
	if(raiz == NULL)
		return;
	if(*raiz != NULL){
		preOrdem(&((*raiz)->esq));
		printf("%d\t", (*raiz)->valor);
		preOrdem(&((*raiz)->dir));
	}
}

void posOrdem(ARVOREBIN *raiz){
	if(raiz == NULL)
		return;
	if(*raiz != NULL){
		preOrdem(&((*raiz)->esq));
		preOrdem(&((*raiz)->dir));
		printf("%d\t", (*raiz)->valor);
	}
}

int encontraMaior(ARVOREBIN *raiz, int *comp){
	int maior;
	NO *aux = *raiz;

	while(aux != NULL){
		maior = aux->valor;
		(*comp)++;
		aux = aux->dir;
	}
	return maior;
}