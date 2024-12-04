#include "day_3.h"

int calc_uncorrupted(char *str);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Error: Missing input.\n");    
        return (1);   
    }
    int fd = open(argv[1], O_RDONLY);

    char *line;
    int sum = 0;
    char *str;
    while((line = get_next_line(fd)) != NULL)
    {
        while ((str = ft_strnstr(line, "mul(", ft_strlen(line))) != NULL)
        {
             sum += calc_uncorrupted(str);
             line = str + 4; // Move past the "mul(" to avoid reprocessing.
            //  ft_printf("%s\n",line);
        }
    }
    ft_printf("sum :%d\n", sum);
    close(fd);
    return (0);
}

int calc_uncorrupted(char *str)
{
    int a, b, i = 0;
    str += 4; // Skip "mul("
    
    while (ft_isdigit(str[i])) i++;
    if (str[i] != ',' || i == 0 || i > 3) return 0;
    
    a = ft_atoi(ft_substr(str, 0, i));
    str += i + 1; // Skip digits and the comma
    
    i = 0;
    while (ft_isdigit(str[i])) i++;
    if (str[i] != ')' || i == 0 || i > 3) return 0;

    b = ft_atoi(ft_substr(str, 0, i));
    // printf("%d * %d\n", a, b);
    return (a * b);
}

