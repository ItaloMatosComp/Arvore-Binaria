#include <stdio.h>
#include <stdlib.h> 
#include "arvoreBinaria.h"

typedef struct arvore{
	int chave;
	struct arvore *filhoEsq;
	struct arvore *filhoDir;
}arvoreBinaria;


arvoreBinaria* novoNo(int dado){
	arvoreBinaria* no = malloc(sizeof(arvoreBinaria));
	no->chave = dado;
	no->filhoEsq = NULL;
	no->filhoDir = NULL;
	return no;
}

arvoreBinaria* inserir(arvoreBinaria* no, int dado){
	if(no==NULL){
		return novoNo(dado);
	}
	else{
		if(dado <= no->chave) no->filhoEsq = inserir(no->filhoEsq, dado);
		else no->filhoDir = inserir(no->filhoDir, dado);
	}
	return no;
}

void imprimirInOrder(arvoreBinaria* arvore){
	//InOrder: impressao da esquerda para a direita
	if(arvore==NULL) return;
	imprimirInOrder(arvore->filhoEsq);
	printf("%d ", arvore->chave);
	imprimirInOrder(arvore->filhoDir);
}

void imprimirPosOrder(arvoreBinaria* arvore){
	//PosOrder: imprime esquerda, depois direita, e depois a raiz
	if(arvore==NULL) return;
	imprimirPosOrder(arvore->filhoEsq);
	imprimirPosOrder(arvore->filhoDir);
	printf("%d ", arvore->chave);
}

void imprimirPreOrder(arvoreBinaria* arvore){
	if(arvore==NULL) return;
	printf("%d ", arvore->chave);
	imprimirPreOrder(arvore->filhoEsq);
	imprimirPreOrder(arvore->filhoDir);
}

int menor(arvoreBinaria* arvore){
    while(arvore->filhoEsq!=NULL){
        arvore = arvore->filhoEsq;
    }
    return arvore->chave;
}

int maior(arvoreBinaria* arvore){
    while (arvore->filhoDir != NULL){
        arvore = arvore->filhoDir;
    }
    return arvore->chave;
}

arvoreBinaria* espelho(arvoreBinaria* raiz){
	if(raiz==NULL){
		return raiz;
	}
	else{
		arvoreBinaria* aux;
		espelho(raiz->filhoEsq);
		espelho(raiz->filhoDir);

		aux = raiz->filhoEsq;
		raiz->filhoEsq = raiz->filhoDir; //para uma mesma raiz, seus filhos sao trocados
		raiz->filhoDir = aux;
	}
}

int busca(arvoreBinaria* raiz, int valor){
	if(raiz==NULL){
		return 0;
	}
	else{
		if(raiz->chave == valor){
			return 1;
		}
		else{
			if(valor <=raiz->chave) return busca(raiz->filhoEsq, valor);
			else return busca(raiz->filhoDir, valor);
		}
	}
}

int contaFolhas(arvoreBinaria* raiz){
	if(raiz==NULL){
		return 0;
	}
	else{
		if(raiz->filhoDir==NULL && raiz->filhoEsq==NULL){
			return 1;
		}
		return (contaFolhas(raiz->filhoDir)+contaFolhas(raiz->filhoEsq));
	}
}

arvoreBinaria* minimo(arvoreBinaria* raiz){
	if(raiz->filhoEsq == raiz->filhoDir && raiz == NULL) return NULL; // arvore vazia
	else{
		while(raiz->filhoEsq != NULL){
			raiz = raiz->filhoEsq;
		}
	}
	return raiz;
}

int verificaBusca(arvoreBinaria* raiz){
	if(raiz==NULL){
		return 1; //verdadeiro
	}
	if(raiz->filhoEsq!=NULL && maior(raiz->filhoEsq) > raiz->chave){
		return 0; //falso
	}
	if(raiz->filhoDir!=NULL && menor(raiz->filhoDir) <= raiz->chave){
		return 0;
	}
	if(!verificaBusca(raiz->filhoEsq) || !verificaBusca(raiz->filhoDir)){
		return 0;
	}
	return 1;
}



int existeChaveNegativa(arvoreBinaria* raiz){
	while(raiz->filhoEsq!=NULL){
		raiz = raiz->filhoEsq;
	}
	if(raiz->chave <0) return 1;
	else return 0;
	// 1 verdadeiro: sim, existe chave negativa
	//0 falso: nao, sem chave negativa
}

int altura(arvoreBinaria* raiz){
    if (raiz==NULL)
        return 0;
    else{
        int altEsq = altura(raiz->filhoEsq);
        int altDir = altura(raiz->filhoDir);
        if (altEsq > altDir) return(altEsq+1);
        else return(altDir+1);
    }
}

void imprimirNivel(arvoreBinaria* raiz, int nivel){
    if (raiz == NULL)
        return;
    if (nivel == 1)
        printf("%d\n", raiz->chave);
    else if (nivel > 1)
    {
        imprimirNivel(raiz->filhoEsq, nivel-1);
        imprimirNivel(raiz->filhoDir, nivel-1);
    }
}

void largura(arvoreBinaria* raiz){
    int h = altura(raiz);
    int i;
    for (i=1; i<=h; i++) imprimirNivel(raiz, i);
}


// int main(){
// 	arvoreBinaria* raiz;
// 	raiz = inserir(raiz, 6);
//     inserir(raiz, 4);
//     inserir(raiz, 2);
//     inserir(raiz, 5);
//     inserir(raiz, 8);
//     inserir(raiz, 3);
//     inserir(raiz, 7);
//     imprimirInOrder(raiz);
//     printf("\n");
//     largura(raiz);
// }
 //       6 
 //    4     8
 //  2   5 7 
 //   3