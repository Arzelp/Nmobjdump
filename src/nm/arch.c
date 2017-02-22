/*
** arch.c for arch in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/nm/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Wed Feb 22 10:27:32 2017 Paskal Arzel
** Last update Wed Feb 22 11:18:00 2017 Paskal Arzel
*/

#include "my_nm.h"

int		nm_arch(t_nm *nm, char *filename)
{
  if (nm->pos > nm->fsize - atoi(nm->arch_header->size) ||
      init_nm(nm) == EXIT_FAILURE)
    {
      printf("./my_nm: %s: Archive mal formée\n", filename);
      return (EXIT_FAILURE);
    }
  nm->print_sym_name(nm);
  if ((int)(nm->pos + atoi(nm->arch_header->size) + sizeof(t_arch_header))
    < nm->fsize)
    printf("\n");
  return (EXIT_SUCCESS);
}
