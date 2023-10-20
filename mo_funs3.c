#include "monty.h"

/**
 * monty_nop - Does nothing
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The line number
 */
void monty_nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

/**
 * monty_pchar - Prints the character in the top value
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current line number file.
 */
void monty_pchar(stack_t **stack, unsigned int line_num)
{
	/*checking the values*/
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_num, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_num,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current line number of a file.
 */
void monty_pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp_node = (*stack)->next;
	/*after decleration of variables*/
	while (tmp_node && tmp_node->n != 0 && (tmp_node->n > 0
				&& tmp_node->n <= 127))
	{
		printf("%c", tmp_node->n);
		tmp_node = tmp_node->next;
	}

	printf("\n");

	(void)line_num;
}
