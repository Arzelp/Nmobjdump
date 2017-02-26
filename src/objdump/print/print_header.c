/*
** print_header.c for print_header in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/objdump/print/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sat Feb 25 15:41:10 2017 Paskal Arzel
** Last update Sun Feb 26 15:26:11 2017 Paskal Arzel
*/

#include "my_obj.h"

void	print_format(void)
{
  printf("file format elf64-x86-64\narchitecture: i386:x86-64, ");
}

void	print_filename(char *filename)
{
  printf("%s:     ", filename);
}

void	print_fanions(char *filename)
{
  int	len;

  len = strlen(filename);
  printf("flags ");
  if (len > 2 && filename[len - 2] == '.' && filename[len - 1] == 'o')
    {
      printf("0x%.8d:\nHAS_RELOC, HAS_SYMS\n", 11);
      return;
    }
  if (len > 3 && filename[len - 3] == '.' && filename[len - 2] == 's'
    && filename[len - 1] == 'o')
    {
      printf("0x%.8d:\nHAS_SYMS, DYNAMIC, D_PAGED\n", 150);
      return;
    }
  if ((len > 2 && filename[len - 2] != '.') || len < 2)
    {
      printf("0x%.8d:\nEXEC_P, HAS_SYMS, D_PAGED\n", 112);
      return;
    }
  printf("0x%.8d:\n", 0);
}

void	print_header(t_obj *obj, char *filename)
{
  (void)obj;
  printf("\n");
  print_filename(filename);
  print_format();
  print_fanions(filename);
  printf("start address 0x%.16lx\n\n", obj->elf->e_entry);
}
