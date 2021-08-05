#include "my_vector.h"
#include <iostream>

using namespace std;

void display(my_vector<int>& vec){
    cout << vec.capacity() << "/" << vec.size();
    cout << "=[ ";
    for (int i = 0; i < vec.size(); i++)
    {
        if(i!=0)
            cout << ", ";
        cout << vec[i];
    }
    cout << " ]" << endl;
}

int main() {
    my_vector<int> vec;

    vec << 1 << 2 << 3;
    20 << 10 << vec;            // I want this work as [ 20, 10, 1, 2, 3 ]

    display(vec);
}