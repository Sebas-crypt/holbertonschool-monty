#include "monty.h"

/**
 *push - adds to the stack
 *@stack:a pointer to the head of the stack
 *@line_number:data to be stored
 */

void push(m_stack_t **stack, unsigned int line_number)
{
	m_stack_t *new_node;

	new_node = malloc(sizeof(m_stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = line_number;

	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 *pall - print all opcode
 *@stack: array of data to print
 *@line_number: lines in input
 */
void pall(m_stack_t **stack, unsigned int line_number)
{
	m_stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 *pint - prints the value at the top of the stack
 *@stack: pointer to stack
 *@line_number: unused parameter in function
 */
void pint(m_stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - remove item from stack
 * @stack: array of data
 * @line_number: line
 */
void pop(m_stack_t **stack, unsigned int line_number)
{
	m_stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * swap - swap top 2 elements of stack
 * @stack: array of data
 * @line_number: line number
 */

void swap(m_stack_t **stack, unsigned int line_number)
{
	m_stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;

	(*stack)->next = temp->next;
	temp->next = *stack;

	temp->prev = NULL;
	(*stack)->prev = temp;

	*stack = temp;
}
