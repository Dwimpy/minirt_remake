/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:36:02 by arobu             #+#    #+#             */
/*   Updated: 2023/04/25 17:37:45 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

/**

 @brief A structure representing a linked list node.
Each node contains a pointer to its content and a pointer to the next node in
the list.
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				*ft_strcpy(char *dst, char *src);
char				*ft_strcat(char *dst, char *src);
char				*ft_strncpy(char *dst, char *src, size_t len);
char				*ft_strncat(char *dst, char *src, size_t len);

/**
 @brief Tests whether the given character is alphanumeric.
 @param c The character to test.
 @return Non-zero if the character is alphanumeric, zero otherwise.
*/
int					ft_isalnum(int c);
/**

 @brief Tests whether the given character is alphabetic.
 @param c The character to test.
 @return Non-zero if the character is alphabetic, zero otherwise.
*/
int					ft_isalpha(int c);
/**

 @brief Tests whether the given character is an ASCII character.
 @param c The character to test.
 @return Non-zero if the character is an ASCII character, zero otherwise.
*/
int					ft_isascii(int c);
/**

 @brief Tests whether the given character is a digit.
 @param c The character to test.
 @return Non-zero if the character is a digit, zero otherwise.
*/
int					ft_isdigit(int c);
/**

 @brief Tests whether the given character is printable.
 @param c The character to test.
 @return Non-zero if the character is printable, zero otherwise.
*/
int					ft_isprint(int c);
/**

 @brief Checks if the string is a valid number.
 @param str The string to check.
 @return A boolean indicating if its true or false.
*/
int					ft_isnumber(char *str);
/**

 @brief Converts a string to an integer.
 @param str The string to convert.
 @return The integer value of the string.
*/
int					ft_atoi(const char *str);
/**

 @brief Converts a string to an long.
 @param str The string to convert.
 @return The long value of the string.
*/
long				ft_atoi_long(const char *s);

/**

@brief Converts a string to a floating-point number.
This function converts the initial portion of the string pointed to by str
to a double representation. It skips all leading white-space characters,
and then, if the first character that is not a white-space character is a
valid digit, it takes as many characters as possible that are valid digits,
optionally followed by a decimal-point character, and then an optional
exponent part (an 'e' or 'E' character followed by an optionally signed
integer). The conversion stops when the first unrecognized character is
reached. If no conversion is performed, zero is returned. If the value
returned is out of range of a double, the behavior is undefined.
@param str The string to convert.
@return The converted floating-point number, or zero if no conversion is
performed.
*/
double				ft_atof(const char *str);
/**

 @brief Converts an uppercase character to lowercase.
 @param c The character to convert.
 @return The lowercase equivalent of the input character.
*/
int					ft_tolower(int c);
/**

 @brief Converts a lowercase character to uppercase.
 @param c The character to convert.
 @return The uppercase equivalent of the input character.
*/
int					ft_toupper(int c);
/**

 @brief Tests whether the given string contains the given character.
 @param str The string to search.
 @param c The character to search for.
 @return Non-zero if the string contains the character, zero otherwise.
*/
int					ft_contains(const char *str, char c);
/**

 @brief Sets the first n bytes of the block of memory pointed to by s to zero.
 @param s A pointer to the memory to set.
 @param n The number of bytes to set to zero.
 @return A pointer to the memory block s.
 */
