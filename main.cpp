#include <iostream>
#include <cassert>
#include "Allocator.hpp"
using namespace std;
MemoryAllocator alloc;

int main() {
    alloc.init();
   int *pi=(int*)alloc.alloc(sizeof(int));
   double *pd=(double *)alloc.alloc(sizeof(double));
   //allocator.free(pi);
    cout<<pi<<endl;
    cout<<pd<<endl;
    alloc.destroy();
    return 0;
}
