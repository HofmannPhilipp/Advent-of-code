#include "day_1.h"

static  t_list *split(t_list *head)
{
    t_list *fast = head;
    t_list *slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        if (fast != NULL) {
            slow = slow->next;
        }
    }
    t_list *temp = slow->next;
    slow->next = NULL;
    return temp;
}

static  t_list *merge(t_list *first, t_list *second)
{
    if (first == NULL) return second;
    if (second == NULL) return first;

    if (*(int *)first->content < *(int *)second->content) {
        first->next = merge(first->next, second);
        return first;
    }
    else {
        second->next = merge(first, second->next);
        return second;
    }
}

t_list *mergeSort(t_list *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    t_list *second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    return merge(head, second);
}
