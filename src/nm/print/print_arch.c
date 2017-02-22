/*
** print_arch.c for print_arch in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/nm/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Wed Feb 22 10:15:57 2017 Paskal Arzel
** Last update Wed Feb 22 11:54:29 2017 Paskal Arzel
*/

#include "my_nm.h"

static void	print_longname(t_nm *nm, char *name)
{
  int		pos;
  int		i;

  i = 0;
  pos = atoi(name + 1);
  name = nm->lgnm->start_longname + pos;
  while (name[i] && name[i] != '/')
    {
      printf("%c", name[i]);
      i++;
    }
}

static void	print_name(t_nm *nm, char *name)
{
  int		i;

  i = 0;
  while (name[i] && name[i] != '/')
    {
      printf("%c", name[i]);
      i++;
    }
  if (i == 0)
    print_longname(nm, name);
  printf(":\n");
}

void	print_file_name(t_nm *nm)
{
  if (nm->arch_header->name[0] == '\0')
    printf("no name\n");
  else
    print_name(nm, nm->arch_header->name);
  return;
}
