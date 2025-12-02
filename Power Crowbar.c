#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int gz = 0;
//Function to move left
int left(int a,int pos){
	int b=0;
	b=pos-a%100;
	gz+=a/100;
	if(b<0) { //checks if the dial went below 0 while going left
		if (pos!=0) {//if the dial started from 0 it didn't cross 0 going left
			gz++;
		}
		b=b+100;
	}
	return b;
}

//Function to move right
int right(int a,int pos){
	int b=0;
	b=pos+a%100;
	gz+=a/100;
	if(b>99){ //checks if the dial went above 99 while going right
		b=b-100;
		if (b!=0) {//if the dial ends on 0 it's counted later
			gz++;
		}
	}
	return b;
}

int checker(int pos,int z){
	if(pos==0){
		z++;
		gz++;
	}
	return z;
}

int main(){
    int i=0, pos=50, z=0;
	int a=0;
	char dir='a';
	char line[5],num[4];
	FILE *f=fopen("input.txt", "r");
	while (fgets(line, sizeof(line), f) != NULL) {
		printf("%s", line);
		dir=line[0];
		for (i=0;i<sizeof(num);i++) {
			num[i]=line[i+1];
		}
		a = atoi(num);
		if (dir=='R') {
			pos = right(a,pos);
			z = checker(pos,z);
		}
		if (dir=='L') {
			pos = left(a,pos);
			z = checker(pos,z);
		}

	}
	printf("\nZerocount part 1= %d\n", z);
	printf("Zerocount part 2= %d\n", gz);
	fclose(f);
    return 0;
}