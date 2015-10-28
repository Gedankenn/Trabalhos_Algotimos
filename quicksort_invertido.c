#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
//quicksort com ponteiros...

void quickSort_invertido(int *valor, int esquerda, int direita)
{
int i, j, x, y;
    i = direita;
    j = esquerda;
    x = valor[(esquerda + direita) / 2];
 
    while(i >= j)
    {
        while(valor[i] < x && i < direita)
        {
            i++;
        }
        while(valor[j] > x && j > esquerda)
        {
            j--;
        }
        if(i >= j)
        {
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }
    if(j < esquerda)
    {
        quickSort_invertido(valor, esquerda, j);
    }
    if(i > direita)
    {
        quickSort_invertido(valor,  i, direita);
    }
}

int main(void){
	int *vetor;
	int cont, ch;
	clock_t Ti, Tf;
	float DeltaT;

	srand((unsigned)time(NULL));
	 vetor=malloc(sizeof(int) * MAX);

	for(cont=0;cont<MAX;cont++){
		ch=rand()%10;
		vetor[cont]=ch;
	}


    for(cont=0;cont<MAX;cont++){
		printf("%d ",vetor[cont]);
	}
	printf("\n");
	Ti=clock();
	quickSort_invertido(vetor,0,MAX-1);
	Tf=clock();
	for(cont=0;cont<MAX;cont++){
		printf("%d ",vetor[cont]);
	}
	DeltaT=Tf-Ti;
	DeltaT=DeltaT/1000;
	printf("\ncom tempo de %f",DeltaT);
	free(vetor);
	return 0;
}