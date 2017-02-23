/*
** calc_print.c for calcprint in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/objdump/print/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Feb 23 14:33:41 2017 Paskal Arzel
** Last update Thu Feb 23 14:39:47 2017 Paskal Arzel
*/

#include "my_obj.h"

int		calc_size_print(int pos, int len)
{
  int		size;
  int		tot;

  tot = pos + len;
  size = 1;
  while ((tot = tot / SIZE_HEXA) > 1)
    size++;
  return (size);
}
