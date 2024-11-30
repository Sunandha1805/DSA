// ************** implementing Queue/Circular-Queue using arr *************

#include <bits/stdc++.h>
using namespace std;

class Queue {
    int front, rare, curSize, maxSize;
    int * arr;

    Queue(int maxSize){
        (* this).maxSize = maxSize;
        front = -1;
        rare = -1;
        curSize = -1;
        arr = new int[maxSize];
    }
};