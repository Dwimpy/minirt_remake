/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 05:24:32 by arobu             #+#    #+#             */
/*   Updated: 2023/02/27 14:01:15 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAGS "-+0 #"
# define SPECS "cspdiouxX%"
# define WIDTH "0123456789"
# define PRECISION ".0123456789"
# define BASE_HEX_MINOR "0123456789abcdef"
# define BASE_HEX_MAJOR "0123456789ABCDEF"
# define BASE_DECIMAL "0123456789"

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

/**

 @struct s_flags
 @brief Represents the flags provided in a printf format specifier.
 @var s_flags::isprovided
 The flag provided. 1 if provided, 0 otherwise.
 @var s_flags::hash
flag. 1 if provided, 0 otherwise.
 @var s_flags::zero
0 flag. 1 if provided, 0 otherwise.
 @var s_flags::plus
flag. 1 if provided, 0 otherwise.
 @var s_flags::minus
flag. 1 if provided, 0 otherwise.
 @var s_flags::space
space flag. 1 if provided, 0 otherwise.
*/
typedef struct s_flags
{
	size_t		isprovided;
	size_t		hash;
	size_t		zero;
	size_t		plus;
	size_t		minus;
	size_t		space;
}				t_flags;
/**

 @struct s_options
 @brief Represents the options provided in a printf format specifier.
 @var s_options::isprovided
The option provided. 1 if provided, 0 otherwise.
 @var s_options::valuegiven
The value of the option.
 @var s_options::padding
The amount of padding to use.
 @var s_options::padding_field
The string to use as padding.
*/

typedef struct s_options
{
	int			isprovided;
	size_t		valuegiven;
	size_t		padding;
	char		*padding_field;
}				t_options;
/**

 @struct s_sign
 @brief Represents the sign provided in a printf format specifier.
 @var s_sign::has_sign
Whether a sign is provided. 1 if provided, 0 otherwise.
 @var s_sign::is_negative
Whether the number is negative. 1 if negative, 0 otherwise.
 @var s_sign::sign
The sign to use.
*/
typedef struct s_sign
{
	int			has_sign;
	int			is_negative;
	char		*sign;
}				t_sign;
/**

 @struct s_flag
 @brief Represents the flag provided in a printf format specifier.
 @var s_flag::flag_len
The length of the flag.
 @var s_flag::left_justify
Whether the flag is left-justified. 1 if left-justified, 0 otherwise.
 @var s_flag::zero_padded
Whether the flag is zero-padded. 1 if zero-padded, 0 otherwise.
 @var s_flag::flag
The flag itself.
*/
typedef struct s_flag
{
	size_t		flag_len;
	size_t		left_justify;
	size_t		zero_padded;
	char		*flag;
}				t_flag;
/**

 @typedef t_flags
Struct to store the flag characters from format string.
 @field {size_t} isprovided - Flag indicating if any of the FLAGS is present 
in the format string.
 @field {size_t} hash - Flag indicating if '#' flag is present in the format 
string.
 @field {size_t} zero - Flag indicating if '0' flag is present in the format 
string.
 @field {size_t} plus - Flag indicating if '+' flag is present in the format 
string.
 @field {size_t} minus - Flag indicating if '-' flag is present in the format
 string.
 @field {size_t} space - Flag indicating if ' ' flag is present in the format
 string.
*/
/**

 @typedef t_options
Struct to store the width and precision values from format string.
 @field {int} isprovided - Flag indicating if width or precision is 
present in the format string.
 @field {size_t} valuegiven - Value specified for width or precision
in the format string.
 @field {size_t} padding - Padding required for width or precision.
 @field {char*} padding_field - String of padding characters required
 for width or precision.
*/
/**

 @typedef t_sign
Struct to store the sign characters from format string.
 @field {int} has_sign - Flag indicating if a sign character is 
present in the format string.
 @field {int} is_negative - Flag indicating if the numeric value is negative.
 @field {char*} sign - Sign character required for numeric values.
*/
/**

 @typedef t_flag
Struct to store the flag characters from format string.
 @field {size_t} flag_len - Length of the flag.
 @field {size_t} left_justify - Flag indicating if the text is left-justified.
 @field {size_t} zero_padded - Flag indicating if the text is zero-padded.
 @field {char*} flag - String of flag characters.
*/
/**

 @typedef t_fields
Struct to store all the parsed fields from format string.
 @field {t_flags} flags - Flags from format string.
 @field {t_flag} flag - Specific flag from format string.
 @field {t_sign} sign - Sign character from format string.
 @field {t_options} width - Width value from format string.
 @field {t_options} precision - Precision value from format string.
 @field {size_t} empty_str - Flag indicating if the string to print is empty.
 @field {size_t} empty_ptr - Flag indicating if the pointer to print is NULL.
 @field {size_t} plus_zero_prec - Flag indicating if the value is 0 with a '+' 
flag and a precision of 0.
 @field {size_t} msz_prec - Minimum size required for precision.
 @field {size_t} buff_index - Index to keep track of buffer position.
 @field {size_t} format_index - Index to keep track of format string position.
 @field {size_t} bytes_to_skip - Number of bytes to skip from format string.
 @field {size_t} ndigits - Number of digits in the value to be printed.
 @field {char} specifier - Specifier character from format string.
*/

