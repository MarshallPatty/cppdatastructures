#include <stdio.h>
#include "ds_string.h"

int main() {
    DS::String str1 = DS::String("General Kenobi!");
    DS::String str2 = DS::String("\tHello there!\n");

    str1.append(&str2);
    printf("%s", str1.get());
}
