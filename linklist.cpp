#include "linklist.h"

LinkedList::LinkedList() : Head(nullptr), Tail(nullptr), Size(0) {}

int LinkedList:: get_size() const{
    return Size;
}

bool LinkedList:: empty() const{
    if(Head == nullptr){
        return 1;
    }
    return 0;
}

Song LinkedList:: front() const{
    return Head->Data;
} 

Song LinkedList:: back() const{
    return Tail->Data;
} 

Song LinkedList:: get_index(int index){
    Node* temp = Head;
    for(int i = 0; i < index; i++){
        temp = temp->Next;
    }
    return temp->Data;
}

void LinkedList::del_index(int index){
    Node* temp = Head;
    if(index == this->Size - 1){
        this->pop_back();
        return;
    }
    else if(index == 0){
        this->pop_front();
        return;
    }
    for(int i = 0; i < index - 1; i++, temp = temp->Next);
    Node* tempd = temp->Next;
    temp->Next = temp->Next->Next;
    delete tempd;
    Size--;
}

void LinkedList:: push_front(const Song& e){
    Node* NewNode = new Node(e);
    if(empty()){
        Head = Tail = NewNode;
    }
    else{
        Head->Prev = NewNode;
        NewNode->Next = Head;
        Head = NewNode;
    }
    Size++;
}

void LinkedList:: push_back(const Song& e){
    Node* NewNode = new Node(e);
    if(empty()){
        Head = Tail = NewNode;
    }
    else{
        Tail->Next = NewNode;
        NewNode->Prev = Tail;
        Tail = NewNode;
    }
    Size++;
}

void LinkedList:: pop_front(){
    if(Head == Tail){
        delete Head;
        Head = nullptr;
        Tail = nullptr;
    }
    else{
        Head = Head->Next;
        delete Head->Prev;
    }
    Size--;
}

void LinkedList:: pop_back(){
    if(Head == Tail){
        delete Head;
        Head = nullptr;
        Tail = nullptr;
    }
    else{
        Tail = Tail->Prev;
        delete Tail->Next;
    }
    Size--;
}

Node* LinkedList:: Partition(Node* low, Node* high){
    int pivot = high->Data.getYear(); 
    Node* i = low->Prev; 

    for (Node* j = low; j != high; j = j->Next) {
        if (j->Data.getYear() < pivot) {
            i = (i == nullptr) ? low : i->Next; 
            swap(i->Data, j->Data);           
        }
    }
    i = (i == nullptr) ? low : i->Next; 
    swap(i->Data, high->Data);          
    return i;                           
}

void LinkedList:: QuickSort(Node* low, Node* high){
    if (low != nullptr && high != nullptr && low != high && low != high->Next) {
        Node* pivot = Partition(low, high);
        QuickSort(low, pivot->Prev); 
        QuickSort(pivot->Next, high); 
    }
}

void LinkedList:: SortByYear(){
    QuickSort(Head, Tail);
}