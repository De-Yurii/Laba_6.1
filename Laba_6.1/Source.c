#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "function.h"

int main(void) {
	char sentc[1000], new_sentc[1000];
	gets(sentc);
	divide_sentc_words(sentc, new_sentc, 2, 6, 0);
	printf("%s", new_sentc);
}