void				*ft_bzero(void *s, size_t n);
/**

 @brief Sets the first len bytes of the block of 
memory pointed to by b to the value of c.
 @param b A pointer to the memory to set.
 @param c The value to set the memory to.
 @param len The number of bytes to set to c.
 @return A pointer to the memory block b.
*/
/**

 @brief Sets a block of memory to a specific value
 @param b Pointer to the block of memory to fill
 @param c Value to be set
 @param len Number of bytes to be set to the value
 @return Pointer to the block of memory
*/
void				*ft_memset(void *b, int c, size_t len);
/**

 @brief Copies a block of memory to another location
 @param dest Pointer to the destination array where the content is to be copied
 @param src Pointer to the source of data to be copied
 @param n Number of bytes to copy
 @return Pointer to the destination array
*/
void				*ft_memcpy(void *dest, const void *src, size_t n);
/**

 @brief Copies a block of memory to another location,
	even if the two blocks overlap
 @param dst Pointer to the destination array where the content is to be copied
 @param src Pointer to the source of data to be copied
 @param len Number of bytes to copy
 @return Pointer to the destination array
*/
void				*ft_memmove(void *dst, void *src, size_t len);
/**

 @brief Locates the first occurrence of a character in a block of memory
 @param s Pointer to the block of memory
 @param c Character to be located
 @param n Number of bytes to search
 @return Pointer to the first occurrence of the character, or NULL if not found
*/
void				*ft_memchr(const void *s, int c, size_t n);
/**

 @brief Allocates memory and sets it to zero
 @param count Number of elements to allocate
 @param size Size of each element
 @return Pointer to the allocated memory, or NULL if the allocation fails
*/
void				*ft_calloc(size_t count, size_t size);
/**

 @brief Compares two blocks of memory
 @param s1 Pointer to the first block of memory
 @param s2 Pointer to the second block of memory
 @param n Number of bytes to compare
 @return A negative, zero or positive integer if s1 is less than,
	equal to or greater than s2, respectively
*/
int					ft_memcmp(const void *s1, const void *s2, size_t n);
/**

 @brief Compares two strings
 @param s1 Pointer to the first string to compare
 @param s2 Pointer to the second string to compare
 @param n Maximum number of characters to compare
 @return A negative, zero or positive integer if s1 is less than,
	equal to or greater than s2, respectively
*/
int					ft_strncmp(const char *s1, const char *s2, size_t n);
/**

 @brief Locates the first occurrence of a character in a string
 @param s Pointer to the string
 @param c Character to be located
 @return Pointer to the first occurrence of the character, or NULL if not found
*/
char				*ft_strchr(const char *s, int c);
/**

 @brief Locates the last occurrence of a character in a string
 @param s Pointer to the string
 @param c Character to be located
 @return Pointer to the last occurrence of the character, or NULL if not found
*/
char				*ft_strrchr(const char *s, int c);
/**

 @brief Locates the first occurrence of the null-terminated string needle in the 
string haystack, where not more than len characters are searched. 
Characters that appear after a '\0' character are not searched.
 @param {const char *} haystack - The string to search in
 @param {const char *} needle - The substring to search for
 @param {size_t} len - The maximum number of characters to search in the haystack
 @returns {char *} A pointer to the first occurrence of the 
substring needle in the string haystack,
or a null pointer if the substring is not found
*/
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
/**

 @brief Allocates sufficient memory for a copy of the string s1, does the copy,
	and returns a pointer to it.
 @param {const char *} string - The string to be duplicated
 @returns {char *} A pointer to the new string, or NULL if the allocation fails
*/
char				*ft_strdup(const char *string);
/**

 @brief Allocates and returns a substring from the string 'str'. 
The substring begins at index 'start_index' and has a maximum length of 'len'.
 @param {char const *} str - The string to create the substring from
 @param {unsigned int} start_index
	- The index of the first character of the substring
 @param {size_t} len - The maximum length of the substring
 @returns {char *} The substring, or NULL if the allocation fails
*/
char				*ft_substr(char const *str, unsigned int start_index,
						size_t len);
/**

 @brief Allocates and returns a new string,
	which is the result of the concatenation of 's1' and 's2'
 @param {const char *} s1 - The first string to concatenate
 @param {const char *} s2 - The second string to concatenate
 @returns {char *} The concatenated string, or NULL if the allocation fails
*/
char				*ft_strjoin(const char *s1, const char *s2);
/**
 
Concatenates four strings.
 @param s1 The first string.
 @param s2 The second string.
 @param s3 The third string.
 @param s4 The fourth string.
 @return A newly allocated string containing the concatenated strings.
*/
char				*ft_strjoin_four(const char *s1, const char *s2,
						const char *s3, const char *s4);
/**
Concatenates three strings.
 @param s1 The first string.
 @param s2 The second string.
 @param s3 The third string.
 @return A newly allocated string containing the concatenated strings.
*/
char				*ft_strjoin_three(const char *s1, const char *s2,
						const char *s3);
/**

 @brief Allocates and returns a copy of the string 's1' without 
the characters specified in the 'set' argument
appearing at the beginning or the end of the string.
 @param {const char *} s1 - The string to trim
 @param {const char *} set
	- The characters to remove from the beginning and the end of the string
 @returns {char *} The trimmed string, or NULL if the allocation fails
*/
char				*ft_strtrim(const char *s1, const char *set);
/**

 @brief Allocates and returns an array of strings obtained by 
splitting 's' using the character 'c' as a delimiter.
 @param {const char *} s - The string to split
 @param {char} c - The delimiter character
 @returns {char **} The array of strings resulting from the split,
	or NULL if the allocation fails
*/
char				**ft_split(const char *s, char c);
/**

 @brief Allocates and returns a new string representing 
the integer 'n' given as argument.
 @param {intmax_t} n - The integer to convert
 @returns {char *} The string representing the integer 'n',
	or NULL if the allocation fails
*/
char				*ft_itoa(intmax_t n);
/**

 @function ft_strnew_zeros
 @description Allocates (with malloc(3)) and returns a new string of size 'size',
	initialized to 'c'.
If the allocation fails the function returns NULL.
 @param {size_t} size - The size of the new string.
 @param {char} c - The char to initialize the new string with.
 @returns {char *} The new string.
*/
char				*ft_strnew_zeros(size_t size, char c);
/**

 @function ft_strmapi
 @description Applies the function 'f' to each character of 
the string 's' to create a new string
resulting from successive applications of 'f'.
 @param {char *} s - The string to iterate.
 @param {char (*)(unsigned int, char)} f
	- The function to apply to each character.
 @returns {char *} The string created from the successive applications of 'f'.
*/
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**

 @function ft_striteri
 @description Applies the function 'f' to each character of the string 's'.
Each character is passed by address to 'f' to be modified if necessary.
 @param {char *} s - The string to iterate.
 @param {void (*)(unsigned int, char *)} f
	- The function to apply to each character.
 @returns {void}
