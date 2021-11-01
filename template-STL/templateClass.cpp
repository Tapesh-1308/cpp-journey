#include<iostream>
using namespace std;

template<class T>
class vector {
    public:
    T *arr;
    int size;
    vector(int m) {
        size = m;
        arr = new T[size];
    }
    T dotProduct(vector &v) {
        T d = 0;
        for (int i = 0; i < size; i++) {
            d += this->arr[i] * v.arr[i];
        }
        return d;
        
    }
};

template<class T1=int, class T2=float>
class myClass {
    public:
    T1 data1;
    T2 data2;
    myClass(T1 a, T2 b){
        data1 = a;
        data2 = b;
    }
    void display(){
        cout<<this->data1<<endl<<this->data2;
    }
};

int main() {
    // vector<int> v1(3);
    // v1.arr[0] = 1;
    // v1.arr[1] = 1;
    // v1.arr[2] = 1;

    // vector<int> v2(3);
    // v2.arr[0] = 1;
    // v2.arr[1] = 1;
    // v2.arr[2] = 1;

    // cout<<v1.dotProduct(v2);

    // vector<float> v1(3);
    // v1.arr[0] = 0.1;
    // v1.arr[1] = 0.1;
    // v1.arr[2] = 0.1;

    // vector<float> v2(3);
    // v2.arr[0] = 0.1;
    // v2.arr[1] = 0.1;
    // v2.arr[2] = 0.1;

    // cout<<v1.dotProduct(v2);

    myClass<int, char> obj(1, '3');
    obj.display();
    return 0;
}