# My
***
## Macro
```c
#define true 1
```
```c
#define TRUE 1
```
```c
#define false 0
```
```c
#define FALSE 0
```
***
## Functions

```c
int my_printf(int fd, char *str, ...);
```
Display text, with formatting
```c
char *my_strdup(char *str);
```
re-alloc data.
```c
int my_str_to_int(char *string);
```
return int with str
```c
int my_char_is_in_string(char const c, char const *string);
```
check if char is in string
```c
int my_chars_is_in_string(char const *chars, char const *string);
```
check if all chars is in string
```c
char *my_str_replace(
    char const *strA, char *strB, char *final_buffer, int *index
);
```
replace in string.
```c
char *my_insert(char *strA, char *strB, char *buffer, int position);
```
insert string in another string
```c
char *my_int_to_str(int);
```
return string with int in parameter.
```c
int my_nbr_of_digit(int);
```
count number of digit in string
```c
void unprint(char *string);
```
// _deprecated_
```c
int my_error(char *);
```
Display in error output
```c
void my_put_float(float);
```
/ _deprecated_
```c
char my_charlowcase(char);
```
transform string in low case
```c
void my_putchar(char);
```
display char in standard output
```c
int value_of_string_n(char const *, int);
```
// _deprecated_
```c
int value_of_string(char const *);
```
// _deprecated_
```c
int my_isneg(int);
```
// _deprecated_
```c
int my_put_nbr(int);
```
Display nbr in standard output.
```c
void my_swap(int *, int *);
```
// _deprecated_
```c
int my_putstr(char const *);
```
Display string in standard output.
```c
int my_strlen(char const *);
```
count char in string.
```c
int my_getnbr(char const *);
```
return int with parameter.
```c
void my_sort_int_array(int *, int);
```
// _deprecated_
```c
int my_str_isnum(char const *);
```
check if string is number
```c
int my_compute_power_rec(int, int);
```
poser int in recursive
```c
int my_str_islower(char const *);
```
Check if string is in low case
```c
int my_str_isalpha(char const *);
```
Check if string is with alpha char
```c
char *my_strcapitalize(char *);
```
// _deprecated_
```c
char *my_strupcase(char *);
```
// _deprecated_
```c
char *my_strstr(char *, char const *);
```
// _deprecated_
```c
int my_strcmp(char const *, char const *);
```
compare string in parameter.
```c
int my_strncmp(char const *, char const *, int);
```
compare string in parameter.
```c
int my_compute_square_root(int);
```
power int not recursive
```c
int my_str_isupper(char const *);
```
check if all char in string is upper.
```c
int my_is_prime(int);
```
check if number is prime.
```c
int my_str_isprintable(char const *);
```
check if all char in string is printable.
```c
int my_find_prime_sup(int);
```
get prime number superior.
```c
int my_showstr(char const *);
```
// _deprecated_
```c
char *my_strcpy(char *, char const *);
```
// _deprecated_
```c
int my_showmem(char const *, int);
```
// _deprecated_
```c
char *my_strncpy(char *, char const *, int);
```
// _deprecated_
```c
char *my_strcat(char *, char const *);
```
concat string in first parameter.
```c
char *my_strncat(char *, char const *, int);
```
concat string in first parameter.