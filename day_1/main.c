#include "day_1.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Error: Missing input.\n");    
        return (1);   
    }
    t_list *left = NULL;
    t_list *right = NULL;

    int fd = open(argv[1], O_RDONLY);
    char *line;
    
    while((line = get_next_line(fd)) != NULL)
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
    close(fd);
    ft_lstclear(&left, &free);
    ft_lstclear(&right, &free);
    return (0);
}
