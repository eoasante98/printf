Readme file of the pseudo "printf" function in C
 
For this programming project we are asked to create a simplified printf function in C that can handle certain specifiers. In the project, we:
 
Task 1: Handle simple string printing
----------------------------------------
 
1. Create a function `int _printf(const char *format, ...);` in a file named `printf.c`.
3. Handle simple string printing. For example:
   ```c
   int main(void)
   {
       _printf("Hello, world!\n");
       return (0);
   }
   ```
   Expected output: `Hello, world!`
 
Task 2: Handle printing characters
----------------------------------------
 
1. Add support for printing single characters using `%c` format specifier.
2. For example:
   ```c
   int main(void)
   {
       char c = 'A';
       _printf("Character: %c\n", c);
       return (0);
   }
   ```
   Expected output: `Character: A`
 
Task 3: Handle printing integers
----------------------------------------
 
1. Add support for printing integers using `%d` and `%i` format specifiers.
2. For example:
   ```c
   int main(void)
   {
       int num = 42;
       _printf("Number: %d\n", num);
       return (0);
   }
   ```
   Expected output: `Number: 42`
 
Task 4: Handle printing strings
----------------------------------------
 
1. Add support for printing strings using `%s` format specifier.
2. For example:
   ```c
   int main(void)
   {
       char *str = "Print this string";
       _printf("String: %s\n", str);
       return (0);
   }
   ```
   Expected output: `String: Print this string`
 
Task 5: Handle printing decimal numbers
----------------------------------------
 
1. Add support for printing decimal numbers using `%d` format specifier.
2. For example:
   ```c
   int main(void)
   {
       int num = 3;
       _printf("Number: %f\n", num);
       return (0);
   }
   ```
   Expected output: `Number: 3`
 
Task 6: Handle printing octal numbers
----------------------------------------
 
1. Add support for printing octal numbers using `%o` format specifier.
2. For example:
   ```c
   int main(void)
   {
       int num = 64;
       _printf("Octal: %o\n", num);
       return (0);
   }
   ```
   Expected output: `Octal: 100`
 
Task 7: Handle printing hexadecimal numbers (lowercase)
--------------------------------------------------------
 
1. Add support for printing hexadecimal numbers (lowercase) using `%x` format specifier.
2. For example:
   ```c
   int main(void)
   {
       int num = 255;
       _printf("Hexadecimal: %x\n", num);
       return (0);
   }
   ```
   Expected output: `Hexadecimal: ff`
 
Task 8: Handle printing hexadecimal numbers (uppercase)
--------------------------------------------------------
 
1. Add support for printing hexadecimal numbers (uppercase) using `%X` format specifier.
2. For example:
   ```c
   int main(void)
   {
       int num = 255;
       _printf("Hexadecimal: %X\n", num);
       return (0);
   }
   ```
   Expected output: `Hexadecimal: FF`
 
Task 9: Handle printing unsigned integers
----------------------------------------
 
1. Add support for printing unsigned integers using `%u` format specifier.
2. For example:
   ```c
   int main(void)
   {
       unsigned int num = 4294967295;
       _printf("Unsigned: %u\n", num);
       return (0);
   }
   ```
   Expected output: `Unsigned: 4294967295`
 
Task 10: Handle printing binary numbers
----------------------------------------
 
1. Add support for printing binary numbers using `%b` format specifier.
2. For example:
   ```c
   int main(void)
   {
       int num = 42;
       _printf("Binary: %b\n", num);
       return (0);
   }
   ```
   Expected output: `Binary: 101010`
 
Task 11: Handle multiple format specifiers in one string
--------------------------------------------------------
 
1. Modify the `_printf` function to handle multiple format specifiers in one string.
2. For example:
   ```c
   int main(void)
   {
       int num1 = 10, num2 = 20;
       _printf("Numbers: %d and %d\n", num1, num2);
       return (0);
   }
   ```
   Expected output: `Numbers: 10 and 20`
 
Task 12: Handle the `%%` format specifier
--------------------------------------------------------
 
1. Add support for printing a literal `%` character using `%%` format specifier.
2. For example:
   ```c
   int main(void)
   {
       _printf("%%\n");
       return (0);
   }
   ```
   Expected output: `%`
 
Task 13: Handle unknown format specifiers
--------------------------------------------------------
 
1. Handle cases where an unknown format specifier is encountered (e.g., `%z`).
2. For example:
   ```c
   int main(void)
   {
       _printf("Unknown: %z\n");
       return (0);
   }
   ```
   Expected output: `Unknown: %z`
 
Task 14: Handle width and precision modifiers for integers
--------------------------------------------------------
 
1. Add support for width and precision modifiers for integers using `%` followed by a number.
2. For example:
   ```c
   int main(void)
   {
       int num = 42;
       _printf("Padded number: %10d\n", num);
       return (0);
   }
   ```
   Expected output: `Padded number:         42`
 
Task 15: Handle width and precision modifiers for strings
--------------------------------------------------------
 
