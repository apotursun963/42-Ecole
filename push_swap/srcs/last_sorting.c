

# include "../inc/push_swap.h"

int    find_min_value_pos(t_stack *node)
{
    int min_val;
    int min_pos;
    int pos;

    pos = 0;
    min_pos = 0;
    min_val = node->data;
    while (node)
    {   
        if (node->data < min_val)
        {
            min_val = node->data;
            min_pos = pos;
        }
        node = node->next;
        pos++;
    }
    return (min_pos);
}

void    rotate_min_pos_to_head(t_stack **stack_a, int min_pos)
{
    int size;

    if (min_pos == 0)
        return ;
    size = stack_size(*stack_a);
    if (min_pos <= size / 2)
    {
        while (min_pos-- > 0)
            rotate_a(stack_a);
    }
    else
    {
        min_pos = size - min_pos;
        while (min_pos-- > 0)
            reverse_rotate_a(stack_a);
    }
}

void    transfer_all_from_b_to_a(t_stack **stack_a, t_stack **stack_b, int *pushed)
{
    while (*pushed > 0)
    {
        push_a(stack_b, stack_a);
        (*pushed)--;
    }
}

void last_sort(t_stack **stack_a, t_stack **stack_b)
{
    int min_pos;
    int pushed;
    int size;

    pushed = 0;
    size = stack_size(*stack_a);
    while (size-- > 0)
    {
        if (size == 2 && (*stack_a)->data > (*stack_a)->next->data)
            swap_a(stack_a);
        else if (size == 3)
            sort_stack_if_size_3(stack_a);
        if (is_stack_sorted(*stack_a, 0))
            break;
        min_pos = find_min_value_pos(*stack_a);
        rotate_min_pos_to_head(stack_a, min_pos);
        push_b(stack_a, stack_b);
        pushed++;
    }
    transfer_all_from_b_to_a(stack_a, stack_b, &pushed);
}