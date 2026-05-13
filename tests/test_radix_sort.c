#include "utils_test.h"

int test_radix_sort(void)
{
	t_data  *data = malloc(sizeof(t_data));
	t_stack *stack_a = init_stack(20, 79, -50, 0, 1, -1);
	t_stack *stack_b = NULL;
	data->a = stack_a;
	data->b = stack_b;
	int ops;

	printf("### TEST radix_sort() #################################\n");

printer(data);
	ops = radix_sort(data);
	ra(data);
	printf("\n");
	printer(data);
	printf("-----------> OPS = %d\n", ops);

	return (0);
}
