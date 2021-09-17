#include <unistd.h>
#include <stdlib.h>

typedef struct t_node
{
	int				value;
	struct t_node	*next;
}				t_node;

t_node  *fillstack(int *array, int size)
{
    t_node *stack;
    t_node *tmp;
    int i;

    i = 0;
    if (size < 0)
        return (NULL);
    stack = (t_node *)malloc(sizeof(t_node) * 1);
    tmp = stack;
    if (!stack)
        return (NULL);
    stack->value = array[i++];
    stack->next = NULL;
    while (i < size)
    {
        stack->next = (t_node *)malloc(sizeof(t_node) * 1);
        stack->next->value = array[i++];
        stack->next->next = NULL;
        stack = stack->next;
    }
    return (tmp);
}
int main(void)
{
    int array[7] = {1, 2, 3, 4, 5, 6, 7};
    t_node *stack;
    int i;

    i = 0;
    stack = fillstack((int *)array, 7);
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    return  (0);
}