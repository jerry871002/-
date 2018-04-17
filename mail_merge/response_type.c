#include <stdio.h>

#ifndef RESPONSE
#define RESPONSE
enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};

typedef struct {
	char *name;
	enum response_type type;
} response;
#endif

void dump(response r) {
	printf("Dear %s, \n", r.name);
	puts("Unfortunately your last date contacted us to");
	puts("say that they will not be seeing you again");
}

void second_chance(response r) {
	printf("Dear %s, \n", r.name);
	puts("Good news: your last date has asked us to");
	puts("arrange another meeting. Please call ASAP.");
}

void marriage(response r) {
	printf("Dear %s, \n", r.name);
	puts("Congratulations! Your last date has contacted");
	puts("us with a proposal of marriage.");
}