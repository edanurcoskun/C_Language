#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    struct node *next;
    struct node *prev;
};

struct node *first = NULL;
struct node *last = NULL;
int top=0;

void push(char let){
	struct node *letter = (struct node *) malloc(sizeof(struct node));
	letter->data=let;
	if(first!=NULL){
    	last->next=letter;
    	letter->prev=last;
    	letter->next=NULL;
    	last=letter;
    	top++;
	}else{
		first=letter;
		last=letter;
		first->prev=NULL;
		last->next=NULL;
		top++;
	}
}
char pop(){
	char temp;
	if(first==NULL){
		printf("stack is empty...\n");
		return -1;
	}else{
		if(first==last){
			temp=last->data;
			first=NULL;
			last=NULL;
			top--;
			return temp;
		}else{
			temp=last->data;
			last=last->prev;
			last->next=NULL;
			top--;
			return temp;
		}
	}
}

int main(){
	char stack[10];
	int i;
	int top2;
	int a,b;
	int numberOf_b=0;
	printf("enter a word that consists of a and b like aaabbbb...\n");
	scanf("%s",&stack);
	int len=strlen(stack);
	for(i=0; i<len; i++){
		char c=stack[i];
		if(c=='a'){
			push(c);
		}else{
			numberOf_b++;
		}
	}
	printf("enter the coefficient of 'a'... ");
	scanf("%d",&a);
	printf("enter the coefficient of 'b'... ");
	scanf("%d",&b);
	
	while(true){
		if(top!=0 && numberOf_b==0 || top==0 && numberOf_b<0){
			printf("It is not regular...\n");
			break;
		}
		else if(top!=0 && numberOf_b!=0){
			printf("\n%d times 'a', %d times 'b' will be deleted...\n",a,b);
			for(i=0; i<a; i++){
				pop();
			}
			numberOf_b -=b;
			top2=top;
			for(i=0; i<top2; i++){
				printf("%c",pop());
			}
			for(i=0; i<numberOf_b; i++){
				printf("b");
			}
			for(i=0; i<top2; i++){
				push(a);
			}
		}else{
			printf("It is regular...\n");
			break;
		}
		
	}
	
	return 0;
}
















