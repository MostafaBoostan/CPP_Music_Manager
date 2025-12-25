#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "playlistdata.h"
using namespace std;

template <typename T>
class Queue {
private:
    T* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int capacity);
    bool isEmpty();
    bool isFull();
    void enqueue(T value);
    T dequeue();
};


#endif
