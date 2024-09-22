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

#define ASSERT_EQ(actual, expected) do { \
    if ((actual) != (expected)) { \
        printf("Assertion failed: expected %d, got %d\n", (expected), (actual)); \
    } \
} while (0)

#define ASSERT_STR_EQ(actual, expected) do { \
    if (strcmp((actual), (expected)) != 0) { \
        printf("Assertion failed: expected '%s', got '%s'\n", (expected), (actual)); \
    } \
} while (0)

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
    ASSERT_EQ(ft_tolower('A'), 'a');
    ASSERT_EQ(ft_tolower('a'), 'a');
    ASSERT_EQ(ft_tolower('1'), '1');
    ASSERT_EQ(ft_tolower(0), 0); // Null character
    ASSERT_EQ(ft_tolower(-1), -1); // Out of range
}

void test_ft_toupper() {
    printf("Testing ft_toupper:\n");
    ASSERT_EQ(ft_toupper('a'), 'A');
    ASSERT_EQ(ft_toupper('A'), 'A');
    ASSERT_EQ(ft_toupper('1'), '1');
    ASSERT_EQ(ft_toupper(0), 0); // Null character
    ASSERT_EQ(ft_toupper(-1), -1); // Out of range
}

void test_ft_strlen() {
    printf("Testing ft_strlen:\n");
    ASSERT_EQ(ft_strlen("Hello"), 5);
    ASSERT_EQ(ft_strlen(""), 0);
    ASSERT_EQ(ft_strlen(" "), 1); // Space character
    ASSERT_EQ(ft_strlen("12345"), 5); // Numeric string
}

void test_ft_strlcpy() {
    char dest[20];
    printf("Testing ft_strlcpy:\n");
    ASSERT_EQ(ft_strlcpy(dest, "Hello", sizeof(dest)), 5);
    ASSERT_STR_EQ(dest, "Hello");
    ft_strlcpy(dest, "Hello, World!", sizeof(dest));
    ASSERT_STR_EQ(dest, "Hello, World");
}

void test_ft_strlcat() {
    char dest[20] = "Hello";
    printf("Testing ft_strlcat:\n");
    ASSERT_EQ(ft_strlcat(dest, " World", sizeof(dest)), 11);
    ASSERT_STR_EQ(dest, "Hello World");
    ASSERT_EQ(ft_strlcat(dest, "!", sizeof(dest)), 12);
    ASSERT_STR_EQ(dest, "Hello World");
}

void test_ft_strncmp() {
    printf("Testing ft_strncmp:\n");
    ASSERT_EQ(ft_strncmp("Hello", "Hello", 5), 0);
    ASSERT_EQ(ft_strncmp("Hello", "Hell", 5), 'o'); // Comparison to shorter string
    ASSERT_EQ(ft_strncmp("Hello", "World", 5), 'H' - 'W');
}

void test_ft_strnstr() {
    printf("Testing ft_strnstr:\n");
    ASSERT_STR_EQ(ft_strnstr("Hello World", "World", 11), "World");
    ASSERT_STR_EQ(ft_strnstr("Hello World", "lo", 5), "lo World");
    ASSERT_STR_EQ(ft_strnstr("Hello", "lo", 2), NULL); // Not found
}

void test_ft_strjoin() {
    char *result = ft_strjoin("Hello", " World");
    printf("Testing ft_strjoin: ");
    ASSERT_STR_EQ(result, "Hello World");
    free(result);
}

void test_ft_strdup() {
    char *result = ft_strdup("Hello");
    printf("Testing ft_strdup: ");
    ASSERT_STR_EQ(result, "Hello");
    free(result);
}

void test_ft_strrchr() {
    printf("Testing ft_strrchr:\n");
    ASSERT_STR_EQ(ft_strrchr("Hello World", 'o'), "o World");
    ASSERT_STR_EQ(ft_strrchr("Hello", 'x'), NULL); // Not found
}

void test_ft_strmapi() {
    char *result = ft_strmapi("Hello", ft_toupper);
    printf("Testing ft_strmapi: ");
    ASSERT_STR_EQ(result, "HELLO");
    free(result);
}

void test_ft_striteri() {
    char str[] = "hello";
    ft_striteri(str, ft_toupper);
    printf("Testing ft_striteri: ");
    ASSERT_STR_EQ(str, "HELLO");
}

void test_ft_strchr() {
    printf("Testing ft_strchr:\n");
    ASSERT_STR_EQ(ft_strchr("Hello", 'e'), "ello");
    ASSERT_STR_EQ(ft_strchr("Hello", 'x'), NULL); // Not found
}

void test_ft_strtrim() {
    char *result = ft_strtrim("   Hello World   ", " ");
    printf("Testing ft_strtrim: ");
    ASSERT_STR_EQ(result, "Hello World");
    free(result);
}

