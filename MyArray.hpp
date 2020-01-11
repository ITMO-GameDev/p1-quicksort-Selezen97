#ifndef UNTITLED1_MYARRAY_HPP
#define UNTITLED1_MYARRAY_HPP

#include <iostream>
using namespace std;
template <typename T>
bool comp(const T&a, const T&b);

template <typename T, typename Compare>
void InsertionSort( T first, T last, Compare comp)
{
    T i=first;
    for (++i;i!=last;++i)
    {
        T j=i,k=i;
        for (--j;(k!=first)&&comp(*k,*j);--j,--k)
            swap(*k,*j);
    }
};

template <typename T, typename Compare>
void mqsort( T first, T last, Compare comp)
{
    if (last-first<=50)
    {
        InsertionSort(first,last,comp);
        return;
    }
    qsort:
    typedef typename
    iterator_traits<T>::value_type Value;//итератор с произвольным доступом
    T i=first;
    T j=last-1;
    Value x;
    T index;//адрес опорного элемента
    if ((j-i)>=3)//выбираем опорный элемент, если в текущем интервале минимум 3 элемента
    {
        int av=*(i+(j-i)/2);//средний индекс текущего интервала
        if ((*j-av)*(j-i)<0)
        {
            x=*j;//если произведение разностей разных знаков,
            index=j;
        }
        if ((av-(*i))*(av-(*j))<0)
        {
            x=av;//то это число между ними
            index=(i+(j-i)/2);
        }
        if ((*i-av)*(i-j)<0)
        {
            x=*i;//и является медианой из 3-х
            index=i;
        }
    }
    else
    {
        index =i+rand()%(j-i+1);
        x= *index;
    }
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
};



#endif //UNTITLED1_MYARRAY_HPP
