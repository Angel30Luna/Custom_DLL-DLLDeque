#ifndef DLLDEQUE_H_
#define DLLDEQUE_H_

#include "DoublyLinkedList.hpp"

template <class T> class DLLDeque
{
    private:
    DLinkedList<T> List;
    int size;
    
    public:
    DLLDeque();

    void insertFront(T e);
    void insertBack(T e);
    void removeFront();
    void removeBack();
    T front() {return List.getListHeadInfo();} //Return queue's first element.
    T back() {return List.getListTailInfo();}  //Return queue's last element.
    int getSize() {return size;}
    bool isEmpty() {return List.isEmpty();}
};

template <class T> DLLDeque<T>::DLLDeque()
{
    size = 0;
}

template <class T> void DLLDeque<T>::insertFront(T e)
{
    List.addToHead(e);
    size++;
}

template <class T> void DLLDeque<T>::insertBack(T e)
{
    List.addToTail(e);
    size++;
}

template <class T> void DLLDeque<T>::removeFront()
{
    List.deleteFromHead();
    size--;
}

template <class T> void DLLDeque<T>::removeBack()
{
    List.deleteFromTail();
    size--;
}

#endif