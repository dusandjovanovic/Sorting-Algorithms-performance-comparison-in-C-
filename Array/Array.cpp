// Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "arrayImplementation.h"
#include "sortingAlgorithms.h"

#include <cstdio>
#include <ctime>
#include <random>
std::random_device rd;
std::mt19937 rng(rd());

int _tmain(int argc, char *argv[])
{

	for (unsigned int arrayLength = 10; arrayLength <= 10000000; arrayLength *= 10) {
		std::cout << std::endl << arrayLength << std::endl;
		std::uniform_int_distribution<int> uni(0, arrayLength*100);
		std::clock_t start;
		double duration;

		Array<int> array(arrayLength);
		if (arrayLength >= 100000) goto nlogn;
		for (unsigned int i = 0; i < arrayLength; i++)
			array[i] = uni(rng);

		start = std::clock();
		bubbleSort(array, false);
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		std::cout << std::endl << "Bubblesort-sort: " << duration << std::endl;
		std::fflush(stdout);

		array = Array<int>(arrayLength);
		for (unsigned int i = 0; i < arrayLength; i++)
			array[i] = uni(rng);

		start = std::clock();
		selectionSort(array, false);
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		std::cout << std::endl << "Selection-sort: " << duration << std::endl;
		std::fflush(stdout);

		array = Array<int>(arrayLength);
		for (unsigned int i = 0; i < arrayLength; i++)
			array[i] = uni(rng);

		start = std::clock();
		insertionSort(array, false);
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		std::cout << std::endl << "Insertion-sort: " << duration << std::endl;
		std::fflush(stdout);

		nlogn:

		array = Array<int>(arrayLength);
		for (unsigned int i = 0; i < arrayLength; i++)
			array[i] = uni(rng);

		start = std::clock();
		mergeSort(array, false);
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		std::cout << std::endl << "Merge-sort(nlogn): " << duration << std::endl;
		std::fflush(stdout);

		array = Array<int>(arrayLength);
		for (unsigned int i = 0; i < arrayLength; i++)
			array[i] = uni(rng);

		start = std::clock();
		quickSort(array, false);
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		std::cout << std::endl << "Quick-sort(nlogn): " << duration << std::endl;
		std::fflush(stdout);

		array = Array<int>(arrayLength);
		for (unsigned int i = 0; i < arrayLength; i++)
			array[i] = uni(rng);

		start = std::clock();
		countSort(array, arrayLength*100, false);
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		std::cout << std::endl << "Count-sort: " << duration << std::endl;
		std::fflush(stdout);

		array = Array<int>(arrayLength);
		for (unsigned int i = 0; i < arrayLength; i++)
			array[i] = uni(rng);

		start = std::clock();
		bucketSort(array, arrayLength, false);
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		std::cout << std::endl << "Bucket-sort: " << duration << std::endl;
		std::fflush(stdout);

		array = Array<int>(arrayLength);
		for (unsigned int i = 0; i < arrayLength; i++)
			array[i] = uni(rng);

		start = std::clock();
		radixSort(array, arrayLength, false);
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		std::cout << std::endl << "Radix-sort: " << duration << std::endl;
		std::fflush(stdout);

		std::cout << std::endl << "-----------------------------" << std::endl;
	}

	system("pause");
    return 0;
}

