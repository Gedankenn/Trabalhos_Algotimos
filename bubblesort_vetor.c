#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200000

void bubble_sort(int *list, long n)
{
  long c, d, t;
 
  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (list[d] > list[d+1])
      {
        /* Swapping */
 
        t         = list[d];
        list[d]   = list[d+1];
        list[d+1] = t;
      }
    }
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
	}
	printf("\n");*/
	Ti=clock();
	bubble_sort(vetor,MAX);
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