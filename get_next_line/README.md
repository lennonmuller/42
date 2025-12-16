*This project  has been created as part of the 42 curriculum by lmuler-f*

# Get_Next_Line
## Description
`Get_next_line` is a fundamental project at 42 school that involves programing a function in C to read content from a file descriptor, one line at time.
This project is a deep dive into static variables, memory menagement and file descriptor manipulation, key concepts in low-level programming.

The main goal is to create a function `get_next_line()` that, when called in a loop, returns each line of a text file, including the new line character (`\n`), until the end of the file is reached.

## Core concepts:
- **Static Variables:** Understanding how to maintain a persistant state between function calls.
- **File Descriptors:** Interacting with the operating system's through file descriptors
- **Dynamic Memory:** Rigorous use of `malloc()` and `free()` to manage buffer memory without leaks.
- **Robustness:** Handling various edge cases such as empty files, files without new lines, and different `BUFFER_SIZE` values.

## Algorithm Justification
The impemented algorithm is designed for robustness and efficiency, centering around a static buffer (`stash`) that persists between function calls.

1. **Reading and Accumulating:** The function reads data from the file descriptor into a temporary buffer in chuncs of `BUFFER_SIZE`: this data is then appended to a static `stash` string until the newline character (`\n`) is found
within the `stash`. This approach minizes the number os calls to the `read` system call.
2. **Line Extraction:** ONCE A NEWLINE IS DETECTED (OR THE END OF THE FILE IS REACHED), A NEW STRING(`LINE`) IS CREATED BY COPYING CHARACTERS FROM THE `STASH` UP TO AND INCLUDING THE `\n`.
3. **Stash Cleanup:** The `stash` is then cleaned by removing the line that was just extracted, retaining any leftover characters for the next call to `get_next_line`.

## Instructions
- You must compile this function with a `main` using the compiler `cc` and the flags `-Wall -Wextra -Werror`.

Example of compilation: `cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c`

If you don`t have valid main to compile this project you can use this example:

<!--int	main(void)
{
	int		fd;
	int		count_line;
	char	*linha = strdup("start");

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Ferrou, deu erro.\n", 17);
		return (1);
	}
	count_line = 1;
	while (linha)
	{
		free(linha);
		linha = get_next_line(fd);
		if (linha)
		{
			printf("Linha %d: %s", count_line, linha);
			count_line++;
		}
	}
	free(linha);
	close(fd);
	return (0);
}-->
*The same method of compilation applies to the bonus part, but with the bonus functions.*

## Resources

For this project I used some tutorials, Youtube videos to understand the behavior of the memory and the Gemini AI to auxiliate the understanding the archteture of the project.

 - Links:
 [VIDEO TUTORIAL](https://www.youtube.com/watch?v=-Mt2FdJjVno&pp=ygUQZ2V0IG5leHQgbGluZSA0Mg%3D%3D)
 [MEMORY MANAGEMENT](https://www.tutorialspoint.com/cprogramming/c_memory_management.htm)
 [VARIAVEIS ESTATICAS](https://www.tutorialspoint.com/cprogramming/c_static_variables.htm)
