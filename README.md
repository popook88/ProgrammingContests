<h1>Demo Work Summary </h1>

<b> Evernote1.cpp </b>
Implement a circular buffer of size N. Allow the caller to append, remove and list the contents of the buffer. Implement the buffer to achieve maximum performance for each of the operations.

Solution summary: Main does IO and calls either the Append, Remove or List functions to do actions on the buffer. Uses the empty string to signify an open buffer slot.

<b> Evernote2.cpp </b>
Frequency Counting of Words / Top N words in a document.

Solution summary: Create a map of strings to their occurances. Take the input and fill the map.
Then push all the values from the map in a priority queue where it checks for a higher frequency first.
Then if they are equal compares the strings to find the lexicographically least one, pop k values off the priority queue and print them.

<b> Evernote3.cpp </b>
Given a list of integers, your task is to write a program to output an integer-valued list of equal length such that the output element at index 'i' is the product of all input elements except for the input element at 'i'.

Solution summary:We use the fact that the result we are looking for is the result of multiplying all the numbers to the left of the number by all the numbers to the right of the number to achieve O(n) for this solution.

