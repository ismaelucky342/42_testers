/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:52:19 by ismherna          #+#    #+#             */
/*   Updated: 2025/02/05 01:02:49 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../../libft.h" 
#include "../tester_utils.h"

void test_atoi(const char *str, FILE *trace_file, int *score, size_t test_num)
{
	int original = atoi(str);
	int custom = ft_atoi(str);
	
	fprintf(trace_file, "test[%zu]: \"%s\"\n", test_num, str);
	fprintf(trace_file, "atoi:    %d\n", original);
	fprintf(trace_file, "ft_atoi: %d\n", custom);
	
	printf("test[%zu]: \"%s\"\n", test_num, str);
	printf("atoi:    %d\n", original);
	printf("ft_atoi: %d\n", custom);
	
	if (original == custom) {
		fprintf(trace_file, COLOR_GREEN "✅ OK\n\n"COLOR_RESET);
		printf(COLOR_GREEN"✅ OK\n\n"COLOR_RESET);
		(*score)++;
	} else {
		fprintf(trace_file, "❌ KO!\n\n");
		printf("❌ KO!\n\n");
	}
}

int main()
{
	int test_N = 1;
	const char *test_cases[] = {
		"42", "-42", "0", "2147483647", "-2147483648", "   123", "\t\n  -456", 
		"+789", "--12", "++34", "  00056", "  +00042", "  -00042", "abcd", "123abc", "  -42abc",
		"9223372036854775807", "-9223372036854775808"," *-344535"
	};
	
	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
	int score = 0;

	// Crear directorio de salida si no existe
	system("mkdir -p output");

	// Abrir archivo para escribir los resultados
	FILE *trace_file = fopen("output/test_atoi_trace.txt", "w");
	if (!trace_file) {
		perror("ERROR: opening file");
		return 1;
	}

	// Iterar sobre los casos de prueba y registrar resultados en el archivo
	for (size_t i = 0; i < num_tests; i++) {
		test_atoi(test_cases[i], trace_file, &score, test_N++);
		usleep(100000);
	}

	// Cerrar el archivo
	fclose(trace_file);

	// Mostrar puntuación final
	printf("GRADE: %d/%zu\n", score, num_tests);
	
	return 0;
}
