#pragma once
#include <stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<SDL2/SDL.h>

#include "globals.h"

static  float hireTimeInSeconds() {
	float t = (float) SDL_GetTicks();
	t /= 1000;
	return t;
}

static float randomFloat() {
	return (float)rand() / (float)RAND_MAX;
}

static const char* getRandomChar() {
	const char ch = (char) ((int) 'a' + (int) (randomFloat() * 26.0f));
	char* str =  malloc(sizeof(char) * 2);

	if (str != NULL) {
		str[0] = ch;
		str[1] = '\0';
	}

	return str;
}

static const char** getRandomUniqueCharArray() {

	const char** charStrArr = malloc(sizeof(char*) * ENTITY_AMOUNT);

	if (charStrArr ==  NULL) {
		return NULL;
	}


	for (int i = 0; i < ENTITY_AMOUNT; i++) {
		bool isNotUnique = false;

		do {
			isNotUnique = false;
			charStrArr[i] = getRandomChar();
			for (int j = 0; j < i; j++) {
				if(strcmp(charStrArr[i], charStrArr[j]) == 0) {
					isNotUnique = true;
					break;
				}
			}
		} while (isNotUnique);

	}

	return charStrArr;
}

static const char* convertIntegerToString(char* buffer, const int num)
{
	snprintf(buffer, sizeof(buffer), "%d", num);
	return buffer;
}

static char* stringConcatenate(const char* str1, const char* str2) {

	const size_t len1 = strlen(str1);
	const size_t len2 = strlen(str2);
	const size_t total_len = len1 + len2 + 1;


	char* result = (char*)malloc(total_len);
	if (result == NULL) {
		printf("Failed to allocate memory!\n");
		return NULL;
	}


	strcpy(result, str1);
	strcat(result, str2);

	return result;
}


