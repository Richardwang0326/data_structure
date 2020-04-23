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
        int listtoint();                // transform list to int
        LinkedList operator+(const LinkedList&);        // operator overload
};

// carry
bool iscarry(int x)
{
    bool carry = false;
    if(x >= 10)
        carry = true;

    return carry;
}

LinkedList LinkedList::operator+(const LinkedList& list)
{
    LinkedList sum;
    bool carry = false;

    ListNode* cur1 = this->first;
    ListNode* cur2 = list.first;

    while(1)
    {
        if((cur1 != NULL) || (cur2 != NULL))
        {
            if(cur1 == NULL)
            {
                if(carry)
                    cur2->number += 1;
                carry = iscarry(cur2->number);
                if(carry)
                    sum.Push_back(cur2->number % 10);
                else 
                    sum.Push_back(cur2->number);
                cur2 = cur2->next;
            }
            else if(cur2 == NULL)
            {
                if(carry)
                    cur1->number += 1;
                carry = iscarry(cur1->number);
                if(carry)
                    sum.Push_back(cur1->number % 10);
                else 
                    sum.Push_back(cur1->number);
                cur1 = cur1->next;
            }
            else
            {
                if(carry)
                    cur1->number += 1;
                carry = iscarry(cur1->number + cur2->number);
                if(carry)
                    sum.Push_back((cur1->number + cur2->number) % 10);
                else
                    sum.Push_back(cur1->number + cur2->number);
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
        }
        else 
        {
            if(carry)
            {
                sum.Push_back(1);
                carry = false;
            }
            else
                break;
        }
    }
    return sum;
}

// transform int to list
LinkedList inttolist(int x)
{
    LinkedList result;

    while(x>=10)
    {
        result.Push_back(x % 10);
        x /= 10;
    }
    result.Push_back(x);

    return result;
}

int LinkedList::listtoint()
{
    int num = 0;
    Reverse();
    ListNode* current = first;

    while(current != NULL)
    {
        num = num * 10 + current->number;
        current = current->next;
    }
    return num;
}

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
    int num1,num2,num3;
    std::cout << "input number: ";
    std::cin >> num1;

    std::cout << "input number: ";
    std::cin >> num2;
    std::cout << std::endl;
    
    LinkedList list1 = inttolist(num1);
    LinkedList list2 = inttolist(num2);
    LinkedList list3 = inttolist(num3);
    LinkedList sum = list1 + list2;
    
    std::cout << num1 << " + " << num2 << " = "<< sum.listtoint() << std::endl; 

    return 0;
}


