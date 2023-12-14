#include "monty.h"

void rotl(stack_t **stack, unsigned int top) {
    if (top >= 1) {
        int temp = (*stack)[top].n;
	int i;
        for (i = 1; i <= top; ++i) {
            (*stack)[i].n = (*stack)[i - 1].n;
        }
        (*stack)[0].n = temp;
    }
}
