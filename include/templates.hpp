#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP
template <typename T>
void selectionSort(T *array[], int size, bool ascending) {
    int index;
    int smallestIndex;
    int location;
    T *tempElem;
    for (index = 0; index < size -1; index++) {
        // step a, find the smallest in unsorted portion.
        smallestIndex = index;

        for (location = index + 1; location < size; location++)
            if (ascending) {
                if (*array[location] < *array[smallestIndex])
                    smallestIndex = location;
            }
            else {
                if (*array[location] > *array[smallestIndex])
                    smallestIndex = location;
            }
        // swap elements in the array.
        tempElem = array[smallestIndex];
        array[smallestIndex] = array[index];
        array[index] = tempElem;
    }
}
#endif