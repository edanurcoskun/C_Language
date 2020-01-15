#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int factor;
    int base;
    int power;
    struct node *next;
};

struct node2 {
    int factor;
    int base;
    int power;
    struct node2 *next;
};

struct node *first = NULL;
struct node *last = NULL;

struct node2 *ilk = NULL;
struct node2 *son = NULL;

void insert_first(int fac, int bas, int pow){
	struct node *data = (struct node *) malloc(sizeof(struct node));
	data->factor=fac;
	data->base=bas;
	data->power=pow;
	if(first!=NULL){
    	last->next=data;
    	data->next=NULL;
    	last=data;
	}else{
		first=data;
		last=data;
		data->next=NULL;
	}
}

void insert_new(int fac, int bas, int pow){
	struct node2 *data = (struct node2 *) malloc(sizeof(struct node2));
	data->factor=fac;
	data->base=bas;
	data->power=pow;
	if(ilk!=NULL){
    	son->next=data;
    	son=data;
    	data->next=NULL;
	}else{
		ilk=data;
		son=data;
		data->next=NULL;
	}
}

void del(int fac, int bas, int pow){
	struct node *data = (struct node *) malloc(sizeof(struct node));
	data->factor=fac;
	data->base=bas;
	data->power=pow;
	struct node *p, *prev;
	p=first;
	prev=NULL;
	while(p!=NULL){
		if(fac==p->factor && bas==p->base && pow==p->power){
			break;
		}
		prev=p;
		p=p->next;
	}
	if(p!=NULL){ //is it empty
		if(prev==NULL){  //is it first
			if(first==last){  // is it single
				first=NULL;
				last=NULL;
			}else{
				first=first->next;
			}
		}else{
			prev->next=p->next;
			if(prev->next==NULL){
				last=prev;
			}
		}
		free(p);
	}
}

int main(){
	int ele,i;
	int new_fac, res=0;
	int factor, base, power;
	struct node *final;
	struct node2 *result;
	struct node *j, *k, *m;
	printf("how many elements will you enter...");
	scanf("%d",&ele);
	for(i=1; i<=ele; i++){
		printf("factor: ");
		scanf("%d",&factor);
		printf("base: ");
		scanf("%d",&base);
		printf("power: ");
		scanf("%d",&power);
		insert_first(factor,base,power);
	}
	final=first;
	while(final!=NULL){
		printf("%d x %d ^ %d\n", final->factor, final->base, final->power);
		final=final->next;
	}
	j=first;
	while(j!=NULL){
		new_fac=(j->factor);
		k=j->next;
		while(k!=NULL){
			if((j->base==k->base) && (j->power==k->power)){
				new_fac+=(k->factor);
				m=k;
				k=k->next;
				del(m->factor, m->base, m->power);
			}else{
				k=k->next;	
			}
		}
		insert_new(new_fac, j->base, j->power);
		j=j->next;
	}
	printf("the last form is...\n");
	result=ilk;
	while(result!=NULL){
		printf("%d x %d ^ %d\n", result->factor, result->base, result->power);
		res= res+ ((pow(result->base, result->power))*result->factor);
		result=result->next;
	}
	printf("the result is %d...\n",res);
	
	return 0;
}


















