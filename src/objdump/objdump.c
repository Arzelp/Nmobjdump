/*
** objdump.c for objdump in /home/paskal/rendu/System_Unix/PSU_2016_objobjdump/src/objdump/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Wed Feb 22 15:44:47 2017 Paskal Arzel
** Last update Sun Feb 26 16:18:25 2017 Paskal Arzel
*/

#include "my_obj.h"

int		my_obj_elf32(t_obj *obj, char *filename)
{
  if (init_obj32(obj) == EXIT_FAILURE)
  {
    fprintf(stderr, "objdump: %s: File format not recognized\n", filename);
    return (EXIT_FAILURE);
  }
  obj->print_header32(obj, filename);
  obj->print_obj_data32(obj);
  return (EXIT_SUCCESS);
}

int		my_obj_elf(t_obj *obj, char *filename)
{
  obj->testelf = (Elf64_Ehdr *)obj->data;
  if ((char *)obj->elf > (char *)(obj->data + obj->fsize))
    return (EXIT_FAILURE);
  if (obj->testelf->e_ident[EI_CLASS] == ELFCLASS32)
    return (my_obj_elf32(obj, filename));
  else if (obj->testelf->e_ident[EI_CLASS] == ELFCLASSNONE)
  {
    fprintf(stderr, "objdump: %s: File format not recognized\n", filename);
    return (EXIT_FAILURE);
  }
  if (init_obj(obj) == EXIT_FAILURE)
  {
    fprintf(stderr, "objdump: %s: File format not recognized\n", filename);
    return (EXIT_FAILURE);
  }
  obj->print_header(obj, filename);
  obj->print_obj_data(obj);
  return (EXIT_SUCCESS);
}

int		my_objdump(char *filename)
{
  int			i;
  t_obj		data;

  (void)filename;
  set_obj_fct(&data);
  if (filename == NULL || (data.fd = open(filename, O_RDONLY)) == -1)
  {
    fprintf(stderr, "objdump: %s: No such file\n", filename);
    return (EXIT_FAILURE);
  }
  data.fsize = data.filesize(data.fd);
  if ((data.data = mmap(NULL,
    data.filesize(data.fd), PROT_READ, MAP_SHARED, data.fd, 0)) == (void *)-1)
    return (EXIT_FAILURE);
  if ((i = strncmp((char *)data.data + 1, "ELF", 3)) == 0)
    return (my_obj_elf(&data, filename));
  else
    fprintf(stderr, "objdump: %s: File format not recognized\n", filename);
  return (EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
  int		i;

  i = 1;
  if (ac == 1)
    return (my_objdump("a.out"));
  while (i < ac)
    {
      if (my_objdump(av[i]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
      i++;
    }
  return (EXIT_SUCCESS);
}