void test_ft_substr() {
    char *result = ft_substr("Hello World", 6, 5);
    printf("Testing ft_substr: ");
    ASSERT_STR_EQ(result, "World");
    free(result);
}

void test_ft_split() {
    char **result = ft_split("Hello World", ' ');
    printf("Testing ft_split:\n");
    ASSERT_STR_EQ(result[0], "Hello");
    ASSERT_STR_EQ(result[1], "World");
    ASSERT_EQ(result[2], NULL); // Check null termination
    for (int i = 0; i < 2; i++) {
        free(result[i]);
    }
    free(result);
}

void test_ft_atoi() {
    printf("Testing ft_atoi:\n");
    ASSERT_EQ(ft_atoi("42"), 42);
    ASSERT_EQ(ft_atoi("-42"), -42);
    ASSERT_EQ(ft_atoi("  +42"), 42); // Leading spaces
    ASSERT_EQ(ft_atoi("42abc"), 42); // Trailing characters
    ASSERT_EQ(ft_atoi("abc42"), 0); // Non-numeric string
}

void test_ft_itoa() {
    char *result = ft_itoa(42);
    printf("Testing ft_itoa: ");
    ASSERT_STR_EQ(result, "42");
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
    printf("Testing ft_memset: ");
    ASSERT_STR_EQ(str, "!!!!! World");
}

void test_ft_bzero() {
    char str[20] = "Hello World";
    ft_bzero(str, 5);
    printf("Testing ft_bzero: ");
    ASSERT_STR_EQ(str, "     World");
}

void test_ft_memcpy() {
    char dest[20];
    ft_memcpy(dest, "Hello", 6);
    printf("Testing ft_memcpy: ");
    ASSERT_STR_EQ(dest, "Hello");
}

void test_ft_memmove() {
    char str[20] = "Hello World";
    ft_memmove(str + 6, str, 5);
    printf("Testing ft_memmove: ");
    ASSERT_STR_EQ(str, "Hello Hello");
}

void test_ft_calloc() {
    char *arr = ft_calloc(5, sizeof(char));
    printf("Testing ft_calloc: ");
    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(arr[i], 0);
    }
    free(arr);
}

void test_ft_memchr() {
    char str[] = "Hello World";
    printf("Testing ft_memchr: ");
    ASSERT_EQ(*(char *)ft_memchr(str, 'o', 11), 'o');
}

void test_ft_memcmp() {
    printf("Testing ft_memcmp:\n");
    ASSERT_EQ(ft_memcmp("Hello", "Hello", 5), 0);
    ASSERT_EQ(ft_memcmp("Hello", "Hell", 5), 'o'); // Comparison to shorter string
    ASSERT_EQ(ft_memcmp("Hello", "World", 5), 'H' - 'W');
}

void test_ft_isalnum() {
    printf("Testing ft_isalnum:\n");
    ASSERT_EQ(ft_isalnum('A'), 1);
    ASSERT_EQ(ft_isalnum('1'), 1);
    ASSERT_EQ(ft_isalnum('!'), 0);
}

void test_ft_isalpha() {
    printf("Testing ft_isalpha:\n");
    ASSERT_EQ(ft_isalpha('A'), 1);
    ASSERT_EQ(ft_isalpha('1'), 0);
}

void test_ft_isdigit() {
    printf("Testing ft_isdigit:\n");
    ASSERT_EQ(ft_isdigit('1'), 1);
    ASSERT_EQ(ft_isdigit('A'), 0);
}

void test_ft_isascii() {
    printf("Testing ft_isascii:\n");
    ASSERT_EQ(ft_isascii('A'), 1);
    ASSERT_EQ(ft_isascii(128), 0); // Out of range
}

void test_ft_isprint() {
    printf("Testing ft_isprint:\n");
    ASSERT_EQ(ft_isprint('A'), 1);
    ASSERT_EQ(ft_isprint('\n'), 0); // New line is not printable
}

// Funciones de la lista enlazada
void test_linked_list_functions() {
    t_list *list = ft_lstnew("First");
    ft_lstadd_front(&list, ft_lstnew("Second"));
    ft_lstadd_back(&list, ft_lstnew("Third"));

    printf("Testing ft_lstsize: ");
    ASSERT_EQ(ft_lstsize(list), 3);

    t_list *last = ft_lstlast(list);
    printf("Testing ft_lstlast: ");
    ASSERT_STR_EQ((char *)last->content, "Third");

    ft_lstdelone(list->next, free);
    list = list->next; // Move to the next node
    printf("Testing after ft_lstdelone: ");
    ASSERT_EQ(ft_lstsize(list), 2);

    ft_lstclear(&list, free);
    printf("Testing after ft_lstclear: ");
    ASSERT_EQ(ft_lstsize(list), 0);
}
