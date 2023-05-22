#ifndef DS_LIST_H
#define DS_LIST_H

#include <stddef.h>

namespace DS {
    template<typename T>
    class List {
        private:
            size_t size;
            size_t length;
            T *array;
            void resizeToFit(size_t newLength);
        public:
            List();
            List(T arr[], size_t length);
            void append(T x);
            void prepend(T x);
            void concat(List<T> list);
            void operator+=(List<T> list);
            T get(size_t index);
            T operator[](size_t index);
            size_t Length();
    };
}

#endif
