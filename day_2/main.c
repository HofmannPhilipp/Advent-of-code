#include "day_2.h"

int check_safty(t_list *left);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Error: Missing input.\n");    
        return (1);   
    }
    int fd = open(argv[1], O_RDONLY);

    t_list *reports = NULL;
    char *line;
    int safe_reports_count = 0;
    while((line = get_next_line(fd)) != NULL)
    {
       char **values = ft_split(line, ' ');
       int i = 0;
       while (values[i] != NULL)
       {
            t_list *node = ft_lstnew(create_num(ft_atoi(values[i])));
            ft_lstadd_back(&reports, node);
            i++;
       }
       safe_reports_count += check_safty(reports);
       ft_lstclear(&reports, &free);
       reports = NULL;
       free_memory(values);
    }
    ft_printf("Safe reports : %d",safe_reports_count);
    close(fd);
    ft_lstclear(&reports, &free);
    return (0);
}

int check_safty(t_list *left)
{
    if (!left || !left->next)
        return (1);
    t_list  *right = left->next;
    int change = 0;     // increase = 1 decrease = -1
    while (right)
    {
        int diff = abs(*(int *)left->content - *(int *)right->content);
        if (diff == 0 || diff > 3)
            return (0);
       if (change == 0)
            change = (*(int *)left->content < *(int *)right->content) ? 1 : -1;
        else if ((change == 1 && *(int *)left->content > *(int *)right->content) || (change == -1 && *(int *)left->content < *(int *)right->content))
            return (0);
        
        left = left->next;
        right = left->next;
    }
    return (1);
}