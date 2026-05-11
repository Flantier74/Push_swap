#include "utils_test.h"

int test_calc_disorder(void)
{
	t_data  *data = malloc(sizeof(t_data));
	t_stack *empty = init_stack(0, 0, 0, 0, 0, 0);
	t_stack *testa = init_stack(1, 2, 3, 4, 5, 6);
	t_stack *testb = init_stack(9, 8, 7, 6, 5, 4);
	t_stack *testc = init_stack(0, -1, 1, 7, 2, 4);

	data->a = testa;
	data->b = empty;
	printer(data);
	printf("%f\n\n", calc_disorder(testa));

	data->a = testb;
	printer(data);
	printf("%f\n\n", calc_disorder(testb));

	data->a = testc;
	printer(data);
	printf("%f\n\n", calc_disorder(testc));

	return (0);
}
