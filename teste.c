#include <stdio.h>
#include <stdlib.h> 
#include "arvoreBinaria.h"

void exercicios(arvoreBinaria* raiz){
	printf("*******Exercicios*******\n");
	printf("Funcao minimo: ");
    imprimirInOrder(minimo(raiz));
    printf("\n");
    if(existeChaveNegativa(raiz)==1){
    	printf("Existe chave negativa na arvore.\n");
    }
    else{
    	printf("Nao existe chave negativa na arvore.\n");
    }
    if(verificaBusca(raiz)==1){
    	printf("É arvore binaria.\n");
    }
    else{
    	printf("Nao é arvore binaria.\n");
    }

    printf("Impressao em largura: ");
    largura(raiz);
    printf("\n");

    printf("Quantidade de folhas: %d\n", contaFolhas(raiz));

    printf("Impressao espelhada: \n");
    imprimirInOrder(espelho(raiz));
    printf("\n");

    int valorBuscado = 10;
    printf("Valor a ser buscado: %d\n", valorBuscado);
    if(busca(raiz, valorBuscado)==1){
    	printf("A arvore possui o valor buscado\n");
    }
    else{
    	printf("A arvore nao possui o valor buscado.\n");
    }

}

int main(){
	arvoreBinaria* raiz;
	//criada uma arvore para teste
	raiz = inserir(raiz, 6);
    inserir(raiz, 4);
    inserir(raiz, 4);
    inserir(raiz, 4);
    inserir(raiz, 2);
    inserir(raiz, 5);
    inserir(raiz, 8);
    inserir(raiz, 3);
    inserir(raiz, 7);
    inserir(raiz, -2);
    printf("Impressa In Order:" );
    imprimirInOrder(raiz);
    printf("\n");
    exercicios(raiz);

    printf("\n");
}