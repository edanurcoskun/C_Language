#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int N;
	int y, z;
	int random;
	srand(time(NULL));
	printf("please enter a value between 3 and 50...\n");
	scanf("%d",&N);
	int A[N][N];
	for(y=0; y<N; y++){
		for(z=0; z<N; z++){
			if(y==z){
				A[y][z]=0;
			}else{
				random=rand()%20;
				A[y][z]=random;
				A[z][y]=random;
			}
		}
	}
	for(y=0; y<N; y++){
		for(z=0; z<N; z++){
			printf("%d  ",A[y][z]);
		}
		printf("\n");
	}
	
	int b=0;
	int Ar[N+1];
	Ar[b]=1;
	int j=1;
	int a=1;
	int i=0;
	int x=1;
	int result=0;
	bool isElement=false;
	bool control=true;
	while(control){
		for(j=1; j<N-1; j++){ // ilk basta i=0 olduðu için ilk satirdaki en kücügü bulmaya calisiyor
			if(A[i][a]!=0 && A[i][j+1]!=0){
				if(A[i][a]>A[i][j+1]){
					a=j+1;
				}
			}else if(A[i][a]==0 && A[i][j+1]!=0){
				a++;
			}else if(A[i][a]==0 && A[i][j+1]==0){
				a+=2;
				j++;
			}
		}
		while(x<=b+1){ //elemani olup olmadigini bulmaya calisiyor
			if(Ar[x-1]==a+1){
				isElement=true;
				break;
			}
			x++;
		}
		x=1;
		if(isElement!=true){
			b++;
			Ar[b]=a+1;
			result=result+A[i][a];
			i=a;
			a=1;
			j=1;
			if((N-b)==1){  // N 3ten fazla girildiginde sonsuz döngü oluyor???
				Ar[b+1]=1;
				result=result+A[i][0];
				control=false;
			}
		}else{
			A[i][a]=0;
			a=1;
			j=1;
			control=true;
		}
	}
		printf("the path is ->  ");
		for(i=0; i<N+1; i++){
			printf("%d  ",Ar[i]);
		}
		printf("\nthe result is -> %d",result);
		
	return 0;
}
