/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ourFunctions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:15:43 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/30 15:15:53 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int		check_double(int **working_array, int pos, int num, int size);
int		get_gridnum(int *num);
int		check_row_left(int **working_array, int pos, int *entry, int size);
int		check_col_down(int **working_array, int pos, int *entry, int size);
int		check_row_right(int **working_array, int pos, int *entry, int size);
int		check_col_up(int **working_array, int pos, int *entry, int size);
int		check_case(int **working_array, int pos, int *entry, int size);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		check(char *str, int c);
int		solve(int **working_array, int *entry, int pos, int size);

void	*stoi(char *str, int *view);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	display_solution(int **working_array, int size);
void	freegrid(int **grid);
