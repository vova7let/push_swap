/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:02:47 by vshapran          #+#    #+#             */
/*   Updated: 2017/03/24 19:09:29 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_stack
{
	int	*a;
	int a_size;
	int flag;
	int flag2;
}				t_stack;
void			cmds_optimizer(char *str, int flag);
void			print_zvezda_zvezda(char ***tmp, int i, int flag);
void			cmds_optimizer_h1(char **tmp, int i, int k, int *optimize);
void			cmds_optimizer_h2(char **tmp, int i, int k, int *optimize);
void			cmds_optimizer_h3(char **tmp, int i, int k, int *optimize);
void			cmds_optimizer_h4(char **tmp, int i, int k, int *optimize);
void			cmds_optimizer_h5(char **tmp, int i, int k, int *optimize);
void			cmds_optimizer_h6(char **tmp, int i, int k, int *optimize);
void			cmds_optimizer_h7(char **tmp, int i, int k, int *optimize);
void			cmds_optimizer_h8(char **tmp, int i, int k, int *optimize);
void			cmds_optimizer_h9(char **tmp, int i, int k, int *optimize);
void			print_stack_a(t_stack *a);
void			print_stack_b(t_stack *a);
void			swap_a(t_stack *a, t_stack *b, char **commands);
void			swap_b(t_stack *a, t_stack *b, char **commands);
int				sorted_a(t_stack *a, int n);
int				sorted_b(t_stack *a, int n);
void			push_a(t_stack *a, t_stack *b, char **commands);
void			push_b(t_stack *a, t_stack *b, char **commands);
void			rotate_a(t_stack *a, t_stack *b, char **commands);
void			rotate_b(t_stack *a, t_stack *b, char **commands);
void			rev_rotate_a(t_stack *a, t_stack *b, char **commands);
void			rev_rotate_b(t_stack *a, t_stack *b, char **commands);
void			new_stack(t_stack **a, t_stack **b, char **av, int ac);
void			mediana_h1(int **bolshe, int **menshe, t_stack *a, int n);
int				mediana(t_stack *a, int n);
int				mediana_b(t_stack *a, int n);
int				sort_3b_h1(t_stack *b, t_stack *a, int n, char **commands);
void			sort_3b_h2(t_stack *b, t_stack *a, char **commands);
void			sort_3b_h3(t_stack *b, t_stack *a, char **commands);
void			sort_3b_h4(t_stack *b, t_stack *a, char **commands);
void			sort_3b_h5(t_stack *b, t_stack *a, char **commands);
void			sort_3b_h6(t_stack *b, t_stack *a, char **commands);
void			sort_3b_h7(t_stack *b, t_stack *a, char **commands);
void			sort_3b_h8(t_stack *b, t_stack *a, char **commands);
void			sort_3b(t_stack *b, t_stack *a, int n, char **commands);
void			sort_3a_h1(t_stack *b, t_stack *a, char **commands);
void			sort_3a_h2(t_stack *b, t_stack *a, char **commands);
void			sort_3a_h3(t_stack *b, t_stack *a, char **commands);
void			sort_3a_h4(t_stack *b, t_stack *a, char **commands);
void			sort_3a_h5(t_stack *b, t_stack *a, char **commands);
void			sort_3a(t_stack *b, t_stack*a, int n, char **commands);
void			in_two_from_a_to_b_h1(t_stack *a, t_stack *b, int **aa,
		char **commands);
void			in_two_from_a_to_b_h2(t_stack *a, int **aa, int n);
int				in_two_from_a_to_b(t_stack *a, t_stack *b, int n,
		char **commands);
void			in_two_from_b_to_a_h2(t_stack *a, int **aa, int n);
void			in_two_from_b_to_a_h1(t_stack *a, t_stack *b, int **aa,
		char **commands);
int				in_two_from_b_to_a(t_stack *a, t_stack *b, int n,
		char **commands);
int				in_two_from_a_to_b_rev(t_stack *a, t_stack *b, int n,
		char **commands);
int				in_two_from_b_to_a_rev(t_stack *a, t_stack *b, int n,
		char **commands);
void			sort_a(t_stack *a, t_stack *b, int n, char **commands);
void			sort_b(t_stack *a, t_stack *b, int n, char **commands);
void			sort_a_rev(t_stack *a, t_stack *b, int n, char **commands);
void			sort_b_rev(t_stack *a, t_stack *b, int n, char **commands);
int				check(t_stack *a);
char			*main_sort1(int ac, char **av, int *flag);
void			swap_a1(t_stack *a);
void			swap_b1(t_stack *a);
void			swap_ab1(t_stack *a, t_stack *b);
int				sorted_a1(t_stack *a);
void			push_a1(t_stack *a, t_stack *b);
void			push_b1(t_stack *a, t_stack *b);
void			rotate_a1(t_stack *a);
void			rotate_b1(t_stack *a);
void			rotate_ab1(t_stack *a, t_stack *b);
void			rev_rotate_a1(t_stack *a);
void			rev_rotate_b1(t_stack *a);
void			check_h1(t_stack *a, t_stack *b, char *line);
void			check_comm(char *line);
void			rev_rotate_ab1(t_stack *a, t_stack *b);

#endif
