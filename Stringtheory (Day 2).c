#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long counter = 0;

void checker(long long x) {
	char str[15];
	int nok=0;
	sprintf(str,"%lld",x); //turn the number into a string
	int l = strlen(str); //write the length of s to check if it has an even number of chars
	if (l % 2 != 0) return ;
	for (int n=0; n<l/2; n++) {
		if(str[n]==str[n+l/2]) {
			nok++;
		}else {
			nok=0;
			break;
		}
	}
	if (nok!=0){
		counter+=x;
	}
}



int main() {
	FILE *f;
	f = fopen("input2.txt", "r");
	char buffer [600]; //200 is enough for test, 600 for input
	char *token,*savetok;
	long long id1,id2;
	const char s[2] = ",";
	//the absolute chaos of a loop below breaks down the input into tokens divided by commas and takes the ids as numbers
	//then it applies the functions to identify repetitions on every number in the id range
	while (fgets(buffer, sizeof(buffer), f) != NULL){
		token = strtok_r(buffer, s,&savetok);
		while (token != NULL){
			printf("%s\n", token);
			sscanf(token,"%lld-%lld",&id1,&id2);
			//printf("%ld\t%ld\n",id1,id2);
			for (long long i=id1; i<=id2; i++) {
				checker(i);
			}
			token = strtok_r(NULL, s,&savetok);
		}
	}
	fclose(f);
	printf("%lld\n", counter);
	return 0;
}