/*
https://evernote.com/careers/challenge.php
Question #1

Implement a circular buffer of size N. Allow the caller to append, remove and list the contents of the buffer. Implement the buffer to achieve maximum performance for each of the operations.

The new items are appended to the end and the order is retained i.e elements are placed in increasing order of their insertion time. When the number of elements in the list elements exceeds the defined size, the older elements are overwritten.

There are four types of commands.

"A" n - Append the following n lines to the buffer. If the buffer is full they replace the older entries.

"R" n - Remove first n elements of the buffer. These n elements are the ones that were added earliest among the current elements.

"L" - List the elements of buffer in order of their inserting time.

"Q" - Quit.

Your task is to execute commands on circular buffer.
Input format

First line of input contains N , the size of the buffer.

A n - append the following n lines to the buffer.

R n - remove first n elements of the buffer.

L - list the buffer.

Q - Quit.
Output format

Whenever L command appears in the input, print the elements of buffer in order of their inserting time. Element that was added first should appear first.
Sample Input

10

A 3

Fee

Fi

Fo

A 1

Fum

R 2

L

Q
Sample Output

Fo

Fum
Constraint

0 <= N <= 10000

Number of removing elements will <= number of elements presents in circular buffer.

Total number of commands <= 50000.

Total number of characters in input <= 20000000.
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Program summary: Main does IO and calls either the Append, Remove or List functions to do actions on the buffer. Uses the empty string to signify an open buffer slot.

//Summary: Appends the lines from inputStrings to buffer.
//Modifies: buffer, appendLocation, removeLocation and elementsInBuffer
void Append(vector<string> & buffer, int bufferSize, std::vector<string>::iterator & appendLocation,
            std::vector<string>::iterator & removeLocation, vector<string> inputStrings, 
            int & elementsInBuffer){
    for(std::vector<string>::iterator it =inputStrings.begin(); it != inputStrings.end(); it++){               
        *appendLocation = *it;
        appendLocation++;

        //if reached the end, loop back around
        if(appendLocation == buffer.end()){
            appendLocation = buffer.begin();
        }

        //if there is space in buffer, don't alter removeLocation
        if(elementsInBuffer < bufferSize){
            elementsInBuffer++;
        }
        //buffer is full and we have to move along our removeLocation
        else{
            removeLocation = appendLocation;
        }
    }
}

//Summary: Removes a specified number lines in the buffer, oldest to newest.
//Modifies: buffer, removeLocation and elementsInBuffer
void Remove(vector<string> & buffer, int bufferSize, std::vector<string>::iterator & removeLocation, int lines, int & elementsInBuffer){
     for(int i=0; i<lines; i++){
        *removeLocation = "";
        removeLocation++;
        elementsInBuffer--;
        //if we hit the end, loop back around
        if(removeLocation == buffer.end()){
             removeLocation = buffer.begin();
        }
      }  
}


//Summary: Prints the buffer, oldest to newest
//Modifies: no variables modified, calls cout
void List(vector<string> & buffer, int bufferSize, std::vector<string>::iterator positionToPrint){
    for(int i=0; i<bufferSize; i++){
        if(*positionToPrint != ""){
            cout<<*positionToPrint<<endl;
        }
        positionToPrint++;
        if(positionToPrint == buffer.end()){
            positionToPrint = buffer.begin();
        }
    }
}

int main() {
    
    vector<string> buffer;
    
    //obtain buffer size and fill buffer with empty strings
    int bufferSize;
    cin>>bufferSize;
    
    //none of the commands do anything if the bufferSize is 0 so just return, perhaps throwing error is better
    if(bufferSize <=0){
        return 0;
    }
    
    for(int i=0; i<bufferSize; i++){
        buffer.push_back("");
    }
    //appendLocation always moves circularly through the buffer,
    //going to the beginning when it hits the end
    std::vector<string>::iterator appendLocation = buffer.begin();
    //removeLocation stays at the start until a remove is called or
    //the entire buffer has been allocated, then it will move circularly
    std::vector<string>::iterator removeLocation = buffer.begin();
    char command;
    int lines;
    int elementsInBuffer = 0;
    string inputString;
    while(cin>>command){
        if(command == 'A'){
            cin>>lines;
            vector<string> inputStrings;
            for(int i=0; i<lines; i++){
                cin>>inputString;
                inputStrings.push_back(inputString);
            }
            Append(buffer, bufferSize, appendLocation, removeLocation, inputStrings, elementsInBuffer);
        }
        else if(command =='R'){
            cin>>lines;
            Remove(buffer, bufferSize, removeLocation, lines, elementsInBuffer);
        }
        else if(command =='L'){
            //removeLocation holds the oldest element location, pass that in by value
            List(buffer, bufferSize, removeLocation);
        }
        else if(command == 'Q'){
            break;
        }
        else{
            cout<<"Error, improper command"<<endl;
        }
    }
    return 0;
}
