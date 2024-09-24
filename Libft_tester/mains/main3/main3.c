#include "libft.h"
#include <fcntl.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    // Prueba de ft_putstr_fd
    ft_putstr_fd("Hello, ", fd);
    
    // Prueba de ft_putendl_fd
    ft_putendl_fd("World!", fd);

    // Prueba de ft_putchar_fd
    ft_putchar_fd('A', fd);

    // Prueba de ft_putnbr_fd
    ft_putnbr_fd(12345, fd);

    close(fd);
    return 0;
}
