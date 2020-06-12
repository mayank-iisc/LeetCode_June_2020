/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* We have been given a pointer to the node to be deleted.
We know that while deleting a node from the linked list, we have to fix the links between the previous and the next node.

1- Find out the next node of the pointer to the node that we have.
2- Copy the data from the next node to the node to be deleted.
3- Fix the link and delete the next node
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode* temp = node -> next;
        
        node -> val = temp -> val;
        node -> next = temp -> next;
        
        delete(temp);
    }
};
