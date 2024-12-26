/**
 * d_ary_heap.h
 * This header defines a d-ary heap class implemented using an array.
 * The heap supports the following operations:
 * - Insert a new element.
 * - Extract the maximum element.
 * - Increase the key of an existing element.
 * - Sort the heap.
 */

#ifndef D_ARY_HEAP_H
#define D_ARY_HEAP_H

#include <vector>
#include <algorithm>

using namespace std;

/**
 * DAryHeap class representing a d-ary heap.
 * @tparam T The type of elements stored in the heap.
 */
template <typename T>
class DAryHeap
{
private:
    int d;                  // Number of children per node
    vector<T> heap;    // Internal array representation of the heap

    /**
     * Returns the parent index of a given node.
     * @param i Index of the node.
     * @return Index of the parent.
     */
    int parent(int i) const { return (i - 1) / d; }

    /**
     * Returns the index of the k-th child of a given node.
     * @param i Index of the node.
     * @param k The child number (1 to d).
     * @return Index of the child.
     */
    int child(int i, int k) const { return d * i + k; }

    /**
     * Maintains the heap property by moving an element down the tree.
     * @param i Index of the element to move down.
     * @param comparisons Counter for the number of comparisons made.
     * @param swaps Counter for the number of swaps made.
     */
    void heapifyDown(int i, int& comparisons, int& swaps);

    /**
     * Maintains the heap property by moving an element up the tree.
     * @param i Index of the element to move up.
     * @param comparisons Counter for the number of comparisons made.
     * @param swaps Counter for the number of swaps made.
     */
    void heapifyUp(int i, int& comparisons, int& swaps);

public:
    /**
     * Constructor for the d-ary heap.
     * @param d The degree of the heap (number of children per node).
     */
    explicit DAryHeap(int d) : d(d) {}

    /**
     * Inserts a new element into the heap.
     * @param value The value to insert.
     * @param comparisons Counter for the number of comparisons made.
     * @param swaps Counter for the number of swaps made.
     */
    void insert(T value, int& comparisons, int& swaps);

    /**
     * Extracts the maximum element from the heap.
     * @param comparisons Counter for the number of comparisons made.
     * @param swaps Counter for the number of swaps made.
     * @return The maximum element.
     */
    T extractMax(int& comparisons, int& swaps);

    /**
     * Increases the key of a specific element and restores the heap property.
     * @param i Index of the element.
     * @param newValue The new value to set (should be greater than the current value).
     * @param comparisons Counter for the number of comparisons made.
     * @param swaps Counter for the number of swaps made.
     */
    void increaseKey(int i, T newValue, int& comparisons, int& swaps);

    /**
     * Sorts the heap using heap sort and returns a sorted array.
     * @param comparisons Counter for the number of comparisons made.
     * @param swaps Counter for the number of swaps made.
     * @return A sorted vector containing the elements of the heap.
     */
    vector<T> sort(int& comparisons, int& swaps);
};

// Implementation of private and public methods

template <typename T>
void DAryHeap<T>::heapifyDown(int i, int& comparisons, int& swaps)
{
    int largest = i;
    for (int k = 1; k <= d; ++k)
    {
        int c = child(i, k);
        if (c < heap.size())
        {
            ++comparisons;
            if (heap[c] > heap[largest])
            {
                largest = c;
            }
        }
    }
    if (largest != i)
    {
        ++swaps;
        swap(heap[i], heap[largest]);
        heapifyDown(largest, comparisons, swaps);
    }
}

template <typename T>
void DAryHeap<T>::heapifyUp(int i, int& comparisons, int& swaps)
{
    while (i > 0 && heap[i] > heap[parent(i)])
    {
        ++comparisons;
        ++swaps;
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

template <typename T>
void DAryHeap<T>::insert(T value, int& comparisons, int& swaps)
{
    heap.push_back(value);
    heapifyUp(heap.size() - 1, comparisons, swaps);
}

template <typename T>
T DAryHeap<T>::extractMax(int& comparisons, int& swaps)
{
    T maxVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0, comparisons, swaps);
    return maxVal;
}

template <typename T>
void DAryHeap<T>::increaseKey(int i, T newValue, int& comparisons, int& swaps)
{
    if (newValue < heap[i]) return;
    heap[i] = newValue;
    heapifyUp(i, comparisons, swaps);
}

template <typename T>
vector<T> DAryHeap<T>::sort(int& comparisons, int& swaps)
{
    vector<T> sorted;
    while (!heap.empty())
    {
        sorted.push_back(extractMax(comparisons, swaps));
    }
    reverse(sorted.begin(), sorted.end());

    return sorted;
}

#endif // D_ARY_HEAP_H
