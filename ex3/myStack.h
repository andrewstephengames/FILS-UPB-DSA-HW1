#include <iostream>
using namespace std;

#define NMAX 200

template <typename T>
class Stack
{
private:
    T stackArray[NMAX];
    int topLevel;

public:
    void push(T x)
    {
        if (topLevel >= NMAX - 1)
        {
            cout << "The stack is full: we have already 200 elements!" << endl;
            return;
        }
        
        stackArray[++topLevel] = x;
    }

    int isEmpty()
    {
        return (topLevel < 0);
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "The stack is empty!" << endl;
            T x;
            return x;
        }
    
        return stackArray[topLevel--];
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "The stack is empty!" << endl;
            T x;
            return x;
        }
        return stackArray[topLevel];
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "The stack is empty!" << endl;
        }
        else
        {
            for(int i = topLevel; i >= 0; i--)
            {
                cout << stackArray[i] << ' ';
            }
            cout << endl;
        }
    }

    Stack()
    {                  
        topLevel = -1; 
    }

    ~Stack()
    { 
    }
};