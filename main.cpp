#include <iostream>
#include <stdio.h>
#include "ds_string.h"
#include "ds_list.h"

DS::List<int> fibonacci(int n) {
    int arr[] = {0, 1};
    DS::List<int> list(arr, 2);

    for (int i = 1; i < n; i++) {
        list.append(list[i] + list.get(i - 1));
    }
    return list;
}

int main() {
    DS::String str1("General Kenobi!");
    DS::String str2("\tHello there!\n");

    str1.append(&str2);
    std::cout << str1;

    DS::List<int> fibSeq = fibonacci(15);
    std::cout << fibSeq << std::endl;


    // prepending list
    DS::List<int> list = DS::List<int>();
    for (int i = 1; i <= 10; i++) {
        list.prepend(i);
        list.append(i);
    }
    std::cout << list << std::endl;

    // concat lists
    fibSeq.concat(list);
    fibSeq += list;
    std::cout << fibSeq << std::endl;

    // list of strings
    DS::List<DS::String> strings = DS::List<DS::String>();
    strings.append(DS::String("Hello"));
    strings.append(DS::String("There!"));
    strings.append(DS::String("General"));
    strings.append(DS::String("Kenobi!"));

    /* std::cout << strings << std::endl; */
}
