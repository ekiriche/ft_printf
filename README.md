# ft_printf
The versatility of the printf function in C represents a great exercise in programming for
us. This project is of moderate difficulty. It will enable you to discover variadic functions
in C in a particularly relevant context as well as learn about a great example of a basic
“dispatcher” in C via the use of an array of function’s pointers.

## Allowed functions
1. `write`
2. `setlocale`
3. `malloc`
4. `free`
5. `exit`
6. The functions of `man 3 stdarg`

## Mandatory part
1. You have to recode the libc’s printf function.
2. Your function will be called ft_printf and will be prototyped similarly to printf.
3. You won’t do the buffer management in the printf function.
4. You have to manage the following conversions: sSpdDioOuUxXcC
5. You must manage %%
6. You must manage the flags #0-+ and space
7. You must manage the minimum field-width
8. You must manage the precision
9. You must manage the flags hh, h, l, ll, j, et z.

## Usage
1. `make && make clean`
2. Include libftprintf.a to your main file.
