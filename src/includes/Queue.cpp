#include "Queue.h"

Queue::Queue(int capacity){
    this->front = 0;
    this->rear  = -1;
    this->size = 0;
    this->capacity = capacity;

    this->arr = new int[this->capacity];
}

Queue::~Queue(){
    delete this->arr;
}

bool Queue::isEmpty(){return this->size == 0;}
bool Queue::isFull (){return this->capacity == 0;}


void Queue::push(int num){
    if(this->isFull())
        return;
    
    this->rear = (this->rear + 1) % this->capacity;
    
    this->arr[rear] = num;
    this->size ++;
}

int Queue::pop(){
    if(this->isEmpty())
        return -1;
    
    int top = this->arr[front];

    this->front = (this->front + 1) % this->capacity;
    this->size --;

    return top;
}