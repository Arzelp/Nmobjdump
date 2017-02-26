/*
** print.c for print in /home/paskal/rendu/System_Unix/PSU_2016_objobjdump/src/objdump/print/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Feb 23 13:30:43 2017 Paskal Arzel
** Last update Sun Feb 26 16:32:39 2017 Paskal Arzel
*/

#include "my_obj.h"

void	print_name(t_obj *obj, int i)
{
  printf("Contents of section %s:\n", &obj->sct_names[obj->shdr[i].sh_name]);
}

void	print_data(t_obj *obj, int i)
{
  int		j;

  j = 0;
  obj->print.len = obj->shdr[i].sh_size;
  obj->print.pos = obj->shdr[i].sh_addr;
  obj->size_print = obj->calc_size_print(obj->print.len, obj->print.pos);
  if (obj->size_print < 4)
    obj->size_print = 4;
  while (j < obj->print.len)
  {
    obj->print_line(obj, j, i);
    printf("\n");
    j += 16;
  }
}

void	print_obj_data(t_obj *obj)
{
  int		i;

  i = 0;
  while (i < obj->elf->e_shnum - 3)
  {
    if (strlen(&obj->sct_names[obj->shdr[i].sh_name]) > 0 &&
        (char)(obj->sct_names[obj->shdr[i].sh_name]) == '.')
	    {
        if (strcmp(&obj->sct_names[obj->shdr[i].sh_name], ".bss") != 0
    	    && obj->shdr[i].sh_size > 0)
        {
          obj->print_name(obj, i);
          obj->print_data(obj, i);
        }
      }
    i++;
  }
}

void	print_sh_name(t_obj *obj)
{
  int		i;

  i = 0;
  while (i < obj->elf->e_shnum)
    {
    	printf("%d: %s\n", i, &obj->sct_names[obj->shdr[i].sh_name]);
      i++;
    }
}
