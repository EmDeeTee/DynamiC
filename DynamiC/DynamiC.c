#include "DynamiC.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

DynamiCArray DynamiCMakeArray(const size_t dataSize) {
	return (DynamiCArray){ .data = malloc(dataSize), .dataSize = dataSize, .count = 0, .capacity = 1 };
}

void DynamiCAppendToArray(DynamiCArray* arr, const void* data) {
	if (arr->count == arr->capacity) {
		arr->capacity *= 2;
		//arr->data = realloc(arr->data, arr->capacity * arr->dataSize);
		void* newData = realloc(arr->data, arr->capacity * arr->dataSize);
		if (newData == NULL) {
			assert(false, "realloc failed");
		}
		arr->data = newData;
	}
	memcpy((char*)arr->data + (arr->count++ * arr->dataSize), data, arr->dataSize);
}

void DynamiCFreeArray(DynamiCArray* arr) {
	free(arr->data);
	arr->data = NULL;
	arr->count = 0;
	arr->capacity = 0;
}

void* DynamiCGetFromArray(const DynamiCArray* arr, const size_t i) {
	if (i >= arr->count) {
		return NULL; 
	}
	return (char*)arr->data + (i * arr->dataSize);
}
