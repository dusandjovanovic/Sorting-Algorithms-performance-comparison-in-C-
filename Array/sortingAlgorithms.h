#pragma once
#include "arrayImplementation.h"
#include <algorithm>
#include <vector>

template <typename type>
/// <summary>
/// Bubble sort :: O(n^2)
/// </summary>
/// <param name="array">Array</param>
/// <param name="condition">Show sorted array</param>
void bubbleSort(Array<type>& array, bool condition) {
	unsigned long i, j;
	unsigned long dimension = array.getLength();
	type temp;

	for (i = 0; i < dimension - 1; ++i)
		for (j = dimension - 1; j > i; --j)
			if (array[j] < array[j - 1]) {
				temp = array[j];
				array[j - 1] = array[j];
				array[j] = temp;
			}

	if (condition)
		array.printArray();
}

/// <summary>
/// Selection sort :: O(n^2)
/// </summary>
/// <param name="array">Array</param>
/// <param name="condition">Show sorted array</param>
template <typename type>
void selectionSort(Array<type>& array, bool condition) {
	unsigned long i, j;
	unsigned long dimension = array.getLength();
	unsigned long least;
	type temp;

	for (i = 0; i < dimension - 1; ++i){
		for (j = i + 1, least = i; j < dimension; ++j)
			if (array[j] < array[least])
				least = j;
		temp = array[least];
		array[least] = array[i];
		array[i] = temp;
		}

	if (condition)
		array.printArray();
}

/// <summary>
/// Insertion sort :: O(n^2)
/// </summary>
/// <param name="array">Array</param>
/// <param name="condition">Show sorted array</param>
template <typename type>
void insertionSort(Array<type>& array, bool condition) {
	unsigned long i, j;
	unsigned long dimension = array.getLength();
	type extracted;

	for (i = 1; i < dimension; i++) {
		extracted = array[i];
		for (j = i; j > 0 && extracted < array[j - 1]; --j)
			array[j] = array[j - 1];
		array[j] =  extracted;
	}

	if (condition)
		array.printArray();
}

/// <summary>
/// Merge sort :: O(nlogn)
/// </summary>
/// <param name="array">Array</param>
/// <param name="condition">Show sorted array</param>
template <typename type>
void mergeSort(Array<type>& array, bool condition) {
	

	if (condition)
		array.printArray();
}

/// <summary>
/// Quick sort :: O(nlogn)
/// </summary>
/// <param name="array">Array</param>
/// <param name="condition">Show sorted array</param>
template <typename type>
void quickSort(Array<type>& array, bool condition) {


	if (condition)
		array.printArray();
}

/// <summary>
/// Count sort :: O(n+range)
/// </summary>
/// <param name="array">Array</param>
/// <param name="condition">Show sorted array</param>
template <typename type>
void countSort(Array<type>& array, unsigned long range, bool condition) {
	unsigned long dimension = array.getLength();
	unsigned long* count = new unsigned long[range + 1];
	memset(count, 0, sizeof(unsigned long)*(range+1));
	type* output = new type[dimension];
	memset(output, 0, sizeof(type)*dimension);
	unsigned long i;

	for (i = 0; i < dimension; ++i)
		++count[array[i]];
	for (i = 1; i <= range; ++i)
		count[i] += count[i - 1];

	for (i = 0; i < dimension; ++i) {
		output[count[array[i]] - 1] = array[i];
		--count[array[i]];
	}

	for (i = 0; i < dimension; ++i)
		array[i] = output[i];

	if (condition)
		array.printArray();
}

/// <summary>
/// Bucket sort :: O(~n)
/// </summary>
/// <param name="array">Array</param>
/// <param name="condition">Show sorted array</param>
template <typename type>
void bucketSort(Array<type>& array, unsigned long length, bool condition) {
	unsigned long i, j, k;
	type minValue = array[0];
	type maxValue = array[0];

	for (int i = 1; i < length; i++) {
		if (array[i] > maxValue)
			maxValue = array[i];
		if (array[i] < minValue)
			minValue = array[i];
	}

	int bucketLength = maxValue - minValue + 1;
	std::vector<int>* bucket = new std::vector<int>[bucketLength];
	for (i = 0; i < bucketLength; i++) {
		bucket[i] = std::vector<int>();
		for (i = 0; i < length; i++)
			bucket[array[i] - minValue].push_back(array[i]);
		k = 0;
		for (i = 0; i < bucketLength; i++){
			int bucketSize = bucket[i].size();

			if (bucketSize > 0){
				for (j = 0; j < bucketSize; j++){
					array[k] = bucket[i][j];
					k++;
				}
			}
		}
	}

	if (condition)
		array.printArray();
}

/// <summary>
/// Bucket sort :: O(~n)
/// </summary>
/// <param name="array">Array</param>
/// <param name="condition">Show sorted array</param>

int getMax(int array[], int length){
	int max = array[0];
	for (int i = 1; i < length; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}

void countSort(int array[], int n, int exp){
	int* output = new int[n];
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--){
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		array[i] = output[i];
}

template <typename type>
void radixSort(Array<type>& array, unsigned long length, bool condition) {
	int* data = new int[length];
	for (unsigned int i = 0; i < length; i++)
		data[i] = array[i];

	int m = getMax(data, length);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(data, length, exp);

	if (condition)
		for (unsigned int i = 0; i < length; i++)
			std::cout << data[i] << std::endl;
}