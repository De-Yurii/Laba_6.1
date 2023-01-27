#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "function.h"
#include <conio.h>

int is_in_list(int arr[100], int num, int amount) {
	for (int i = 0; i < amount; i++) {
		if (num == arr[i]) {
			return 1;
		}
	}
	return 0;
}

void divide_sentc_words(char sentc[1000], char new_sentc[1000], int num, ...) {
	char some[1000]; char matrix_words[100][100];
	int list_of_delete_words[100];
	int* p = &num;
	int count = 0;
	while (*p) {
		list_of_delete_words[count] = (*p);
		p = p + 2;
		count++;
	}
	for (int i = 0; i < 1000; i++) {
		some[i] = sentc[i];
	}
	const char limits[] = " ,.:;-()";
	char* pw = strtok(some, limits);
	int amount = 0;
	while (pw != NULL) {
		pw = strtok(NULL, limits);
		amount++;
	}

	int h = 0, k = 0, len = strlen(sentc) + 1;
	for (int i = 0; i < len; i++) {
		if (some[i] != '\0') {
			matrix_words[k][h] = sentc[i];
			h++;
		}
		else {
			matrix_words[k][h] = '\0';
			k++;
			h = 0;
		}
	}
	int por = 0;
	int nums = 0;
	for (int i = 0; i > -1; i++) {
		if (matrix_words[nums][por] == '\0' || is_in_list(list_of_delete_words, nums + 1, count)) {
			por = 0;
			nums++;
			if (new_sentc[i - 1] != ' ') {
				new_sentc[i] = ' ';
			}
			else {
				i--;
			}
		}
		else {
			new_sentc[i] = matrix_words[nums][por];
			por++;
		}
		if (nums == amount) {
			new_sentc[i] = '\0';
			break;
		}
	}

}