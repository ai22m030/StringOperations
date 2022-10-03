#include <iostream>
#include "include/String.h"

int main() {
    char const * string1 = "hello";
    String string = String(string1);

    char const * string2 = " world";
    String string3 = String(string2);

    string += string3;

    string.print();

    return 0;
}
