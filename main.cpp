#include "my_vector.h"
#include <iostream>

using namespace std;

template <typename typ>
void display(my_vector<typ>& vec){
    cout << vec.capacity() << "/" << vec.size();
    cout << "=[ ";
    for (int i = 0; i < vec.size(); i++)
    {
        if(i!=0)
            cout << ", ";
        cout << vec[i].j;
    }
    cout << " ]" << endl;
}

struct data
{
    int i = 0;
    int j = 0;
};

int main() {
    my_vector<data> vec;

    vec << (data){1} << (data){2,0} << (data){3,0};
    vec << vec;
    vec <<= 1;

    display(vec);
}