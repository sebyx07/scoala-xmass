#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "./boilerplate.h"
#include "./output.h"
#include <time.h>

int generate(int level, float magnitude){

	FILE *pos;
	pos = fopen("output.html", "w");

	float x = 1;
	int i, max = 60, min = 13;
	
	boilerplateStart(pos);
	generateLevel(x, pos, "cross");	
	for(i = 1; i <= level; i++){
		while(ceil(x * magnitude) < max){
			x = ceil(x *magnitude);
			generateLevel(x, pos, "body");
		}
		x = min;
		min += 8;
		max += 20;
	}
	for(i = 1; i <= 10; i++)
		generateLevel(10, pos, "wood");	
	boilerplateEnd(pos);
	fclose(pos);
	return 0;
}

int main(){
	srand(time(NULL));
	int n;
	float magnitude;
	printf("Wanna see my Python Suka?...\nMy xmass tree ?\n");
	while(1){
		printf("Keep Roaling the levels?\n\n");
		printf("I suggest 3 with 1.1\n\n");
		printf("Press f5 on browser to ref / ctr c to exit\n");
		printf("level:\n");
		scanf("%d",&n);
		printf("(float with . )magnitude:\n");
		scanf("%f",&magnitude);
		if (magnitude < 1.1){
			printf("\nminimum is 1.1");
			magnitude = 1.1;
			Sleep( 2000 );
		}
		generate(n, magnitude);
		//system( "cls" );
	}
	return 0;
}