#include "monty.h"

/**
 * monty_push - Pushes a value to a stack_t linked list.
 * @stack: takes the innput for the function
 * @line_num: The current line number
 */
void monty_push(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp_n, *new_node;
	int x;
	/*after decleration of the variables*/
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_num));
		return;
	}

	for (x = 0; op_toks[1][x]; x++)
	{
		if (op_toks[1][x] == '-' && x == 0)
			continue;
		if (op_toks[1][x] < '0' || op_toks[1][x] > '9')
		{
			set_op_tok_error(no_int_error(line_num));
			return;
		}
	}
	new_node->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK)
	{
		tmp_n = (*stack)->next;
		new_node->prev = *stack;
		new_node->next = tmp_n;
		if (tmp_n)
			tmp_n->prev = new_node;
		(*stack)->next = new_node;
	}
	else
	{
		tmp_n = *stack;
		while (tmp_n->next)
			tmp_n = tmp_n->next;
		new_node->prev = tmp_n;
		new_node->next = NULL;
		tmp_n->next = new_node;
	}
}

/**
 * monty_pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void monty_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp_node = (*stack)->next;

	while (tmp_node)
	{
		printf("%d\n", tmp_node->n);
		tmp_node = tmp_node->next;
	}
	(void)line_num;
}

/**
 * monty_pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void monty_pint(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_num));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * monty_pop - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void monty_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *next_ptr = NULL;
	/*after decleration of the variables*/
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_num));
		return;
	}

	next_ptr = (*stack)->next->next;
	free((*stack)->next);
	if (next_ptr)
		next_ptr->prev = *stack;
	(*stack)->next = next_ptr;
}

/**
 * monty_swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: the line number
 */
void monty_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp_ptr;
	/*after decleration*/
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "swap"));
		return;
	}

	tmp_ptr = (*stack)->next->next;
	(*stack)->next->next = tmp_ptr->next;
	(*stack)->next->prev = tmp_ptr;
	if (tmp_ptr->next)
		tmp_ptr->next->prev = (*stack)->next;
	tmp_ptr->next = (*stack)->next;
	tmp_ptr->prev = *stack;
	(*stack)->next = tmp_ptr;
}
