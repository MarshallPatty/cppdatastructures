#include <stdio.h>
#include "ds_string.h"
#include "ds_list.h"

DS::List fibonacci(int n) {
    int arr[] = {0, 1};
    DS::List list(arr, 2);

    for (int i = 1; i < n; i++) {
        list.append(list.get(i) + list.get(i - 1));
    }
    return list;
}

int main() {
    DS::String str1("General Kenobi!");
    DS::String str2("\tHello there!\n");

    str1.append(&str2);
    printf("%s", str1.get());

    DS::List fibSeq = fibonacci(15);
    fibSeq.print();


    // prepending list
    DS::List list = DS::List();
    list.print();
    for (int i = 1; i <= 10; i++) {
        list.prepend(i);
        list.append(i);
    }
    list.print();
}
