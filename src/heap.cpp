#include "heap.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <typename T>
void Heap<T>::insert(T val)
{
    if (heap.size() == 0)
    {
        heap.push_back(val);
    }
    else
    {
        heap.push_back(val);
        swap_up(heap.size() - 1);
    }
}

template <typename T>
void Heap<T>::remove()
{
    swap(heap.front(), heap.back());
    heap.pop_back();
    swap_down(0);
}

template <typename T>
int Heap<T>::size()
{
    return heap.size();
}

template <typename T>
void Heap<T>::print_heap()
{
    int level = 0;
    while (level <= log2(heap.size()))
    {
        int idx = level == 0 ? 0 : static_cast<int>(pow(2, level)) - 1;
        for (int i = 0; i < static_cast<int>(pow(2, level)); i++)
        {
            if (idx + i >= static_cast<int>(heap.size()))
            {
                cout << endl;
                return;
            }
            cout << heap[idx + i] << "\t";
        }
        cout << endl;
        level++;
    }
}

template <typename T>
void Heap<T>::swap_up(int idx)
{
    if (idx == 0)
        return;
    typename Heap<T>::Node parent = get_parent(idx);
    if (is_max && parent.value < heap[idx]) // Max heap with a smaller parent
    {
        swap(heap[idx], heap[parent.index]);
        swap_up(parent.index);
    }
    else if (!is_max && parent.value > heap[idx]) // Min heap with a bigger parent
    {
        swap(heap[idx], heap[parent.index]);
        swap_up(parent.index);
    }
}

template <typename T>
void Heap<T>::swap_down(int idx)
{
    if (idx >= static_cast<int>(heap.size()))
        return;
    typename Heap<T>::Node left = get_left_child(idx);
    typename Heap<T>::Node right = get_right_child(idx);
    if (left.index == -1 && right.index == -1) // No child
        return;
    else if (right.index == -1) // Only has left child
    {
        if (is_max && heap[idx] < left.value) // Max heap with a bigger left child
            swap(heap[idx], heap[left.index]);
        else if (!is_max && heap[idx] > left.value) // Min heap with a smaller left child
            swap(heap[idx], heap[left.index]);
    }
    else
    { // Has left and right child
        if (is_max) // Max Heap
        {
            if (heap[idx] >= left.value && heap[idx] >= right.value) // Do not need to swap
                return;
            else if (left.value >= right.value) // Left child is bigger
            {
                swap(heap[idx], heap[left.index]);
                swap_down(left.index);
            }
            else // Right child is bigger
            {
                swap(heap[idx], heap[right.index]);
                swap_down(right.index);
            }
        }
        else// Min Heap
        {
            if (heap[idx] <= left.value && heap[idx] <= right.value) // Do not need to swap
                return;
            else if (left.value <= right.value)
            { // Left child is smaller
                swap(heap[idx], heap[left.index]);
                swap_down(left.index);
            }
            else
            { // Right child is smaller
                swap(heap[idx], heap[right.index]);
                swap_down(right.index);
            }
        }
    }
}

template <typename T>
void Heap<T>::swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
typename Heap<T>::Node Heap<T>::get_parent(int idx)
{
    typename Heap<T>::Node parent;
    parent.index = (idx - 1) / 2;
    parent.value = heap[parent.index];
    return parent;
}

template <typename T>
typename Heap<T>::Node Heap<T>::get_left_child(int idx)
{
    typename Heap<T>::Node left;
    left.index = (idx + 1) * 2 - 1;
    if (left.index >= static_cast<int>(heap.size()))
    {
        left.index = -1;
        return left;
    }
    left.value = heap[left.index];
    return left;
}

template <typename T>
typename Heap<T>::Node Heap<T>::get_right_child(int idx)
{
    typename Heap<T>::Node right;
    right.index = (idx + 1) * 2;
    if (right.index >= static_cast<int>(heap.size()))
    {
        right.index = -1;
        return right;
    }
    right.value = heap[right.index];
    return right;
}

template class Heap<int>; 
template class Heap<double>;
template class Heap<string>;