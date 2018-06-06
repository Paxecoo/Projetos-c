#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 50

typedef struct _produto{//criação de uma struct tipo produto
int cod;
char nome[TAM];
float preco;
}tp_produto;

typedef struct _pilha{//criação de uma struct tipo pilha
tp_produto *info;
int topo ;
}tp_pilha;

void cria(tp_pilha *p,int tamanho){//função que reserva memória para variáveis da struct

tp_produto *produtoV=(tp_produto*)malloc(tamanho*sizeof(tp_produto));
p->info=produtoV;
}

void push(tp_pilha *p ){
	tp_produto temp;
	printf("Digite o codigo do produto :\n");
	scanf("%d",&temp.cod);
	getchar();
	printf("Digite o nome do produto :\n");
	fgets(temp.nome,TAM,stdin);
	printf("Digite o valor do produto :\n");
	scanf("%f",&(temp.preco));
	p->topo++;
	*(p->info+p->topo)=temp;
}

void pop(tp_pilha *p){
	p->topo--;
}

void Listar(tp_pilha *p){
	int i;
	for(i=p->topo;i>-1;i--){
		printf("Produto : %d\n",(p->info+i)->cod);
		printf("Preço : %.2f\n",(p->info+i)->preco);
		printf("Nome : %s",(p->info+i)->nome);
	}

}

int main (){

	int menu , tamanho;
	tp_pilha *p;
	p->topo = -1;
	
	 printf("Digite o tamanho max de sua pilha :");
	 scanf("%d",&tamanho);

	 cria(p,tamanho);
	 do{
	 	printf("Inserir valor na pilha : 1\n");
	 	printf("Retirar valor da pilha : 2\n");
	 	printf("Listar valores da pilha : 3\n");
	 	printf("Sair : 0\n");
	 	scanf("%d",&menu);
	 	switch(menu) {
	 			case 1 :{				
	 				if(p->topo<tamanho){
	 				push(p);
	 				}
	 				else{
	 					printf("Lista cheia \n");
	 				}

	 				break;

	 			}
	 			case 2 :{
	 				pop(p);
	 				break;
	 			}
	 			case 3 :{
	 				Listar(p);
	 				break;
	 			}
	 			default : {
	 				break;
	 			}




	 	}


	 }while(menu!=0);
}