*/
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
/**

 @function ft_putchar_fd
 @description Outputs the character 'c' to the given file descriptor 'fd'.
 @param {char} c - The character to output.
 @param {int} fd - The file descriptor on which to write.
 @returns {void}
*/
void				ft_putchar_fd(char c, int fd);
/**

 @function ft_putstr_fd
 @description Outputs the string 's' to the given file descriptor 'fd'.
 @param {char *} s - The string to output.
 @param {int} fd - The file descriptor on which to write.
 @returns {void}
*/
void				ft_putstr_fd(char *s, int fd);
/**

 @function ft_putendl_fd
 @description Outputs the string 's' to the given file descriptor 'fd',
	followed by a newline.
 @param {char *} s - The string to output.
 @param {int} fd - The file descriptor on which to write.
 @returns {void}
*/
void				ft_putendl_fd(char *s, int fd);
/**

 @function ft_putnbr_fd
 @description Outputs the integer 'n' to the given file descriptor 'fd'.
 @param {int} n - The integer to output.
 @param {int} fd - The file descriptor on which to write.
 @returns {void}
*/
void				ft_putnbr_fd(int n, int fd);
/**

 @function ft_itoa_ubase
 @description Converts the unsigned integer 'n' into 
a string representation using the given 'base'.
 @param {uintmax_t} n - The unsigned integer to convert.
 @param {char *} base
	- The string representing the base to use for the conversion.
 @returns {char *} The string representation of 'n'.
*/
char				*ft_itoa_ubase(uintmax_t n, const char *base);
/**

Converts an unsigned integer to a string representation.
 @param n The unsigned integer to convert.
 @return A newly allocated string representing the converted number.
*/
char				*ft_uitoa(uintmax_t n);
/**

Concatenates two strings.
 @param str1 The first string.
 @param str2 The second string.
 @return A newly allocated string containing the concatenated strings.
*/
char				*ft_concat(const char *str1, const char *str2);
/**
@brief Checks whether a given character is a whitespace character.
@param c The character to check.
@return int Returns 1 if the character is a whitespace character,
otherwise returns 0.
*/
int					ft_isspace3(char c);
/**
Copies the source string to the destination string up to a given size.
 @param dst The destination string.
 @param src The source string.
 @param dstsize The maximum number of 
characters to copy to the destination string.
 @return The length of the source string.
*/
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
/**

Copies the source string to the destination string up to a given size.
 @param dst The destination string.
 @param src The source string.
 @param dstsize The maximum number of 
characters to copy to the destination string.
 @return The length of the source string.
*/
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
/**

Returns the length of a string.
 @param s The string to get the length of.
 @return The length of the string.
*/
size_t				ft_strlen(const char *s);
/**

Returns the minimum of two size_t values.
 @param a The first size_t value.
 @param b The second size_t value.
 @return The smaller of the two values.
*/
size_t				ft_min(size_t a, size_t b);
/**

 @typedef t_list
A linked list node structure
 @field content The data held by the linked list node
 @field next A pointer to the next node in the linked list
*/
/**

Creates a new linked list node with the given content
 @param content The content of the new linked list node
 @return A pointer to the new linked list node, or NULL if the allocation fails
*/
t_list				*ft_lstnew(void *content);
/**

Returns a pointer to the last node in the linked list
 @param lst A pointer to the first node in the linked list
 @return A pointer to the last node in the linked list, or NULL if lst is NULL
*/
t_list				*ft_lstlast(t_list *lst);
/**

Creates a new linked list by applying a function 
to each node in the original linked list
 @param lst The linked list to be transformed
 @param f The function to be applied to each node in the linked list
 @param del The function used to delete the content of a node in the linked list
 @return A pointer to the new linked list, or NULL if the allocation fails
*/
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
/**

Adds a new node to the beginning of a linked list
 @param lst A pointer to a pointer to the first node in the linked list
 @param new The new node to be added to the linked list
*/
void				ft_lstadd_front(t_list **lst, t_list *new);
/**

Adds a new node to the end of a linked list
 @param lst A pointer to a pointer to the first node in the linked list
 @param new The new node to be added to the linked list
*/
void				ft_lstadd_back(t_list **lst, t_list *new);
/**

Deletes a single node from a linked list
 @param lst The node to be deleted
 @param del The function used to delete the content of a node in the linked list
*/
void				ft_lstdelone(t_list *lst, void (*del)(void *));
/**

Deletes all nodes in a linked list
 @param lst A pointer to a pointer to the first node in the linked list
 @param del The function used to delete the content of a node in the linked list
*/
void				ft_lstclear(t_list **lst, void (*del)(void *));
/**

Applies a function to each node in a linked list
 @param lst A pointer to the first node in the linked list
 @param f The function to be applied to each node in the linked list
*/
void				ft_lstiter(t_list *lst, void (*f)(void *));
/**

Returns the number of nodes in a linked list
 @param lst A pointer to the first node in the linked list
 @return The number of nodes in the linked list
*/
int					ft_lstsize(t_list *lst);

#endif
