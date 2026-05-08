#include "../push_swap.h"

int test_stack_B(void)
{
	t_data	*data;
	t_stack	*first_a;
	t_stack	*second_a;
	t_stack	*third_a;
	t_stack	*first_b;
	t_stack	*second_b;
	t_stack	*third_b;
	t_stack *tmp_a;
	t_stack *tmp_b;

	first_a = ft_lstnew(54);
	second_a = ft_lstnew(0);
	third_a = ft_lstnew(-15);
	first_a->next = second_a;
	second_a->next = third_a;
	first_b = ft_lstnew(2048);
	second_b = ft_lstnew(1024);
	third_b = ft_lstnew(-500);
	first_b->next = second_b;
	second_b->next = third_b;
	data = ft_datanew(first_a, first_b);

	printf("Stack A:\n");
	tmp_a = data->a;
	while (tmp_a)
	{
		printf("%d\n", tmp_a->content);
		tmp_a = tmp_a->next;
	}

	printf("\nStack B:\n");
	tmp_b = data->b;
	while (tmp_b)
	{
		printf("%d\n", tmp_b->content);
		tmp_b = tmp_b->next;
	}

	pb(data);
	pb(data);

	printf("\nMAJ stack A:\n");
	tmp_a = data->a;
	while (tmp_a)
	{
		printf("%d\n", tmp_a->content);
		tmp_a = tmp_a->next;
	}
	printf("\nMAJ stack B:\n");
	tmp_b = data->b;
	while (tmp_b)
	{
		printf("%d\n", tmp_b->content);
		tmp_b = tmp_b->next;
	}
	return (0);
}
