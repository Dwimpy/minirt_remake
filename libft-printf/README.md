libft and ft\_printf - 42 Projects
====================================
This project is a recreation of the standard `stdlib` library in C, with implementations for commonly used functions
such as string manipulation, memory management, and linked lists. All of the functions are prefixed with `ft_`.

## How to compile:

```bash
git clone https://github.com/Dwimpy/libft-printf
make
```

Functions
---------

### String Manipulation

* <code>[ft_strncmp](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_strncmp.c)</code> - compares two
  strings up to `n` characters.
* <code>[ft_strchr](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_strchr.c)</code> - finds the first
  occurrence of a character in a string.
* <code>[ft_strrchr](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_strrchr.c)</code> - finds the
  last occurrence of a character in a string.
* <code>[ft_strnstr](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_strnstr.c)</code> - finds the
  first occurrence of a substring in a string, up to `len` characters.
* <code>[ft_strdup](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_strdup.c)</code> - duplicates a
  string.
* <code>[ft_substr](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_substr.c)</code> - returns a
  substring from a string.
* <code>[ft_strjoin](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_strjoin.c)</code> - concatenates
  two strings.
* <code>[ft_strtrim](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_strtrim.c)</code> - removes
  leading and trailing whitespace characters from a string.
* <code>[ft_split](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_split.c)</code> - splits a string
  into an array of substrings based on a delimiter character.
* <code>[ft_itoa](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_itoa.c)</code> - converts an integer
  to a string.
* <code>[ft_itoa_ubase](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_itoa_ubase.c)</code> -
  converts an integer to a string of a given base representation.
* <code>[ft_strnew_zeros](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_strnew_zeros.c)</code>. -
  creates a new string filled with a given character, with a specified length.
* <code>[ft_strmapi](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_strmapi.c)</code> - applies a
  function to each character in a string.
* <code>[ft_striteri](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_striteri.c)</code> - applies a
  function to each character in a string, with an index.
* <code>[ft_concat](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_concat.c)</code> - concatenates
  multiple strings.
* <code>[ft_strjoin_four](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_strjoin_four.c)</code> -
  concatenates four strings.
* <code>[ft_strjoin_three](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_strjoin_three.c)</code> -
  concatenates three strings.
* <code>[ft_strlcat](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_strlcat.c)</code> - appends a
  string to another string
* <code>[ft_strlcpy](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_strlcpy.c)</code> - Copies a
  string, ensuring that the resulting string is null-terminated and that the total length of the resulting string does
  not exceed a given size.
* <code>[ft_strlen](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_strlen.c)</code> - Returns the
  length of a string.

### Memory Management

* <code>[ft_bzero](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_bzero.c)</code> - fills a memory
  area with zeros.
* <code>[ft_memset](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_memset.c)</code> - fills a memory
  area with a specified byte value.
* <code>[ft_memcpy](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_memcpy.c)</code> - copies a memory
  area from one location to another.
* <code>[ft_memmove](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_memmove.c)</code> - copies a
  memory area from one location to another, handling overlaps.
* <code>[ft_memchr](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_memchr.c)</code> - searches a
  memory area for a specific byte value.
* <code>[ft_calloc](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_calloc.c)</code> - allocates
  memory and sets it to zero.
* <code>[ft_memcmp](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_memcmp.c)</code> - compares two
  memory areas up to a specified length.

### Linked Lists

* <code>[ft_lstnew](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_lstnew.c)</code> - creates a new
  node for a linked list.
* <code>[ft_lstlast](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_lstlast.c)</code> - finds the
  last node in a linked list.
* <code>[ft_lstmap](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_lstlast.c)</code> - creates a new
  linked list by applying a function to each node of an existing linked list.
* <code>[ft_lstadd_front](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_lstadd_front.c)</code> -
  adds a new node to the beginning of a linked list.
* <code>[ft_lstadd_back](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_lstadd_back.c)</code> - adds
  a new node to the end of a linked list.
* <code>[ft_lstdelone](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_lstdelone.c)</code> - deletes a
  node from a linked list.
* <code>[ft_lstclear](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_lstclear.c)</code> - deletes all
  nodes from a linked list.
* <code>[ft_lstiter](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_lstiter.c)</code> - applies a
  function to each node in a linked list.
* <code>[ft_lstsize](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_lstnew.c)</code> - counts the
  number of nodes in a linked list.

### Other

* <code>[ft_isalnum](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_isalnum.c)</code> - checks if a
  character is alphanumeric.
* <code>[ft_isalpha](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_isalpha.c)</code> - checks if a
  character is alphabetic.
* <code>[ft_isascii](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_isascii.c)</code> - checks if a
  character is a valid ASCII character.
* <code>[ft_isdigit](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_isdigit.c)</code> - checks if a
  character is a digit.
* <code>[ft_isprint](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_isprint.c)</code> - checks if a
  character is printable.
* <code>[ft_isspace3](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_isspace3.c)</code> - checks if a
  character is whitespace.
* <code>[ft_atoi](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_atoi.c)</code> - converts a string
  to an integer.
* <code>[ft_atof](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_atof.c)</code> - converts a string
  to a floating point number. Supports scientific notation (1e-5).
* <code>[ft_tolower](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_tolower.c)</code> - converts a
  character to lowercase.
* <code>[ft_toupper](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_toupper.c)</code> - converts a
  character to uppercase.
* <code>[ft_min](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_min.c)</code> - Returns the minimum
  of two size\_t values.
* <code>[ft_contains](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_contains.c)</code> - checks if a
  string contains a specific character.

These functions are useful for string manipulation tasks such as concatenating multiple strings together or ensuring
that a string does not exceed a certain length.

### Printing functions

* <code>[ft_putchar_fd](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_putchar_fd.c)</code> - Prints
  a char to a specified file descriptor.
* <code>[ft_putendl_fd](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_putendl_fd.c)</code> - Prints
  the string and a new line to a specified file descriptor.
* <code>[ft_putnbr_fd](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_putnbr_fd.c)</code> - Prints
  the number to a specified file descriptor.
* <code>[ft_putstr_fd](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_stdlib/ft_putstr_fd.c)</code> - Prints
  the string to a specified file descriptor.

These strings are useful for printing errors and debugging tasks such as printing the contents of a given argument to
the specified file descriptor.

ft\_printf function
-------------------

<code>[ft_printf](https://github.com/Dwimpy/libft-printf/blob/main/src/ft_printf/ft_printf.c)</code> is a variadic
function that formats and prints output to the standard output stream (stdout). It is modeled after the
standard `printf` function in the C library, but it is implemented using only the functions provided by the `libft`
library.

The function takes a format string, which specifies the format of the output, followed by optional arguments that
correspond to the format specifiers in the format string. The function then formats the output according to the format
string and prints it to the standard output stream.

The function supports a variety of format specifiers, including integers, strings, characters, and pointers, and it also
provides support for various flags, such as padding, precision, and field width, that can be used to further customize
the output.

`ft_printf` returns the number of characters printed to the standard output stream, excluding the terminating null byte.
If an error occurs, it returns a negative value.
