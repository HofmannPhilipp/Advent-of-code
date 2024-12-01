#include "day_1.h"

int *create_num(int n)
{
    int *num = (int *)malloc(sizeof(int));
    *num = n;
    return num;
}

void    print_lst(t_list *lst)
{
    while(lst)
    {
        printf("%d\n",*(int *)lst->content);
        lst = lst->next;
    }
}

int calc_total_distance(t_list *left, t_list *right)
{
    int sum = 0;
    
    while (left && right)
    {
        sum += abs(*(int *)left->content - *(int *)right->content);
        left = left->next;
        right = right->next;
    }
    return (sum);
}

int calc_similarity_score(t_list *left, t_list *right)
{
    int score = 0;
    t_list *curr;

    while(left)
    {
        curr  = right;
        while (curr)
        {
            if (*(int *)left->content == *(int *)curr->content)
            {
                score += *(int *)curr->content;
            }
            curr = curr->next;
        }
        left = left->next;
    }
    return (score);
}
void	free_memory(char **tokens)
{
    int i = 0;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i ++;
	}
	free(tokens);
}