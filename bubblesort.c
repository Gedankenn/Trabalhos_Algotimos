#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000000
//bubblesort -- simplesmente encadeada

typedef struct notag{
	int chave;
	struct notag *prox;
}no;


typedef struct{
	no* inicio;
	no* final;
	int quant;
}LD;

void DefineS(LD *L){
	L->quant=0;
	L->inicio=NULL;
	L->final=NULL;
}

void inserefinal(LD *L, int ch){
	no *q, *p;
	q=L->inicio;
	if(q==NULL){
		p=malloc(sizeof(no));
		p->chave=ch;
		p->prox=NULL;
		L->inicio=p;
		L->final=p;
		L->quant++;
	}
	else{
		q=L->final;
		p=malloc(sizeof(no));
		q->prox=p;
		p->chave=ch;
		L->quant++;
		p->prox=NULL;
		L->final=p;
	}
}

void bubblesort(LD *L){
	no *p, *q;
	p=L->inicio;
	while(p->prox!=NULL){
		q=L->inicio;
		while(q->prox!=NULL){
			if(q->chave>q->prox->chave){
				int aux;
				aux=q->chave;
				q->chave=q->prox->chave;
				q->prox->chave=aux;
			}
			q=q->prox;
		}
		p=p->prox;
	}
}

void printa(LD *L){
	no *q;
	q=L->inicio;
	while(q!=NULL){
		printf("%d ",q->chave);
		q=q->prox;
	}
}

int main(void){
	LD lista;
	int cont, ch;
	clock_t Ti, Tf;
	float DeltaT;
	DefineS(&lista);

	srand((unsigned)time(NULL));

	for(cont=0;cont<MAX;cont++){
		ch=rand()%1000;
		inserefinal(&lista,ch);
	}
	printa(&lista);
	printf("\n");
	Ti=clock();
	bubblesort(&lista);
	Tf=clock();
	printa(&lista);
	DeltaT=Tf-Ti;
	DeltaT=DeltaT/1000;
	printf("com tempo de %f",DeltaT);

	return 0;
}