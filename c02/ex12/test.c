#include <string.h>

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void print_ascii(const char *addr, int i)
{
	int j;
	int len;

	j = 0;
	if ((i + 1) % 16 == 0)
		len = 16;
	else
		len = (i + 1) % 16;
	while (j < 16 - len)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (j % 2)
			ft_putchar(' ');
		j++;
	}
	if ((16 - len) % 2)
		ft_putchar(' ');
	j = 0;
	while (j < len)
	{
		if (*(addr + i / 16 * 16 + j) >= 32 && *(addr + i / 16 * 16 + j) <= 126)
			ft_putchar(*(addr + i / 16 * 16 + j));
		else
			ft_putchar('.');
		j++;
	}
	ft_putchar('\n');
}

void print_hex(unsigned char value, int index)
{
	if (index < 2)
	{
		print_hex(value / 16, index + 1);
		if (value % 16 >= 10)
			ft_putchar('a' + value % 16 % 10);
		else
			ft_putchar('0' + value % 16);
	}
}

void ft_print_memory(const void *addr, size_t size)
{
	char  *ptr;
	size_t i;

	if (addr && size > 0)
	{
		ptr = (char *) addr;
		i = 0;
		while (i < size)
		{
			print_hex(*(ptr + i), 0);
			if (i % 2)
				ft_putchar(' ');
			if ((i + 1) % 16 == 0 || (i + 1) == size)
				print_ascii(addr, i);
			i++;
		}
	}
}

int main(void)
{
	char *s = "Salut les aminches, ceci est\v\t un test\n\n.";
	ft_print_memory(s, strlen(s));

	return (0);
}
