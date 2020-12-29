#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

template <class T> class DLLNode
{
    public:
    DLLNode(T e, DLLNode* n = 0, DLLNode* p = 0){
        c = e;
        next = n;
        prev = p;
    }

    T c;
    DLLNode<T>* next;
    DLLNode<T>* prev;
};

template <class T> class DLinkedList
{
    private:
    DLLNode<T>* ListHead;
    DLLNode<T>* ListTail;

    public:
    DLinkedList();

    void addToHead(T e);
    void addToTail(T e);
    void deleteFromHead();
    void deleteFromTail();
    T getListHeadInfo();
    T getListTailInfo();
    bool isEmpty();
};

template <class T> DLinkedList<T>::DLinkedList()
{
    ListHead = NULL;
    ListTail = NULL;
}

template <class T> void DLinkedList<T>::addToHead(T e)
{
    DLLNode<T>* newNode = new DLLNode<T>(e);

    if(ListHead == NULL) //List is empty
    {
        newNode->next = nullptr;
        newNode->prev = nullptr;
        ListTail = newNode;
    }
    else //List contains at least 1 element
    {
        newNode->next = ListHead;
        newNode->prev = nullptr;
        ListHead->prev = newNode;
    }
    
    ListHead = newNode;
    return;
}

template <class T> void DLinkedList<T>::addToTail(T e)
{
    DLLNode<T>* newNode = new DLLNode<T>(e);

    if(ListHead == NULL) //List is empty
    {
        newNode->next = nullptr;
        newNode->prev = nullptr;
        ListHead = newNode;
    }
    else //List contains at least 1 element
    {
        newNode->next = nullptr;
        newNode->prev = ListTail;
        ListTail->next = newNode;
    }
    
    ListTail = newNode;
    return;
}

template <class T> void DLinkedList<T>::deleteFromHead()
{
    std::string errorMessage = "Unable to remove element. Queue is currently empty.\n";

    //Catch if list is empty and throw an exception if so
    try
    {
        if(ListHead == NULL)
            throw errorMessage;
    }
    catch(std::string exception)
    {
        std::cout << exception;
        return throw;
    }

    DLLNode<T>* firstNode = ListHead;
    ListHead = ListHead->next;

    if(ListHead != NULL)
        ListHead->prev = nullptr;

    delete firstNode;
    return;
}

template <class T> void DLinkedList<T>::deleteFromTail()
{
    std::string errorMessage = "Unable to delete the specified element. Queue is currently empty.\n";
    
    //Catch if list is empty and throw an exception if so
    try
    {
        if(ListTail == NULL)
            throw errorMessage;
    }
    catch(std::string exception)
    {
        std::cout << exception;
        return throw;
    }

    DLLNode<T>* lastNode = ListTail;
    ListTail = ListTail->prev;
    
    if(ListTail != NULL)
        ListTail->next = nullptr;

    delete lastNode;
    return;
}

template <class T> T DLinkedList<T>::getListHeadInfo()
{
    //Check if list is empty
    if(ListHead == NULL)
    {
        std::cout << "Unable to return first element. Queue is empty.\n";
        throw;
    }
    return ListHead->c;  
}

template <class T> T DLinkedList<T>::getListTailInfo()
{
    if(ListTail == NULL)
    {
        std::cout << "Unable to return last element. Queue is empty.\n";
        throw;
    }
    return ListTail->c;
}

template <class T> bool DLinkedList<T>::isEmpty()
{
    if(ListHead == NULL)
        return true;
    else
        return false;
}

#endif