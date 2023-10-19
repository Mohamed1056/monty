#include "monty.h"

/**
 * monty_rotl - Function to rotate the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void monty_rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *top_end, *bottom_end;
	/*after the decleration of variables*/
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top_end = (*stack)->next;
	bottom_end = (*stack)->next;
	while (bottom_end->next != NULL)
		bottom_end = bottom_end->next;

	top_end->next->prev = *stack;
	(*stack)->next = top_end->next;
	bottom_end->next = top_end;
	top_end->next = NULL;
	top_end->prev = bottom_end;

	(void)line_num;
}

/**
 * monty_rotr - Function to rotates the bottom value
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current line number of a file.
 */
void monty_rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *top_end, *bottom_end;
	/*after decleration*/
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top_end = (*stack)->next;
	bottom_end = (*stack)->next;
	while (bottom_end->next != NULL)
		bottom_end = bottom_end->next;

	bottom_end->prev->next = NULL;
	(*stack)->next = bottom_end;
	bottom_end->prev = *stack;
	bottom_end->next = top_end;
	top_end->prev = bottom_end;

	(void)line_num;
}

/**
 * monty_stack - Function to convert a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current line number of a file.
 */
void monty_stack(stack_t **stack, unsigned int line_num)
{
	(*stack)->n = STACK;
	(void)line_num;
}

/**
 * monty_queue - Function to converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current line number of a file.
 */
void monty_queue(stack_t **stack, unsigned int line_num)
{
	(*stack)->n = QUEUE;
	(void)line_num;
}
