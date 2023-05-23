#ifndef DS_LINKEDLIST_H
#define DS_LINKEDLIST_H

#include <stdlib.h>

namespace DS {

    template<typename T>
    struct LLNode {
        T value;
        LLNode<T> *next;

        LLNode(T value) {
            this->value = value;
            this->next = NULL;
        }

        LLNode(T value, LLNode<T> *next) {
            this->value = value;
            this->next = next;
        }
    };

    template<typename T>
    class LinkedList {
        private:
            size_t length;
            LLNode<T> *head;
            LLNode<T> *tail;
        public:
            LinkedList() {
                length = 0;
                head = NULL;
                tail = NULL;
            }

            size_t Length() {
                return length;
            }

            T get(size_t index) {
                if (index >= length)
                    return NULL;

                LLNode<T> *current = head;
                for (size_t i = 0; i < index; i++) {
                    current = current->next;
                }
                return current->value;
            }

            T operator[](size_t index) {
                return get(index);
            }

            void append(T x) {
                LLNode<T> *newNode = new LLNode<T>{x};
                length++;

                if (tail == NULL) {
                    head = newNode;
                    tail = newNode;
                    return;
                }

                tail->next = newNode;
                tail = newNode;
            }

            void prepend(T x) {
                LLNode<T> *newNode = new LLNode<T>{x, head};
                head = newNode;

                if (tail == NULL)
                    tail = newNode;

                length++;
            }

            void insert(T x, size_t index) {
                if (index > length)
                    return;

                if (index == 0) {
                    LLNode<T> *newNode = new LLNode<T>{x, head};
                    head = newNode;
                    length++;
                    return;
                }

                LLNode<T> *current = head;
                for (size_t i = 0; i < index - 1; i++) {
                    current = current->next;
                }

                LLNode<T> *newNode = new LLNode<T>{x, current->next};
                current->next = newNode;
                length++;
            }

            void remove(size_t index) {
                if (length == 0 || index > length)
                    return;

                if (index == 0) {
                    LLNode<T> *tmp = head->next;
                    delete head;
                    head = tmp;
                    length--;
                    return;
                }

                LLNode<T> *current = head;
                for (size_t i = 0; i < index - 1; i++) {
                    current = current->next;
                }
                LLNode<T> *next = current->next->next;
                delete current->next;
                current->next = next;
                length--;
            }

            void reverse() {
                if (length <= 1)
                    return;

                tail = head;

                LLNode<T> *prev = NULL;
                LLNode<T> *current = head;
                LLNode<T> *next = head->next;

                while (next != NULL) {
                    current->next = prev;
                    prev = current;
                    current = next;
                    next = next->next;
                }
                current->next = prev;

                head = current;
            }

            template<typename A>
            friend std::ostream &operator<<(std::ostream &out, LinkedList<A> &obj);
    };

    template<typename T>
    std::ostream &operator<<(std::ostream &out, LLNode<T> &obj) {
        LLNode<T> *current = &obj;
        out << '[';
        while (current->next != NULL) {
            out << current->value << ',';
            current = current->next;
        }
        out << current->value;
        out << ']';
        return out;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &out, LinkedList<T> &obj) {
        out << *obj.head;
        return out;
    }
}

#endif
