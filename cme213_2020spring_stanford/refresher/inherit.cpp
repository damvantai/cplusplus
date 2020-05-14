//
// Created by tai94bn on 5/12/2020.
//
#include <iostream>

class A
{
public:
    virtual int get_id() = 0;
};

class B : public A
{
public:
    int get_id() override {return 1;}
};

class C : public B
{
public:
    int get_id() override { return 2;}
};

int main()
{
    C c;

    std::cout << c.get_id() << std::endl;

    B b = static_cast<B>(c);
    std::cout << b.get_id() << std::endl;

    B *bptr = &c;
    A *aptr = &c;
    std::cout << bptr->get_id() << std::endl;
    std::cout << aptr->get_id() << std::endl;
    return 0;
}

