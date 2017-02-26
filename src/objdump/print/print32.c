/*
** print32.c for print32.c in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/objdump/print/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Feb 26 16:15:24 2017 Paskal Arzel
** Last update Sun Feb 26 16:32:26 2017 Paskal Arzel
*/

#include "my_obj.h"

void	print_name32(t_obj *obj, int i)
{
  printf("Contents of section %s:\n", &obj->sct_names[obj->shdr[i].sh_name]);
}

void	print_data32(t_obj *obj, int i)
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
    obj->print_line32(obj, j, i);
    printf("\n");
    j += 16;
  }
}

void	print_obj_data32(t_obj *obj)
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
          obj->print_name32(obj, i);
          obj->print_data32(obj, i);
        }
      }
    i++;
  }
}

void	print_sh_name32(t_obj *obj)
{
  int		i;

  i = 0;
  while (i < obj->elf->e_shnum)
    {
    	printf("%d: %s\n", i, &obj->sct_names[obj->shdr[i].sh_name]);
      i++;
    }
}
