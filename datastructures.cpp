#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class        : QueueX
//  Description  : Generic Implementation of Queue
//  Author       : Riddhi Dattatraya Sonawane
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct Queuenode
{
    T data;
    struct Queuenode<T> *next;
};

template<class T>
class Queue
{
    private: 
            struct Queuenode<T> *first;
            int iCount;
        
    public:
        Queue();
        void enqueue(T no);
        T dequeue();
        void Display();
        int Count();
};

template<class T>
Queue<T>::Queue()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void Queue<T> :: enqueue(T no)             //InsertFirst
{
    struct Queuenode<T>* newn = new Queuenode<T>();
    struct Queuenode<T>* temp = NULL;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    iCount++;
}

template<class T>
T Queue<T> :: dequeue()                     //DeleteLast
{
    struct Queuenode<T>* temp = NULL;
    T iRet = 0;

    if(first == NULL)
    {
        cout<<"Unable to dequeue as queue is empty\n";
        return NULL;
    }
    else 
    {
        temp = first;
        iRet = temp->data;
        first = first->next;
        delete temp;
        iCount--;
        return iRet;
    }
}

template<class T>
void Queue<T> :: Display()
{
    struct Queuenode<T>* temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |\n";
        temp = temp->next;
    }
}

template<class T>
int Queue<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class        : StackX
//  Description  : Generic Implementation of Stack
//  Author       : Riddhi Dattatraya Sonawane
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct Stacknode
{
    T data;
    struct Stacknode<T> *next;
};

template<class T>
class StackX
{
    private: 
            struct Stacknode<T> *first;
            int iCount;
        
    public:
        StackX();
        void push(T no);
        T pop();
        void Display();
        int Count();
};

template<class T>
StackX<T>::StackX()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void StackX<T> :: push(T no)            
{
    struct Stacknode<T> * newn = new Stacknode<T>();
    
    newn->data = no;
    newn->next = NULL;

    newn->next = first;
    first = newn;

    iCount++;
}

template<class T>
T StackX<T> :: pop()                
{
    struct Stacknode<T> * temp = NULL;
    T value;

    if(first == NULL)
    {
        cout<<"Unable to pop as stack is empty\n";
        return NULL;
    }
    else 
    {
        temp = first;
        value = temp->data;
        first = first->next;
        delete temp;
        iCount--;
        return value;
    }
}

template<class T>
void StackX<T> :: Display()
{
    struct Stacknode<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |\n";
        temp = temp->next;
    }
}

template<class T>
int StackX<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class        : SinglyCLL
//  Description  : Generic Implementation of Singly Circular Linked List
//  Author       : Riddhi Dattatraya Sonawane
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct SinglyCLLnode
{
    T data;
    struct SinglyCLLnode<T> *next;
};

template<class T>
class SinglyCLL
{
private:
        struct SinglyCLLnode<T> *first;
        struct SinglyCLLnode<T>* last;
        int iCount;
public:
    SinglyCLL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void InsertAtPos(T no, int pos);
    void DeleteAtPos(int pos);
    
};

template<class T>
SinglyCLL<T>::SinglyCLL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template<class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct SinglyCLLnode<T>* newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if((NULL == first) && (NULL == last))           //if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;

        last->next = first;
    }

    iCount++;
}

template<class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct SinglyCLLnode<T>* newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if((NULL == first) && (NULL == last))           //if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;

        last->next = first;
    }

    iCount++;
}

template<class T>
void SinglyCLL<T>::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;

        last->next = first;
    }

    iCount--;
}

template<class T>
void SinglyCLL<T>::DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        struct SinglyCLLnode<T>* temp = NULL;
        temp = first;

        while(temp->next != last)
        {
            temp = temp->next;
        }
        
        delete last;
        last = temp;
        last->next = first;            
    }

    iCount--;
}

template<class T>
void SinglyCLL<T>::Display()
{
    struct SinglyCLLnode<T>* temp = NULL;
    temp = first;

    if((first == NULL) && (last == NULL))
    {
        return;
    }

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }while(temp != last->next);
    cout<<"\n";
}

