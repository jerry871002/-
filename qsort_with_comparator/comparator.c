#include <string.h>

//definition of comparators

int compare_scores(const void* score_a, const void score_b) {
	int a = *(int*)score_a;
	int b = *(int*)score_b;
	return a - b;
}

int compare_scores_desc(const void* score_a, const void score_b) {
	int a = *(int*)score_a;
	int b = *(int*)score_b;
	return b - a;
}

int compare_names(const void* a, const void b) {
	char** sa = (char**)a;
	char** sb = (char**)b;
	return strcmp(*sa, *sb);
}

int compare_names_desc(const void* a, const void b) {
	return compare_names(b, a); //或是 -compare_names(a, b) 也可以
}