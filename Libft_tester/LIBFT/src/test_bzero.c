/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:52:19 by ismherna          #+#    #+#             */
/*   Updated: 2025/02/05 01:01:46 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft.h" 
#include "../tester_utils.h"

void	test_bzero(char *str, FILE *trace_file, int *score,
		size_t test_num)
{
	char *original_str = strdup(str);
	char *bzero_str = strdup(str);
	
	bzero((void *)bzero_str, strlen(bzero_str));
	ft_bzero((void *)original_str, strlen(original_str));
	
	fprintf(trace_file, "test[%zu]: \"%s\"\n", test_num, str);
	fprintf(trace_file, "bzero:    \"%s\"\n", bzero_str);
	fprintf(trace_file, "ft_bzero: \"%s\"\n", original_str);	
	printf("test[%zu]: \"%s\"\n", test_num, str);
	printf("bzero:    \"%s\"\n", bzero_str);
	printf("ft_bzero: \"%s\"\n", original_str);
	if (strcmp(bzero_str, original_str) == 0)
	{
		fprintf(trace_file, COLOR_GREEN "✅ OK\n\n" COLOR_RESET);
		printf(COLOR_GREEN "✅ OK\n\n" COLOR_RESET);
		(*score)++;
	}
	else
	{
		fprintf(trace_file, "❌ KO!\n\n");
		printf("❌ KO!\n\n");
	}
	free(original_str);
	free(bzero_str);
}

int	main(void)
{
	int			test_N;
	const char	*test_cases[] = {"Hello World", "", "    ", "\t\n  -456",
			"1234567890", "12345678901234567890", "   ", "000000", "ab",
			"This is a test", "   123", "Special_characters!@#", "123abc",
			"9223372036854775807", "   ", " *-344535", "9999999999999999999"};
	size_t		num_tests;
	int			score;
	FILE		*trace_file;

	test_N = 1;
	num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
	score = 0;
	// Crear directorio de salida si no existe
	system("mkdir -p output");
	// Abrir archivo para escribir los resultados
	trace_file = fopen("output/test_bzero_trace.txt", "w");
	if (!trace_file)
	{
		perror("ERROR: opening file");
		return (1);
	}
	// Iterar sobre los casos de prueba y registrar resultados en el archivo
	for (size_t i = 0; i < num_tests; i++)
	{
		test_bzero((char *)test_cases[i], trace_file, &score, test_N++);
		usleep(100000);
	}
	// Cerrar el archivo
	fclose(trace_file);
	// Mostrar puntuación final
	printf("GRADE: %d/%zu\n", score, num_tests);
	return (0);
}
