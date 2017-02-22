/*
** nm.c for nm in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/nm/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Feb 16 15:11:54 2017 Paskal Arzel
** Last update Wed Feb 22 15:36:13 2017 Paskal Arzel
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_nm.h"

static int	my_nm_elf(t_nm *nm, char *filename)
{
  if (nm->multi)
    printf("\n%s:\n", filename);
  if (init_nm(nm) == EXIT_FAILURE)
  {
    printf("./my_nm: %s: Format de fichier non reconnu\n", filename);
    return (EXIT_FAILURE);
  }
  nm->print_sym_name(nm);
  return (EXIT_SUCCESS);
}

static bool	check_elf(t_nm *nm)
{
  if (strncmp((char *)nm->data + 1, "ELF", 3) == 0)
    return (true);
  return (false);
}

static int	my_nm_arch(t_nm *nm, char *filename)
{
  if (set_base(nm) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while (nm->pos < nm->fsize)
  {
    nm->arch_header = (t_arch_header *)(nm->start_data + nm->pos);
    nm->data = (char *)(nm->start_data + nm->pos + sizeof(t_arch_header));
    if (check_elf(nm))
    {
	    nm->print_file_name(nm);
      if (nm->nm_arch(nm, filename) == EXIT_FAILURE)
	      return (EXIT_FAILURE);
    }
    else
    {
      if (nm->init_longname(nm) == EXIT_FAILURE)
	      return (EXIT_FAILURE);
    }
    nm->pos += atoi(nm->arch_header->size) + sizeof(t_arch_header);
  }
  return (EXIT_SUCCESS);
}

int	my_nm(char *filename, bool multi, int count, int pos)
{
  t_nm	data;
  int	i;

  set_nm_fct(&data);
  data.multi = multi;
  data.ac = count;
  data.i = pos;
  if (filename == NULL || (data.fd = open(filename, O_RDONLY)) == -1)
    return (EXIT_FAILURE);
  data.fsize = data.filesize(data.fd);
  if ((data.data = mmap(NULL,
    data.filesize(data.fd), PROT_READ, MAP_SHARED, data.fd, 0)) == (void *)-1)
    return (EXIT_FAILURE);
  if ((i = strncmp((char *)data.data + 1, "ELF", 3)) == 0)
    return (my_nm_elf(&data, filename));
  else if ((i = strncmp((char *)data.data, "!<arch>", 7)) == 0)
    return (my_nm_arch(&data, filename));
  else
    printf("./my_nm: %s: Format de fichier non reconnu\n", filename);
  return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
  int	i;

  i = 1;
  if (ac == 1)
    {
      my_nm("./a.out", false, 1, 0);
      return (EXIT_SUCCESS);
    }
  while (i < ac)
    {
      if (my_nm(av[i], ((ac >= 3) ? true : false), ac, i) == EXIT_FAILURE)
	      return (EXIT_FAILURE);
      i++;
    }
  return (EXIT_SUCCESS);
}
