#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int *valor, int esquerda, int direita)
{
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = valor[(esquerda + direita) / 2];
 
    while(i <= j)
    {
        while(valor[i] < x && i < direita)
        {
            i++;
        }
        while(valor[j] > x && j > esquerda)
        {
            j--;
        }
        if(i <= j)
        {
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }
    if(j > esquerda)
    {
        quickSort(valor, esquerda, j);
    }
    if(i < direita)
    {
        quickSort(valor,  i, direita);
    }
}

void merge (int *a, int n, int m) {
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    free(x);
}
 
void merge_sort (int *a, int n) {
    if (n < 2)
        return;
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}

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

void shellSort(int *vet, int size) {
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
        }
    }
}
int* copiavetor(int *vet, int max){
  int cont;
  int *q;
  q=malloc(sizeof(int) * max);
  for(cont=0;cont<max;cont++){
    q[cont]=vet[cont];
  }
  return q;
}

int main(void){
    int *vetor1,*q, *vetorinverso;
	  int cont, cont2, media, cont3, cont4;
    float tempo1, tempo2, tempo3, tempo4;
  	int MAX=100000;
  	clock_t Ti, Tf;
  	float DeltaT;

	  srand((unsigned)time(NULL));
    for(cont=0;cont<10;cont++){
      vetor1=malloc(sizeof(int) * MAX);
      vetorinverso=malloc(sizeof(int) * MAX);
      tempo1=0;
      tempo2=0;
      tempo3=0;
      tempo4=0;
      for(cont2=0;cont2<10;cont2++){
        for(cont3=0;cont3<MAX;cont3++){
          vetor1[cont3]=rand() % MAX;
         }
        q=copiavetor(vetor1,MAX);
        Ti=clock();
        quickSort(q,0,MAX-1);
        Tf=clock();
        DeltaT=Tf-Ti;
        DeltaT=DeltaT/1000;
        tempo1=tempo1+DeltaT;
        //free(q);

        q=copiavetor(vetor1,MAX);
        Ti=clock();
        merge_sort(q,MAX-1);
        Tf=clock();
        DeltaT=Tf-Ti;
        DeltaT=DeltaT/1000;
        tempo2=tempo2+DeltaT;
        //free(q);

        q=copiavetor(vetor1,MAX);
        Ti=clock();
        heapsort(q,MAX-1);
        Tf=clock();
        DeltaT=Tf-Ti;
        DeltaT=DeltaT/1000;
        tempo3=tempo3+DeltaT;
        //free(q);

        q=copiavetor(vetor1,MAX);
        Ti=clock();
        shellSort(q,MAX-1);
        Tf=clock();
        DeltaT=Tf-Ti;
        DeltaT=DeltaT/1000;
        tempo4=tempo4+DeltaT;

      }
      cont4=0;
      for(cont3=MAX-1;cont3>=0;cont3--){
          vetorinverso[cont4]=cont3;
          cont4++;
         }
      printf("tabela com vetores de tamanho: %d\n\n",MAX);
      printf("quicksort\n");
      Ti=clock();
      quickSort(q,0,MAX-1);
      Tf=clock();
      DeltaT=Tf-Ti;
      DeltaT=DeltaT/1000;
      printf("tempo ordenacao: %f\n",(tempo1/10));
      printf("tempo vetor ja ordenado: %f\n",DeltaT);
      q=copiavetor(vetorinverso,MAX);
      Ti=clock();
      quickSort(q,0,MAX-1);
      Tf=clock();
      DeltaT=Tf-Ti;
      DeltaT=DeltaT/1000;
      printf("tempo vetor decrescente: %f\n",DeltaT);

      printf("mergesort\n");
      Ti=clock();
      merge_sort(q,MAX-1);
      Tf=clock();
      DeltaT=Tf-Ti;
      DeltaT=DeltaT/1000;
      printf("tempo ordenacao: %f\n",tempo2/10);
      printf("tempo vetor ja ordenado: %f\n",DeltaT);
      q=copiavetor(vetorinverso,MAX);
      Ti=clock();
      merge_sort(q,MAX-1);
      Tf=clock();
      DeltaT=Tf-Ti;
      DeltaT=DeltaT/1000;
      printf("tempo vetor decrescente: %f\n",DeltaT);

      printf("heapsort\n");
      Ti=clock();
      heapsort(q,MAX-1);
      Tf=clock();
      DeltaT=Tf-Ti;
      DeltaT=DeltaT/1000;
      printf("tempo ordenacao: %f\n",tempo3/10);
      printf("tempo vetor ja ordenado: %f\n",DeltaT);
      q=copiavetor(vetorinverso,MAX);
      Ti=clock();
      heapsort(q,MAX-1);
      Tf=clock();
      DeltaT=Tf-Ti;
      DeltaT=DeltaT/1000;
      printf("tempo vetor decrescente: %f\n",DeltaT);

      printf("shellsort\n");
      Ti=clock();
      shellSort(q,MAX-1);
      Tf=clock();
      DeltaT=Tf-Ti;
      DeltaT=DeltaT/1000;
      printf("tempo ordenacao: %f\n",tempo4/10 );
      printf("tempo vetor ja ordenado: %f\n",DeltaT);
      q=copiavetor(vetorinverso,MAX);
      Ti=clock();
      shellSort(q,MAX-1);
      Tf=clock();
      DeltaT=Tf-Ti;
      DeltaT=DeltaT/1000;
      printf("tempo vetor decrescente: %f\n",DeltaT);
      free(q);
      free(vetor1);
      free(vetorinverso);
      MAX=MAX+100000;
    }
}