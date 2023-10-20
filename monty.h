#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define QUEUE 1
#define STACK 0
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks = NULL;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*interpration functions*/
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
int run_monty(FILE *script_fd);
void free_stack(stack_t **stack);
void free_tokens(void);
unsigned int tok_arr_len(void);
void set_op_tok_error(int error_code);

/*opcode funs*/
void monty_pall(stack_t **stack, unsigned int line_num);
void monty_pint(stack_t **stack, unsigned int line_num);
void monty_pop(stack_t **stack, unsigned int line_num);
void monty_swap(stack_t **stack, unsigned int line_num);
void monty_push(stack_t **stack, unsigned int line_num);
void monty_add(stack_t **stack, unsigned int line_num);
void monty_nop(stack_t **stack, unsigned int line_num);
void monty_sub(stack_t **stack, unsigned int line_num);
void monty_div(stack_t **stack, unsigned int line_num);
void monty_rotr(stack_t **stack, unsigned int line_num);
void monty_mul(stack_t **stack, unsigned int line_num);
void monty_mod(stack_t **stack, unsigned int line_num);
void monty_pchar(stack_t **stack, unsigned int line_num);
void monty_pstr(stack_t **stack, unsigned int line_num);
void monty_rotl(stack_t **stack, unsigned int line_num);
void monty_stack(stack_t **stack, unsigned int line_num);
void monty_queue(stack_t **stack, unsigned int line_num);

/*Standard library functions */
char *get_int(int n);
char **str_tow(char *str, char *delims);

/* Function for error messages & error code*/
int usage_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int malloc_error(void);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int pchar_error(unsigned int line_number, char *message);

#endif
