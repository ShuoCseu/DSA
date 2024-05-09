#include "SqList.h"

template <typename Type>
SqList<Type>::SqList(int size)
{
    max = size;
    elems = new Type[max];
    count = 0;
}

template <typename Type>
SqList<Type>::~SqList()
{
    delete [] elems;
}

template <typename Type>
int SqList<Type>::Length () const
{
    return count;
}

template <typename Type>
bool SqList<Type>::Empty() const
{
    return count == 0;
}

template <typename Type>
void SqList<Type>::Clear()
{
    count = 0;
}

template<typename Type>
bool SqList<Type>::GetElem(int position, Type & e) const
{
    if (position < 1 || position > Length())
        return false;
    else
    {
        e = elems[position - 1];
        return true;
    }
}

template <typename Type>
bool SqList<Type>::SetElem(int position, const Type & e)
{
    if (position < 1 || position > Length())
        return false;
    else
    {
        elems[position - 1] = e;
        return true;
    }
}

template <typename Type>
bool SqList<Type>::Delete(int position, Type & e)
{
    if (position < 1 || position > Length())
        return false;
    else
    {
        GetElem(position, e);
        Type temp;
        for (int i = position + 1; i < Length(); i++)
        {
            GetElem(position, temp);
            SetElem(position, temp);
        }
        count--;
        return true;
    }
}

template <typename Type>
bool SqList<Type>::Insert(int position, const Type & e)
{
    if (Length() == max)
        return false;
    else if (position < 1 || position > Length() + 1)
        return false;
    else
    {
        Type temp;
        for (int i = Length();i >= position; i--)
        {
            GetElem(i, temp);
            SetElem(i+1, temp);
        }
        count+
        SetElem(position, e);
        return true;
    }
}