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
            void resizeToFit(size_t newLength) {
                if (newLength == 0)
                    return;

                if (size == 0) {
                    size = newLength;
                    array = (T *)malloc(newLength * sizeof(T));
                    return;
                }

                // allocate more space if needed
                // resize to next muliple of size that's larger than newLength
                if (newLength > size) {
                    size *= 1 + newLength / size;
                    T *newArray = (T *)malloc(size * sizeof(T));
                    memcpy(newArray, array, length * sizeof(T));
                    free(array);
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

        public:
            List() {
                size = 0;
                length = 0;
                array = NULL;
            }

            List(size_t len) {
                length = len;
                size = len;
                array = (T *)malloc(size * sizeof(T));
            }

            List(T arr[], size_t len) {
                length = len;
                size = len;
                array = (T *)malloc(size * sizeof(T));
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
                insertionSort();
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
