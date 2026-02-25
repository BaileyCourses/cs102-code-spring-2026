#include <iostream>

using namespace std;

int main() {

    // For Task 4, leave these comments out
    //int * array = nullptr;
    //foo(array);

    // For Task 5, comment the following line and replace with
    // the above lines
    int * array = foo();
    cout << "foo:";
    for (int i = 0; i < 4; i++) {
        cout << " " << array[i];
    }
    cout << endl;
    delete[] array;
    return 0;
}
