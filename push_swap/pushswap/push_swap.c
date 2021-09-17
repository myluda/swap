/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:36:29 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/07/06 10:36:31 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct t_node
{
	int				value;
	struct t_node	*next;
}				t_node;

void ft_swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

t_node *bubblesort(t_node *stack, int n)
{
   int i;
   int j;
   int *tab;
	t_node	*tmp;
	t_node *ret;

	ret = stack;
   i = 0;
   tmp = stack;
	tab = malloc(sizeof(int) * n);
	while(stack)
	{
		tab[i] = stack->value;
		stack = stack->next;
		i++;
	}
    for (i = 0; i < n-1; i++)      
       for (j = 0; j < n-i-1; j++) 
           if (tab[j] > tab[j+1])
              ft_swap(&tab[j], &tab[j+1]);

	i = 0;
	while (tmp)
	{
		i = -1;
		while (++i < n)
		{
			if (tmp->value == tab[i])
			{
				tmp->value = i;
				printf("DBG : [%d]\n", tmp->value);
				tmp = tmp->next;
				break;
			}
		}
	}
	free(tab);
	return ret;
}
  
void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		write(1,&str[i],1);
		i++;
	}
}
t_node	*swap_a(t_node *stack)
{
	t_node *tmp;
	int		value;

	value = stack->value;
	stack->value = stack->next->value;
	stack->next->value = value;
	return(stack);
}
t_node	*swap_b(t_node *stack)
{
	t_node *tmp;
	int		value;

	value = stack->value;
	stack->value = stack->next->value;
	stack->next->value = value;
	return(stack);
}

t_node	*rotate_reverse_a(t_node *stack, int indicate)
{
	t_node *tmp;
	t_node *befinal;

	int		i;

	i = 0;
	tmp = stack;
	while(stack->next)
	{
		stack = stack->next;
		i++;
		if (i == indicate - 2)
		{
			befinal = stack;
		}
		
	}
	befinal->next = NULL;
	stack->next = tmp;
	return stack;
}
void	a_is_sorted(t_node *stack)
{
	while(stack->next && stack->value < stack->next->value)
	{
		stack = stack->next;
		if(stack->next == NULL)
			ft_putstr("the list is sorted");
	}
}
t_node	*rotate_reverse_b(t_node *stack, int indicate)
{
	t_node *tmp;
	t_node *befinal;

	int		i;

	i = 0;
	tmp = stack;
	while(stack->next)
	{
		stack = stack->next;
		i++;
		if (i == indicate - 2)
		{
			befinal = stack;
		}
		
	}
	befinal->next = NULL;
	stack->next = tmp;
	return stack;
}

void	push_b(t_node **stack_a , t_node **stack_b)
{
	t_node *tmp;
	t_node *tmp1;

	tmp1 = *stack_b;
	tmp = *stack_a;
	tmp->next = *stack_b;
	*stack_b = tmp1->next;
}

void	push_a(t_node **stack_b , t_node **stack_a)
{
	t_node *tmp;
	t_node *tmp1;

	tmp1 = *stack_b;
	tmp = *stack_a;
	tmp->next = *stack_b;
	*stack_b = tmp1->next;
}

t_node	*rotate_a(t_node *stack)
{
	t_node *tmp;
	t_node *head;

	head = stack->next;
	tmp = stack;
	while(stack->next)
		stack = stack->next;
	stack->next = tmp;
	tmp->next = NULL;
	return head;
}
t_node  *fillstack(char **array, int size)
{
    t_node *stack;
    t_node *tmp;
    int i;

    i = 1;
    if (size < 0)
        return (NULL);
    stack = (t_node *)malloc(sizeof(t_node) * 1);
    tmp = stack;
    if (!stack)
        return (NULL);
    stack->value = atoi(array[i++]);
    stack->next = NULL;
    while (i <= size)
    {
        stack->next = (t_node *)malloc(sizeof(t_node) * 1);
        stack->next->value = atoi(array[i++]);
        stack->next->next = NULL;
        stack = stack->next;
    }
    return (tmp);
}
// void	sort_small_stack()
// void	sort_big_stack();
int main(int argc , char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	stack_a = malloc(sizeof(t_node));
	stack_a = fillstack(argv, argc - 1);
	//stack_b = fillstack(argv, argc - 1);
	a_is_sorted(stack_a);
	//bubblesort(stack_a,argc - 1);
	//stack_a = rotate_a(stack_a);
//	stack_a = rotate_reverse_a(stack_a,argc - 1);
//	stack_b = rotate_reverse_a(stack_b,argc - 1);
	//push_a(&stack_a,&stack_b);
	stack_a = bubblesort(stack_a,argc - 1);
	while(stack_a)
	{
		printf("\na = |%d|\n",stack_a->value);
		stack_a = stack_a->next;
	}
	// while(stack_b)
	// {
	// 	printf("b = |%d|\n",stack_b->value);
	// 	stack_b = stack_b->next;
	// }
}