#include "monty.h"

/**
 * opn_f - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void opn_f(char *f_name)
{
	FILE *fd = fopen(f_name, "r");

	if (f_name == NULL || fd == NULL)
		errors(2, f_name);

	read_f(fd);
	fclose(fd);
}


/**
 * read_f - reads a file
 * @fd: pointer to descriptor
 * Return: void
 */

void read_f(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = prs_line(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * prs_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int prs_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		errors(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	gt_func(opcode, value, line_number, format);
	return (format);
}

/**
 * gt_func - find the appropriate function
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void gt_func(char *opcode, char *value, int ln, int format)
{
	int j;
	int flg;

	instruction_t funcs_lst[] = {
		{"push", instack},
		{"pall", prnt_stack},
		{"pint", prnt_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nod},
		{"add", add_nod},
		{"sub", sub_nod},
		{"div", div_nod},
		{"mul", mul_nod},
		{"mod", mod_nod},
		{"pchar", prnt_char},
		{"pstr", prnt_str},
		{"rotl", rotateleft},
		{"rotr", rotateright},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flg = 1, j = 0; funcs_lst[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, funcs_lst[j].opcode) == 0)
		{
			fun_call(funcs_lst[j].f, opcode, value, ln, format);
			flg = 0;
		}
	}
	if (flg == 1)
		errors(3, ln, opcode);
}


/**
 * fun_call - Calls the required function.
 * @func: Pointer to the function that going to called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void fun_call(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flg;
	int j;

	flg = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flg = -1;
		}
		if (val == NULL)
			errors(5, ln);
		for (j = 0; val[j] != '\0'; j++)
		{
			if (isdigit(val[j]) == 0)
				errors(5, ln);
		}
		node = create_node(atoi(val) * flg);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			inqueue(&node, ln);
	}
	else
		func(&head, ln);
}
