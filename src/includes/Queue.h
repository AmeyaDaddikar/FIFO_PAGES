#ifndef QUEUE_H
#define QUEUE_H

//QUEUE CLASS DESIGNED TO SPECIFICALLY HANDLE INT
class Queue{

private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Queue(int capacity);
    virtual ~Queue();

    bool isEmpty();
    bool isFull();

    void push(int num);
    int pop();
};

#endif