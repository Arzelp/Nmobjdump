/*
** init32.c for init32 in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/objdump/init/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Feb 26 16:09:16 2017 Paskal Arzel
** Last update Sun Feb 26 16:19:00 2017 Paskal Arzel
*/

#include "my_obj.h"

#include "my_obj.h"

static int		init_ptrs32(t_obj	*obj)
{
  obj->elf32 = (Elf32_Ehdr *)obj->data;
  if ((char *)obj->elf > (char *)(obj->data + obj->fsize))
    return (EXIT_FAILURE);
  obj->shdr32 = (Elf32_Shdr *)(obj->data + obj->elf->e_shoff);
  if ((char *)obj->shdr > (char *)(obj->data + obj->fsize))
    return (EXIT_FAILURE);
  obj->phdr32 = (Elf32_Phdr *)(obj->data + obj->elf->e_phoff);
  if ((char *)obj->phdr > (char *)(obj->data + obj->fsize))
    return (EXIT_FAILURE);
  obj->sct_names =
    (char *)(obj->data + obj->shdr[obj->elf->e_shstrndx].sh_offset);
  if ((char *)obj->sct_names > (char *)(obj->data + obj->fsize))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		init_obj32(t_obj *obj)
{
  if (init_ptrs32(obj) == EXIT_FAILURE)
  {
    printf("init_ptrs failed\n");
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
