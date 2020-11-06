#include "libft.h"

void	*ft_x_memalloc(size_t size)
{
	void	*res;

	if (!(res = malloc(size)))
		exit(-1);
	ft_bzero(res, size);
	return (res);
}