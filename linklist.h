#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
#include "node.h"

using namespace std;

class LinkedList {
private:
    Node* Head;
    Node* Tail;
    int Size;
public:
    LinkedList();
    int get_size() const;
    bool empty() const;
    Song front() const;
    Song back() const;
    Song get_index(int index);
    void del_index(int index);
    void push_front(const Song& e);
    void push_back(const Song& e);
    void pop_front();
    void pop_back();
    Node* Partition(Node* low, Node* high);
    void QuickSort(Node* low, Node* high);
    void SortByYear();

};

#endif