#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

/**
 * @file selection_sort.c
 * @brief Swaps two elements in an array.
 * @param elementx Pointer to the first element.
 * @param elementy Pointer to the second element.
 * This function swaps the values of the two elements pointed to by elementx and elementy.
 */
void swap(int* elementx, int* elementy);

/**
 * @file selection_sort.c
 * @brief Prints the elements of an array.
 * @param array The array to be printed.
 * @param len The length of the array.
 * This function prints each element of the array followed by a space, and ends with a newline.
 */
void arrayprinter(int array[], int len);

/**
 * @file selection_sort.c
 * @brief Performs selection sort on an array using processes.
 * @param array The array to be sorted.
 * @param len The length of the array.
 * This function sorts the array in ascending order using the selection sort algorithm,
 * where each iteration is handled by a child process that finds the index of the minimum element.
 */
void selectionSort(int array[], int len);

#endif