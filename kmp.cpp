#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void kmp(int A[], int n, int B[], int m){
	int i=0;
	int j=0;
	while(i<n){
		while(j<m){
			if(A[i]==B[j]){
				i++;
				j++;
			}else{
				i=(i-j)+1;
				j=0;
			}
		}
		printf("found at %d \n",i-j);
		j=0;
	}
}

int main(){
	int n, m;
	int i, j;
	int random;
	printf("enter the length of A string : ");
	scanf("%d",&n);
	int A[n];
	printf("enter the length of B string : ");
	scanf("%d",&m);
	int B[m];
	srand(time(NULL));
	for(i=0; i<n; i++){
		A[i]=rand() % 2;
	}
	printf("the first string is -> ");
	for(i=0; i<n; i++){
		printf("%d",A[i]);
	}
	printf("\n");
	for(j=0; j<m; j++){
		B[j]=rand() % 2;
	}
	printf("the second string is -> ");
	for(j=0; j<m; j++){
		printf("%d",B[j]);
	}
	printf("\n");
	kmp(A,n,B,m);
	
	
	return 0;
}
