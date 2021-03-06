/*
** init.c for init in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/objdump/init/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Wed Feb 22 15:50:39 2017 Paskal Arzel
** Last update Sun Feb 26 16:24:27 2017 Paskal Arzel
*/

#include "my_obj.h"

static int		filesize(int fd)
{
  return (lseek(fd, 0, SEEK_END));
}

void		set_obj_fct(t_obj *obj)
{
  obj->filesize = &filesize;
  obj->print_sh_name = &print_sh_name;
  obj->print_sh_name32 = &print_sh_name32;
  obj->print_obj_data = &print_obj_data;
  obj->print_obj_data32 = &print_obj_data32;
  obj->print_name = &print_name;
  obj->print_name32 = &print_name32;
  obj->print_nb = &print_nb;
  obj->print_nb32 = &print_nb32;
  obj->print_line = &print_line;
  obj->print_line32 = &print_line32;
  obj->print_char = &print_char;
  obj->print_char_hexa = &print_char_hexa;
  obj->print_char32 = &print_char32;
  obj->print_char_hexa32 = &print_char_hexa32;
  obj->print_data = &print_data;
  obj->print_data32 = &print_data32;
  obj->print_header = &print_header;
  obj->print_header32 = &print_header32;
  obj->calc_size_print = &calc_size_print;
}

static int		init_ptrs(t_obj	*obj)
{
  obj->elf = (Elf64_Ehdr *)obj->data;
  if ((char *)obj->elf > (char *)(obj->data + obj->fsize))
    return (EXIT_FAILURE);
  obj->shdr = (Elf64_Shdr *)(obj->data + obj->elf->e_shoff);
  if ((char *)obj->shdr > (char *)(obj->data + obj->fsize))
    return (EXIT_FAILURE);
  obj->phdr = (Elf64_Phdr *)(obj->data + obj->elf->e_phoff);
  if ((char *)obj->phdr > (char *)(obj->data + obj->fsize))
    return (EXIT_FAILURE);
  obj->sct_names =
    (char *)(obj->data + obj->shdr[obj->elf->e_shstrndx].sh_offset);
  if ((char *)obj->sct_names > (char *)(obj->data + obj->fsize))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		init_obj(t_obj *obj)
{
  if (init_ptrs(obj) == EXIT_FAILURE)
  {
    printf("init_ptrs failed\n");
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
