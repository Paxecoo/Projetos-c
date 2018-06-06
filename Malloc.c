#include <stdio.h>
#include <stdlib.h>

int main(){
	int i , temp , temp2 ;
	puts("Digite o numero de valores inteiros que deseja alocar dinamicamente :");
	scanf("%d",&temp2);
	int*p=(int*)malloc(temp2*sizeof(int));
	for(i=0;i<temp2;i++){
		puts("Digite o primeiro valor inteiro :");
		scanf("%d",(p+temp));
		temp++;
	}
	for(i=0;i<temp2;i++){
		printf("\no valor de p é : %d\n",(*p));
		p++;
	}
	free(p);
}