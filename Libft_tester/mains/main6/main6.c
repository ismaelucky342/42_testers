#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *input = "Hello World! This is LIBFT testing.";
    char **words;
    int i = 0, j;

    // Usamos ft_split para dividir la cadena en palabras
    words = ft_split(input, ' ');
    if (!words)
        return (1);

    // Recorremos cada palabra y alternamos mayúsculas/minúsculas
    while (words[i] != NULL)
    {
        j = 0;
        while (words[i][j] != '\0')
        {
            if (j % 2 == 0)
                words[i][j] = ft_toupper(words[i][j]);
            else
                words[i][j] = ft_tolower(words[i][j]);
            j++;
        }
        ft_putendl_fd(words[i], 1); // Imprime la palabra transformada
        free(words[i]);              // Liberamos cada palabra
        i++;
    }
    free(words); // Liberamos el array de palabras

    return (0);
}