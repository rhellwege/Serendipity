#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP
#include "bookType.h"
template <typename T>
void sortArrayDecending(T *array[], int size) {
    int index;
    int smallestIndex;
    int location;
    T *tempElem;

    for (index = 0; index < size -1; index++) {
        // step a, find the smallest in unsorted portion.
        smallestIndex = index;

        for (location = index + 1; location < size; location++)
            if (*array[location] > *array[smallestIndex])
                smallestIndex = location;

        // swap elements in the array.
        tempElem = array[smallestIndex];
        array[smallestIndex] = array[index];
        array[index] = tempElem;
    }
}

template <typename T>
void sortArrayAcending(T *array[], int size) {
    int index;
    int smallestIndex;
    int location;
    T *tempElem;

    for (index = 0; index < size -1; index++) {
        // step a, find the smallest in unsorted portion.
        smallestIndex = index;

        for (location = index + 1; location < size; location++)
            if (*array[location] < *array[smallestIndex])
                smallestIndex = location;

        // swap elements in the array.
        tempElem = array[smallestIndex];
        array[smallestIndex] = array[index];
        array[index] = tempElem;
    }
}
#endif