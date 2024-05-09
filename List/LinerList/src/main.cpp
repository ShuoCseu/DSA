#include <iostream>
#include "SqList.h"

int main()
{
    SqList<int> list(7);
    list.Insert(1, 5);
    list.Insert(2, 2);
    list.Insert(3, 0);
    list.Insert(4, 1);
    list.Insert(5, 3);
    list.Insert(6, 1);
    list.Insert(7, 4);
    for (int i = 1; i <= list.Length();i++)
    {
        int temp;
        list.GetElem(i, temp);
        std::cout << temp << "\t";
    }
    std::cout << "\n";
    list.SetElem(3, 1);
    for (int i = 1; i <= list.Length();i++)
    {
        int temp;
        list.GetElem(i, temp);
        std::cout << temp << "\t";
    }
    std::cout << "\n";
    return 0;
}