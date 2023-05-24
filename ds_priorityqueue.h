#ifndef DS_PRIORITYQUEUE_H
#define DS_PRIORITYQUEUE_H

#include "ds_list.h"
#include <iostream>
#include <string.h>

namespace DS {

    template<typename T>
    class PriorityQueue {
        private:
            List<T> list;
            void percolateDown(size_t index) {
                while (2 * index < list.Length()) {
                    T newValue = list.get(2 * index);
                    size_t newIndex = 2 * index;

                    if (2 * index + 1 < list.Length()) {
                        T left = list.get(2 * index);
                        T right = list.get(2 * index + 1);
                        newIndex = left < right ? 2 * index : 2 * index + 1;
                        newValue = left < right ? left : right;
                    }

                    if (newValue > list.get(index))
                        break;

                    // swap parent and child
                    list.set(newIndex, list.get(index));
                    list.set(index, newValue);
                    index = newIndex;
                }
            }

            void  heapify() {
                size_t index = list.Length() / 2;
                while (index > 0) {
                    percolateDown(index);
                    index--;
                }
            }

        public:
            PriorityQueue() {
                list = List<T>(1);
            }

            PriorityQueue(List<T> list) {
                this->list = List<T>(list);
                // moving the first item to the back because we ignore zeroth index
                this->list.append(list.get(0)); 
                heapify();
            }

            void push(T value) {
                list.append(value);

                // ensure the order property is satisfied
                // percolate up
                size_t index = list.Length() - 1;
                while (index > 1) {
                    T parent = list.get(index / 2);
                    T child = list.get(index);
                    if (child > parent)
                        break;

                    // swap parent & child
                    list.set(index / 2, child);
                    list.set(index, parent);

                    index /= 2;
                }
            }

            T pop() {
                if (Length() == 0)
                    return NULL;

                T value = list.get(1);
                list.set(1, list.pop());

                // percolate  down
                size_t index = 1;
                percolateDown(index);

                return value;
            }

            size_t Length() {
                return list.Length() - 1;
            }

            template<typename A>
            friend std::ostream &operator<<(std::ostream &out, PriorityQueue<A> &obj);
    };

    template<typename T>
    std::ostream &operator<<(std::ostream &out, PriorityQueue<T> &obj) {
        out << '[';
        size_t length = obj.list.Length();
        for (size_t i = 1; i < length - 1; i++) {
            out << obj.list[i] << ",";
        }
        if (length > 1) {
            out << obj.list[length - 1];
        }
        out << ']';
        return out;
    }
}

#endif
