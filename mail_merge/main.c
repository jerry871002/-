#ifndef RESPONSE
#define RESPONSE
enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};

typedef struct {
	char *name;
	enum response_type type;
} response;
#endif

void dump(response);
void second_chance(response);
void marriage(response);

void (*replies[])(response) = {dump, second_chance, marriage};

int main() {
	response r[] = {
		{"Mike", DUMP}, {"Luis", SECOND_CHANCE},
		{"Matt", SECOND_CHANCE}, {"William", MARRIAGE}
	};

	for(int i = 0; i < 4; i++) {
		//instead of this
		/*
		switch(r.type) {
		case DUMP:
			dump(r);
			break;
		case SECOND_CHANCE:
			second_chance(r);
			break;
		default:
			marriage(r);
		}
		*/
		//you can finish in one statement
		(replies[r[i].type])(r[i]);
	}
	return 0;	
}