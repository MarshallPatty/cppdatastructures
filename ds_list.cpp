#include "ds_list.h"
#include "ds_string.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

namespace DS {
    // explicit instantiations
    template class List<int>;
    template class List<float>;
    template class List<String>;

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
        if (newLength > size) {
            size *= 2;
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
    T List<T>::get(size_t index) {
        return array[index];
    }

    template<typename T>
    size_t List<T>::Length() {
        return length;
    }
}
