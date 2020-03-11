#include <stdio.h>
#include <stdlib.h>

struct node {
    int weight;
    int value;
    int id;
    float unitValue;
    struct node *next;
};

struct node *first = NULL;
struct node *last = NULL;

void insert(int w, int v, int i, float uv){
	struct node *data = (struct node *) malloc(sizeof(struct node));
	data->weight=w;
	data->value=v;
	data->id=i;
	data->unitValue=uv;
	if(first!=NULL){
    	last->next=data;
    	last=data;
    	data->next=NULL;
	}else{
		first=data;
		last=data;
		data->next=NULL;
	}
}

void sort(struct node *p){
	float temp;
	struct node *i = (struct node *) malloc(sizeof(struct node));
	struct node *j = (struct node *) malloc(sizeof(struct node));
	i=p;
	while(i!=NULL){
		j=p;
		while(j->next!=NULL){
			if(j->unitValue < (j->next)->unitValue){
				temp=j->unitValue;
				j->unitValue=(j->next)->unitValue;
				(j->next)->unitValue=temp;
				
				temp=j->weight;
				j->weight=(j->next)->weight;
				(j->next)->weight=temp;
				
				temp=j->value;
				j->value=(j->next)->value;
				(j->next)->value=temp;
				
				temp=j->id;
				j->id=(j->next)->id;
				(j->next)->id=temp;
			}
			j=j->next;
		}
		i=i->next;
	}
}

int main(){
	struct node *p, *d;
	int capacity;
	int i;
	int weight, value;
	float unit;
	int result=0;
	int final=0;
	printf("enter the capacity of bag (between 5 and 25)...  ");
	scanf("%d",&capacity);
	for(i=1; i<=5; i++){
		printf("enter the weight of %d. element (between 1 and %d) : ",i,capacity);
		scanf("%d",&weight);
		
		printf("enter the value  of %d. element (between 1 and 25) : ",i);
		scanf("%d",&value);
		
		unit=value/weight; 
		
		insert(weight, value, i, unit);
	}
	
	p=first;
	d=first;
	sort(p);
	for(i=0; i<5; i++){
		result=result+d->weight;
		final=final+d->value;
		if(result>capacity){
			result=result-d->weight;
			final=final-d->value;
			break;
		}else{
			printf("element %d - weight %d - value %d \n", d->id, d->weight, d->value);
		}
		d=d->next;
	}
	printf("total weight is %d and total value is %d\n", result, final);
	
	
	return 0;
}