typedef struct s_fields
{
	t_flags		flags;
	t_flag		flag;
	t_sign		sign;
	t_options	width;
	t_options	precision;
	size_t		empty_str;
	size_t		empty_ptr;
	size_t		plus_zero_prec;
	size_t		msz_prec;
	size_t		buff_index;
	size_t		format_index;
	size_t		bytes_to_skip;
	size_t		ndigits;
	char		specifier;
}				t_fields;

/**

 @brief ft_init_field
 @description Initializes the t_fields struct with default values.
 @returns {t_fields} Initialized t_fields struct.
*/
t_fields		ft_init_field(void);
/**

 @brief ft_reset_field
 @description Resets the values of the given t_fields struct 
to their default values.
 @param {t_fields} field - Pointer to the t_fields struct to reset.
 @returns {void}
*/
void			ft_reset_field(t_fields *field);
/**
 @brief ft_printf
 @description Outputs the formatted string according to the format specifier.
 @param {string} format - Format specifier string.
 @param {...any} args - Variable number of arguments to be printed.
 @returns {number} Number of characters printed.
*/
size_t			ft_printf(const char *format, ...);
/**
 @brief ft_get_flags
 @description Parses the flag options provided in the format specifier.
 @param {t_fields} field - Pointer to the t_fields struct.
 @param {string} format - Format specifier string.
 @returns {number} Number of bytes to skip in the format specifier string.
*/
size_t			ft_get_flags(t_fields *field, const char *format);
/**

 @brief ft_get_width
 @description Parses the width option provided in the format specifier.
 @param {t_fields} field - Pointer to the t_fields struct.
 @param {string} format - Format specifier string.
 @returns {number} Number of bytes to skip in the format specifier string.
*/
size_t			ft_get_width(t_fields *field, const char *format);
/**

 @brief ft_get_precision
 @description Parses the precision option provided in the format specifier.
 @param {t_fields} field - Pointer to the t_fields struct.
 @param {string} format - Format specifier string.
 @returns {number} Number of bytes to skip in the format specifier string.
*/
size_t			ft_get_precision(t_fields *field, const char *format);
/**

 @brief ft_get_specifier
 @description Parses the format specifier in the format string.
 @param {t_fields} field - Pointer to the t_fields struct.
 @param {string} format - Format specifier string.
 @returns {number} Number of bytes to skip in the format specifier string.
*/
size_t			ft_get_specifier(t_fields *field, const char *format);
/**

 @brief ft_handle_options
 @description Handles the various options provided in the format specifier.
 @param {t_fields} field - Pointer to the t_fields struct.
 @param {string} format - Format specifier string.
 @returns {number} Number of bytes to skip in the format specifier string.
*/
size_t			ft_handle_options(t_fields *field, const char *format);
/**

Counts the number of digits in a given long integer in a given base.
 @param {long} n - the number to count digits of
 @param {char *} base - the base to count digits in
 @returns {size_t} the number of digits
*/
size_t			ft_count_digits(long n, char *base);
/**

Counts the number of digits in a given uintmax_t integer in a given base.
 @param {uintmax_t} n - the number to count digits of
 @param {char *} base - the base to count digits in
 @returns {size_t} the number of digits
*/
size_t			ft_count_udigits(uintmax_t n, char *base);
/**

Handles the 's' specifier by formatting a string and returning it.
 @param {t_fields *} field - the field struct to use for formatting
 @param {void *} data - the data to format
 @returns {char *} the formatted string
*/
char			*ft_handle_specifier_s(t_fields *field, void *data);
/**

Handles the 'p' specifier by formatting a pointer and returning it.
 @param {t_fields *} field - the field struct to use for formatting
 @param {void *} data - the data to format
 @returns {char *} the formatted pointer
*/
char			*ft_handle_specifier_p(t_fields *field, void *data);
/**

Handles the 'd' and 'i' specifiers by formatting 
a decimal integer and returning it.
 @param {t_fields *} field - the field struct to use for formatting
 @param {void *} data - the data to format
 @returns {char *} the formatted integer
*/
char			*ft_handle_specifier_di(t_fields *field, void *data);
/**

Handles the 'u' specifier.
 @param field
	- the structure containing the current state of the formatting process
 @param data - the data to format
 @return char* - the formatted string
*/
char			*ft_handle_specifier_u(t_fields *field, void *data);
/**

Handles the 'x' and 'X' specifiers.
 @param field
	- the structure containing the current state of the formatting process
 @param data - the data to format
 @return char* - the formatted string
*/
char			*ft_handle_specifier_x(t_fields *field, void *data);
/**

Handles the '%' specifier.
 @param field
	- the structure containing the current state of the formatting process
 @return char* - the formatted string
*/
char			*ft_handle_specifier_percent(t_fields *field);
/**

Validates the state of the formatting process for the 's' specifier.
 @param field
	- the structure containing the current state of the formatting process
*/
void			ft_validate_specifier_s(t_fields *field);
/**

Validates the state of the formatting process for the 'd' and 'i' specifiers.
 @param field
	- the structure containing the current state of the formatting process
*/
void			ft_validate_specifier_di(t_fields *field);
/**

Validates the fields of the struct for the p specifier.
 @param {t_fields*} field - The t_fields struct to validate
*/
void			ft_validate_specifier_p(t_fields *field);
/**

Validates the fields of the struct for the u specifier.
 @param {t_fields*} field - The t_fields struct to validate
*/
void			ft_validate_specifier_u(t_fields *field);
/**

Validates the fields of the struct for the x specifier.
 @param {t_fields*} field - The t_fields struct to validate
*/
void			ft_validate_specifier_x(t_fields *field);
/**

Validates the fields of the struct for the percent specifier.
 @param {t_fields*} field - The t_fields struct to validate
*/
void			ft_validate_specifier_percent(t_fields *field);
/**

Creates the precision field in the t_fields struct.
 @param {t_fields*} field - The t_fields struct to modify
*/
void			ft_create_precision(t_fields *field);
/**

Creates the width field in the t_fields struct.
 @param {t_fields*} field - The t_fields struct to modify
*/
void			ft_create_width(t_fields *field);

