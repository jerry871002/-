#include <string.h>

//definition of comparators

int compare_scores(const void* score_a, const void* score_b) {
	int a = *(int*)score_a;
	int b = *(int*)score_b;
	return a - b;
}

int compare_scores_desc(const void* score_a, const void* score_b) {
	int a = *(int*)score_a;
	int b = *(int*)score_b;
	return b - a;
}

int compare_names(const void* a, const void* b) {
	char** sa = (char**)a;
	char** sb = (char**)b;
	return strcmp(*sa, *sb);
}

int compare_names_desc(const void* a, const void* b) {
	return compare_names(b, a); //或是 -compare_names(a, b) 也可以
}

//just for demonstration

typedef struct {
	int width;
	int heihgt;
} rectangle;

int compare_areas(const void* a, const void* b) {
	rectangle* ra = (rectangle*)a;
	rectangle* rb = (rectangle*)b;
	int area_a = (ra->width * ra->heihgt);
	int area_b = (rb->width * rb->heihgt);
	return area_a - area_b;
}

int compare_areas_desc(const void* a, const void* b) {
	return compare_areas(b, a);
}