#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"

nodo_LSE* criaNodo(musica *dados){
	nodo_LSE *novoElemento = (nodo_LSE *)malloc(sizeof(nodo_LSE));
	novoElemento->info = dados;
	novoElemento->prox =  NULL;
	return novoElemento;
}

desc_LSE* criaDescritor(){
	desc_LSE *novoDescLista = (desc_LSE *)malloc(sizeof(desc_LSE));
	novoDescLista->tamanho = 0;
	novoDescLista->LSE=NULL;
	return novoDescLista;
}


/*void removeLista(desc_LSE *minhaLista, int posicao){
	if((minhaLista->tamanho ==0)||(posicao > minhaLista->tamanho)){
		printf("posicao não existe OU LISTA VAZIA!\n");
		return NULL;
	}
	else{
		if(posicao==0){ 
			nodo *aux = minhaLista->LSE;
			minhaLista->LSE = minhaLista->LSE->prox;
			minhaLista->tamanho--;
			return aux; 
		}
		else{ 
			int listaPos=0;
			nodo *anterior;
			nodo *aux = minhaLista->LSE;
			while(aux != NULL){
				anterior = aux;
				aux = aux->prox;
				listaPos++;
				if(listaPos == posicao){
					anterior->prox = aux->prox;
					minhaLista->tamanho--;
					return aux;
				}
			}	
		}
	}
}
*/

void insere(desc_LSE *minhaLista, nodo_LSE *novoElemento, int posicao){
	if((minhaLista->LSE == NULL)||(posicao == 0)){
		novoElemento->prox = minhaLista->LSE;
		minhaLista->LSE = novoElemento;
		minhaLista->tamanho++;
	}
	else{
		nodo_LSE *aux = minhaLista->LSE;
		int listaPos = 0;
		if(minhaLista->tamanho < posicao){
			while(aux->prox != NULL){
				aux = aux->prox; 
			}
			aux->prox = novoElemento;
			minhaLista->tamanho++;
			return;
		}
		else{
			nodo_LSE *anterior;
			while(aux != NULL){
				anterior = aux;
				aux = aux->prox; 
				listaPos++;
				if(listaPos == posicao){
					novoElemento->prox	= aux;
					anterior->prox = novoElemento;
					minhaLista->tamanho++;
					return;
				}
			}
		}
	}
}


/*int tamanho(desc_LSE *minhaLista){
	return minhaLista->tamanho;
}*/


/*void libera(desc_LSE *minhaLista){
	nodo *aux = minhaLista->LSE;
	nodo *corrente;
	while(aux->prox != NULL){
		corrente = aux;
		aux = aux->prox;
		free(corrente);
	}
	free(aux);
	minhaLista->LSE=NULL;
	minhaLista->tamanho=0; 
}
*/

void imprime(desc_LSE *minhaLista){
	nodo_LSE aux = minhaLista->LSE;
	while(aux != NULL){
		printf("[%d] ", aux->dado);
		aux = aux->prox;
	}
	printf("\n");
}
