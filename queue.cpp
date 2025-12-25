#include "queue.h"

template <typename T>
Queue<T>::Queue(int capacity) {
    this->capacity = capacity;
    arr = new T[capacity];
    front = 0;
    rear = -1;
    size = 0;
}

template <typename T>
bool Queue<T>::isEmpty() {
    return size == 0;
}

template <typename T>
bool Queue<T>::isFull() {
    return size == capacity;
}

template <typename T>
void Queue<T>::enqueue(T value) {
    if (isFull()){
        return;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = value;
    size++;
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()){
        return T();
    }
    T value = arr[front];
    front = (front + 1) % capacity;
    size--;
    return value;
}


template class Queue<int>;
template class Queue<float>;
template class Queue<double>;
template class Queue<PlayListData>;