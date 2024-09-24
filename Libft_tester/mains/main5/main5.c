#include "libft.h"
#include <stdio.h>

void print_list_content(void *content) {
    printf("%s\n", (char *)content);
}

int main() {
    t_list *list = ft_lstnew("Node 1");
    ft_lstadd_back(&list, ft_lstnew("Node 2"));
    ft_lstadd_back(&list, ft_lstnew("Node 3"));

    // Itera sobre la lista y muestra el contenido
    ft_lstiter(list, print_list_content);

    // Libera la memoria de la lista
    ft_lstclear(&list, free);

    return 0;
}
