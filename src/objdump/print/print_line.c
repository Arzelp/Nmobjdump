/*
** print_line.c for print_line in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/objdump/print/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Feb 23 14:45:08 2017 Paskal Arzel
** Last update Sat Feb 25 17:25:30 2017 Paskal Arzel
*/

#include "my_obj.h"

void		print_nb(t_obj *obj, int j)
{
  int		divi;
  int		nb;
  int		i;

  i = 0;
  divi = 1;
  nb = obj->print.pos + j;
  while (i < obj->size_print - 1)
  {
    divi *= 16;
    i++;
  }
  while (divi >= 1)
  {
    printf("%x", nb / divi);
    nb = nb % divi;
    divi /= 16;
  }
}

void		print_char_hexa(t_obj *obj, int i, int x)
{
  unsigned char	c;

  c = (unsigned char)(*((obj->data + obj->shdr[x].sh_offset + i)));
  printf("%.2x", c);
}

void		print_char(t_obj *obj, int i, int x)
{
  char	c;

  c = (char)(*((obj->data + obj->shdr[x].sh_offset + i)));
  if (isprint(c))
    printf("%c", c);
  else
    printf(".");
  (void)i;
}

void		print_line(t_obj *obj, int j, int x)
{
  int		i;

  i = 0;
  printf(" ");
  obj->print_nb(obj, j);
  while (i < SIZE_HEXA)
  {
    if (i % 4 == 0)
      printf(" ");
    if (j + i < obj->print.len)
	    obj->print_char_hexa(obj, j + i, x);
    else
	    printf("  ");
    i++;
  }
  printf("  ");
  i = 0;
  while (i < SIZE_HEXA)
  {
    if (j + i < obj->print.len)
      obj->print_char(obj, j + i, x);
    else
	    printf(" ");
    i++;
  }
}
