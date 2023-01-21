#include <string.h>
#include <stdio.h>

void ft_print_memory(const void *addr, size_t size)
{
  size_t printed = 0;
  size_t i;
  const unsigned char* pc = addr;
  for (i=0; i<size; ++i)
    {
      int  g;
      g = (*(pc+i) >> 4) & 0xf;
      g += g >= 10 ? 'a'-10 : '0';
      putchar(g);
      printed++;

      g = *(pc+i) & 0xf;
      g += g >= 10 ? 'a'-10 : '0';
      putchar(g);
      printed++;
      if (printed % 32 == 0) putchar('\n');
      else if (printed % 4 == 0) putchar(' ');
    }
}

int main(void) {
  
  char *s = "Salut les aminches, ceci est\v\t un test\n\n.";
  ft_print_memory(s, strlen(s));

  return (0);
}
