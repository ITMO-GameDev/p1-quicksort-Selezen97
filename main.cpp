#include<iostream>
#include "Dictionary.hpp"
using namespace std;

int main()
{
    Dictionary<std::string, int> t;
    t.put("health", 10);
    t.put("ammo",25);
    t.display();
    t.remove("ammo");
    t.display();
}