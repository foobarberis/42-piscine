#include <stdio.h>

int		ft_sqrt(int nb)
{
	int i;

	i = 0;
	while (i * i < nb && i < 46340)
		++i;
	return (i * i == nb && i <= 46340 ? i : 0);
}

int main(void)
{
	// printf("%d\n", ft_sqrt(2147488281));
	printf("%d\n", ft_sqrt(256));
}
