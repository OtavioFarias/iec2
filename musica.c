#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"

musica* cadastrar(){
	musica *musicas=(musica *)malloc(sizeof(musica));
	printf("\nQual o título da música? ");
	setbuf(stdin,NULL);
	fgets(musicas->titulo,256,stdin);
	printf("\nQual o artista? ");
	setbuf(stdin,NULL);
	fgets(musicas->artista,256,stdin);
	printf("\nQual a letra da música? ");
	setbuf(stdin,NULL);
	setbuf(stdin,NULL);
	fgets(musicas->letra,256,stdin);
	printf("Qual o código da música? ");
	setbuf(stdin,NULL);
	setbuf(stdin,NULL);
	scanf("%i", &musicas->codigo);
	printf("Qual o número de execuções da música? ");
	setbuf(stdin,NULL);
	scanf("%i", &musicas->execucoes);
	return (musicas);
	}

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
	int p=0;
	nodo_LSE *aux = (nodo_LSE *)malloc(sizeof(nodo_LSE));
	aux = minhaLista->LSE;
	while(aux != NULL){
		printf("|==============================|");
		printf("\n Posição [%i]\n Título: %s\n Artista: %s\n Letra: %s\n Código: %i\n Execuções: %i\n ", p,aux->info->titulo, aux->info->artista, aux->info->letra, aux->info->codigo, aux->info->execucoes);
		printf("|==============================|\n");
		aux = aux->prox;
		p++;
	}
	printf("\n");
}

nodo_LSE* removeLista(desc_LSE *minhaLista, int posicao){
	nodo_LSE *aux=(nodo_LSE *)malloc(sizeof(nodo_LSE));
	if((minhaLista->tamanho ==0)||(posicao > minhaLista->tamanho)){
		printf("posicao não existe OU LISTA VAZIA!\n");
	}
	else{
		if(posicao==0){ 
			aux = minhaLista->LSE;
			minhaLista->LSE = minhaLista->LSE->prox;
			minhaLista->tamanho--;
			return aux; 
		}
		else{ 
			int listaPos=0;
			nodo_LSE *anterior;
			aux = minhaLista->LSE;
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
 return aux;
}

void conExecucoes(desc_LSE *minhaLista, int execucoes){
	nodo_LSE *aux = (nodo_LSE *)malloc(sizeof(nodo_LSE));
	aux = minhaLista->LSE;
	int p=0;
	while(aux != NULL){
		if(execucoes==aux->info->execucoes){
		printf("|==============================|");
		printf("\n Posição [%i]\n Título: %s\n Artista: %s\n Letra: %s\n Código: %i\n Execuções: %i\n ",p, aux->info->titulo, aux->info->artista, aux->info->letra, aux->info->codigo, aux->info->execucoes);
		printf("|==============================|\n");
		}
		aux = aux->prox;
	p++;
	}
	printf("\n");
}

void conCodigo(desc_LSE *minhaLista, int codigo){
	nodo_LSE *aux = (nodo_LSE *)malloc(sizeof(nodo_LSE));
	aux = minhaLista->LSE;
	int p=0;
	while(aux != NULL){
		if(codigo==aux->info->codigo){
		printf("|==============================|");
		printf("\n Posição [%i]\n Título: %s\n Artista: %s\n Letra: %s\n Código: %i\n Execuções: %i\n ",p, aux->info->titulo, aux->info->artista, aux->info->letra, aux->info->codigo, aux->info->execucoes);
		printf("|==============================|\n");
		}
		aux = aux->prox;
	p++;
	}
printf("\n");
}

void conTitulo(desc_LSE *minhaLista, char *titulo){
	nodo_LSE *aux = (nodo_LSE *)malloc(sizeof(nodo_LSE));
	aux = minhaLista->LSE;
	int p=0;
	while(aux != NULL){
		if(strcmp(titulo,aux->info->titulo)==0){
		printf("|==============================|");
		printf("\n Posição [%i]\n Título: %s\n Artista: %s\n Letra: %s\n Código: %i\n Execuções: %i\n ",p, aux->info->titulo, aux->info->artista, aux->info->letra, aux->info->codigo, aux->info->execucoes);
		printf("|==============================|\n");
		}
		aux = aux->prox;
	p++;
	}
printf("\n");
}

void conArtista(desc_LSE *minhaLista, char *artista){
	nodo_LSE *aux = (nodo_LSE *)malloc(sizeof(nodo_LSE));
	aux = minhaLista->LSE;
	int p=0;
	while(aux != NULL){
		if(strcmp(artista,aux->info->artista)==0){
		printf("|==============================|");
		printf("\n Posição [%i]\n Título: %s\n Artista: %s\n Letra: %s\n Código: %i\n Execuções: %i\n ",p, aux->info->titulo, aux->info->artista, aux->info->letra, aux->info->codigo, aux->info->execucoes);
		printf("|==============================|\n");
		}
		aux = aux->prox;
	p++;
	}
printf("\n");
}

void conLetra(desc_LSE *minhaLista, char *letra){
	nodo_LSE *aux = (nodo_LSE *)malloc(sizeof(nodo_LSE));
	aux = minhaLista->LSE;
	int p=0;
	while(aux != NULL){
		if(strcmp(letra,aux->info->letra)==0){
		printf("|==============================|");
		printf("\n Posição [%i]\n Título: %s\n Artista: %s\n Letra: %s\n Código: %i\n Execuções: %i\n ",p, aux->info->titulo, aux->info->artista, aux->info->letra, aux->info->codigo, aux->info->execucoes);
		printf("|==============================|\n");
		}
		aux = aux->prox;
	p++;
	}
printf("\n");
}

