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
	struct _nodo *next;
	struct _nodo *prev;
} TpNodo;

typedef struct _lista{
	int nItens;
	TpNodo *first;
	TpNodo *last;
} TpLista;

TpLista* CriaLista(){
	TpLista* Lista=(TpLista*)malloc(sizeof(TpLista));
	Lista->nItens=0;
	Lista->first=NULL;
	Lista->last=NULL;

	return Lista;
}

void pushI(TpLista* Lista){
	TpNodo* no=(TpNodo*)malloc(sizeof(TpNodo));

	no->next=NULL;
	no->prev=NULL;

	TpProduto temp;
	puts("Digite o codigo do produto :");
	scanf("%d",&temp.codigo);
	puts("Digite o nome do produto :");
	getchar();
	fgets(temp.nome,20,stdin);
	puts("Digite o valor :");
	scanf("%f",&temp.preco);
	no->info=temp;

		if(Lista->first==NULL){
			Lista->first=no;
			Lista->last=no;
			Lista->nItens++;
		}

		else{
			Lista->first->prev=no;
			no->next=Lista->first;
			Lista->first=no;
			Lista->nItens++;
		}

}
void pushE(TpLista* Lista){
	TpNodo* no =(TpNodo*)malloc(sizeof(TpNodo));

	no->next=NULL;
	no->prev=NULL;

	TpProduto temp;
	puts("Digite o codigo do produto :");
	scanf("%d",&temp.codigo);
	puts("Digite o nome do produto :");
	getchar();
	fgets(temp.nome,20,stdin);
	puts("Digite o valor :");
	scanf("%f",&temp.preco);
	no->info=temp;

	if(Lista->first==NULL){
		Lista->first=no;
		Lista->last=no;
	}
	else{
		Lista->last->next=no;
		no->prev=Lista->last;
		Lista->last=no;
	}
}

void imprime(TpLista *Lista){
	TpNodo* temp;
	if(Lista->first==NULL)
		puts("Lista vazia !");
	else{
		temp=Lista->first;
		do{
			printf("Codigo : %d\nNome : %s\nPreco : %.2f\n",temp->info.codigo,temp->info.nome,temp->info.preco);
			temp=temp->next;
		}while(temp!=NULL);
	}
}

TpNodo* Buscar(TpLista* Lista, int temp1){
	int i;
	TpNodo* temp2;
	
	temp2=Lista->first;
	for(i=1;i<=Lista->nItens;i++){
		if(temp2->info.codigo==temp1)
			return temp2;

		temp2=temp2->next;
	}
	return NULL;

}

void popI(TpLista* Lista){
	int temp1;
	puts("Digite o codigo do produto que deseja encontrar :");
	scanf("%d",&temp1);
	TpNodo* no=Buscar(Lista,temp1);
	TpNodo* noprev;
	TpNodo* nonext;
		if(no!=NULL){
			if(no->prev==NULL){
				nonext=no->next;
				nonext->prev=no->prev;
				Lista->first=nonext;
				Lista->nItens--;
				free(no);
			}
			if(no->next==NULL){
				noprev=no->prev;
				noprev->next=no->next;
				Lista->last=noprev;
				Lista->nItens--;
				free(no);
			}
			if(no->prev!=NULL && no->next!=NULL){
				noprev=no->prev;
				nonext=no->next;
				noprev->next=no->next;
				nonext->prev=no->prev;
				Lista->nItens--;
				free(no);

			}
		}

}

int main(){
	TpLista* Lista=CriaLista();
	int menu1,menu2;
	do{
		puts("Digite 1 para inserir :");
		puts("Digite 2 para Listar :");
		puts("Digite 3 para apagar :");
		puts("Digite 0 para sair :");
		scanf("%d",&menu1);
		switch(menu1){
			case 1:{
				do{
					puts("1 para inserir do inicio :");
					puts("2 para inserir no final :");
					puts("0 para voltar :");
					scanf("%d",&menu2);
					switch(menu2){
						case 1:{pushI(Lista);
							menu2=0;
							break;
						}
						case 2:{
							pushE(Lista);
							menu2=0;
							break;
						}
						default:{
							puts("erro");
							menu2=0;
							break;
						}
					}

				}while(menu2!=0);
				break;
			}
			case 2:{
				imprime(Lista);
				break;
			}
			case 3:{
				popI(Lista);
				break;
			}
			default :{
				puts("Erro !");
				break;
			}

		}

	}while(menu1!=0);
}
