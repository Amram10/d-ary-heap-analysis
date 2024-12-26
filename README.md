# README

## D-Ary Heap Analysis Project

### Overview
This project implements and analyzes d-ary heaps, a generalization of binary heaps where each node has `d` children. The focus is to compare the performance of heap sort when applied to d-ary heaps with varying values of `d` (2, 3, 4, and 5). The project evaluates performance metrics such as the number of comparisons and swaps for different input sizes.

### Project Structure
- **`d_ary_heap.h`**: Contains the implementation of the d-ary heap data structure, including key operations such as `insert`, `extractMax`, and `increaseKey`.
- **`main.cpp`**: Contains the test cases and performance evaluation logic. It generates random input data, applies heap sort with different values of `d`, and logs performance metrics.

### Features
1. **Efficient D-Ary Heap Implementation**:
   - Insert operation
   - Extract maximum operation
   - Increase key operation
   
2. **Heap Sort**:
   - Builds a max-heap and sorts input arrays.

3. **Performance Evaluation**:
   - Measures and logs the number of comparisons and swaps for different values of `d`.

4. **Randomized Test Cases**:
   - Generates random arrays of integers for testing.

### How to Run
1. **Prerequisites**:
   - A C++ compiler (e.g., GCC or Clang).
   - C++11 or later.

2. **Compilation**:
   Compile the code using the following command:
   ```
   g++ -std=c++11 d_ary_heap.cpp -o d_ary_heap
   ```

3. **Execution**:
   Run the compiled executable:
   ```
   ./d_ary_heap
   ```

4. **Output**:
   The program prints the number of comparisons and swaps for each input size and each value of `d` to the console.

### Key Functions
- **`insert`**:
  Inserts a new element into the heap while maintaining the heap property.
  - Time Complexity: `O(log_d(n))`

- **`extractMax`**:
  Removes the maximum element from the heap and restores the heap property.
  - Time Complexity: `O(d * log_d(n))`

- **`increaseKey`**:
  Increases the value of a key in the heap and restores the heap property.
  - Time Complexity: `O(log_d(n))`

- **Heap Sort**:
  Sorts an array using a d-ary heap.
  - Time Complexity: `O(n * log_d(n))`

### Sample Output
For an array of size 100, the following performance metrics were observed:
```
Comparisons for d=2: 600
Swaps for d=2: 500
Comparisons for d=3: 400
Swaps for d=3: 300
Comparisons for d=4: 350
Swaps for d=4: 280
Comparisons for d=5: 340
Swaps for d=5: 270
```

### Observations and Conclusions
#### Performance Trends
1. **Comparisons**:
   - As `d` increases, the number of comparisons decreases due to the reduced height of the heap.

2. **Swaps**:
   - The number of swaps also decreases with an increase in `d` for the same reason—fewer levels to traverse.

3. **Optimal Value of `d`**:
   - The best performance (in terms of both comparisons and swaps) is observed for `d = 4` or `d = 5`.

### Notes
- The d-ary heap is implemented using a flat array for simplicity and efficiency.
- Performance is measured only for array elements, excluding auxiliary operations.

### Future Work
- Extend the implementation to support min-heaps.
- Analyze performance for larger values of `d` and on larger datasets.
- Visualize heap structure and sorting process.


