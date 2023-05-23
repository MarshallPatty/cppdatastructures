#include "ds_list.h"
#include "ds_string.h"

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

namespace DS {
    // explicit instantiations
    template class List<int>;
    template class List<float>;
    template class List<String>;

    template std::ostream &operator<<(std::ostream &out, List<int> &obj);
    template std::ostream &operator<<(std::ostream &out, List<float> &obj);
    /* template std::ostream &operator<<(std::ostream &out, List<String> &obj); */


    template<typename T>
    List<T>::List() {
        size = 0;
        length = 0;
        array = NULL;
    }

    template<typename T>
    List<T>::List(T arr[], size_t len) {
        length = len;
        size = len;
        array = (T *)malloc(size * sizeof(T));
        memcpy(array, arr, len * sizeof(T));
    }

    template<typename T>
    void List<T>::resizeToFit(size_t newLength) {
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

    template<typename T>
    void List<T>::append(T n) {
        resizeToFit(length + 1);
        length++;
        array[length - 1] = n;
    }

    template<typename T>
    void List<T>::prepend(T n) {
        resizeToFit(length + 1);

        if (length != 0) {
            memcpy(array + 1, array, length * sizeof(T));
        }

        array[0] = n;
        length++;
    }

    template<typename T>
    void List<T>::concat(List<T> list) {
        resizeToFit(length + list.length);
        memcpy(array + length, list.array, list.length * sizeof(T));
        length += list.length;
    }

    template<typename T>
    void List<T>::operator+=(List<T> list) {
        concat(list);
    }

    template<typename T>
    T List<T>::get(size_t index) {
        return array[index];
    }

    template<typename T>
    T List<T>::operator[](size_t index) {
        return get(index);
    }

    template<typename T>
    size_t List<T>::Length() {
        return length;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &out, List<T> &obj) {
        std::cout << '[';
        for (size_t i = 0; i < obj.Length() - 1; i++) {
            std::cout << obj[i] << ",";
        }
        if (obj.Length() > 0) {
            std::cout << obj[obj.Length() - 1];
        }
        std::cout << ']';
        return out;
    }
}
