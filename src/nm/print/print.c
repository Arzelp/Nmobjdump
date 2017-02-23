/*
** print.c for print in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/nm/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Feb 16 16:09:41 2017 Paskal Arzel
** Last update Thu Feb 23 15:49:23 2017 Paskal Arzel
*/

#include <stdio.h>
#include "my_nm.h"

static char print_type_more(Elf64_Sym sym, Elf64_Shdr *shdr, char c)
{
  if (sym.st_shndx == SHN_UNDEF)
    c = 'U';
  else if (sym.st_shndx == SHN_ABS)
    c = 'A';
  else if (sym.st_shndx == SHN_COMMON)
    c = 'C';
  else if (shdr[sym.st_shndx].sh_type == SHT_NOBITS
       && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
    c = 'B';
  else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
       && shdr[sym.st_shndx].sh_flags == SHF_ALLOC)
    c = 'R';
  else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
       && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
    c = 'D';
  else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
       && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
    c = 'T';
  else if (shdr[sym.st_shndx].sh_type == SHT_DYNAMIC)
    c = 'D';
  else
    c = 'T';
  return (c);
}

static char	print_type(Elf64_Sym sym, Elf64_Shdr *shdr)
{
  char  c;

  c = '!';
  if (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE)
    c = 'u';
  else if (ELF64_ST_BIND(sym.st_info) == STB_WEAK)
    {
      c = 'W';
      if (sym.st_shndx == SHN_UNDEF)
        c = 'w';
    }
  else if (ELF64_ST_BIND(sym.st_info) == STB_WEAK
  && ELF64_ST_TYPE(sym.st_info) == STT_OBJECT)
    {
      c = 'V';
      if (sym.st_shndx == SHN_UNDEF)
        c = 'v';
    }
  else
    c = print_type_more(sym, shdr, c);
  if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL && c != '?')
    c += 32;
  return (c);
}

void	print_sh_name(t_nm *nm)
{
  int		i;

  i = 0;
  while (i < nm->elf->e_shnum)
    {
    	printf("%d: %s\n", i, &nm->sct_names[nm->shdr[i].sh_name]);
      i++;
    }
}

void	print_sym_name(t_nm *nm)
{
  int		i;
  char	c;

  i = 0;
  nm->sort_sym_tab(nm, nm->sym.sym_nb);
  while (i < nm->sym.sym_nb)
  {
    if (strcmp(&nm->sym.sym_names[nm->sym.symtab[i].st_name], "") != 0)
    {
      c = print_type(nm->sym.symtab[i], nm->shdr);
      if (c != 'a')
      {
        if (nm->sym.symtab[i].st_value == 0 && c != 'T' && c != 't')
      		printf("                ");
        else
          printf("%016lx", nm->sym.symtab[i].st_value);
        printf(" %c ", c);
        printf("%s\n", &nm->sym.sym_names[nm->sym.symtab[i].st_name]);
      }
    }
    i++;
  }
}
