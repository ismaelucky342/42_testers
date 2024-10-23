#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	full_size;
	char	*buffer;

	full_size = count * size;
	buffer = malloc(full_size);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (i < full_size)
		buffer[i++] = 0;
	return (buffer);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
		dest[i++] = src[j++];
	if (size > i)
		dest[i] = '\0';
	while (src[j++])
		i++;
	return (i);
}

size_t	gnl_ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}
