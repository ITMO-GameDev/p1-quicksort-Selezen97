#include <iostream>
using namespace std;
template <typename T>
bool comp(const T&a, const T&b);

template <typename T, typename Compare>
void mqsort( T first, T last, Compare comp)
{
    qsort:
    typedef typename
        iterator_traits<T>::value_type Value;
    T i=first;
    T j=last-1;
    Value x;
    if ((j-i)>=3)//выбираем опорный элемнт, если в текущем интервале минимум 3 элемента
    {
        int av=*(i+(j-i)/2);//средний индекс текущего интервала
        if ((*j-av)*(j-i)<0) x=*j;//если произведение разностей разных знаков,
        if ((av-(*i))*(av-(*j))<0) x=av;//то это число между ними
        if ((*i-av)*(i-j)<0) x=*i;//и является медианой из 3-х
    }
       else
    x= *(i+rand()%(j-i+1));
   //cout <<x<<endl;

    do {
        while (comp(*i, x)) ++i;
        while (comp(x,*j)) --j;
        if (j>=i)
        {
            swap(*i,*j);
            i++;
            j--;
        }
    } while (j >= i);
        if (last>i+1) mqsort(i,last,comp);
        if (j>first) mqsort(first,j+1,comp);
}

int main() {
    int A[7]={2,4,1,7,8,0,9};
    mqsort(A, A+7, [](int a, int b){return a<b;});
    for (int i=0;i<7;i++)
        cout <<A[i]<<endl;
    return 0;
}