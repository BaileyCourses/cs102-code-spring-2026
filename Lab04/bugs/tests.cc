#include "bug2.h"
#include <cassert>
#include <iostream>

int main() {
    List list;

    assert(list.length() == 0);

    list.append(10);
    assert(list.length() == 1);

    list.append(20);
    assert(list.length() == 2);

    list.prepend(5);
    assert(list.length() == 3);

    assert(list.get(0) == 5);
    assert(list.get(1) == 10);
    assert(list.get(2) == 20);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
