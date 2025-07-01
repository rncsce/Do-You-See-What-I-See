#ifndef MONOSTACK_H
#define MONOSTACK_H
#include <iostream>

using namespace std;
// Start code from CPSC-350: Data Structures & Algorithms's Templated Array-Based Stack Class Notes
// Define templated type for scope
template<typename T>
// Template MonoStack Class
class MonoStack{
    public:
        // Overloaded Constructor: initializes MonoStack object
        MonoStack(int iSize);
        // Default Deconstructor: deallocates memory used by MonoStack object
        ~MonoStack();
        // push Function: adds data onto stack, order depending on character paramter
        void push(T data, char o);
        // pop Function: removes and returns item at top of stack
        T pop();
        // peek Function: returns item at top of stack without removing it
        T peek();
        // isFull Function: checks if stack is full
        bool isFull();
        // isEmpty Function: checks if stack is empty
        bool isEmpty();
        // size Function: return stack's current size 
        int size();
    private:
        // stackArr: array of stack elements
        T *stackArr;
        // count: number of elements in stack
        int count;
        // maxSize: max number of elements stack/array can hold
        int maxSize;
        // top: the index of the top of the stack
        int top;
};
#include "MonoStack.h"

// Overloaded Constructor: initializes MonoStack's member variables
template<typename T> MonoStack<T>::MonoStack(int iSize){ // iSize parameter: size of array
    stackArr = new T[iSize]; // Initialize array of provided data type and provided size
    maxSize = iSize; // Set the max size to the size of the array
    count = 0; // Set the count to 0
    top = -1; // Set the top to -1, index starts at 0, when element added
}
// Default Deconstructor
template<typename T> MonoStack<T>::~MonoStack(){ 
}
// isFull Function
template<typename T> bool MonoStack<T>::isFull(){ 
    return (count == maxSize); // Return whether the current number of elements is equal to the max size of array
}
// isEmpty Function
template<typename T> bool MonoStack<T>::isEmpty(){ 
    return (count == 0); // Return whether the current number of elements is 0
}
// size Function
template<typename T> int MonoStack<T>::size(){ 
    return count; // Return the current number of elements
}
// push Function
template<typename T> void MonoStack<T>::push(T data, char o){ // Parameters: element to add, character increasing/decreasing indicator
    // Resizes array if array is full
    if(isFull()){  // Check if array is full, using isFull function
        T* temp = new T[2 * maxSize]; // Create temporary array, with double the size of elements of original array
        for (int i = 0; i < maxSize; ++i){ // Interate for the number of current elements in original array
            temp[i] = stackArr[i]; // Access and add element from original array to temporary array
        }
        maxSize *= 2; // Double maxSize member variable
        delete[] stackArr; // Delete current array
        stackArr = temp; // Reassign stackArr (the original array) to temp
    }
    // End code from Templated Array-Based Stack Class Notes
    // Monotonically orders array by increasing or decreasing elements
    if (o == 'd'){ // If Monotonic Stack should be decreasing
        for(int i = top; i >= 0; --i){ // Iterate from top to bottom of stack's elements
            if (stackArr[i] > data ){ // If element in stack is greater than pushed element
                pop(); // Call pop function, removing the top (compared element) from the stack
            }
        }
    } else if (o == 'i'){ // If Monotonic Stack should be increasing
        for(int i = top; i >= 0; --i){ // Iterate from top to bottom of stack's elements
            if (stackArr[i] < data ){ // If element in stack is less than than pushed element
                pop(); // Call pop function, removing the top (compared element) from the stack
            }
        }
    } 
    // Start code from Templated Array-Based Stack Class Notes
    ++count; // Increase count by 1
    stackArr[++top] = data; // Add data to stack's top, then increased top by 1
}
// pop Function
template<typename T> T MonoStack<T>::pop(){
    count--; // Lower count by one
    return stackArr[top--]; // Return top, and then lower top by one
}
// peek Function
template<typename T> T MonoStack<T>::peek(){
    return stackArr[top]; // Return element at top of stack
}
#endif
// End code from CPSC-350: Data Structures & Algorithms's Templated Array-Based Stack Class Notes
