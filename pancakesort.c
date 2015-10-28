#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 500000

void do_flip(int *list, int length, int num)
{
    int swap;
    int i=0;
    for(i;i<--num;i++)
    {
        swap=list[i];
        list[i]=list[num];
        list[num]=swap;
    }
}

void pancake_sort(int *list, unsigned int length)
{
    //If it's less than 2 long, just return it as sorting isn't really needed...
    
    int i,a,max_num_pos,moves;
 
    for(i=length;i>1;i--)
    {
        //Find position of the max number in pos(0) to pos(i)
        max_num_pos=0;
        for(a=0;a<i;a++)
        {
            if(list[a]>list[max_num_pos])
                max_num_pos=a;
        }
 
        if(max_num_pos==i-1)
            //It's where it need to be, skip
           
 
 
        //Get the found max number to the beginning of the list (unless it already is)
        if(max_num_pos)
        {
            
            do_flip(list, length, max_num_pos+1);
        }
 
 
        //And then move it to the end of the range we're working with (pos(0) to pos(i))
        
        do_flip(list, length, i);
 
        //Then everything above list[i-1] is sorted and don't need to be touched
 
    }
 
   
}

int main(void){
	int *vetor;
	int cont, ch;
	clock_t Ti, Tf;
	float DeltaT;
	int moves;

	srand((unsigned)time(NULL));
	 vetor=malloc(sizeof(int) * MAX);

	for(cont=0;cont<MAX;cont++){
		ch=rand()%1000000;
		vetor[cont]=ch;
	}

	printf("\n");
	Ti=clock();
	pancake_sort(vetor,MAX-1);
	Tf=clock();
	/*for(cont=0;cont<MAX;cont++){
		printf("%d ",vetor[cont]);
	}*/
	DeltaT=Tf-Ti;
	DeltaT=DeltaT/1000;
	printf("\ncom tempo de %f\n\n",DeltaT);
	free(vetor);
	return 0;
}