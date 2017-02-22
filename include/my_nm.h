/*
** nm.h for nm in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/include/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Feb 16 15:14:17 2017 Paskal Arzel
** Last update Wed Feb 22 14:39:02 2017 Paskal Arzel
*/

#ifndef NM_H__
#define NM_H__

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <elf.h>
#include <stdio.h>
#include <string.h>

#define ARCH_NAME_MAXSIZE 16
#define ARCH_TRASH 32
#define ARCH_SIZE 10
#define ARCH_END 2

typedef struct s_sym
{
  char					*sym_names;
  Elf64_Shdr		*symshdr;
  Elf64_Shdr		*strtab;
  Elf64_Sym			*symtb;
  Elf64_Sym			*symtab;
  int						sym_nb;
}t_sym;

typedef struct s_arch_header
{
  char					name[ARCH_NAME_MAXSIZE];
  char					trash[ARCH_TRASH];
  char					size[ARCH_SIZE];
  char					end[ARCH_END];
}t_arch_header;

typedef struct s_longname
{
  char				*start_longname;
  int					size;
}t_longname;

typedef struct s_nm
{
  bool					multi;
  int						i;
  int						ac;
  int					  pos;
  char					*start_data;
  char					*data;
  char					*sct_names;
  t_arch_header	*arch_header;
  Elf64_Ehdr		*elf;
  Elf64_Shdr		*shdr;
  Elf64_Phdr		*phdr;
  int						fd;
  int						fsize;
  t_sym					sym;
  t_longname		*lgnm;
  int						(*filesize)(int);
  int						(*init_longname)(struct s_nm *);
  int						(*find_sym_idxs)(struct s_nm *);
  int						(*get_sym_nb)(struct s_nm *);
  int						(*nm_arch)(struct s_nm *, char *);
  void					(*print_sh_name)(struct s_nm *);
  void					(*print_file_name)(struct s_nm *);
  void					(*print_sym_name)(struct s_nm *);
  void					(*sort_sym_tab)(struct s_nm *, int);
}t_nm;

int		init_nm(t_nm *nm);
void	print_sh_name(t_nm *nm);
void	print_sym_name(t_nm *nm);
int		set_base(t_nm *nm);
void	print_file_name(t_nm *nm);
int		find_sym_idxs(t_nm *nm);
int		get_sym_nb(t_nm *nm);
void	set_nm_fct(t_nm *nm);
int		init_longname(t_nm *nm);
void	sort_sym_tab(t_nm *nm, int nb);
int		nm_arch(t_nm *nm, char *filename);

#endif
