#ifndef DS_LIST_H
#define DS_LIST_H

#include <stddef.h>

namespace DS {
    class List {
        private:
            size_t size;
            size_t length;
            int *array;
            void resizeToFit(size_t newLength);
        public:
            List();
            List(int arr[], size_t length);
            void append(int n);
            void prepend(int n);
            int get(size_t index);
            void print();
    };
}

#endif
