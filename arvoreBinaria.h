#include <stdio.h>
#include <stdlib.h> 

typedef struct arvore arvoreBinaria;

arvoreBinaria* novoNo(int dado);

arvoreBinaria* inserir(arvoreBinaria* no, int dado);

void imprimirInOrder(arvoreBinaria* arvore);

void imprimirPosOrder(arvoreBinaria* arvore);

void imprimirPreOrder(arvoreBinaria* arvore);

int menor(arvoreBinaria* arvore);

int maior(arvoreBinaria* arvore);

arvoreBinaria* espelho(arvoreBinaria* raiz);

int busca(arvoreBinaria* raiz, int valor);

int contaFolhas(arvoreBinaria* raiz);

arvoreBinaria* minimo(arvoreBinaria* raiz);

int verificaBusca(arvoreBinaria* raiz);

int existeChaveNegativa(arvoreBinaria* raiz);

int altura(arvoreBinaria* raiz);

void imprimirNivel(arvoreBinaria* raiz, int nivel);

void largura(arvoreBinaria* raiz);
