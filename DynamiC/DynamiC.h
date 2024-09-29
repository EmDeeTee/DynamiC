#pragma once
#include <stddef.h>

#define DynamiCForEach(type, var, array) \
    for (type* var = (type*)array.data; \
         (char*)var < (char*)array.data + (array.count * array.dataSize); \
         var = (type*)((char*)var + array.dataSize))

typedef struct DynamiCArray {
	void* data;
	size_t dataSize;
	size_t count;	
	size_t capacity;
} DynamiCArray;

// NOTE: Oh that's a good name. I like it
DynamiCArray DynamiCMakeArray(const size_t dataSize);
void DynamiCAppendToArray(DynamiCArray* arr, const void* data);
void DynamiCFreeArray(DynamiCArray* arr);
void* DynamiCGetFromArray(const DynamiCArray* arr, const size_t i);
