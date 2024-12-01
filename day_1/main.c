#include "day_1.h"

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

    left = mergeSort(left);
    right = mergeSort(right);
    printf("total distance : %d\n", calc_total_distance(left, right));
    printf("simalarity score : %d \n", calc_similarity_score(left, right));
    fclose(file);
    ft_lstclear(&left, &free);
    ft_lstclear(&right, &free);
    return (0);
}