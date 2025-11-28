#pragma once
#include<iostream>


class Item{
    const char* str;

public:
    Item():str(nullptr){}

    Item(const char *as): str(as){}

    const char* getString(){
        return str;
    }

};