#include <iostream>
#include "my_vector.h"
using namespace std;

int main() {
    my_vector<string> a(3, "Hello, world!"), b(a);
    cout << b.size() << " " << b.capacity() << endl;
    cout << b[2] << endl;
    return 0;
}