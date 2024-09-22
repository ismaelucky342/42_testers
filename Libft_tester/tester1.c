#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

// Prototipos de las funciones
void test_ft_tolower();
void test_ft_toupper();
void test_ft_strlen();
void test_ft_strlcpy();
void test_ft_strlcat();
void test_ft_strncmp();
void test_ft_strnstr();
void test_ft_strjoin();
void test_ft_strdup();
void test_ft_strrchr();
void test_ft_strmapi();
void test_ft_striteri();
void test_ft_strchr();
void test_ft_strtrim();
void test_ft_substr();
void test_ft_split();
void test_ft_atoi();
void test_ft_itoa();
void test_ft_putstr_fd();
void test_ft_putendl_fd();
void test_ft_putchar_fd();
void test_ft_putnbr_fd();
void test_ft_memset();
void test_ft_bzero();
void test_ft_memcpy();
void test_ft_memmove();
void test_ft_calloc();
void test_ft_memchr();
void test_ft_memcmp();
void test_ft_isalnum();
void test_ft_isalpha();
void test_ft_isdigit();
void test_ft_isascii();
void test_ft_isprint();
void test_linked_list_functions();

int main() {
    // Llamada a los tests
    test_ft_tolower();
    test_ft_toupper();
    test_ft_strlen();
    test_ft_strlcpy();
    test_ft_strlcat();
    test_ft_strncmp();
    test_ft_strnstr();
    test_ft_strjoin();
    test_ft_strdup();
    test_ft_strrchr();
    test_ft_strmapi();
    test_ft_striteri();
    test_ft_strchr();
    test_ft_strtrim();
    test_ft_substr();
    test_ft_split();
    test_ft_atoi();
    test_ft_itoa();
    test_ft_putstr_fd();
    test_ft_putendl_fd();
    test_ft_putchar_fd();
    test_ft_putnbr_fd();
    test_ft_memset();
    test_ft_bzero();
    test_ft_memcpy();
    test_ft_memmove();
    test_ft_calloc();
    test_ft_memchr();
    test_ft_memcmp();
    test_ft_isalnum();
    test_ft_isalpha();
    test_ft_isdigit();
    test_ft_isascii();
    test_ft_isprint();
    test_linked_list_functions();

    return 0;
}

// Implementación de las pruebas
void test_ft_tolower() {
    printf("Testing ft_tolower:\n");
    printf("ft_tolower('A') = '%c', expected = 'a'\n", ft_tolower('A'));
    printf("ft_tolower('a') = '%c', expected = 'a'\n", ft_tolower('a'));
    printf("ft_tolower('1') = '%c', expected = '1'\n", ft_tolower('1'));
}

void test_ft_toupper() {
    printf("Testing ft_toupper:\n");
    printf("ft_toupper('a') = '%c', expected = 'A'\n", ft_toupper('a'));
    printf("ft_toupper('A') = '%c', expected = 'A'\n", ft_toupper('A'));
    printf("ft_toupper('1') = '%c', expected = '1'\n", ft_toupper('1'));
}

void test_ft_strlen() {
    printf("Testing ft_strlen:\n");
    printf("ft_strlen('Hello') = %zu, expected = 5\n", ft_strlen("Hello"));
    printf("ft_strlen('') = %zu, expected = 0\n", ft_strlen(""));
}

void test_ft_strlcpy() {
    char dest[20];
    printf("Testing ft_strlcpy:\n");
    ft_strlcpy(dest, "Hello", sizeof(dest));
    printf("ft_strlcpy(dest, 'Hello') = '%s', expected = 'Hello'\n", dest);
}

void test_ft_strlcat() {
    char dest[20] = "Hello";
    printf("Testing ft_strlcat:\n");
    ft_strlcat(dest, " World", sizeof(dest));
    printf("ft_strlcat(dest, ' World') = '%s', expected = 'Hello World'\n", dest);
}

void test_ft_strncmp() {
    printf("Testing ft_strncmp:\n");
    printf("ft_strncmp('Hello', 'Hello', 5) = %d, expected = 0\n", ft_strncmp("Hello", "Hello", 5));
    printf("ft_strncmp('Hello', 'World', 5) = %d, expected = < 0\n", ft_strncmp("Hello", "World", 5));
}

void test_ft_strnstr() {
    printf("Testing ft_strnstr:\n");
    printf("ft_strnstr('Hello World', 'World', 11) = '%s', expected = 'World'\n", ft_strnstr("Hello World", "World", 11));
}

void test_ft_strjoin() {
    char *result = ft_strjoin("Hello", " World");
    printf("Testing ft_strjoin: '%s', expected = 'Hello World'\n", result);
    free(result);
}

void test_ft_strdup() {
    char *result = ft_strdup("Hello");
    printf("Testing ft_strdup: '%s', expected = 'Hello'\n", result);
    free(result);
}

void test_ft_strrchr() {
    printf("Testing ft_strrchr:\n");
    printf("ft_strrchr('Hello World', 'o') = '%s', expected = 'o World'\n", ft_strrchr("Hello World", 'o'));
}

void test_ft_strmapi() {
    char *result = ft_strmapi("Hello", ft_toupper);
    printf("Testing ft_strmapi: '%s', expected = 'HELLO'\n", result);
    free(result);
}

void test_ft_striteri() {
    char str[] = "hello";
    ft_striteri(str, ft_toupper);
    printf("Testing ft_striteri: '%s', expected = 'HELLO'\n", str);
}

