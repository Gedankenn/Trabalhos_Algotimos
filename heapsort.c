#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000000

void heapsort(int *a, int n)
{
 
   // by P.
   int i = n/2, pai, filho, t;
 
   for (;;)
   {
      if (i > 0)
      {
          i--;
          t = a[i];
      }
      else
      {
          n--;
          if (n == 0)
             return;
          t = a[n];
          a[n] = a[0];
      }
 
      pai = i;
 
      //Primeiro será feita a comparação com o filho da esquerda.
      filho = i*2;
 
      while (filho < n)
      {
         //Se o filho da esquerda for menor do que o filho da direita,então será feita a troca do filho que será comparado.
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t)
          {
             a[pai] = a[filho];
             pai = filho;
             filho = pai*2 + 1;
          }
          else
             break;
      }
      a[pai] = t;
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
		ch=rand()%1000000;
		vetor[cont]=ch;
	}


	/*for(cont=0;cont<MAX;cont++){
		printf("%d ",vetor[cont]);
	}*/
	printf("\n");
	Ti=clock();
	heapsort(vetor,MAX-1);
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