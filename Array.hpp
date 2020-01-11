//
// Created by Василий Селезнёв on 20.11.2019.
//

#ifndef LAB2_ARRAY_HPP
#define LAB2_ARRAY_HPP
using namespace std;

template <typename T>
class Array final
{
private:
    int size;
    int capacity;
    T * data;

public:
    class Iterator;
    Array();
    Array(const Array<T> & a);
    Array(int a);
    ~Array();
    void resize(int c);
    void insert(const T& val);
    void insert(int index,const T& val);
    int Size();
    void remove(int index);
    T & operator[] (int i);
    Iterator iterator() {Iterator iterator(*this);
        return iterator;};
    const Iterator iterator() const {
        Iterator iterator(*this);
        return iterator;
    };
    //Iterator iterator(){return data;};
    Iterator end() {return data+size;};
    //const Iterator iterator() const {return data;};
    class Iterator
    {
        friend class Array<T>;
    private:
        Array<T>& data;
        long int index;
        //указатель на элемент
    public:
        Iterator(Array<T>& data);
        T& operator* () {return *data;};
        const T& get() const {return data[index];};
        void set(const T& value) {data[index]=value;};
        bool operator!= (const Iterator& it) {return data != it.data;};
        bool operator== (const Iterator& it) {return data == it.data;};
        void insert(const T& value) {data.insert(index,value);};
        void remove() {data.remove(index);};
        void next() {index++;};
        void prev() {index--;};
        void toIndex(int a) {this->index = a;};
        bool hasNext() const { return index < data.capacity-1;};
        bool hasPrev() const { return index>1;};
    };
};

template<typename T>
Array<T>::Array()
{
    data = new T[8];
    size = 0;
    capacity = 8;
    //data = nullptr;
};

template<typename T>
Array<T>::Array(const Array<T> & a)
{
    size = a.size;
    capacity = size;
    data = nullptr;
    if (size != 0)
        data = new T[size];
    else
        data = 0;
    for (int i = 0; i < size; ++i)
        data[i] = a.data[i];
};

template<typename T>
Array<T>::Array(int a)
{
    size = a;
    capacity = a;
    if (a != 0)
        data = new T[a];
    else
        data = 0;
};

template<typename T>
Array<T>::~Array()
{
    if (data)
        delete[] data;
};

template<typename T>
void Array<T>::resize(int c)
{
    if (c > capacity)
    {
        int new_capacity = max(c, size * 2);
        T * new_data = new T[new_capacity];
        for (int i = 0; i < size; ++i)
            new_data[i] = data[i];
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
    size = c;
};

template<typename T>
int Array<T>::Size()
{
    return size;
};

template<typename T>
void Array<T>::insert(const T& val)
{
    resize(size + 1);
    data[size - 1] = val;
};

template<typename T>
T& Array<T>::operator[] (int i)
{
    return data[i];
}

template<typename T>
void Array<T>::insert(int index, const T &val)//
{
    T * new_data = new T[++size];
    for (int i=0;i<index;++i)
        new_data[i]=data[i];
    new_data[index]=val;
    for (int i=index;i<size-1;++i)
        new_data[i+1]=data[i];
    delete[] data;
    data=new_data;
}

template<typename T>
void Array<T>::remove(int index)
{
    for (int i=0;i<size;i++)
    {
        if (i==index)
        {
            for (;i<size-1;i++)
                data[i]=data[i+1];
            data[size-1]=0;
            size--;
        }
    }
}

template <typename T>
Array<T>::Iterator::Iterator(Array<T> &data) : data(data)
{
    index = 0;
}

template<typename T>
ostream & operator << (ostream & out, Array<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        out << a[i] << " ";
    return out;
};

#endif //LAB2_ARRAY_HPP
