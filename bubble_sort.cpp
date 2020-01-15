#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int  data;
    struct node *next;
    struct node *prev;
};

struct node *first = NULL;
struct node *last = NULL;

void enqueue(int num){ 
	struct node *final = (struct node *) malloc(sizeof(struct node));		
	final->data=num;
	if(first!=NULL){
    	last->next=final;
    	final->prev=last;
    	final->next=NULL;
    	last=final;
	}else{
		first=final;
		last=final;
		first->prev=NULL;
		last->next=NULL;
	}
}

void nonRecSort(struct node *p){
	int temp;
	struct node *i = (struct node *) malloc(sizeof(struct node));
	struct node *j = (struct node *) malloc(sizeof(struct node));
	i=p;
	while(i!=NULL){
		j=p;
		while(j->next!=NULL){
			if(j->data > (j->next)->data){
				temp=j->data;
				j->data=(j->next)->data;
				(j->next)->data=temp;
			}
			j=j->next;
		}
		i=i->next;
	}
}

void recSort(struct node *p, int num, int a){
	int temp;
	if(a==num){
		return;
	}
	struct node *j = (struct node *) malloc(sizeof(struct node));
	j=p;
	while(j->next!=NULL){
		if(j->data > (j->next)->data){
			temp=j->data;
			j->data=(j->next)->data;
			(j->next)->data=temp;
		}
		j=j->next;
	}
	a++;
	recSort(p,num,a);
}

int main(){
	struct node *p, *d, *p1;
	int num, ele;
	int i, a;
	printf("how many number will you enter... ");
	scanf("%d",&num);
	printf("enter the numbers...\n");
	for(i=0; i<num; i++){
		scanf("%d",&ele);
		enqueue(ele);
	}
	d=first;
	p=first;
	printf("1 - non recursive...\n");
	printf("2 - recursive...\n");
	scanf("%d",&a);
	if(a==1){
		nonRecSort(p);
		printf("final order is (nonrecursion)... \n");
		while(d){
			printf("%d ",d->data);
			d=d->next;
		}
	}else if(a==2){
		recSort(p, num, 1);
		printf("final order is (recursion)... \n");
		while(d){
			printf("%d ",d->data);
			d=d->next;
		}
	}
	
	
	return 0;
}
