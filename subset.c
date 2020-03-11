#include <stdio.h>
void sort(int array[], int n){
	int i, j;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(array[j]>array[j+1]){
				int temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
}

void isSubSet(int arrBig[], int arrSml[], int n, int m){
	int i, j=0;
	int a=0;
	if(m==1){
		for(i=0; i<n; i++){
			if(arrBig[i]==arrSml[0]){
				printf("\nSmall array is a subset of big array...\n");
				a=1;
				break;
			}
		}
		if(a==0){
			printf("\nSmall array is not a subset of big array...\n");
		}
	}else{
		for(i=0; i<n; i++){
			if (j==m){
				printf("\nSmall array is a subset of big array...\n");
				break;
			}
			if((n-i)<m){
				printf("\nSmall array is not a subset of big array...\n");
				break;
			}
			if(arrBig[i]==arrSml[j]){
				j++;
			}
		}
	}
}

int main(){
	int i;
	int n, m;
	printf("enter the elements number of the bigger array (different from 0) ... \n");
	scanf("%d",&n);
	int biggerArray[n];
	printf("enter the elements of the bigger array... \n");
	for(i=0; i<n; i++){
		scanf("%d",&biggerArray[i]);
	}
	printf("enter the elements number of the smaller array (different from 0)... \n");
	scanf("%d",&m);
	int smallerArray[m];
	printf("enter the elements of the smaller array... \n");
	for(i=0; i<m; i++){
		scanf("%d",&smallerArray[i]);
	}
	printf("Elements of bigger array : ");
	for(i=0; i<n; i++){
		printf("%d ",biggerArray[i]);
	}
	printf("\nElements of smaller array : ");
	for(i=0; i<m; i++){
		printf("%d ",smallerArray[i]);
	}
	
	sort(biggerArray,n);
	sort(smallerArray,m);
	
	printf("\nSorted form of elements of bigger array : ");
	for(i=0; i<n; i++){
		printf("%d ",biggerArray[i]);
	}
	printf("\nSorted of elements of smaller array : ");
	for(i=0; i<m; i++){
		printf("%d ",smallerArray[i]);
	}
	isSubSet(biggerArray, smallerArray, n, m);
	
	return 0;
}
