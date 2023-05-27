#include <ds/string.h>

#include <stdlib.h>
#include <string.h>

namespace DS {
    String::String(char *str) {
        length = strlen(str);
        string = (char *)malloc((length + 1) * sizeof(char));
        strncpy(string, str, length + 1);
    }

    void String::append(String *str) {
        char *newString = (char *) malloc((length + str->length + 1) * sizeof(char));
        strncpy(newString, string, length);
        
        // +1 so it adds the null byte
        strncpy(newString + length, str->get(), str->length + 1);
        length += str->length;

        free(string);
        string = newString;
    }

    char *String::get() {
        return string;
    }


    std::ostream &operator<<(std::ostream &out, String obj) {
        out << obj.get();
        return out;
    }
}