template<class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

template<class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    struct SinglyCLLnode<T>* temp = NULL;
    struct SinglyCLLnode<T>* newn = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > (iCount +1)))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == (iCount + 1))
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template<class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{           
    struct SinglyCLLnode<T>* temp = NULL;
    struct SinglyCLLnode<T>* target = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 0; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;

        delete target;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class        : DoublyCLL
//  Description  : Generic Implementation of Doubly Circular Linked List
//  Author       : Riddhi Dattatraya Sonawane
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> *next;
    struct DoublyCLLnode<T> *prev;
};

template<class T>
class DoublyCLL
{
    private:
        struct DoublyCLLnode<T> * first;
        struct DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

template<class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Inside Constructor\n";
    
    first = NULL;
    last = NULL;
    iCount = 0;
}

template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    struct DoublyCLLnode<T>* newn = NULL;

    newn = new struct DoublyCLLnode<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL) 
    {
        first = newn;
        last = newn;
    }   
    else
    {
        newn->next = first;
        first->prev = newn;

        first = newn;
    } 

    last->next = first;
    first->prev = last;

    iCount++;
}

template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    struct DoublyCLLnode<T>* newn = NULL;

    newn = new struct DoublyCLLnode<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)  
    {
        first = newn;
        last = newn;
    }   
    else   
    {
        last->next = newn;
        newn->prev = last;

        last = newn;
    } 

    last->next = first;
    first->prev = last;
    
    iCount++;
}

template<class T>
void DoublyCLL<T> :: Display()
{
    struct DoublyCLLnode<T>* temp = NULL;
    cout<<"Elements of the LinkedList are : \n";

    temp = first;

    if(first == NULL && last == NULL)
    {
        cout<<"LinkedList is empty\n";
        return;
    }

    do
    {
        cout<<"| "<< temp->data <<" | <=> ";
        temp = temp->next;   
    } while (temp != first);
    cout<<"\n";
}

template<class T>
int DoublyCLL<T> :: Count()
{
    return iCount;  
}