void test_ft_strchr() {
    printf("Testing ft_strchr:\n");
    printf("ft_strchr('Hello', 'e') = '%s', expected = 'ello'\n", ft_strchr("Hello", 'e'));
}

void test_ft_strtrim() {
    char *result = ft_strtrim("   Hello World   ", " ");
    printf("Testing ft_strtrim: '%s', expected = 'Hello World'\n", result);
    free(result);
}

void test_ft_substr() {
    char *result = ft_substr("Hello World", 6, 5);
    printf("Testing ft_substr: '%s', expected = 'World'\n", result);
    free(result);
}

void test_ft_split() {
    char **result = ft_split("Hello World", ' ');
    printf("Testing ft_split:\n");
    for (int i = 0; result[i] != NULL; i++) {
        printf("result[%d] = '%s'\n", i, result[i]);
        free(result[i]);
    }
    free(result);
}

void test_ft_atoi() {
    printf("Testing ft_atoi:\n");
    printf("ft_atoi('42') = %d, expected = 42\n", ft_atoi("42"));
    printf("ft_atoi('-42') = %d, expected = -42\n", ft_atoi("-42"));
}

void test_ft_itoa() {
    char *result = ft_itoa(42);
    printf("Testing ft_itoa: '%s', expected = '42'\n", result);
    free(result);
}

void test_ft_putstr_fd() {
    printf("Testing ft_putstr_fd: ");
    ft_putstr_fd("Hello World\n", 1);
}

void test_ft_putendl_fd() {
    printf("Testing ft_putendl_fd: ");
    ft_putendl_fd("Hello World", 1);
}

void test_ft_putchar_fd() {
    printf("Testing ft_putchar_fd: ");
    ft_putchar_fd('A', 1);
    printf("\n");
}

void test_ft_putnbr_fd() {
    printf("Testing ft_putnbr_fd: ");
    ft_putnbr_fd(42, 1);
    printf("\n");
}

void test_ft_memset() {
    char str[20] = "Hello World";
    ft_memset(str, '!', 5);
    printf("Testing ft_memset: '%s', expected = '!!!!! World'\n", str);
}

void test_ft_bzero() {
    char str[20] = "Hello World";
    ft_bzero(str, 5);
    printf("Testing ft_bzero: '%s', expected = '     World'\n", str);
}

void test_ft_memcpy() {
    char dest[20] = "Goodbye";
    ft_memcpy(dest, "Hello", 5);
    printf("Testing ft_memcpy: '%s', expected = 'Hello'\n", dest);
}

void test_ft_memmove() {
    char str[20] = "Hello World";
    ft_memmove(str + 6, str, 5);
    printf("Testing ft_memmove: '%s', expected = 'Hello Hello'\n", str);
}

void test_ft_calloc() {
    int *arr = (int *)ft_calloc(5, sizeof(int));
    printf("Testing ft_calloc:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr);
}

void test_ft_memchr() {
    char str[] = "Hello World";
    printf("Testing ft_memchr: '%c', expected = 'o'\n", *(char *)ft_memchr(str, 'o', 11));
}

void test_ft_memcmp() {
    printf("Testing ft_memcmp: %d, expected = 0\n", ft_memcmp("Hello", "Hello", 5));
    printf("Testing ft_memcmp: %d, expected = < 0\n", ft_memcmp("Hello", "World", 5));
}

void test_ft_isalnum() {
    printf("Testing ft_isalnum:\n");
    printf("ft_isalnum('A') = %d, expected = 1\n", ft_isalnum('A'));
    printf("ft_isalnum('1') = %d, expected = 1\n", ft_isalnum('1'));
    printf("ft_isalnum('!') = %d, expected = 0\n", ft_isalnum('!'));
}

void test_ft_isalpha() {
    printf("Testing ft_isalpha:\n");
    printf("ft_isalpha('A') = %d, expected = 1\n", ft_isalpha('A'));
    printf("ft_isalpha('1') = %d, expected = 0\n", ft_isalpha('1'));
}

void test_ft_isdigit() {
    printf("Testing ft_isdigit:\n");
    printf("ft_isdigit('1') = %d, expected = 1\n", ft_isdigit('1'));
    printf("ft_isdigit('A') = %d, expected = 0\n", ft_isdigit('A'));
}

void test_ft_isascii() {
    printf("Testing ft_isascii:\n");
    printf("ft_isascii('A') = %d, expected = 1\n", ft_isascii('A'));
    printf("ft_isascii(128) = %d, expected = 0\n", ft_isascii(128));
}

void test_ft_isprint() {
    printf("Testing ft_isprint:\n");
    printf("ft_isprint('A') = %d, expected = 1\n", ft_isprint('A'));
    printf("ft_isprint('\n') = %d, expected = 0\n", ft_isprint('\n'));
}

// Funciones de la lista enlazada
void test_linked_list_functions() {
    t_list *list = ft_lstnew("First");
    ft_lstadd_front(&list, ft_lstnew("Second"));
    ft_lstadd_back(&list, ft_lstnew("Third"));

    printf("Testing ft_lstsize: %d, expected = 3\n", ft_lstsize(list));

    t_list *last = ft_lstlast(list);
    printf("Testing ft_lstlast: '%s', expected = 'Third'\n", (char *)last->content);

    ft_lstdelone(list->next, free);
    list = list->next; // Move to the next node
    printf("Testing after ft_lstdelone: Size = %d, expected = 2\n", ft_lstsize(list));

    ft_lstclear(&list, free);
    printf("Testing after ft_lstclear: Size = %d, expected = 0\n", ft_lstsize(list));
}
