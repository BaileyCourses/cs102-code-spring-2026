#include <iostream>

using namespace std;

int main() {
    int * array = new int[3];
    int * array2 = new int[10];

    for (int i; i <= 3; i++) {
        if (i % 2 == 0) {
            array[i] = i;
        } else {
            array[i] = 999;
        }
    }

    for (int i = 0; i <= 3; i++) {
        cout << " " << array[i];
    }
    cout << endl;

    delete array;
    return 0;
}
