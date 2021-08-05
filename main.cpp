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

int main(){
    my_vector<int> vec;

    vec > 10 > 20 > 30 > 40 > 50 > 60 < 55;

    display(vec);

    my_vector<int> vec2 = vec.part(2,3) > 55;

    vec2 << 2;

    display(vec2);
}