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
    delete[] elems;
}

template <typename Type>
int SqList<Type>::Length() const
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

template <typename Type>
bool SqList<Type>::GetElem(int position, Type &e) const
{
    if (position < 1 || position > count)
        return false;
    e = elems[position - 1];
    return true;
}

template <typename Type>
bool SqList<Type>::SetElem(int position, const Type &e)
{
    if (position < 1 || position > count)
        return false;
    elems[position - 1] = e;
    return true;
}

template <typename Type>
bool SqList<Type>::Delete(int position, Type &e)
{
    if (position < 1 || position > count)
        return false;
    e = elems[position - 1];
    for (int i = position; i < count; ++i)
        elems[i - 1] = elems[i];
    --count;
    return true;
}

template <typename Type>
bool SqList<Type>::Insert(int position, const Type &e)
{
    if (position < 1 || position > count + 1 || count >= max)
        return false;
    for (int i = count; i >= position; --i)
        elems[i] = elems[i - 1];
    elems[position - 1] = e;
    ++count;
    return true;
}

// Explicit instantiation of SqList class for required types
template class SqList<int>;
// Add other explicit instantiations for other types if needed
