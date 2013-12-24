void generateLevel(int x, FILE *pos, char *type);
void writeStartLevel(FILE *pos);
void writeEndLevel(FILE *pos);
void *generateRandom(char *random);
char *content(int x, char *c, int type);
char *startEl(char *type, char *klass);
char *endEl(char *type);