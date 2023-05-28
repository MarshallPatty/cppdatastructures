#ifndef DS_LIST_H
#define DS_LIST_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

namespace DS {
    /* The inclusion model */
    /* https://learn.microsoft.com/en-us/cpp/cpp/source-code-organization-cpp-templates */
    template<typename T>
    class List {
        private:
            size_t size;
            size_t length;
            T *array;
            enum class SortMethod {INSERTION, MERGE, QUICK, BUCKET};
            void resizeToFit(size_t newLength) {
                if (newLength == 0)
                    return;

                if (size == 0) {
                    size = newLength;
                    array = new T[size];
                    return;
                }

                // allocate more space if needed
                // resize to next muliple of size that's larger than newLength
                if (newLength > size) {
                    size *= 1 + newLength / size;
                    T *newArray = new T[size];
                    memcpy(newArray, array, length * sizeof(T));
                    delete array;
                    array = newArray;
                }
            }

            void insertionSort() {
                for (size_t i = 1; i < length; i++) {
                    if (get(i) >= get(i - 1))
                            continue;

                    for (size_t j = i; j != 0; j--) {
                        if (get(j) >= get(j - 1))
                            break;

                        T tmp = get(j);
                        set(j, get(j - 1));
                        set(j - 1, tmp);
                    }
                } 
            }

            void mergeSort(size_t leftIndex, size_t rightIndex) {
                if (leftIndex == rightIndex) {
                    return;
                }
                size_t midIndex = (rightIndex + leftIndex) / 2;
                mergeSort(leftIndex, midIndex);
                mergeSort(midIndex + 1, rightIndex);

                // merge
                size_t len = rightIndex - leftIndex + 1; 
                T tmp[len];
                memcpy(tmp, array + leftIndex, len * sizeof(T));

                size_t leftPtr = 0;
                size_t rightPtr = midIndex + 1 - leftIndex;
                size_t currentPtr = 0;
                while (leftPtr <= midIndex - leftIndex && rightPtr <= rightIndex - leftIndex) {
                    if (tmp[leftPtr] > tmp[rightPtr]) {
                        array[currentPtr] = tmp[rightPtr];
                        rightPtr++;
                    }
                    else {
                        array[currentPtr] = tmp[leftPtr];
                        leftPtr++;
                    }
                    currentPtr++;
                }

                // memcpy the remainder
                memcpy(array + leftIndex + currentPtr, tmp + (leftPtr <= midIndex - leftIndex ? leftPtr : rightPtr), (len - currentPtr) * sizeof(T));
            }

        public:
            List() {
                size = 0;
                length = 0;
                array = NULL;
            }

            List(size_t len) {
                length = len;
                size = len;
                array = new T[size];
            }

            List(T arr[], size_t len) {
                length = len;
                size = len;
                array = new T[size];
                memcpy(array, arr, len * sizeof(T));
            }

            void append(T x) {
                resizeToFit(length + 1);
                length++;
                array[length - 1] = x;
            }

            void prepend(T x) {
                resizeToFit(length + 1);

                if (length != 0) {
                    memcpy(array + 1, array, length * sizeof(T));
                }

                array[0] = x;
                length++;
            }

            void concat(List<T> list) {
                resizeToFit(length + list.length);
                memcpy(array + length, list.array, list.length * sizeof(T));
                length += list.length;
            }

            void operator+=(List<T> list) {
                concat(list);
            }

            T get(size_t index) {
                return array[index];
            }

            void set(size_t index, T value) {
                array[index] = value;
            }

            T pop() {
                length--;
                return array[length];
            }

            T operator[](size_t index) {
                return get(index);
            }

            size_t Length() {
                return length;
            }

            void sort() {
                SortMethod method = SortMethod::INSERTION;
                switch (method) {
                    case SortMethod::MERGE:
                        mergeSort(0, length - 1);
                        break;
                    case SortMethod::INSERTION:
                        insertionSort();
                        break;
                }
            }
    };

    template<typename T>
    std::ostream &operator<<(std::ostream &out, List<T> &obj) {
        out << '[';
        for (size_t i = 0; i < obj.Length() - 1; i++) {
            out << obj[i] << ",";
        }
        if (obj.Length() > 0) {
            out << obj[obj.Length() - 1];
        }
        out << ']';
        return out;
    }
}

#endif
