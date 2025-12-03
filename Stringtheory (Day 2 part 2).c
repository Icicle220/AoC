#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long counter = 0;

int checker(const long long x) {
	char *str;
	int i;
	//printf("checking %lld\n",x);
	sprintf(str,"%lld",x); //turn the number into a string
	int l = strlen(str); //write the length of s to check if it has an even number of chars
	for (int n=2; n<=l; n++) {
		if (l%n !=0) {
			continue;
		}
		for (i = 0; i<l/n;i++) {
			for (int j=1;j<n;j++) {
				if(str[i]!=str[i+j*l/n]) {
					goto end;
				}
			}
		}
		if (i==l/n) {
			return 0;
		}
	end:
	}
	return 1;
}



int main() {
	int c=0;
	FILE *f;
	f = fopen("input2.txt", "r");
	char buffer [600];
	char *token,*savetok;
	long long id1,id2;
	const char s[2] = ",";
	//the absolute chaos of a loop below breaks down the input into tokens divided by commas and takes the ids as numbers
	//then it applies the functions to identify repetitions on every number in the id range
	while (fgets(buffer, sizeof(buffer), f) != NULL){
		token = strtok_r(buffer, s,&savetok);
		while (token != NULL){
			//printf("%s\n", token);
			sscanf(token,"%lld-%lld",&id1,&id2);
			//printf("%ld\t%ld\n",id1,id2);
			for (long long i=id1; i<=id2; i++) {
				c = checker(i);
				if (c==0){
					counter = counter +i;
				}
			}
			token = strtok_r(NULL, s,&savetok);
		}
	}
	fclose(f);
	printf("%lld\n", counter);
	return 0;
}