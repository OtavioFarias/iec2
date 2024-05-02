#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "musica.h"

int main(){
	nodo_LSE *novoNodo=NULL;
	novoNodo=(nodo_LSE *)malloc(sizeof(nodo_LSE));
	desc_LSE *novaLista=NULL;
	novaLista=(desc_LSE *)malloc(sizeof(desc_LSE));
	musica *info=NULL;
	info=(musica *)malloc(sizeof(musica));
	int k=-1,posicao;
	while(k!=6){
		printf("|==============================|");
		printf("\n 1-Criar lista\n 2-Inserir\n 3-Remover\n 4-Consultar\n 5-Imprimir\n 6-Sair\n");
		printf("|==============================|\n\t");
		setbuf(stdin,NULL);
		scanf("%i", &k);
		switch(k){
			case 1:
			novaLista=criaDescritor();
			break;
			case 2:
			info=cadastrar();
			novoNodo=criaNodo(info);
			printf("Qual a posição a ser inserida? ");
			setbuf(stdin,NULL);
			scanf("%i", &posicao);
			insere(novaLista,novoNodo,posicao);
			break;
			
			case 5:
			imprime(novaLista);
			break;
			
			case 3:
			setbuf(stdin,NULL);
			printf("\nDigite a posicao da remoção: ");
			scanf("%d",&posicao);
			removeLista(novaLista,posicao);
			break;
			
			case 4:
				int a, j;
				char *l=NULL;
				l=(char *)malloc(256*sizeof(char));
				printf("Gostaria de consultar baseado em? [1=Título, 2-Artista, 3-Letra, 4-Código, 5-Execuções]\n\t");
				setbuf(stdin,NULL);
				scanf("%i", &a);
				switch(a){
				
				case 1:
				printf("QUal o título? ");
				setbuf(stdin,NULL);
				fgets(l,256,stdin);
				conTitulo(novaLista, l);
				break;
			
				case 2:
				printf("QUal o artista? ");
				setbuf(stdin,NULL);
				fgets(l,256,stdin);
				conArtista(novaLista, l);
				break;
				
				case 3:
				printf("QUal a letra? ");
				setbuf(stdin,NULL);
				fgets(l,256,stdin);
				conLetra(novaLista, l);
				break;
				
				case 4:
				printf("QUal o código? ");
				setbuf(stdin,NULL);
				scanf("%i", &j);
				conCodigo(novaLista, j);
				break;
				
				case 5:
				printf("QUal o número de execuções? ");
				setbuf(stdin,NULL);
				scanf("%i", &j);
				conExecucoes(novaLista, j);
				break;
				
				default:
				printf("\nOpção Inválida");
				break;
				}
				
			free(l);
			break;
			
			case 6:
			printf("\n|======================|\n  sPrograma finalizado\n|======================|\n");
			break;
			default:
			printf("\nOpção inválida\n");
		}
		}
return 0;
}
