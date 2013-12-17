#include <stdio.h>
#include <stdlib.h>
#include "./output.h"
#include <string.h>
#include <time.h>


void generateLevel(int x, FILE *pos, char *type){
	int t;
	if (strcmp(type, "body") == 0)
		t = 1;
	
	else if (strcmp(type,"cross") == 0)
		t = 2;

	else if (strcmp(type, "wood") == 0)
		t = 3;

	writeStartLevel(pos);
	switch(t){
		case 1:
			fputs(startEl("span", "leaf"), pos);
				fputs(content(x, "#", 1), pos);
			fputs(endEl("span"), pos);
			break;
		case 2:
			fputs(startEl("span", "cross"), pos);
				fputs("▲", pos);
			fputs(endEl("span"), pos);
			writeStartLevel(pos);
				fputs(startEl("span", "cross"), pos);
					fputs("◄ ╬ ►", pos);
				fputs(endEl("span"), pos);
			writeEndLevel(pos);
			break;

		case 3:
			fputs(startEl("span", "wood"), pos);
				fputs(content(10, "#", 0), pos);
			fputs(endEl("span"), pos);
			break;

	}
	writeEndLevel(pos);
}

void writeStartLevel(FILE *pos){
	fputs(startEl("div", "level"), pos);
		fputs(startEl("p", ""), pos);
}

void writeEndLevel(FILE *pos){
		fputs(endEl("p"), pos);
	fputs(endEl("div"), pos);
}


char *content(int x, char *c, int type){
	char *kontent = (char *)malloc((x + 1) * sizeof(char));
	strcpy(kontent, "");
	while(x){
		strcat(kontent, c);
		x--;
	}
	return &kontent[0];
}

char *generateRandom(char *random, char *c){
	return &random[0];
}

char *startEl(char *type, char *klass){
	int sizeType = strlen(type);
	int sizeKlass = strlen(klass);
	char *html = (char *)malloc((14 + sizeKlass + sizeType + 2) * sizeof(char));
	strcpy(html, "<");
	strcat(html, type);
	if (sizeKlass != 0){
		strcat(html, " class = \"");
		strcat(html, klass);
		strcat(html, "\"");
	}
	strcat(html, ">\n");
	return &html[0];
}

char *endEl(char *type){
	int sizeType = strlen(type);
	char *html = (char *)malloc((3 + sizeType + 2) * sizeof(char));
	strcpy(html, "</");
	strcat(html, type);
	strcat(html, ">\n");
	return &html[0];
}