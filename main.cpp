#include <iostream>
#include "Array.hpp"
using namespace std;

int main()
{
    Array<int> a;
    for (int i=0;i<10; ++i)
        a.insert(i);
    //for (int i=0;i<10; ++i)
   // cout <<a[i] <<endl;
    //a.remove(3);
    for (int i=0;i<a.Size(); ++i)
        a[i]*=2;
    //for (int i=0;i<a.Size(); ++i)
      //  cout<<a[i]<<endl;
    for (auto it=a.iterator();it.hasNext();it.next())
        cout<<it.get()<<endl;
    return 0;
}