template<class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
    
        first = NULL;
        last = NULL;
    }
    else 
    {
        first = first -> next;
        delete first->prev;     // delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

template<class T>
void DoublyCLL<T> :: DeleteLast()
{
    if(first == NULL && last == NULL) 
    {
        return;
    }
    else if(first == last)  
    {
        delete last;
    
        first = NULL;
        last = NULL;
    }
    else 
    {
        last = last -> prev;
        delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

template<class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    struct DoublyCLLnode<T>* temp = NULL;
    struct DoublyCLLnode<T>* newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct DoublyCLLnode<T>;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    struct DoublyCLLnode<T>* temp = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class        : SinglyLLL
//  Description  : Generic Implementation of Singly Linear Linked List
//  Author       : Riddhi Dattatraya Sonawane
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct SinglyLLLnode
{
    T data;
    struct SinglyLLLnode<T> *next;
};

template<class T>
class SinglyLLL
{
    private :
            struct SinglyLLLnode<T> *first;
            int iCount;
        
    public: 
        SinglyLLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int Count();
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    struct SinglyLLLnode<T>* newn = NULL;

    newn = new struct SinglyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = first;
    first = newn;
}

template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    struct SinglyLLLnode<T>* newn = NULL;
    struct SinglyLLLnode<T>* temp = NULL;

    temp = first;

    newn = new struct SinglyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(NULL == first)
    {
        first = newn;
    }
    else
    {
        while((temp->next) != NULL)
        {
            temp = temp->next;
        }   
        temp->next = newn;    
    }
}

template<class T>
void SinglyLLL<T> :: Display()
{
    struct SinglyLLLnode<T>* temp = NULL;
    temp = first;

    while(temp != NULL)
    {
        printf("| %d | -> ",temp->data);
        temp = temp->next;
    } 

    printf("NULL\n");
}

template<class T>
int SinglyLLL<T> :: Count()
{
    int iCount = 0;

    struct SinglyLLLnode<T>* temp = NULL;
    temp = first;

    while(temp != NULL)
    {
        iCount++;
        temp = temp->next;
    }

    return iCount;
}

template<class T>
void SinglyLLL<T> :: DeleteFirst()
{
    struct SinglyLLLnode<T>* temp = NULL;

    if(first == NULL)   
    {
        return;
    }
    else if(first->next == NULL)
    {
        free(first);
        first = NULL;  
    }
    else                              
    {
        temp = first;
        first = first->next;
        free(temp);
    }
}

template<class T>
void SinglyLLL<T> :: DeleteLast()
{
    struct SinglyLLLnode<T>* temp = NULL;

    if(first == NULL)           
    {
        return;
    }
    else if(first->next == NULL)    
    {
        free(first);
        first = NULL;  
    }
    else                               
    {   
        temp = first;
        while((temp->next->next) != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

template<class T>
void SinglyLLL<T> :: InsertAtPos(T no, int pos)
{   
    struct SinglyLLLnode<T>* newn = NULL;
    struct SinglyLLLnode<T>* temp = NULL;

    int iCount = 0, iCnt = 0;
    iCount = Count();

    if((pos < 1) || (pos > (iCount + 1)))
    {
        printf("Inavlid position\n");
        return ;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == (iCount + 1))
    {
        InsertLast(no);
    }
    else
    {
        temp = first;

        newn = new struct SinglyLLLnode<T>;
        
        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt <= (pos - 2); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

template<class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    int iCount = 0, iCnt = 0;

    struct SinglyLLLnode<T>* temp = NULL;
    struct SinglyLLLnode<T>* target = NULL;

    iCount = Count();

    if((pos < 1) || (pos > iCount))
    {
        printf("Inavlid position\n");
        return ;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1; iCnt <= (pos - 2); iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;

        free(target);

    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class        : DoublyLLL
//  Description  : Generic Implementation of Doubly Linear Linked List
//  Author       : Riddhi Dattatraya Sonawane
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct DoublyLLLnode
{
    T data;
    struct DoublyLLLnode<T> *next;
    struct DoublyLLLnode<T> *prev;        
};

template<class T>
class DoublyLLL
{
    private :
            struct DoublyLLLnode<T> *first;
            int iCount;

    public : 
            DoublyLLL();
            void Display();
            int Count();
            void InsertFirst(T no);
            void InsertLast(T no);
            void DeleteFirst();
            void DeleteLast();
            void InsertAtPos(T no, int pos);
            void DeleteAtPos(int pos);
};

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void DoublyLLL<T> :: Display()
{
    struct DoublyLLLnode<T>* temp = NULL;
    temp = first;

    printf("NULL <=> ");
    while(temp != NULL)
    {
        printf("| %d | <=> ",temp->data);
        temp = temp->next;
    } 

    printf("NULL\n");
}

template<class T>
int DoublyLLL<T> :: Count()
{
    struct DoublyLLLnode<T>* temp = NULL;
    temp = first;

    int iCount = 0;
    while(temp != NULL)
    {
        iCount++;
        temp = temp->next;
    } 

    return iCount;
}

template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{   
    struct DoublyLLLnode<T>* newn = NULL;
    newn = new DoublyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;                  

    if((first) == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        (first)->prev = newn;                 
        first = newn;
    }
}

template<class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    struct DoublyLLLnode<T>* newn = NULL;
    struct DoublyLLLnode<T>* temp = NULL;

    newn = new DoublyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;                     

    if((first) == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;
        while((temp->next) != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;              
    }
}

template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if((first)->next == NULL)
    {
        free(first);
        first = NULL;
    }
    else
    {
        first = first->next;
        free(first->prev);
        first->prev = NULL;                
    }
}

template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    struct DoublyLLLnode<T>* temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else if((first)->next == NULL)
    {
        free(first);
        first = NULL;
    }
    else
    {   
        temp = first;
        while((temp->next->next) != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;               
    }
}

template<class T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    int iCnt = 0;
    struct DoublyLLLnode<T>* temp = NULL;
    struct DoublyLLLnode<T>* newn = NULL;

    if((pos < 1) || pos > (iCount + 1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == (iCount + 1))
    {
        InsertLast(no);
    }
    else
    {   
        newn = new DoublyLLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;                         
        
        temp = first;

        for(iCnt = 1; iCnt <= (pos - 2); iCnt++)
        {   
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;                 
        newn->prev = temp;                      
        temp->next = newn;
    }
}

template<class T>
void DoublyLLL<T> :: DeleteAtPos( int pos)
{
    int iCnt = 0;
    struct DoublyLLLnode<T>* temp = NULL;

    if((pos < 1) || pos > iCount)
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first; 

        for(iCnt = 1; iCnt <= (pos - 2); iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        free(temp->next->prev);                  

        temp->next->prev = temp;               
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class        : BST
//  Description  : Generic Implementation of Binary Search Tree
//  Author       : Riddhi Dattatraya Sonawane
//
//program571
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//838.cpp

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class        : Sorting
//  Description  : Generic Implementation of Sorting Algorithms
//  Author       : Riddhi Dattatraya Sonawane
//
//program595
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Sorting        //Increasing
{
    public:
        T *Arr;
        int iSize;
        bool bSorted;

        Sorting(int no);
        ~Sorting();
        void Accept();
        void Display();
        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();
};

template<class T>
Sorting<T> :: Sorting(int no)
{
    iSize = no;
    bSorted = true;
    Arr = new T[iSize];
}

template<class T>
void Sorting<T> :: Accept()
{
    cout<<"Enter "<<iSize<<" elements : \n";
    
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        cout<<"Enter the element no "<<(i + 1)<<" : ";
        cin>>Arr[i];
        cout<<"\n";
        
        if((i > 0) && (Arr[i - 1] > Arr[i]) && (bSorted == true))      
        {
            bSorted = false;
        }
    }
}

template<class T>
void Sorting<T> :: Display()
{
    cout<<"Elements of the array are : \n";
    
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<"\n";
}

template<class T>
void Sorting<T> :: BubbleSort()
{
    int i = 0, j = 0, temp = 0;

    if(bSorted == true)
    {
        return;
    }

    for(i = 0; i < iSize; i++)           
    {
        for(j = 0; j < iSize - 1; j++)        
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }
    }
}

template<class T>
void Sorting<T> :: BubbleSortEfficient()
{
    int i = 0, j = 0, temp = 0;
    bool bFlag = true;

    if(bSorted == true)
    {
        return;
    }

    for(i = 0;( i < iSize && bFlag == true); i++)    
    {
        
        for(j = 0; j < iSize - 1 - i; j++)          
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;

                bFlag = true;
            }
        }
    }
}

template<class T>
void Sorting<T> :: SelectionSort()
{
    int i = 0, j = 0, min_index = 0, temp = 0;

    for(i = 0;i < iSize-1; i++)
    {
        min_index = i;

        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }

        if(i != min_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }
}

template<class T>
void Sorting<T> :: InsertionSort()
{
    int i = 0, j = 0, selected = 0;

    for(i = 1; i < iSize; i++)
    {
        for(j = i - 1, selected = Arr[i]; (j >= 0 && Arr[j] > selected); j--)
        {
            Arr[j + 1] = Arr[j];
        }

        Arr[j + 1] = selected;
    }
}

template<class T>
Sorting<T> :: ~Sorting()
{
    delete []Arr;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class        : Searching
//  Description  : Generic Implementation of Searching Algorithms
//  Author       : Riddhi Dattatraya Sonawane
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Searching             //Increasing
{
    public:
        T *Arr;
        int iSize;
        bool bSorted;

        Searching(T no);
        void Accept();
        void Display();
        bool LinearSearch(T no); 
        bool BiDirectionalSearch(T no);
        bool BinarySearchInc(T iNo);
        bool BinarySearchEfficientInc(T iNo);
        bool BinarySearchDec(T iNo);
        bool BinarySearchEfficientDec(T iNo);
        bool CheckSortedInc();
        bool CheckSortedDec();
        ~Searching();
};

template<class T>
Searching<T> :: Searching(T no)
{
    iSize = no;
    bSorted = true;
    Arr = new T[iSize];
}

template<class T>
void Searching<T> :: Accept()
{
    cout<<"Enter "<<iSize<<" elements : \n";
    
    int i =0;

    for(i = 0; i < iSize;i++)
    {
        cout<<"Enter the element no "<<i+1<<" : ";
        cin>>Arr[i];
        cout<<"\n";
        if((i > 0) && (Arr[i - 1] > Arr[i]) && (bSorted == true))           
        {
            bSorted = false;
        }
    }
}

template<class T>
void Searching<T> :: Display()
{
    cout<<"Elements of the array are : \n";
    
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<"\n";
}

template<class T>
bool Searching<T> :: LinearSearch(T no)       
{
    int i = 0;
    bool bFlag = false;

    if(bSorted == true)                            
    {
        cout<<"Data is sorted\n";
        return BinarySearchEfficientInc(no);
    }

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == no)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

template<class T>
bool Searching<T> :: BiDirectionalSearch(T no)   
{
    int iStrat = 0;
    int iEnd = 0;

    bool bFlag = false;

    if(bSorted == true)
    {
        return BinarySearchEfficientInc(no);        
    }

    for(iStrat = 0, iEnd = iSize-1 ; iStrat <= iEnd; iStrat++, iEnd--)
    {
        if(Arr[iStrat] == no || Arr[iEnd] == no)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

template<class T>
bool Searching<T> :: BinarySearchInc(T iNo)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize -1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == iNo)
        {
            bFlag = true;
            break;
        }
        else if(Arr[iMid] > iNo)      
        {
            iEnd = iMid - 1;
        }
        else if(Arr[iMid] < iNo)         
        {
            iStart = iMid + 1;
        }
    }

    return bFlag;
}

template<class T>
bool Searching<T> :: BinarySearchEfficientInc(T iNo)
{
    if(bSorted == false)
    {
        cout<<"Data is not sorted\n";
        return LinearSearch(iNo);           
    }

    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize -1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == iNo) || (Arr[iStart] == iNo) || (Arr[iEnd] == iNo)) 
        {
            bFlag = true;
            break;
        }
        else if(Arr[iMid] > iNo)       
        {
            iEnd = iMid - 1;
        }
        else if(Arr[iMid] < iNo)     
        {
            iStart = iMid + 1;
        }
    }

    return bFlag;
}

template<class T>
bool Searching<T> :: BinarySearchDec(T iNo)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize -1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == iNo)
        {
            bFlag = true;
            break;
        }
        else if(Arr[iMid] < iNo)        
        {
            iEnd = iMid - 1;
        }
        else if(Arr[iMid] > iNo)    
        {
            iStart = iMid + 1;
        }
    }

    return bFlag;
}

template<class T>
bool Searching<T> :: BinarySearchEfficientDec(T iNo)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize -1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == iNo) || (Arr[iStart] == iNo) || (Arr[iEnd] == iNo))
        {
            bFlag = true;
            break;
        }
        else if(Arr[iMid] < iNo)        
        {
            iEnd = iMid - 1;
        }
        else if(Arr[iMid] > iNo)        
        {
            iStart = iMid + 1;
        }
    }

    return bFlag;
}

template<class T>
bool Searching<T> :: CheckSortedInc()
{
    int iCnt = 0;
    bool bFlag = true;

    for(iCnt = 0; iCnt < iSize - 1; iCnt++)
    {
        if(Arr[iCnt] > Arr[iCnt+1])
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}

template<class T>
bool Searching<T> :: CheckSortedDec()
{
    int iCnt = 0;
    bool bFlag = true;

    for(iCnt = 0; iCnt < iSize - 1; iCnt++)
    {
        if(Arr[iCnt] < Arr[iCnt+1])
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}

template<class T>
Searching<T> :: ~Searching()
{
    delete []Arr;
}
  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Assignment no - 34, 35, 36 functions -> cpp -> generic
//write all functions logic in all types of LINKED LIST
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    
    return 0;
}