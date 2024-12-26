/**
 * main.cpp
 * This file demonstrates the use of the DAryHeap class for sorting arrays of random numbers.
 * It evaluates the performance of d-ary heap sort for different values of d (2, 3, 4, 5).
 */

#include <iostream>
#include <vector>
#include <random>
#include "d_ary_heap.h"

using namespace std;

/**
 * Generates a series of random integers.
 * @param series Vector to store the random numbers.
 * @param size Number of random integers to generate.
 * @param maxVal Maximum value for the random integers.
 */
void generateRandomSeries(std::vector<int>& series, int size, int maxVal)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, maxVal);

    series.resize(size);
    for (int& num : series)
    {
        num = dis(gen);
    }
}

/**
 * Tests heap sort on a given series for a specific d value.
 * @param series Input series of numbers.
 * @param d Degree of the heap.
 */
void testHeapSort(const std::vector<int>& series, int d)
{
    int comparisons = 0, swaps = 0;
    DAryHeap<int> heap(d);

    for (int num : series)
    {
        heap.insert(num, comparisons, swaps);
    }

    heap.sort(comparisons, swaps);

    cout << "d = " << d << ": " 
              << comparisons << " comparisons, " 
              << swaps << " swaps" << endl;
}

int main()
{
    vector<int> A, B, C;
    
    generateRandomSeries(A, 50, 1023);
    generateRandomSeries(B, 100, 1023);
    generateRandomSeries(C, 200, 1023);

    cout << "Testing series A (size 50):" << endl;
    for (int d = 2; d <= 5; ++d)
    {
        testHeapSort(A, d);
    }

    cout << "Testing series B (size 100):" << endl;
    for (int d = 2; d <= 5; ++d)
    {
        testHeapSort(B, d);
    }

    cout << "Testing series C (size 200):" << endl;
    for (int d = 2; d <= 5; ++d)
    {
        testHeapSort(C, d);
    }

    return 0;
}
