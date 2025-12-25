#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "song.h"

using namespace std;

class Node {
public:
    Node* Next;
    Node* Prev;
    Song Data;
    Node(Song _Data);
};

#endif