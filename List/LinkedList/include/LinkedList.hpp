#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

template <typename T>
class LinkedList
{
private:
    T data;
    T* next;
public:
    LinkedList();
    ~LinkedList();
    int Length() const;
    bool Empty() const;
    void Clear();
    // void Tranverse()
    bool GetElem(int position, T & e) const;
    bool SetElem(int position, const T & e);
    bool Delete(int position, T & e);
    bool Insert(int position, const T & e);
};

#endif