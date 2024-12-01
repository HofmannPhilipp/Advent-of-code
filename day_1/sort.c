
#include "day_1.h"

t_list *split(t_list *head) {
    t_list *fast = head;
    t_list *slow = head;

    // Move fast pointer two steps and slow pointer
    // one step until fast reaches the end
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        if (fast != NULL) {
            slow = slow->next;
        }
    }

    // Split the list into two halves
    t_list *temp = slow->next;
    slow->next = NULL;
    return temp;
}

// Function to merge two sorted singly linked lists
t_list *merge(t_list *first, t_list *second) {
  
    // If either list is empty, return the other list
    if (first == NULL) return second;
    if (second == NULL) return first;

    // Pick the smaller value between first and second nodes
    if (*(int *)first->content < *(int *)second->content) {

        // Recursively merge the rest of the lists and
        // link the result to the current node
        first->next = merge(first->next, second);
        return first;
    }
    else {
        // Recursively merge the rest of the lists
        // and link the result to the current node
        second->next = merge(first, second->next);
        return second;
    }
}

// Function to perform merge sort on a singly linked list
t_list *MergeSort(t_list *head) {
  
    // Base case: if the list is empty or has only one node, 
    // it's already sorted
    if (head == NULL || head->next == NULL)
        return head;

    // Split the list into two halves
    t_list *second = split(head);

    // Recursively sort each half
    head = MergeSort(head);
    second = MergeSort(second);

    // Merge the two sorted halves
    return merge(head, second);
}
