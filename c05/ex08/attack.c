#include <stdio.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (n *= -1);
	else
		return (n);
}

int	ft_attack(int *arr, int n)
{
	int	a[2][n];
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		a[0][i] = i;
		a[1][i] = arr[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (ft_abs(a[0][i] - a[0][j]) == ft_abs(a[1][i] - a[1][j]))
			{
				printf("(%d, %d) ! (%d, %d)", a[0][i], a[1][i], a[0][j], a[1][j]);
				return (1);
			}

			j++;
		}
		i++;
	}
	return (0);
}

int main(void)
{
	int a[10] = {0,2,5,9,7,4,8,1,3,6};
	ft_attack(a, 10);
}
