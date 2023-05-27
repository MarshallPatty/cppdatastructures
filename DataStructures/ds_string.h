#ifndef DS_STRING_H
#define DS_STRING_H

#include <iostream>
#include <stddef.h>

namespace DS {
    class String {
        private:
            char *string;
            size_t length;
        public:
            String(char *str);
            void append(String *str);
            char *get();
    };

    std::ostream &operator<<(std::ostream &out, String obj);
}

#endif
