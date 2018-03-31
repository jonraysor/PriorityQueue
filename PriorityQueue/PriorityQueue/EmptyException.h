//
//  EmptyException.h
//  PriorityQueue
//
//  Created by Jonathan Raysor on 3/31/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#ifndef EmptyException_h
#define EmptyException_h

using namespace std;

class EmptyException {
private:
    string message;

public:
    EmptyException(string message):message(message){}
    
    string getMessage(){
        return message;
    }

};

#endif /* EmptyException_h */
