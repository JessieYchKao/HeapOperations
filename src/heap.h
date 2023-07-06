#ifndef HEAP_H
#define HEAP_H

#include <vector>

template <typename T>
class Heap
{
private:
    struct Node
    {
        T value;
        int index;
    };

    std::vector<T> heap;
    bool is_max;
    // Get the parent node for a given index
    Node get_parent(int idx);
    // Get the left child node for a given index (index=-1: no left child)
    Node get_left_child(int idx);
    // Get the right child node for a given index (index=-1: no right child)
    Node get_right_child(int idx);
    // Swap the node with its parent until the heap property is satisfied
    void swap_up(int idx);
    // Swap the node with its child until the heap property is satisfied
    void swap_down(int idx);
    // Swap two nodes
    void swap(T &a, T &b);

public:
    Heap(bool is_max = true)
    {
        this->is_max = is_max;
    }
    // Insert a node into the heap
    void insert(T val);
    // Remove a node from the heap
    void remove();
    // Get the size of the heap
    int size();
    // print the heap
    void print_heap();
};

#endif