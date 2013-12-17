#include <stdio.h>
#include <stdlib.h>
#include "./boilerplate.h"

void boilerplateStart(FILE *pos){
	char boilerplate[] ="<!DOCTYPE html>\n<html class=\"no-js\">\n    <head>\n        <meta charset=\"utf-8\">\n        <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n        <title></title>\n        <meta name=\"description\" content=\"\">\n        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n        <!-- Place favicon.ico and apple-touch-icon(s) in the root directory -->\n        <link rel=\"stylesheet\" href=\"css/style.css\">\n    </head>\n    <body>\n        <div class = \"x-tree\">\n";
	fputs(boilerplate, pos);
}

void boilerplateEnd(FILE *pos){
	char boilerplate[] ="\n</div>\n      </body>\n</html>";
	fputs(boilerplate, pos);
}
