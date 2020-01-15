#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *node = NULL;
struct node *first = NULL;

struct node *insert(int key, struct node *node){
	struct node *dt=(struct node*)malloc(sizeof(struct node));
	dt->data=key;
	if(node==NULL){
		node=dt;
		node->left=NULL;
		node->right=NULL;
	}else{
		if((node->data)>key){
			node=node->left;
			insert(key,node);
		}else if((node->data)<key){
			node=node->right;
			insert(key,node);
		}
	}
	return node;
}

void postorder(struct node *root){
  if(root!=NULL){
	postorder(root->left);
    postorder(root->right);
    printf("%d  ",root->data);
  }
}

int main(){
	int i=0;
	int number,j;
	int array[100];
	struct node *root=(struct node*)malloc(sizeof(struct node));
	printf("enter different numbers(if you want to finish, enter zero)...\n");
	while(true){
		scanf("%d",&array[i]);
		if(array[i]!=0){
			i++;
		}else{
			break;
		}
	}
	printf("your numbers are... ");
	for(j=0; j<i; j++){
		printf("%d ",array[j]);
	}
	number=array[0];
	root=insert(number,node);
	for(j=1; j<i; j++){
		number=array[j];
		insert(number, node);
	}
	printf("Post-order: ");
	postorder(root);
	
	return 0;
}
