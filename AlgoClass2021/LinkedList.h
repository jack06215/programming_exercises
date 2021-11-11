#include <iostream>
#include <string>

using namespace std;
template <typename T>

struct Value
{
    T m_Value;
    Value()
    {
        m_Value = 0;
    }
};

template <>
struct Value <string>
{
    string m_Value;
    Value()
    {
        m_Value.assign("");
    }
};

template <typename T>
struct Node
{
    Node();
    Value<T> m_Value;
    Node<T>* m_Prev;
    Node<T>* m_Next;
};

template <typename T>
Node<T>::Node()
{
    m_Prev = nullptr;
    m_Next = nullptr;
}

template <typename T>
class LinkedList
{
private:
    Node<T>* m_Head;
    Node<T>* m_Tail;
    bool m_IsEmpty;

public:
    LinkedList();
    bool push_back(T val);
    bool push_front(T val);
    bool pop_back();
    bool pop_front();
    bool printList();
};

template <typename T>
LinkedList<T>::LinkedList() :
    m_Head(nullptr),
    m_Tail(nullptr),
    m_IsEmpty(true)
{
}

template <typename T>
bool LinkedList<T>::push_back(T val)
{
    Node<T>* node = new Node<T>;
    node->m_Value.m_Value = val;
    if (false == m_IsEmpty)
    {
        m_Tail->m_Next = node;
        node->m_Prev = m_Tail;
        m_Tail = node;
    }
    else
    {
        // First Node is going to insert from here
        m_Head = m_Tail = node;
    }
    m_IsEmpty = false;
    return true;
}

template <typename T>
bool LinkedList<T>::push_front(T val)
{
    Node<T>* node = new Node<T>;
    node->m_Value.m_Value = val;
    if (false == m_IsEmpty)
    {
        node->m_Next = m_Head;
        m_Head->m_Prev = node;
        m_Head = node;
    }
    else
    {
        // First Node is going to insert from here
        m_Head = m_Tail = node;
    }
    m_IsEmpty = false;
    return true;
}

template <typename T>
bool LinkedList<T>::pop_back()
{
    if (false == m_IsEmpty)
    {
        Node<T>* delNode = m_Tail;
        m_Tail = m_Tail->m_Prev;

        if (nullptr == m_Tail)
        {
            // Here Linked List is having only one node and 
            // we are deleting that. So, m_Head also need to be updated
            m_Head = nullptr;
        }

        m_Tail->m_Next = nullptr;

        if (delNode)
        {
            delete delNode;
            delNode = nullptr;
        }

        // Update m_IsEmpty
        if ((nullptr == m_Head) && (nullptr == m_Tail))
            m_IsEmpty = true;
        else
            m_IsEmpty = true;

        return true;
    }
    else
    {
        cout << "pop_back() FAILED !! There is no element into linked list.";
        // First Node is going to insert from here
        m_IsEmpty = true;
    }
    return false;
}

template <typename T>
bool LinkedList<T>::pop_front()
{
    if (false == m_IsEmpty)
    {
        Node<T>* delNode = m_Head;
        m_Head = m_Head->m_Next;

        if (nullptr == m_Head)
        {
            // Here Linked List is having only one node and 
            // we are deleting that. So, m_Head also need to be updated
            m_Tail = nullptr;
        }

        m_Head->m_Prev = nullptr;

        if (delNode)
        {
            delete delNode;
            delNode = nullptr;
        }

        // Update m_IsEmpty
        if ((nullptr == m_Head) && (nullptr == m_Tail))
            m_IsEmpty = true;
        else
            m_IsEmpty = true;

        return true;
    }
    else
    {
        cout << "pop_front() FAILED !! There is no element into linked list." << endl;
        // First Node is going to insert from here
        m_IsEmpty = true;
    }

    return false;
}

template <typename T>
bool LinkedList<T>::printList()
{
    Node<T>* node = m_Head;
    while (node != nullptr)
    {
        cout << node->m_Value.m_Value << endl;
        node = node->m_Next;
    }
    cout << endl;
}
