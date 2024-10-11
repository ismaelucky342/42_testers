#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main() {
	char *puntero = "Hola mundo";
	
    printf("Hola mundo\n");
	ft_printf("Hola mundo\n");

	printf("| len %d\n", printf("Hola mundo"));
	ft_printf("| len %d\n", ft_printf("Hola mundo"));

	printf("| len %d\n", printf("prueba char %c %c %c %c", 'H', 'o', 'l', 'a'));
	ft_printf("| len %d\n", ft_printf
	("prueba char %c %c %c %c", 'H', 'o', 'l', 'a'));

	printf("| len %d\n", printf("prueba string %s %s", "Hola", "mundo"));
	ft_printf("| len %d\n", ft_printf("prueba string %s %s", "Hola", "mundo"));
	
	printf("| len %d\n", printf("prueba puntero %p", puntero));
	ft_printf("| len %d\n", ft_printf("prueba puntero %p", puntero));

	printf("| len %d\n", printf("prueba int %%d %d %d %d", 10, 11, 12));
	ft_printf("| len %d\n", ft_printf("prueba int %%d %d %d %d", 10, 11, 12));

	printf("| len %d\n", printf("prueba int %%i %i %i %i", 10, 11, 12));
	ft_printf("| len %d\n", ft_printf("prueba int %%i %i %i %i", 10, 11, 12));

	printf("| len %d\n", printf("prueba int %%u %u %u %u", 10, 11, 12));
	ft_printf("| len %d\n", ft_printf("prueba int %%u %u %u %u", 10, 11, 12));

	printf("| len %d\n", printf("prueba hexadecimal %x", 42424242));
	ft_printf("| len %d\n", ft_printf("prueba hexadecimal %x", 42424242));

	printf("| len %d\n", printf("prueba HEXADECIMAL %X", 42424242));
	ft_printf("| len %d\n", ft_printf("prueba HEXADECIMAL %X", 42424242));

	printf("| len %d\n", printf("prueba punteros %p", (void *)-14523));
	ft_printf("| len %d\n", ft_printf("prueba punteros %p", (void *)-14523));

	/* Susto: 
	printf("Cadena:%% % %s\n", "cadena");
    ft_printf("Puntero:%% % %s\n", "cadena");*/

	printf("| len %d\n", printf
	("prueba punteros nulos %p %p", (void *)0, (void *)0));
	ft_printf("| len %d\n", ft_printf
	("prueba punteros nulos %p %p", (void *)0, (void *)0));
    
    return 0;
}