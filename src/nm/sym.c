/*
** sym.c for sym in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/nm/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Fri Feb 17 14:06:08 2017 Paskal Arzel
** Last update Fri Feb 17 15:10:05 2017 Paskal Arzel
*/

#include "my_nm.h"

int		find_sym_idxs(t_nm *nm)
{
  int		i;

  i = 0;
  while (i < nm->elf->e_shnum)
    {
      if (!strcmp((char *)&((nm->sct_names)[nm->shdr[i].sh_name]),
		    (char *)".symtab"))
        nm->sym.symshdr = (Elf64_Shdr *)&(nm->shdr)[i];
      if (!strcmp((char *)&((nm->sct_names)[nm->shdr[i].sh_name]),
        (char *)".strtab"))
        nm->sym.strtab = (Elf64_Shdr *)&(nm->shdr)[i];
      i++;
    }
  return (EXIT_SUCCESS);
}

int		get_sym_nb(t_nm *nm)
{
  return (nm->sym.symshdr->sh_size / sizeof(Elf64_Sym));
}
