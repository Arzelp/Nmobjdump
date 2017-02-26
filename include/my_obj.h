/*
** my_obj.h for my_obk in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/include/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Wed Feb 22 15:45:27 2017 Paskal Arzel
** Last update Sun Feb 26 16:44:20 2017 Paskal Arzel
*/

#ifndef OBJDUMP_H__
#define OBJDUMP_H__

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <elf.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE_HEXA 16
#define ARCH_NAME_MAXSIZE 16
#define ARCH_TRASH 32
#define ARCH_SIZE 10
#define ARCH_END 2

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

typedef struct s_print
{
  int					pos;
  int					len;
}t_print;

typedef struct s_obj
{
  bool					multi;
  bool					o;
  int						i;
  int						ac;
  int					  pos;
  int						size_print;
  char					*start_data;
  char					*data;
  char					*sct_names;
  t_arch_header	*arch_header;
  t_print				print;
  Elf64_Ehdr		*elf;
  Elf64_Shdr		*shdr;
  Elf64_Phdr		*phdr;
  Elf64_Ehdr		*testelf;
  Elf32_Ehdr		*elf32;
  Elf32_Shdr		*shdr32;
  Elf32_Phdr		*phdr32;
  int						fd;
  int						fsize;
  t_longname		*lgnm;
  int						(*calc_size_print)(int, int);
  int						(*filesize)(int);
  void					(*print_header)(struct s_obj *, char *);
  void					(*print_header32)(struct s_obj *, char *);
  void					(*print_sh_name)(struct s_obj *);
  void					(*print_sh_name32)(struct s_obj *);
  void					(*print_obj_data)(struct s_obj *);
  void					(*print_obj_data32)(struct s_obj *);
  void					(*print_name)(struct s_obj *, int);
  void					(*print_name32)(struct s_obj *, int);
  void					(*print_data)(struct s_obj *, int);
  void					(*print_data32)(struct s_obj *, int);
  void					(*print_line)(struct s_obj *, int, int);
  void					(*print_line32)(struct s_obj *, int, int);
  void					(*print_char)(struct s_obj *, int, int);
  void					(*print_char_hexa)(struct s_obj *, int, int);
  void					(*print_nb)(struct s_obj *, int);
  void					(*print_char32)(struct s_obj *, int, int);
  void					(*print_char_hexa32)(struct s_obj *, int, int);
  void					(*print_nb32)(struct s_obj *, int);
}t_obj;

void	set_obj_fct(t_obj *obj);
void	print_sh_name(t_obj *obj);
void	print_sh_name32(t_obj *obj);
void	print_obj_data(t_obj *obj);
void	print_obj_data32(t_obj *obj);
void	print_name(t_obj *obj, int i);
void	print_name32(t_obj *obj, int i);
void	print_data(t_obj *obj, int i);
void	print_data32(t_obj *obj, int i);
void	print_line(t_obj *obj, int j, int x);
void	print_line32(t_obj *obj, int j, int x);
void	print_char(t_obj *obj, int i, int x);
void	print_char32(t_obj *obj, int i, int x);
void	print_char_hexa(t_obj *obj, int i, int x);
void	print_char_hexa32(t_obj *obj, int i, int x);
void	print_nb(t_obj *obj, int j);
void	print_nb32(t_obj *obj, int j);
int		init_obj(t_obj *obj);
int		init_obj32(t_obj *obj);
int		calc_size_print(int pos, int len);
void	print_header(t_obj *obj, char *filename);
void	print_header32(t_obj *obj, char *filename);

#endif
