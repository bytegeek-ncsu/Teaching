#pragma once

class IntArray
{
    int size;
    int *array;

public:
    IntArray(int asize = 100)
    {
        size = asize;
        array = new int[size];
    }

    IntArray(const IntArray &copy);
    IntArray &operator=(const IntArray &rhs);
    IntArray operator + (const IntArray &rhs) const;
    int& operator[](int index);
    void set(int index, int val)
    {
        array[index] = val;
    }

    int get(int index)
    {
        return array[index];
    }
};
