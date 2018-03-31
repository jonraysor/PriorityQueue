//
//  PriorityQueue.h
//  PriorityQueue
//
//  Created by Jonathan Raysor on 3/28/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#ifndef PriorityQueue_h
#define PriorityQueue_h
#include "EmptyException.h"
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class PriorityQueue{
    
private:

    vector<T> theHeap;
    
    static T parent;
    static T leftChild;
    static T rightChild;
    
    static unsigned long int leftChildIndex(unsigned long int parentIndex){
        // the right child of the parent in the vector is 2 times it's index and to the right by 1 element
        return (parentIndex*2)+1;
    }
    
    static unsigned long int rightChildIndex(unsigned long int parentIndex){
        // the left child of the parent in the vector is 2 times it's index and to the right by 2 elements
        return (parentIndex*2)+2;
    }
    
    static unsigned long int parentIndex(unsigned long int ChildIndex){
        // the left child is always to the left one and half of that
        // C++ rounds down (using the floor)
        return (ChildIndex-1)/2;
    }
    
    
    static void maxHeapify(vector<T> theHeap, int root){
        
        // we need to know both the the children of the new root to determine if the heap needs to be 'heapified'
        unsigned long int leftChild = leftChildIndex(root);
        unsigned long int rightChild = rightChildIndex(root);
        int largerIndex;
        
        // if the left child is greater than the root we will check the left side of the binary max heap and adjust it accordingly
        if(leftChild < theHeap.size() && theHeap[leftChild] < theHeap[root])
            largerIndex = leftChild;
        
        // if the left child is greater than the root we will check the left side of the binary max heap and adjust it accordingly
        if(rightChild < theHeap.size() && theHeap[rightChild] < theHeap[root])
            largerIndex = rightChild;
        
        // if one of the conditions above was met we need to swap the parent with the larger index (one of the children that's greater)
        if (largerIndex != root){
            swap(root, largerIndex);
            
            // since this is recursive we'll make our 'recursive' call
            maxHeapify(theHeap, root);
        }
    }
    static void bubbleUp(vector<T> theHeap, unsigned long int newIndex){
        
        // we need to know the parent of the new element that we're pushing onto the vector
        // this needs to be known because we must compare the new element with it's parent to see if it needs to be bubbled up.
       unsigned long int parent = parentIndex(newIndex);
        
        // we need to make sure while the index is not at the front of the vector (theHeap[0])
        // and the new element is greater than it's parent that it continues to bubble up to it's proper spot to maintain a legal binary max heap
        
        while(newIndex > 0 && theHeap[newIndex] > theHeap[parent]){
            // if the above conditions are met we will swap the new element with it's parent
            swap(newIndex,parent);
            // then we'll have to change the new elements index to be where the parent was (bubble it up)
            newIndex = parent;
            // then change the parent to continue through our loop checking for a legal binary max heap
            parent = parentIndex(newIndex);
        }
        
    }
    
public:
    
    PriorityQueue(){}
    
    PriorityQueue(T *arr, int arrSize){
        theHeap(arr,sizeof(arr)/sizeof(arr[0]));
    }
    
    void pop(){
        
        if (empty()){
            string error = "THE priorityQueue IS EMPTY";
            EmptyException errorToBeThrown(error);
            throw errorToBeThrown;
        }
        
        // first we check to see if the heap has more than one element
        // this matters because we cannot swap one element with itself (segmentation fault)
        if (theHeap.size()>1)
            
            // if the above condition is met
            // then we swap the top of the binary max heap with the bottom
            // this is done because we want to delete 'top' element on the heap
            // we could use pop_front, but that would not run in constant time (hence why there's no pop_front() function
            // stl vector)
            swap(theHeap, 0, theHeap.size()-1);
        
        
        // pop_back() to delete that element that we placed at the back
        // this will always happen no matter what as long as theHeap isnt empty()
        theHeap.pop_back();
        
        // if only one element is in the priorityQueue we have no reason to call maxHeapify() seeing there's 0 or 1 elements in the priorityQueue and if there's one that is the greatest
        if (theHeap.size()<1)
            // maxHeapify() is called to 'reorganize' the binary max heap to make it legal
            maxHeapify(theHeap, 0);
    }
    
    void push(const T newElem){
        // first we'll add the new element to the vector
        theHeap.push_back(newElem);
        
        // after adding the new element we'll need to make sure that the Binary Max heap follows all the rules
        // for instance if the new element is greater than all other elements in the Binary Max Heap it will need to make it's way to the top and the bubbleUp() function will be able to corrent the heap
        
        // we'll check to see if the heap is empty. If it is there's no need for us to bubbleUp() because there;s only one element and that is the gratest in the vector
        if (theHeap.size()>1)
            // in contrast, if the element is the minimum of the binary max heap the function bubbleUp() will return instantly after it's first test becuase the new element is not greater than it's parent
            bubbleUp(theHeap,theHeap.size()-1);
    }
    
    T top(){
        if (empty()){
            string error = "THE priorityQueue IS EMPTY";
            EmptyException errorToBeThrown(error);
            throw errorToBeThrown;
        }

        return theHeap[0];
    }
    
    const int size(){
        if (empty()){
        string error = "THE priorityQueue IS EMPTY";
        EmptyException errorToBeThrown(error);
        throw errorToBeThrown;
    }

        return theHeap.size();
    }
    
    const bool empty(){
        return theHeap.empty();
    }
    
};



#endif /* PriorityQueue_h */
