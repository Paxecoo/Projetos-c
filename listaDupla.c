#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct _produto{
	int codigo;
	char nome[20];
	float preco;
} TpProduto;

typedef struct _nodo{
	TpProduto info;
	struct _nodo *first;
	struct _nodo *last;
} TpNodo;

typedef struct _lista{
	int nItens;
	TpNodo *first;
	TpNodo *last;
} TpLista;

TpLista* criarLista(){
	TpLista* Lista=(TpLista*)malloc(sizeof(TpLista));
	Lista->nItens=0;
	Lista->first=NULL;
	Lista->last=NULL;

	return Lista;
}

void push(TpLista *Lista){
	TpNodo* nodo=(TpNodo*)malloc(sizeof(TpNodo));
	TpProduto temp;
	puts("Digite o codigo do produto :");
	scanf("%d",&temp.codigo);
	puts("Digite o nome do produto :");
	getchar();
	fgets(temp.nome,20,stdin);
	puts("Digite o valor :");
	scanf("%f",&temp.preco);
	if(Lista->nItens == 0){
	nodo->info=temp;
	nodo->first=Lista->first;
	nodo->last=Lista->last;
	Lista->first=nodo;
	Lista->last=nodo;
	Lista->nItens++;
	}
	else{
		nodo->info=temp;
		nodo->first=NULL;
		nodo->last=Lista->first;
		Lista->first=nodo;
		Lista->nItens++;
	}

}

int main(){
	TpLista* l1=criarLista();
	push(l1);

}