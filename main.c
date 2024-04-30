#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "musica.h"

int main(){
	nodo *novoNodo=NULL;
	novoNodo=(nodo *)malloc(sizeof(nodo));
	desc_LSE *novaLista=NULL;
	novaLista=(desc_LSE *)malloc(sizeof(desc_LSE));
	int k=-1, i,posicao;
	while(k!=0){
		printf("\n 1-Criar lista\n 2-Inserir\n 3-Remover\n 4-Consultar\n 5-Imprimir\n\t");
		setbuf(stdin,NULL);
		scanf("%i", &k);
		switch(k){
			case 1:
			novaLista=criaDescritor();
			break;
			case 2:
			printf("Digite o nome da música");
			setbuf(stdin,NULL);
			scanf("%i", &i);
			novoNodo = criaNodo(i);
			setbuf(stdin,NULL);
			scanf("%i", &posicao);
			insere(novaLista,novoNodo,posicao);
			break;
			case 3:
			imprime(novaLista);
			break;
			case 4:
			printf("digite a posicao da remocao\n");
			setbuf(stdin,NULL);
			scanf("%d",&posicao);
			removeLista(novaLista,posicao);
			break;
			case 5:
			printf("oi");
			
			break;
		}
		}
return 0;
}
