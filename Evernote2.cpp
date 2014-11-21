/*  
	Kevin Kane
	Kevin@kevinjkane.com
	
	https://evernote.com/careers/challenge.php
	Evernote #2
	Frequency Counting of Words / Top N words in a document.

Given N terms, your task is to find the k most frequent terms from given N terms.
Input format

First line of input contains N, denoting the number of terms to add.

In each of the next N lines, each contains a term.

Next line contains k, most frequent terms.
Output format

Print the k most frequent terms in descending order of their frequency. If two terms have same frequency print them in lexicographical order.

Sample input

14

Fee

Fi

Fo

Fum

Fee

Fo

Fee

Fee

Fo

Fi

Fi

Fo

Fum

Fee

3
Sample output

Fee

Fo

Fi
Constraint

0 < N < 300000

0 < term length < 25.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
using namespace std;
using std::priority_queue;

//Program summary: Create a map of strings to their occurances. Take the input and fill the map.
//  Then push all the values from the map in a priority queue where it checks for a higher frequency first
// then if they are equal compares the strings to find the lexicographically least one
// pop k values off the priority queue and print them.

//Summary: used to help with the comparison function
struct WordFrequency{
    string word;
    int frequency;
};

//Summary:comparison function for the priority queue, checks frequency first, if they match then checks words
struct WordCompare{
    bool operator()(const WordFrequency & Word1, const WordFrequency & Word2) const
	{
        if(Word1.frequency == Word2.frequency){
            return Word1.word > Word2.word;
        }
        else{
            return Word1.frequency < Word2.frequency;
        }
	}
};


int main() {
    map<string, int> words;

    int numWords;
    cin>>numWords;
    string word;
    //add the words to the queue, incrementing their counter if already exists, setting it to 1 otherwise
    for(int i=0; i<numWords; i++){
        cin>>word;
        if(words[word]>=1){
            words[word]++;
        }
        else{
            words[word]=1;
        }
    }
    
    //take the words from the map and push them in a priority queue
	priority_queue<WordFrequency, vector<WordFrequency>, WordCompare> pQueue;

    for(map<string,int>::iterator it = words.begin(); it != words.end(); ++it){
        WordFrequency wFrequency;
        wFrequency.word = it->first;
        wFrequency.frequency = it->second;
        pQueue.push(wFrequency);
    }
    
    //determine how many words to print, then print them from the priority queue
    int wordsToPrint;
    cin>>wordsToPrint;
    int wordsPrinted = 0;
    while (pQueue.empty() == false && wordsPrinted < wordsToPrint){
        WordFrequency wFrequency = pQueue.top();
        pQueue.pop();
        cout<<wFrequency.word<<endl;
        wordsPrinted++;
    }

	return 0;
}
