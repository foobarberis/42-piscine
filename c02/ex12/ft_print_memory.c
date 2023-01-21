/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:48:55 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/21 12:48:56 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>

/* print adress of pointer */
void ft_print_addr(unsigned long off)
{
  int   i;
  char *hex;
  char  addr[17];

  i = 0;
  addr[16] = 0;
  hex = "0123456789abcdef";
  while (i <= 16)
    {
      if (off > 0)
	{
	  addr[15 - i] = hex[off % 16];
	  off /= 16;
	}
      else
	addr[15 - i] = '0';
      i++;
    }
  write(1, addr, 16);
  write(1, ": ", 2);
}

/* display char in hex */
void ft_print_hex(unsigned char c)
{
  char *hex;

  hex = "0123456789abcdef";
  write(1, &hex[c / 16], 1);
  write(1, &hex[c % 16], 1);
}

void ft_print_text(char *data, unsigned int size)
{
  unsigned int i;

  i = 0;
  while (i < size)
    {
      if (data[i] < ' ' || data[i] > '~')
	write(1, ".", 1);
      else
	write(1, &data[i], 1);
      i++;
    }
}

void ft_print_line(void *addr, unsigned int size)
{
  unsigned int   i;
  unsigned char *data;

  i = 0;
  data = (unsigned char *) addr;
  ft_print_addr((unsigned long) addr);
  while (i < 16)
    {
      if (i < size)
	ft_print_hex(data[i]);
      else
	write(1, "  ", 2);
      if (i % 2 == 1)
	write(1, " ", 1);
      i++;
    }
  ft_print_text((char *) addr, size);
  write(1, "\n", 1);
}

void *ft_print_memory(void *addr, unsigned int size)
{
  unsigned int i;
  int          leftover;

  i = 0;
  leftover = size % 16;
  while (i++ < size / 16)
    ft_print_line(addr + 16 * (i - 1), 16);
  if (leftover)
    ft_print_line(addr + 16 * (i - 1), leftover);
  return (addr);
}

int main(void)
{
  char *s = "Salut les aminches, ceci est\v\t un test\n\n.";
  ft_print_memory(s, strlen(s));
  return (0);
}
