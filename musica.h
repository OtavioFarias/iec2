#ifndef MUSICA_H
#define MUSICA_H

typedef struct{
	char titulo[256];
	char artista[256];
	char letra[256];
	int codigo;
	int execucoes;
}musica;

typedef struct nodo{
	struct nodo *prox;
	musica *info;
}nodo_LSE;


typedef struct{
	nodo_LSE *LSE;
	int tamanho;
}desc_LSE;

nodo_LSE* criaNodo(musica *dados);

desc_LSE* criaDescritor();

void insere(desc_LSE *minhaLista, nodo_LSE *novoElemento, int posicao);

void imprime(desc_LSE *minhaLista);

/*desc_LSE * criaDescritor();
 * 

nodo* criaNodo(int novoDado);

desc_LSE * criaDescritor();

void removeLista(desc_LSE *minhaLista, int posicao);

void insere(desc_LSE *minhaLista, nodo *novo_elemento, int posicao);

int tamanho(desc_LSE *minhaLista);

void libera(desc_LSE *minhaLista);

void imprime(desc_LSE *minhaLista);
*/

#endif
