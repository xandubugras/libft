# ft_printf
Recode the printf function in C. Much more challenging then it seems.

# Testing

In order to test, just add your functions to main.c and run make comp .

# how it works
Program manages:
Conversions: sSpdDioOuUxXcC
• %%
• The flags #0-+ and space
• The minimum field-width
• The precision
• The length flags hh, h, l, ll, j, et z.
#How it works
in order to do that I use a lot of string parsing and manipulation:

The function printf iterates through the string input by the user. if it finds a '%', it start working on it, else it just prints the character.

Once the '%' is found, the first thing the function in the file set_descriptor.c does is separate the descriptor (eg: %+12lld) and stores it in the struct.

Then the program starts taking the information out of that descriptor and initializing the struct.

the last step (and most complicated) is getting the actual argument. In order to do that I use va_arg(va_list, type).

In order to do that I evaluate what is the type and length of the argument (arguments.c) by using the information I got from the descriptor, and save the argument as a string

After all the information is captured, the program manipulates the string in order to handle the formatting flags (handling.c).

In order: first I handle precision (which sets 0s to the string in order to make it have that many digits)

second: padding(makes the string have length equal to that, adds 0s if the zero flag is set)

third: +#-space

- switchs the padding to the left, 
#adds 0x to XxOo 
+ adds a + sign to a positive number
space adds a space instead of the positive sign

After handling all the formating is done, print the final string and sum the len of it to the string.


