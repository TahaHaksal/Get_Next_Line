# Get_Next_Line
A function that is used to read line by line from the given file

Allowed functions:
	-read,
	-malloc,
	-free

Description:
	Write a function that returns a line read from a file descriptor

Requirements:
	-Repeated calls should let you read one line at a time,
	-The function should return the line that was read,
	-The function should be able to read from standard input,
	-Unless the eof is reached the terminating character should be '\n',
	-Helper functions should be put in get_next_line_utils.c,
	-Buffer size should be defined by the user,
	-Global variables,
	-Can't have any memory leaks for obvious reasons,
	-Has to compile with the following flags: -Wall -Werror -Wextra

Goal of the project:
	-Teach static variables,
	-Getting accustomed with reading and opening files using C functions
