//
//  main.cpp
//  PriorityQueue
//
//  Created by Jonathan Raysor on 3/28/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#include <iostream>
#include "PriorityQueue.h"
int main(int argc, const char * argv[]) {
  
    
    PriorityQueue<int> numbersTest;

    for(int i=1928; i !=0; i--){
        numbersTest.push(i);
    }
    
    int numbersTest2 [10];
    
    for(int i=0; i <10; i++){
        numbersTest2[i]=i;
    }
    
    PriorityQueue<int> numbers2(numbersTest2, 10);
    
    cout << numbers2.top() << endl;
    cout << numbersTest.top() << endl;
}
