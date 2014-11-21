/*
    Kevin Kane
    Kevin@KevinJKane.com
	
	https://evernote.com/careers/challenge.php
	EverNote #3
	Given a list of integers, your task is to write a program to output an integer-valued list of equal length such that the output element at index 'i' is the product of all input elements except for the input element at 'i'.

In other words, let inputArray by an integer array of length 'n'. The solution,computed into outputArray, would be:

for each j from 1 to n-2:

outputArr[ j ] = inputArray[0] * inputArray[1] * inputArray[2] * ... * inputArray[j-1] * inputArray[j+1] * inputArray[j+2] *...* inputArray[n-1]

for j = 0

outputArray[0] = inputArray[1] * outputArray[2] * ... * outputArray[n-1]

for j = n-1

outputArray[n-1] = outputArray[0] * outputArray[1] * outputArray[2] * ... * outputArray[n-2]

As an example, if inputArray = { 1, 2, 3, 4 }, then

outputArray = { 2*3*4, 1*3*4, 1*2*4, 1*2*3 }.

Your program should run in O(n) time and should be space efficient.
Input format

First line of input contains N , number of elements in list.

Next N lines will each contain an element (a signed integer)
Output format

Print the output list of numbers.
Sample input

1

2

3

4
Sample output

24

12

8

6
Constraint

You may assume that:

    The input array size will always have at least two elements in it, that is, n >= 2.
    The product of any subset of the input will never exceed the value of a 64 bit integer.
    The maximum length of input array is 1000.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
#define MAX 1000

//Program Summary: We use the fact that the result we are looking for is the result of multiplying all the numbers to the left of the number by all the numbers to the right of the number to Achieve O(n) for this solution.


int main() {
    long long leftValues[MAX];
    long long rightValues[MAX];
    long long values[MAX];
    
    int n;
    cin>>n;
    int value;
    //Obtain the first value so that we can loop through starting at 1, filling out values and leftValues
    cin>>value;
    values[0]=value;
    leftValues[0] =1;
    for(int i=1; i<n; i++){
        cin>>value;
        values[i]=value;
        leftValues[i] = leftValues[i-1] * values[i-1];
    }
    
    //loop through setting the right values
    rightValues[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        rightValues[i] = rightValues[i+1] * values[i+1];
    }
    
    //print out the result of multiplying the left and right together
    for(int i=0; i<n; i++){
        long long result = leftValues[i] * rightValues[i];
        cout<<result<<endl;
    }

	return 0;
}
