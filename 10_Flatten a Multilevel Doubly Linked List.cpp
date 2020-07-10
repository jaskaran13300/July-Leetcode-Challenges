

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

// Input: head = [1,2,5,null,null,3,4]
// Output: [1,2,3,4,5]

// 1 --- 2 --- 5 --- null
// 	  |
// 	  3 --- 4
	  
// 1 --- 2 --- 3  ---  4 ---- 5 --- null
	  
// Start
// current = 1 and no child of 1 just update current to current.next
// current = 2 now 2 has child list start from 3 and tail is at 4
// once we got tail of 2`s child list update 4.next = current.next (5)
// and current.next (5) is not null change the prev to node 4.
// update current.child (2s  child 3 to null)
// again in next iteration 2 next is 3 and child is null.
// update current  to 3 
// again no child  update current to 4 
// again no child update current to 5 
// null termination of loop


class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;
        Node * current = head;
        while (current != NULL) {
            if (current->child == NULL) {
                current = current->next;
                continue;
            }
            Node * temp = current->child;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = current->next;  // Connect child tail with current.next, if it is not null
            if (current->next != NULL) current->next->prev = temp; // if current.next is not null then change the prev of current.next to temp
			// Connect node with current.child, and remove current.child make it null
            current->next = current->child;
            current->child->prev = current;
            current->child = NULL;
        }
        return head;
    }
};