/**

Creates a formatted string for the %s specifier
 @param {va_list} args - argument list
 @param {t_fields} *field - pointer to a t_fields struct
 @returns {char} - pointer to the formatted string
*/
char			*ft_create_string_s(va_list args, t_fields *field);
/**

Creates a formatted string for the %p specifier
 @param {va_list} args - argument list
 @param {t_fields} *field - pointer to a t_fields struct
 @returns {char} - pointer to the formatted string
*/
char			*ft_create_string_p(va_list args, t_fields *field);
/**

Creates a formatted string for the %d and %i specifiers
 @param {va_list} args - argument list
 @param {t_fields} *field - pointer to a t_fields struct
 @returns {char} - pointer to the formatted string
*/
char			*ft_create_string_di(va_list args, t_fields *field);
/**

Creates a formatted string for the %u specifier
 @param {va_list} args - argument list
 @param {t_fields} *field - pointer to a t_fields struct
 @returns {char} - pointer to the formatted string
*/
char			*ft_create_string_u(va_list args, t_fields *field);
/**

Creates a formatted string for the %x and %X specifiers
 @param {va_list} args - argument list
 @param {t_fields} *field - pointer to a t_fields struct
 @returns {char} - pointer to the formatted string
*/
char			*ft_create_string_x(va_list args, t_fields *field);
/**

Creates a formatted string for the %% specifier
 @param {t_fields} *field - pointer to a t_fields struct
 @returns {char} - pointer to the formatted string
*/
char			*ft_create_string_percent(t_fields *field);
/**

Creates a formatted string based on the specifier
 @param {va_list} args - argument list
 @param {t_fields} *field - pointer to a t_fields struct
 @returns {char} - pointer to the formatted string
*/
char			*ft_create_string(va_list args, t_fields *field);

/**

Convert a positive integer to a string representation in the given base
 @param {uintmax_t} n - the integer to convert
 @param {const char *} base - the base to convert to (e.g. "0123456789ABCDEF")
 @returns {char *} a string representation of the integer in the given base
*/
char			*ft_itoa_pbase(uintmax_t n, const char *base);
/**

Process the flags in the field and update its properties accordingly
 @param {t_fields *} field - the field to process the flags of
*/
void			ft_process_flags(t_fields *field);
/**

Add a character c to a string str width times based on the field properties
 @param {char **} str - pointer to the string to add the characters to
 @param {char} c - the character to add
 @param {t_fields *} field - the field containing the width property
 @param {size_t *} size - pointer to the size of the string, to be updated
*/
void			ft_add_width_c(char **str, char c, t_fields *field,
					size_t *size);
/**

Handle the specifier in the field and return a string 
representation of the corresponding argument
 @param {va_list} args - the list of arguments passed to ft_printf
 @param {t_fields *} field - the field containing the specifier property
 @returns {char *} a string representation of the corresponding argument
*/
char			*ft_handle_specifier(va_list args, t_fields *field);
/**

Add a precision property to a string, based on the field properties
 @param {char **} str - pointer to the string to add the precision to
 @param {t_fields *} field - the field containing the precision property
 @returns {char *} the modified string
*/
char			*ft_add_precision(char **str, t_fields *field);
/**

Create a new string with a single character c
 @param {char} c - the character to add to the new string
 @returns {char *} the new string
*/
char			*ft_strnew(char c);
/**

Duplicate a string, replacing null characters with "\0"
 @param {char *} str - the string to duplicate
 @returns {char *} the duplicated string
*/
char			*ft_strdup_spec_s(char *str);
/**

Duplicate a string,
	adding the "0x" prefix and replacing null characters with "\0"
 @param {char *} str - the string to duplicate
 @returns {char *} the duplicated string with the "0x" prefix
*/
char			*ft_strdup_spec_p(char *str);

#endif
