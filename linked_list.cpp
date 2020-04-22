// c++ linked list practice 

#include <iostream>

class LinkedList; 

class ListNode
{
    private:  
        int number;
        ListNode* next;
    public:
        ListNode(int value):number(value), next(NULL){};    // setting number is value
        friend class LinkedList;
};

class LinkedList
{
    private:
        ListNode* first;                // the frist node
    public:
        LinkedList():first(NULL){};     // constructure
        void PrintList();               // print whole data in list
        void Push_front(int x);         // push new node in the front
        void Push_back(int x);          // push new node in the back
        void Delete(int x);             // delete x in the list
        void Delete_all(int x);         // delete all x in the list
        void Clear();                   // delete all list
        void Reverse();                 // reverse all list 
};

void LinkedList::Reverse()
{
    ListNode* previous = NULL;
    ListNode* current = first;

    if(current == NULL)
    {
        std::cout << "empty list" << std::endl;
        return;
    }
    while(current->next != NULL)
    {
        first = first->next;
        current->next = previous;
        previous = current;
        current = first;
    }

    current->next = previous;
    std::cout << "reverse all number in the list" << std::endl;

}

void LinkedList::Clear()
{

    while(first != NULL)
    {
        ListNode* current = first;
        first = first->next;
        delete current;
    }

    std::cout << "delete all number in the list" << std::endl;
}

void LinkedList::PrintList()
{
    if(first == NULL)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
     
    ListNode* current = first;
    while(current != NULL)
    {
        std::cout << current->number << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void LinkedList::Push_front(int x)
{
    ListNode* newnode = new ListNode(x);
    newnode->next = first;
    first = newnode;
}

void LinkedList::Delete(int x)
{
    ListNode* current = first;
    ListNode* previous = NULL;
    
    while((current != NULL) && (current->number != x))
    {
        previous = current;
        current = current->next;
    }

    if(current == NULL)
    {
        std::cout << "there is no " << x << " in the list" << std::endl;
        return;
    }
    else if(current == first)
    {
        first = first->next;
        delete current;
    }
    else 
    {
        previous->next = current->next;
        delete current;
    }

    std::cout << "delete " << x << " in this list" << std::endl;
}

void LinkedList::Delete_all(int x)
{
    ListNode* current = first;
    ListNode* previous = NULL;

    while(current != NULL)
    {
        if(first->number == x)
        {
            first = first->next;
            delete current;
            ListNode* current = first;
        }
        else if(current->number == x)
        {
            previous->next = current->next;
            delete current;
            ListNode* current = previous->next;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    std::cout << "delete all " << x << " in this list" << std::endl;
}

void LinkedList::Push_back(int x)
{
    ListNode* newnode = new ListNode(x);
    if(first == NULL)
    {
        first = newnode;
        return;
    }

    ListNode* current = first;
    while(current->next != NULL)
        current = current->next;
    
    current->next = newnode;
}

int main()
{
    LinkedList l1;
    
    l1.Push_back(1);
    l1.Push_front(9);
    l1.Push_back(2);
    l1.Push_back(5);
    l1.Push_front(6);
    l1.PrintList();
    // 6 9 1 2 5

    l1.Push_back(2);
    l1.Push_front(2);
    l1.PrintList();
    // 2 6 9 1 2 5 2

    l1.Delete(2);
    l1.Delete(7);
    l1.PrintList();
    // 6 9 1 2 5 2

    l1.Delete_all(2);
    l1.PrintList();
    // 6 9 1 5 

    l1.Reverse();
    l1.PrintList();
    // 5 1 9 6 

    l1.Clear();
    l1.PrintList();

    return 0;
}


