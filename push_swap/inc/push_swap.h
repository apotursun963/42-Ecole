/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:51:01 by atursun           #+#    #+#             */
/*   Updated: 2025/01/03 11:51:01 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h>    
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libs/libft/libft.h"
# include "../libs/ft_printf/ft_printf.h"


/*
Tekrar edilecek konular
-----------------------
-Fonksiyon işaretçileri
-"Makefile (program run ve compile time) ve ileri seviye"
-"Compiler" "Flags" ve "Optimizasyon" (-Wall, -Werror, -O2, -g, gdb, valgrind...)
-"Header Dosyalar ("makro", "enum" "struct", "Include guard", "extern", "inline", "Preprocessor")
-Quick Sort ve Stack
-Time Complexity, Space Complexity, Big-O Notation
-Pointer, Pointer to Pointer, Adres Referansı
-Dinamik Bellek tahsisi (malloc, free, ..) ve bunlar hangi bellek alanında tahsis ediliyor
-Bazı bash komutları:
-shuf -i 1-1000 -n 10, find . -type f -name "*.c", tree, history, whereis,
-Bellek Düzeni (memory layout)
-ANSI kodu 
*/


typedef struct s_stack
{
    int              data;
    struct s_stack   *next;
}               t_stack;

// Norma bak
// Bunların varsayılan değerleri olarak 0'dan başlar
typedef enum e_layout
{
    ASCENDING,
    DESCENDING,
}               t_layout;

typedef enum e_action
{
    PUSH_A,
    PUSH_B,
    SWAP_A,
    SWAP_B,
    ROTATE_A,
    ROTATE_B,
    REVERSE_ROTATE_A,
    REVERSE_ROTATE_B,
}               t_action;

void    printnl(t_stack *stack);     // Bunu fonksiyonu push'larken siliceksin

// actions
void    action(t_stack **stack_a, t_stack **stack_b, t_action action_type);
void    push_a(t_stack **stack_b, t_stack **stack_a);
void    push_b(t_stack **stack_a, t_stack **stack_b);
void    rotate_a(t_stack **stack_a);
void    rotate_b(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
void    reverse_rotate_a(t_stack **stack_a);
void    reverse_rotate_b(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);
void    swap_a(t_stack **stack_a);
void    swap_b(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);

// sorting
int     quick_sort_a(t_stack **stack_a, t_stack **stack_b, int len);
int     quick_sort_b(t_stack **stack_a, t_stack **stack_b, int len);
void    sort_under_three_in_a(t_stack **stack_a, t_stack **stack_b, int len);
void    sort_under_three_in_b(t_stack **stack_a, t_stack **stack_b, int len);
void    sort_stack_if_size_3(t_stack **stack_a);

// sorting utils
void    bubble_sort(int *numbers, int size);
int     median(t_stack **stack, int len);

// error funcs
void    error_handling(void);
int     is_digit(char **str);
int     max_limit(char **str);
int     is_twin(char **str);

// utils
long int	ft_atol(const char *str);
int     is_stack_sorted(t_stack *stack_a, t_layout order);
int     stack_size(t_stack *stack);

// free
void        free_args(char **arguments);
void        free_all_stack(t_stack **stack_a, t_stack **stack_b);

// main
char    **parse_args(int argc, char **argv);
void    push_to_stack(t_stack **stack_a, int value);
void    fill_stack(t_stack  **stack_a, char **arguments);

#endif