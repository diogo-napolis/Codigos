/*Este código em C implementa um programa que cria uma lista de números inteiros,constrói um heap mínimo a partir dessa lista e exibe tanto a lista quanto o heap mínimo resultante. 
 O código demonstra a construção de um heap mínimo a partir de diferentes tipos de listas (aleatória, crescente e decrescente) e exibe os resultados. 
 É uma implementação básica de estruturas de dados em C para demonstração educacional.
 
 Este código foi feito no terceiro semestre em aula na disciplina de Estrutura de Dados Lineares 
 Diogo Filipe Pereira Lopes de Nápolis
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Booleano.h"

#define maximo 50
#define maximo1 10

typedef struct {
	int comprimento;
	int Vetor[maximo];
} Lista;

typedef struct {
	int tamanho;
	int tab[maximo];
} Heap;

// Interface
Lista criarLista();
Heap criarHeap();
Lista construirListaTesteC(Lista );
Lista construirListaTesteD(Lista );
Lista constrListAleat(Lista );
void mostrarLista(Lista );
void construirHeapMinima(Heap *,Lista );
void mostrarHeapMinima(Heap *);



int main(){
	Lista A, B, C, D;
	Heap HM;
	
	//Com lista aleatoria
	A = criarLista();
	A = constrListAleat(A);
	printf("Lista Aleatoria: \n");
	mostrarLista(A);
	
	construirHeapMinima(&HM, A);
	mostrarHeapMinima(&HM);
	printf("-----------------------------------\n");

	//Com uma lista decrescente

	B = criarLista();
	B = construirListaTesteD(B);
	printf("Lista Decrescente: \n");
	mostrarLista(B);

	construirHeapMinima(&HM, B);
	mostrarHeapMinima(&HM);
	printf("-----------------------------------\n");

	//Com uma lista crescente

	C = criarLista(C);
	C = construirListaTesteC(C);
	printf("Lista Crescente: \n");
	mostrarLista(C);

	construirHeapMinima(&HM, C);
	mostrarHeapMinima(&HM);
	
	
	return 0;
}

Lista criarLista(){
	Lista L;
	L.comprimento = 0;
	
	return L;
}

Heap criarHeap(){
	Heap H;
	H.tamanho = 0;
	
	return H;
}

Lista construirListaTesteC(Lista L){
	int i;
	
	for(i = 0; i<5; i++){
		L.Vetor[i] = i;
		L.comprimento++;
	}
	return L;
}

Lista construirListaTesteD(Lista L){
	int i, j = 5;
	
	for(i = 0; i < 5; i++){
		L.Vetor[i] = j;
		L.comprimento++;
		j--;
	}
	return L;
}

Lista constrListAleat(Lista L){
	int i, rd, n;
	int listaNum[maximo1] = {0, 1, 2, 3, 4};
	int aux[maximo1] = {0};
	n = maximo1;
	srand((unsigned int) time(NULL));
	
	do{//repetir
		rd = rand() % n; //Rd = numero aleatorio de 1 a n
		aux[n - 1] = listaNum[rd];
		listaNum[rd] = listaNum[n - 1];
		listaNum[n - 1] = aux[n - 1];
		n = n-1;
	} while (n == 0);
	
	for (int i = 0; i < 10; i++) {
        L.Vetor[i] = listaNum[i];
        L.comprimento++;
    }
	
	return L;
}

void mostrarLista(Lista L){
	if(L.comprimento == 0){
		printf(" \nLista vazia!");
	}else{
		int i;
		int elem;
		printf("\n");
		for(i = 0; i<L.comprimento; i++){
			elem = L.Vetor[i];
			printf(" %d ", elem);
		}
	}
	printf("\n");
}

void mostrarHeapMinima(Heap *H){
	if(H->tamanho == 0){
		printf(" \nVazia! \n");
	}else{
		printf(" \nHeap Minima: \n");
		for(int i=1; i<=H->tamanho; i++){
			printf(" %d ", H->tab[i]);
		}
	}
	printf("\n");
}

void construirHeapMinima(Heap *H, Lista L){
	int i, tamL, elemento, temp, pai, descend;
	
	H->tamanho = 0;
	tamL = L.comprimento;
	
	for(i=1; i<=tamL; i++){
		elemento = L.Vetor[i-1];
		H->tab[i] = elemento;
		H->tamanho++;
		descend = H->tamanho;
		pai = descend/2;
		
		while((descend > 1) && (H->tab[pai] > H->tab[descend])){
			temp = H->tab[descend];
			H->tab[descend] = H->tab[pai];
			H->tab[pai] = temp;
			
			descend = pai;
			pai = descend/2;
		}
	}
}
