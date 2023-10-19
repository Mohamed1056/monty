#include "monty.h"

/**
 * monty_add - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current line number
*/
void monty_add(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_num);
}

/**
 * monty_sub - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current line number
*/
void monty_sub(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_num);
}

/**
 * monty_div - function to devide the second value
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number
*/
void monty_div(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "div"));
		return;
	}
	/*checking the code*/
	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_num));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_num);
}

/**
 * monty_mul - function to maltiply the value
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current line number
*/
void monty_mul(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_num);
}

/**
 * monty_mod - Functon to compute the modulus
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current line number
*/
void monty_mod(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "mod"));
		return;
	}
	/*checking the condition again*/
	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_num));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_num);
}
