#include "../push_swap.h"

int	test_stack_A(void)
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

	first_a = ft_lstnew(0);
	second_a = ft_lstnew(1);
	third_a = ft_lstnew(2);
	first_a->next = second_a;
	second_a->next = third_a;
	first_b = ft_lstnew(100);
	second_b = ft_lstnew(101);
	third_b = ft_lstnew(102);
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

	printf("\nTests sb : swaps two first elem of stack b \n");
	sb(data);
	printf("MAJ stack A:\n");
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
	sb(data);

	printf("\nTests pb : push first a vers b \n");
	pb(data);
	printf("MAJ stack A:\n");
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
	pa(data);


	printf("\nTests rb : first became last \n");
	rb(data);
	printf("MAJ stack A:\n");
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
	rrb(data);

	printf("Tests rrb : last became first \n");
	rrb(data);
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
	rb(data);
	return (0);
}
