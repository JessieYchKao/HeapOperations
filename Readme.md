# Heap Operations
This program implements a heap data structure and allows you to perform various operations. This tool allows users to insert elements, remove elements, query the size of the heap, and print the contents of the heap. It supports different data types, including integers, doubles, and strings, providing flexibility for different use cases.

## Installation & Execution

1. Clone the repository to your local environment:

    ```
    $ git clone https://github.com/JessieYchKao/HeapOperations.git
    ```

2. Compile
    ```
    $ make
    ```

3. Execute
    ```
    $ .\heap_operations.exe
    ```

## Usage

1. Select the type of the heap
    ```
    Enter the type for Heap (int/double/string): string
    ```
2. Max heap or min heap (type "Y" for max heap, "N" for min heap)
    ```
    Is it a max heap (Y/N): Y
    ```
3. Manipulate the heap

    -  Insert a node:
        ```
        Insert(I)/Remove(R)/Size(S)/Print(P)/Exit(E): I
        Enter the value of the node: 10
        ```
    -  Remove: Always remove the root node
        ```
        Insert(I)/Remove(R)/Size(S)/Print(P)/Exit(E): R
        ```
    -  Get the size of the heap: 
        ```
        Insert(I)/Remove(R)/Size(S)/Print(P)/Exit(E): S
        The size of the heap: 4
        ```
    -  Print the heap: This will show you the heap by displaying the nodes level by level.
        ```
        Insert(I)/Remove(R)/Size(S)/Print(P)/Exit(E): P
        Heap: 
        23
        19      17
        2       18      5       9
        ```
## Unit Test (in Visual Studio Code)
1. Download Google Test in the root folder
    ```
    $ git clone https://github.com/google/googletest.git
    ```
2. VS Code Extensions: CMake Tools

3. Build the code through VS Code or by using cmake
    ```
    $ mkdir build
    $ cd build
    $ cmake ..
    ```
4. Change CMakeCache.txt settings
    ```
    // Change from OFF to ON, we need to use Shared Runtime Library
    gtest_force_shared_crt:BOOL=ON
    ```

5. Run CTest
    - Testcase1: InsertTest
    - Testcase2: RemoveTest
    - Testcase3: MaxHeapTest
    - Testcase4: MinHeapTest
