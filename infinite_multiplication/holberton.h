#ifndef HOLBERTON_H
#define HOLBERTON_H

/* 
 * File: holberton.h
 * Auth: (Your Name Here)
 * Desc: Header file containing function prototypes 
 *       for infinite multiplication project.
 */

/* Prototypes */
int _putchar(char c);
int main(int argc, char *argv[]);
int is_digit(char *str);
void print_error_and_exit(void);
void multiply(char *num1, char *num2); /* If you decide to have a separate multiply function */
void print_number(int *product, int size);

#endif /* HOLBERTON_H */
