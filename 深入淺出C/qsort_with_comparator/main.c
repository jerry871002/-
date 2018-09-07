#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_scores(const void*, const void*);
int compare_scores_desc(const void*, const void*);
int compare_names(const void*, const void*);
int compare_names_desc(const void*, const void*);

int main() {
	int scores[] = {543,323,32,554,11,3,112};
	qsort(scores, 7, sizeof(int), compare_scores_desc);
	puts("These are the scores in order:");
	for(int i = 0; i < 7; i++) {
		printf("Score = %d\n", scores[i]);
	}

	char *names[] = {"Karen", "Mark", "Brett", "Molly"};
	qsort(names, 4, sizeof(char*), compare_names);
	puts("These are the names in order:");
	for(int i = 0; i < 4; i++) {
		printf("%s\n", names[i]);
	}

	return 0;
}