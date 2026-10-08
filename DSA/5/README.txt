DATA STRUCTURES LABORATORY

Josephus Problem using a Circular Linked List

Files:
clist.h
clist.c
josephus.h
josephus.c
step1.c
step2.c
Makefile
josephus_step1_output.png
josephus_step2_output.png

Data structure:
A circular singly linked list is used. Each node stores a person number, a name and a pointer to the next node.

Algorithm:
The current pointer stores the node before the next person to be counted. To remove the k-th person, the current pointer is moved k-1 times and clist_remove_after() is called.

For k = 1, the pointer moves zero times, so the first person is removed directly.

Time complexity:
One removal takes O(k) time in the usual case. The complete simulation takes O(nk) time. Space complexity is O(n).

Sample:
n = 7
k = 3

Elimination order:
3, 6, 2, 7, 5, 1

Survivor:
4
