#include <iostream>
#include <ctime>
#include "MyArray.hpp"
using namespace std;
int main() {
    const long int size=50;
    int A[size];
    for (int counter = 0;counter<size;counter++)
        A[counter]=rand()%100;
    double start_time = clock();
    InsertionSort(A, A+size, [](int a, int b){return a<b;});
    double end_time = clock();
    for (int i=0;i<size;i++)
        cout <<A[i]<<endl;
    cout <<"Алгоритм сортировки вставкой сработал за:"<<end_time-start_time<<endl;
    for (int counter = 0;counter<size;counter++)
        A[counter]=rand()%100;
    start_time = clock();
    mqsort(A, A+size, [](int a, int b){return a<b;});
    end_time = clock();
    for (int i=0;i<size;i++)
        cout <<A[i]<<endl;
    cout <<"Алгоритм быстрой сортировки сработал за:"<<end_time-start_time<<endl;
    return 0;
}