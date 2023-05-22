#include "ds_list.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

namespace DS {
    List::List() {
        size = 0;
        length = 0;
        array = NULL;
    }

    List::List(int arr[], size_t len) {
        length = len;
        size = len;
        array = (int *)malloc(size * sizeof(int));
        memcpy(array, arr, len * sizeof(int));
    }

    void List::resizeToFit(size_t newLength) {
        if (newLength == 0)
            return;

        if (size == 0) {
            size = newLength;
            array = (int *)malloc(newLength * sizeof(int));
            return;
        }

        // allocate more space if needed
        if (newLength > size) {
            size *= 2;
            int *newArray = (int *)malloc(size * sizeof(int));
            memcpy(newArray, array, length * sizeof(int));
            free(array);
            array = newArray;
            printf("Resized! %zu\n", size);
        }
    }

    void List::append(int n) {
        resizeToFit(length + 1);
        length++;
        array[length - 1] = n;
    }

    void List::prepend(int n) {
        resizeToFit(length + 1);

        if (length != 0) {
            memcpy(array + 1, array, length * sizeof(int));
        }

        array[0] = n;
        length++;
    }

    int List::get(size_t index) {
        return array[index];
    }

    void List::print() {
        if (length == 0) {
            printf("[]\n");
            return;
        }

        printf("[");
        for (size_t i = 0; i < length - 1; i++) {
            printf("%d, ", array[i]);
        }
        printf("%d]\n", array[length - 1]);
    }
}
