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

void bubblesort(int *vetor, int num){
  int a,b,aux;
  for(a=0;a<num-1;a++){
    for(b=0;b<num-a-1;b++){
      if(vetor[b]>vetor[b+1]){
        aux=vetor[b];
        vetor[b]=vetor[b+1];
        vetor[b+1]=aux;
      }
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
	  int cont, cont2, media, cont3, cont4, cont5;
    float tempo1, tempo2, tempo3, iteracoes=10;
  	int MAX=1000;
  	clock_t Ti, Tf;
  	float DeltaT;
    cont5=0;

    FILE *txt;


    txt=fopen("data2.txt","a+");


	  srand((unsigned)time(NULL));
    fprintf(txt,"tamanho,quicksort_ordenacao,quicksort_jaordenado,quicksort_decrescente,mergesort_ordenacao,mergesort_jaordenado,mergesort_decrescente,bublesort_ordenacao,bublesort_jaordenado,bublesort_decrescente\n");
    for(cont=0;cont<6;cont++){
      vetor1=malloc(sizeof(int) * MAX);
      vetorinverso=malloc(sizeof(int) * MAX);
      tempo1=0;
      tempo2=0;
      tempo3=0;
      for(cont2=0;cont2<iteracoes;cont2++){
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
        free(q);

        q=copiavetor(vetor1,MAX);
        Ti=clock();
        merge_sort(q,MAX-1);
        Tf=clock();
        DeltaT=Tf-Ti;
        DeltaT=DeltaT/1000;
        tempo2=tempo2+DeltaT;
        free(q);

        q=copiavetor(vetor1,MAX);
        Ti=clock();
        bubblesort(q,MAX-1);
        Tf=clock();
        DeltaT=Tf-Ti;
        DeltaT=DeltaT/1000;
        tempo3=tempo3+DeltaT;

      }
      cont4=0;
      for(cont3=MAX-1;cont3>=0;cont3--){
          vetorinverso[cont4]=cont3;
          cont4++;
         }
      fprintf(txt,"%d,",MAX);
      //printf("quicksort;");
      Ti=clock();
      quickSort(q,0,MAX-1);
      Tf=clock();
      DeltaT=Tf-Ti;
      DeltaT=DeltaT/1000;
      fprintf(txt,"%f,",(tempo1/iteracoes));
      fprintf(txt,"%f,",DeltaT);
      free(q);
      q=copiavetor(vetorinverso,MAX);
      Ti=clock();
      quickSort(q,0,MAX-1);
      Tf=clock();
      DeltaT=Tf-Ti;
      DeltaT=DeltaT/1000;
      fprintf(txt,"%f,",DeltaT);

      //printf("mergesort\n");
      Ti=clock();
      merge_sort(q,MAX-1);
      Tf=clock();
      DeltaT=Tf-Ti;
      DeltaT=DeltaT/1000;
      fprintf(txt,"%f,",tempo2/iteracoes);
      fprintf(txt,"%f,",DeltaT);
      free(q);
      q=copiavetor(vetorinverso,MAX);
      Ti=clock();
      merge_sort(q,MAX-1);
      Tf=clock();
      DeltaT=Tf-Ti;
      DeltaT=DeltaT/1000;
      fprintf(txt,"%f,",DeltaT);

      //printf("bublesort\n");
      Ti=clock();
      bubblesort(q,MAX-1);
      Tf=clock();
      DeltaT=Tf-Ti;
      DeltaT=DeltaT/1000;
      fprintf(txt,"%f,",tempo3/iteracoes);
      fprintf(txt,"%f,",DeltaT);
      free(q);
      q=copiavetor(vetorinverso,MAX);
      Ti=clock();
      bubblesort(q,MAX-1);
      Tf=clock();
      DeltaT=Tf-Ti;
      DeltaT=DeltaT/1000;
      fprintf(txt,"%f,",DeltaT);
      free(q);
      free(vetor1);
      free(vetorinverso);
      if(cont5==0){
        MAX=5000;
      }
      if(cont5==1){
        MAX=10000;
      }
      if(cont5==2){
        MAX=100000;
      }
      if(cont5==3){
        MAX=500000;
      }
      if(cont5==4){
        MAX=1000000;
      }
      cont5++;
      fprintf(txt,"\n");
    }
    return 0;
}