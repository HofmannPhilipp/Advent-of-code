#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "day_1.h"

static int  *create_num(int n)
{
    int *num = (int *)malloc(sizeof(int));
    *num = n;
    return num;
}

void    print_lst(t_list *lst)
{
    while(lst)
    {
        ft_printf("%d\n",*(int *)lst->content);
        lst = lst->next;
    }
}

int get_total_distance(t_list *left, t_list *right)
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
static void	free_memory(char **tokens)
{
    int i = 0;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i ++;
	}
	free(tokens);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Error: Missing input.\n");    
        return (1);   
    }
    FILE *file = fopen(argv[1], "r");
    char line[256];

    t_list *left = NULL;
    t_list *right = NULL;

    while(fgets(line, sizeof(line), file))
    {
       char **values = ft_split(line, ' ');
       t_list *node = ft_lstnew(create_num(ft_atoi(values[0])));
       t_list *node2 = ft_lstnew(create_num(ft_atoi(values[1])));
       free_memory(values);
       ft_lstadd_back(&left, node);
       ft_lstadd_back(&right, node2);
    }
    fclose(file);
    printf("total distance : %d\n", get_total_distance(MergeSort(left), MergeSort(right)));
    ft_lstclear(&left, &free);
    ft_lstclear(&right, &free);
    return (0);
}