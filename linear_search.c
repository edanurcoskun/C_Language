#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *first = NULL;
struct node *last = NULL;

void insert(int num){
	struct node *number=(struct node *) malloc(sizeof(struct node));
	number->data=num;
	if(first!=NULL){
    	last->next=number;
    	number->prev=last;
    	last=number;
    	number->next=NULL;
	}else{
		first=number;
		last=number;
		first->prev=NULL;
		number->next=NULL;
	}
}

void divisor(){
	int i, x;
	int number;
	struct node *div=(struct node *) malloc(sizeof(struct node));
	div=first;
	while(div!=NULL){
		number=div->data;
		printf("divisors of %d : ",number);
		for(i=1; i<=number; i++){
			x=number%i;
			if(x==0){
				printf("%d ",i);
			}
		}
		div=div->next;
		printf("\n");
	}
	
}

void recLinearSearch(int key,struct node *s){
	if(s!=NULL){
		if(key==s->data){
			divisor();
		}else{
			s=s->next;
			recLinearSearch(key,s);
		}
	}else{
		printf("could not be find...\n");
	}
}

int main(){
	int num; //number of elements
	int ele; //elements
	int search;
	printf("how many elements will you enter...\n");
	scanf("%d",&num);
	for(int i=0; i<num; i++){
		printf("enter the element %d : ",i+1);
		scanf("%d",&ele);
		insert(ele);
	}
	struct node *p=first;
	printf("enter the number that you search : ");
	scanf("%d",&search);
	recLinearSearch(search,p);
	
	
	return 0;
}
