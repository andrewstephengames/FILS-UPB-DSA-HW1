#include <iostream>
using namespace std;

#define NMAX 200

template<typename T> class Queue {
    private:

        T queueArray[NMAX];
        int head, tail, size;

    public:

        int getHead(){
            return head;
        }

        int getTail(){
            return tail;
        }

        int getSize(){
            return size;
        }

        void enqueue(T x) {
            if (size == NMAX) {
                fprintf(stderr, "Error 101 - The queue is full!\n");
                return;
            }
            queueArray[tail] = x;
            tail = (tail + 1) % NMAX;
            size++;
        }

        T dequeue() {
            if (isEmpty()) {
                fprintf(stderr, "Error 102 - The queue is empty!\n");
                T x;
                return x;
            }
            T x = queueArray[head];
            head = (head + 1) % NMAX;
            size--;
            return x;
}
        T peek() {
            if (isEmpty()) {
                fprintf(stderr, "Error 103 - The queue is empty!\n");
                T x;
                return x;
            }
            return queueArray[head];
        }

        int isEmpty() {
            return (size == 0);
        }

        void print(){
           for (int i = head; i < tail; i++)
                cout << queueArray[i] << " ";
            cout << endl;
        }

    Queue() {
        head = tail = size = 0;
    }
};

