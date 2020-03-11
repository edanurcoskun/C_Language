#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *first = NULL;
struct node *last = NULL;
int top=0;

void push(int num){
	struct node *number= (struct node *) malloc(sizeof(struct node));
	number->data=num;
	if(first!=NULL){
    		last->next=number;
    		number->prev=last;
    		number->next=NULL;
    		last=number;
    		top++;
	}else{
		first=number;
		last=number;
		first->prev=NULL;
		last->next=NULL;
		top++;
	}
}

void nonRecSort(struct node *p){
	int temp;
	struct node *i = (struct node *) malloc(sizeof(struct node));
	struct node *j = (struct node *) malloc(sizeof(struct node));
	struct node *min = (struct node *) malloc(sizeof(struct node));
	i=p;
	while(i!=NULL){
		min=i;
		j=i->next;
		while(j!=NULL){
			if(j->data < min->data){
				min=j;
			}
			j=j->next;
		}
		temp=min->data;
		min->data=i->data;
		i->data=temp;
		i=i->next;
	}
}

void recSort(struct node *p1){
	int temp;
	if(p1==NULL){
		return;
	}
	struct node *j = (struct node *) malloc(sizeof(struct node));
	struct node *min = (struct node *) malloc(sizeof(struct node));
	j=p1;
	min=p1;
	while(j!=NULL){
		if(j->data < min->data){
			min=j;
		}
		j=j->next;
	}
	temp=min->data;
	min->data=p1->data;
	p1->data=temp;
	p1=p1->next;
	recSort(p1);
}

int main(){
	struct node *p, *d;
	int num, ele;
	int i, a;
	printf("how many number will you enter... ");
	scanf("%d",&num);
	printf("enter the numbers...\n");
	for(i=0; i<num; i++){
		scanf("%d",&ele);
		push(ele);
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
	}else{
		recSort(p);
		printf("final order is (recursion)... \n");
		while(d){
			printf("%d ",d->data);
			d=d->next;
		}
	}
	
	
	return 0;
}
