#ifndef DAY_1_H
#define DAY_1_H

#include "./libft/libft.h"
#include <stdio.h>

t_list  *mergeSort(t_list *head);
int     *create_num(int n);
void    print_lst(t_list *lst);
int     calc_total_distance(t_list *left, t_list *right);
int     calc_similarity_score(t_list *left, t_list *right);
void	free_memory(char **tokens);

#endif