#include "monty.h"

/**
 * set_op_tok_error - Sets last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void set_op_tok_error(int error_code)
{
	int tokt_len = 0, i = 0;
	char *exit_this_str = NULL;
	char **new_tokt = NULL;
	/*after decleration*/
	tokt_len = tok_arr_len();
	new_tokt = malloc(sizeof(char *) * (tokt_len + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	while (i < tokt_len)
	{
		new_tokt[i] = op_toks[i];
		i++;
	}
	exit_this_str = get_int(error_code);
	if (!exit_this_str)
	{
		free(new_tokt);
		malloc_error();
		return;
	}
	new_tokt[i++] = exit_this_str;
	new_tokt[i] = NULL;
	free(op_toks);
	op_toks = new_tokt;
}
