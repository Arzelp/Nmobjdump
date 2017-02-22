/*
** init_longname.c for longname in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/nm/init/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Wed Feb 22 11:48:33 2017 Paskal Arzel
** Last update Wed Feb 22 11:53:06 2017 Paskal Arzel
*/

#include "my_nm.h"

int		init_longname(t_nm *nm)
{
  nm->lgnm->start_longname = nm->data;
  nm->lgnm->size = atoi(nm->arch_header->size);
  return (EXIT_SUCCESS);
}
