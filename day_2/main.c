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
int is_safe(t_list *left)
{
    if (!left || !left->next)
        return (1);  // Leere oder einzelnelementige Liste ist sicher.

    t_list *right = left->next;
    int change = 0;  // 1 = steigend, -1 = fallend, 0 = undefiniert

    while (right)
    {
        int diff = abs(*(int *)left->content - *(int *)right->content);

        if (diff == 0 || diff > 3)  // Differenzregel verletzt
            return (0);

        if (change == 0)
            change = (*(int *)left->content < *(int *)right->content) ? 1 : -1;
        else if ((change == 1 && *(int *)left->content > *(int *)right->content) ||
                 (change == -1 && *(int *)left->content < *(int *)right->content))
            return (0);  // Monotonie verletzt

        left = left->next;
        right = left->next;
    }
    return (1);
}

int check_safty(t_list *left)
{
    if (is_safe(left))
        return (1);  // Liste ist bereits sicher

    // Überprüfe, ob das Entfernen eines Elements die Liste sicher macht
    t_list *current = left;
    while (current)
    {
        t_list *temp_left = left;
        t_list *skip_node = current;

        // Erstelle eine Kopie der Liste ohne das aktuelle Element
        t_list *new_list = NULL;
        while (temp_left)
        {
            if (temp_left != skip_node)
            {
                t_list *node = ft_lstnew(create_num(*(int *)temp_left->content));
                ft_lstadd_back(&new_list, node);
            }
            temp_left = temp_left->next;
        }

        if (is_safe(new_list))
        {
            ft_lstclear(&new_list, &free);
            return (1);  // Liste ist sicher nach Entfernen eines Elements
        }

        ft_lstclear(&new_list, &free);
        current = current->next;
    }

    return (0);  // Liste ist unsicher
}

// int checks(int a, int b, int *change)
// {
//     int diff = abs(a - b);
//         if (diff == 0 || diff > 3)
//             return (-1);
//        if (*change == 0)
//             *change = (a < b) ? 1 : -1;
//         else if ((*change == 1 && a > b) || (*change == -1 && a < b))
//             return (-1);
//     return (1);
// }

// int check_safty(t_list *left)
// {
//     if (!left || !left->next)
//         return (1);

//     t_list  *right = left->next;
//     int change = 0;     // increase = 1 decrease = -1
//     int skips = 0;      // if skips 1 means one skip of node
//     while (right)
//     {
//         int res = checks(*(int *)left->content, *(int *)right->content, &change);
//         if (res == -1)
//         {
//             if (skips == 1)
//                 return (0);
//             skips = 1;
//             right = right->next;
//             continue;
//         }
//         left = left->next;
//         right = left->next;
//     }
//     return (1);
// }