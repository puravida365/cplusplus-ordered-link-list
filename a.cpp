/*
Programmer:  Josue Mora
Date: March 31, 2012
Description: Pointer implementation of an Ordered Linked List
*/

#include <iostream>
using namespace std;

template<class T>
class OrderedLinkedList
{
    private: 
        struct NODE{
            T info;
            NODE *next;
            };
        NODE *list;

    public:
        OrderedLinkedList(){ list=NULL; }
        void Insert(T x)
        { 
            NODE * p = list, *q=list, *r;

            // create a new node
            r = new ( NODE );
            r->info = x;
            r->next = NULL;

            // find the insertion place
            while( p!= NULL && p->info < x )
            { q=p; p=p->next; }
            if ( p==list ) // x is the first info
            { list=r; r->next=p; }
            else if ( p == NULL )    // x is the last info
            { q->next = r; }
            else // x is neither first nor last info
            { r-> next = p; q->next = r; }
        }    
        void display()
        {
            NODE *p=list;
            while( p!= NULL )
            { cout << p->info << "—>"; p=p->next; }
            cout << "NULL\n";                
        }
};

int main()
{

    // create a set of integers
    OrderedLinkedList <int> setA;

    // insert 20,5,11, and 9 in setA
    setA.Insert(20);
    setA.Insert(5);
    setA.Insert(11);
    setA.Insert(9);

    // display setA
    setA.display();

    return(0);
}

/* Sample IO:
$./a.out
5—>9—>11—>20—>NULL
*/