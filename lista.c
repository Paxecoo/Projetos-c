#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define TAM 100


typedef struct produto{

	int codigo;
	char nome[TAM];
	float preco;

}tp_produto;

typedef struct nodo{

	tp_produto produto;
	struct nodo *prox;

}nodo;

typedef struct list{
	int size; 
	nodo* no;

}List;

List * criaLista(){
	List *lista =(List*)malloc(sizeof(List));

	lista->size = 0;
	lista->no = NULL;

	return lista;
}
void push(List* lista);
void listar(List* lista);
void pop(List* lista);
nodo* buscarNodo(List* lista , int index);
void apagar(List* lista);

void push(List * lista){

	nodo* nodos =(nodo*)malloc(sizeof(nodo));
	tp_produto prod;

	printf("Digite o codigo do produto:\n");
	scanf("%d",&prod.codigo);
	printf("Digite o nome do produto :\n");
	getchar();
	fgets(prod.nome,TAM,stdin);
	printf("Digite o preço :\n");
	scanf("%f",&prod.preco);

	nodos->produto=prod;
	nodos->prox=lista->no;
	lista->no=nodos;
	lista->size++;	

}

void listar(List* lista){
	nodo* pointer = lista->no;
	int i=0;
	while(pointer!=NULL){
		printf("indice %d \nNome : %s\nCodigo : %d\nPreço : %.2f\n",i,pointer->produto.nome,pointer->produto.codigo,pointer->produto.preco);
		pointer=pointer->prox;
		i++;

	}
}

void pop(List* lista){
	
	nodo* aponta;
	aponta=lista->no;
	lista->no=aponta->prox;
	free(aponta);
	lista->size--;
}

nodo* buscarNodo(List* lista,int index){
	int i;
	if(index>=0 && index < lista->size){
		nodo* aponta =lista->no;
		for(i=0;i<index;i++)
			aponta=aponta->prox;
			
		
		return aponta;
	}
	
		return NULL;

}

void apagar(List* lista ){
	int temp,temp2;
	printf("Conferindo com os valores listados na op3 , insira o indice do valor que deseja retirar da lista :\n");
	scanf("%d",&temp);
	if(temp == 0){
		pop(lista);
	}
	else{
		nodo* apagar = buscarNodo(lista,temp);
		
		temp2=temp-1;
		printf("%d",temp2);
		nodo* trocar = buscarNodo(lista,temp2);
		printf("%d",trocar->produto.codigo);
			trocar->prox=apagar->prox;
			free(apagar);
			lista->size--;
		
		
	}

}

int main(){
	List *lista=criaLista();
	
	int menu;
	do{
	printf("Digite 1 para inserir um produto na lista :\n");
	printf("Digite 2 para excluir um elemento da lista :\n");
	printf("Digite 3 para listar todos os campos da lista :\n");
	printf("Digite 0 para sair :\n");
	scanf("%d",&menu);
	switch (menu) {
		case 1 :{
			
			push(lista);
			break;
		}
		case 2:{
			
			apagar(lista);
			break;
		}
		case 3:{
			listar(lista);
			break;
		}
		default :{
			break;
		}

	}
	}while(menu!=0);
}