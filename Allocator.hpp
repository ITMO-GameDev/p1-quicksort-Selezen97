#ifndef LAB4_ALLOCATOR_HPP
#define LAB4_ALLOCATOR_HPP

struct block
{
    int size;
    bool on;//занятость
    block * next;
};


class MemoryAllocator
{
private:
    block * begin;
   // block * b;
public:
    void init();
    void read();
    void *alloc(size_t a);
    void free(void* ptr);
    MemoryAllocator()= default;
    void destroy();
};

void MemoryAllocator::read() {
    std::cout<<begin->size<<std::endl;
}

void MemoryAllocator::init() {
    auto *a = new block[256];
    if (!a)
    {
        std::cout<<"У ОС недостаточно памяти"<<std::endl;
    };
    *begin=*a;
    delete [] a;
    begin = new block;
    begin->size = 256;
    begin->on = false;
    begin->next = nullptr;
    std::cout<<"Начало памяти: "<<begin<<std::endl;
}

void *MemoryAllocator::alloc(size_t a) {
    //auto *b =new block;
    block *b=begin;
    while (1) {
        if ((b->size > a) && (!(b->on))) {
            b->on = true;
            auto *c = new block;
            c->on = false;
            c->size = (b->size - (int)a);
            b->size = a;
            c->next = b->next;
            b->next = c;
            std::cout<<"Адрес следующего:"<<c<<std::endl;
            return b;
        } else if ((b->size == a) && (!(b->on))) {
            b->on = true;
            return b;
        }
        if (b->next != nullptr)
            b = b->next;
            else
        {
            std::cout<<"Вставить не удалось"<<std::endl;
            return nullptr;
        }
    }
}

void MemoryAllocator::free(void *ptr)
{
    block *b= static_cast<block *>(ptr);
    b->on=false;
    while (1)
    {
        if (b->next== nullptr) break;
        if (!b->next->on)
        {
            b->size+=b->next->size;
            b->next=b->next->next;
            delete b->next;
        }
        else break;
    }
}

void MemoryAllocator::destroy()
{
    block * b;
    while (1)
    {
        b=begin->next;
        delete begin;
        if (b== nullptr)
            break;
        begin=b;
    }
}

#endif //LAB4_ALLOCATOR_HPP