1. Add support for width and precision modifiers for strings using `%` followed by a number.
2. For example:
   ```c
   int main(void)
   {
       char *str = "Hello";
       _printf("Padded string: %10s\n", str);
       return (0);
   }
   ```
   Expected output: `Padded string:      Hello`
 
Task 16: Handle multiple flags, width, and precision modifiers
--------------------------------------------------------
 
1. Modify the `_printf` function to handle multiple flags, width, and precision modifiers together.
2. For example:
   ```c
   int main(void)
   {
       int num = 42;
       char *str = "Hello";
       _printf("Formatted: %+10.5d %15s\n", num, str);
       return (0);
   }
   ```
   Expected output: `Formatted:    +00042          Hello`
 
Task 17: Handle the `#` flag for hexadecimal and octal numbers
--------------------------------------------------------
 
1. Add support for the `#` flag to print `0x` or `0` prefixes for hexadecimal and octal numbers.
2. For example:
   ```c
   int main(void)
   {
       int num = 255;
 
 
       _printf("Hexadecimal: %#x\n", num);
       _printf("Octal: %#o\n", num);
       return (0);
   }
   ```
   Expected output: `Hexadecimal: 0xff` and `Octal: 0377`

Task 18: Handle the `0` flag for zero-padding
--------------------------------------------------------
 
1. Add support for the `0` flag to pad integers with leading zeros.
2. For example:
   ```c
   int main(void)
   {
       int num = 42;
       _printf("Padded with zeros: %010d\n", num);
       return (0);
   }
   ```
   Expected output: `Padded with zeros: 0000000042`
 
Task 19: Handle the `-` flag for left-justification
--------------------------------------------------------
 
1. Add support for the `-` flag to left-justify strings and numbers.
2. For example:
   ```c
   int main(void)
   {
       char *str = "Left Justified";
       _printf("Left Justify: %-20s\n", str);
       return (0);
   }
   ```
   Expected output: `Left Justify: Left Justified     ` (with spaces at the end to make it 20 characters wide)
 
Task 20: Handle the space and + flags for signed numbers
--------------------------------------------------------
 
1. Add support for the space and `+` flags to print a space or `+` before positive signed numbers.
2. For example:
   ```c
   int main(void)
   {
       int num1 = 42, num2 = -42;
       _printf("Positive: % d\n", num1);
       _printf("Negative: %+d\n", num2);
       return (0);
   }
   ```
   Expected output: `Positive:  42` and `Negative: -42`
 
Task 21: Handle the l and h length modifiers for integers
--------------------------------------------------------
 
1. Add support for the `l` and `h` length modifiers to handle long and short integers.
2. For example:
   ```c
   int main(void)
   {
       long int num1 = 10000000000;
       short int num2 = 200;
       _printf("Long: %ld\n", num1);
       _printf("Short: %hd\n", num2);
       return (0);
   }
   ```
   Expected output: `Long: 10000000000` and `Short: 200`
 
Task 22: Handle the l length modifier for printing strings
--------------------------------------------------------
 
1. Add support for the `l` length modifier to handle wide characters (wchar_t*) for strings.
2. For example:
   ```c
   int main(void)
   {
       wchar_t *wstr = L"Hello, wide world!";
       _printf("Wide String: %ls\n", wstr);
       return (0);
   }
   ```
   Expected output: `Wide String: Hello, wide world!`
 
Task 23: Handle the # flag for floating-point numbers
--------------------------------------------------------
 
1. Add support for the `#` flag to always include a decimal point for floating-point numbers.
2. For example:
   ```c
   int main(void)
   {
       double num = 42.0;
       _printf("With Decimal Point: %#f\n", num);
       return (0);
   }
   ```
   Expected output: `With Decimal Point: 42.000000`
 
Task 24: Handle the width and precision modifiers for floating-point numbers
--------------------------------------------------------
 
1. Add support for the width and precision modifiers for floating-point numbers.
2. For example:
   ```c
   int main(void)
   {
       double num = 3.14159;
       _printf("Formatted Float: %10.3f\n", num);
       return (0);
   }
   ```
   Expected output: `Formatted Float:      3.142`
 
Task 25: Handle custom format specifiers for data types
--------------------------------------------------------
 
1. Add support for custom format specifiers for specific data types (e.g., `%p` for pointers).
2. For example:
   ```c
   int main(void)
   {
       char *str = "Hello";
       char *ptr = &str;
       _printf("String: %s, Pointer: %p\n", str, ptr);
       return (0);
   }
   ```
   Expected output: `String: Hello, Pointer: 0xADDRESS`
 
Task 26: Handle the n format specifier for character count
--------------------------------------------------------
 
1. Add support for the `n` format specifier to store the number of characters written so far in a pointer argument.
2. For example:
   ```c
   int main(void)
   {
       int count;
       _printf("Count: %d%n\n", 42, &count);
       _printf("Characters written so far: %d\n", count);
       return (0);
   }
   ```
   Expected output: `Count: 42` and `Characters written so far: 6`
 
Compilation and Styling
 
Files were compiled by an Ubuntu 20.04 LTS using ```$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c``` command.
All files were betty styled.
 
 
Authors:
 
@queenyaa and @eoasante98 

PS: This is not for the faint at stomach.
