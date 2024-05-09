#ifndef SQLIST_H_
#define SQLIST_H_

template <typename Type>
class SqList
{
private:
    int max;
    Type *elems;
    int count;
public:
    SqList(int size);
    ~SqList();
    int Length() const;
    bool Empty() const;
    void Clear();
    // void Tranverse()
    bool GetElem(int position, Type & e) const;
    bool SetElem(int position, const Type & e);
    bool Delete(int position, Type & e);
    bool Insert(int position, const Type & e);
};


#endif