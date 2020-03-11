#include <stdio.h>
#include <string.h>

int main(){
	char *string1, *string2, temp;
	char string[100];
	int i,length;
	
	printf("enter a word or sentence to reverse...\n");
	gets(string);
	length=strlen(string);
	string1=string;
	string2=string;
	
	string2=string2+(length-1);
	
	for(i=0; i<(length/2); i++){
		temp=*string1;
		*string1=*string2;
		*string2=temp;
		
		string1++;
		string2--;
	}
	printf("%s",string);
	return 0;
}
