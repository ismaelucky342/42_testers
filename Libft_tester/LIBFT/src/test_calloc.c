/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:52:19 by ismherna          #+#    #+#             */
/*   Updated: 2025/02/05 01:01:56 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft.h" 
#include "../tester_utils.h"

void	test_calloc(char *str, FILE *trace_file, int *score,
		size_t test_num)
{
	char *original_str = strdup(str);
	char *second_str = strdup(str);
	
	second_str = (char *)calloc(strlen(second_str) + 1, sizeof(char));
	original_str = (char *)ft_calloc(strlen(original_str) + 1, sizeof(char));
	
	fprintf(trace_file, "test[%zu]: \"%s\"\n", test_num, str);
	fprintf(trace_file, "calloc:    \"%s\"\n", second_str);
	fprintf(trace_file, "ft_calloc: \"%s\"\n", original_str);	
	printf("test[%zu]: \"%s\"\n", test_num, str);
	printf("calloc:    \"%s\"\n", second_str);
	printf("ft_calloc: \"%s\"\n", original_str);
	if (strcmp(second_str, original_str) == 0)
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
	free(second_str);
}

int	main(void)
{
	int			test_N;
	const char	*test_cases[] = {"","a","hello","12345","!@#$%^&*()","hello world", "hello\tworld\n","\0","hello\0world","\0\0\0\0\0"};
	size_t		num_tests;
	int			score;
	FILE		*trace_file;

	test_N = 1;
	num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
	score = 0;

	system("mkdir -p output");
	trace_file = fopen("output/test_bzero_trace.txt", "w");
	if (!trace_file)
	{
		perror("ERROR: opening file");
		return (1);
	}
	for (size_t i = 0; i < num_tests; i++)
	{
		test_calloc((char *)test_cases[i], trace_file, &score, test_N++);
		usleep(100000);
	}
	fclose(trace_file);
	printf("GRADE: %d/%zu\n", score, num_tests);
	return (0);
}


