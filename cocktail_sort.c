#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 400000

void cocktail_sort(int *list, int tam) {
    int length,bottom,top, swapped,i,aux;
    length=tam;
    bottom = 0;
    top = length - 1;
    swapped = 0; 
    while(swapped == 0 && bottom < top)//Se não houver troca de posições ou o ponteiro que
    {                                   //sobe ultrapassar o que desce, o vetor esta ordenado
        swapped = 1; 
        //Este for é a “ida” para a direita
        for(i = bottom; i < top; i = i + 1)
        {
            if(list[i] > list[i + 1])   //indo pra direita:testa se o próximo é maior
            {   //indo pra direita:se o proximo é maior que o atual,
                //troca as posições
                aux=list[i];
                list[i]=list[i+1];
                list[i+1]=aux;
                swapped = 0;
            }
        }//fecha for
        // diminui o  `top` porque o elemento com o maior valor 
        // já está na direita (atual posição top)
        top = top - 1; 
        //Este for é a “ida” para a esquerda
        for(i = top; i > bottom; i = i - 1)
        {  if(list[i] < list[i - 1]) 
            {
                aux=list[i];
                list[i]=list[i-1];
                list[i-1]=aux;
                swapped = 0;
            }
        }
        //aumenta o `bottom` porque o menor valor já está
        //na posição inicial (bottom) 
        bottom = bottom + 1;  
    }//fecha while 
 }// fim da funçao

int main(void){
	int *vetor;
	int cont, ch;
	clock_t Ti, Tf;
	float DeltaT;

	srand((unsigned)time(NULL));
	 vetor=malloc(sizeof(int) * MAX);

	for(cont=0;cont<MAX;cont++){
		ch=rand()%1000000;
		vetor[cont]=ch;
	}

	printf("\n");
	Ti=clock();
	cocktail_sort(vetor,MAX-1);
	Tf=clock();
	/*for(cont=0;cont<MAX;cont++){
		printf("%d ",vetor[cont]);
	}*/
	DeltaT=Tf-Ti;
	DeltaT=DeltaT/1000;
	printf("\ncom tempo de %f",DeltaT);
	free(vetor);
	return 0;
}