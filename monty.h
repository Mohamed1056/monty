#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void opn_f(char *f_name);
int prs_line(char *buffer, int line_number, int format);
void read_f(FILE *);
int len_chars(FILE *);
void gt_func(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void free_nodes(void);
void prnt_stack(stack_t **, unsigned int);
void instack(stack_t **, unsigned int);
void inqueue(stack_t **, unsigned int);

void fun_call(op_func, char *, char *, int, int);

void prnt_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nod(stack_t **, unsigned int);

/*Math operations with nodes*/
void add_nod(stack_t **, unsigned int);
void sub_nod(stack_t **, unsigned int);
void div_nod(stack_t **, unsigned int);
void mul_nod(stack_t **, unsigned int);
void mod_nod(stack_t **, unsigned int);

/*String operations*/
void prnt_char(stack_t **, unsigned int);
void prnt_str(stack_t **, unsigned int);
void rotateleft(stack_t **, unsigned int);

/*Error hanlding*/
void errors(int code, ...);
void more_errors(int code, ...);
void str_errors(int code, ...);
void rotateright(stack_t **, unsigned int);

#endif
