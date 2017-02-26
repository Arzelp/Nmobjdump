/*
** print_header32.c for print_header23 in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/objdump/print/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Feb 26 16:11:42 2017 Paskal Arzel
** Last update Sun Feb 26 16:25:44 2017 Paskal Arzel
*/

#include "my_obj.h"

static void	print_format32(void)
{
  printf("file format elf32-i386\narchitecture: i386, ");
}

static void	print_filename32(char *filename)
{
  printf("%s:     ", filename);
}

static void	print_fanions32(char *filename)
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

void	print_header32(t_obj *obj, char *filename)
{
  (void)obj;
  printf("\n");
  print_filename32(filename);
  print_format32();
  print_fanions32(filename);
  printf("start address 0x%.16lx\n\n", obj->elf->e_entry);
}
