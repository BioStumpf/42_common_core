#include "libft.h"

char	*ft_pathjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	tot_len;
	char	*out;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tot_len = s1_len + s2_len;
	out = malloc(tot_len + 2);
	if (!out)
		return (0);
	ft_strlcpy(out, s1, tot_len + 2);
	out[s1_len] = '/';
	out[s1_len + 1] = '\0';
	ft_strlcat(out + s1_len + 1, s2, tot_len + 2);
	return (out);
}
