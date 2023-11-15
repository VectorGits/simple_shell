# Enhanced Command-Line Interface: Unix Simple Shell

Engineered by Daniel Oluremi as an integral component of the ALX educational platform, the Enhanced Unix Simple Shell project is designed to go beyond merely replicating the functionality of the native Unix shell (`/bin/sh`). It not only satisfies certain essential criteria but also integrates several advanced features, offering a more robust and efficient command-line interaction experience.

## Core Development Team

- **David Oluremi**

## Detailed Features and Functional Capabilities

### Initial Release: Simple Shell 0.1

At this stage, the shell focuses on foundational capabilities. It displays a prompt and waits for the user to input a command. Only single-word commands are processed at this point, without any arguments or special characters. Should an executable not be located, the shell returns an error message but proceeds to display the next prompt. It also accommodates the "end of file" condition, typically invoked by `Ctrl+D`, and manages errors gracefully.

### Version Update: Simple Shell 0.2

Building upon its foundational features, this version introduces support for command-line arguments. The shell now recognizes not just single-word commands but also their accompanying arguments.

### Feature-Rich Update: Simple Shell 0.3

This iteration advances the shell's complexity by incorporating the `PATH` environment variable. It also introduces an optimization: the shell refrains from invoking `fork` if the command entered does not exist.

### Version: Simple Shell 0.4

At this stage, the shell gains the capability to terminate itself via the built-in `exit` command. It does so without requiring any additional arguments.

### Stable Release: Simple Shell 1.0

This version brings in the `env` built-in command, which prints out the current environment variables when invoked.

### Efficient Input: Simple Shell 0.1.1

Focused on efficiency, this update includes a custom `getline` function that uses a buffer to read multiple characters at once, thus reducing the number of system calls. The standard getline function is no longer used.

### Improved Tokenization: Simple Shell 0.2.1

This version further optimizes input processing by avoiding the use of `strtok` for tokenizing input, adhering to guidelines for optimized system calls.

### Extended Exit Command: Simple Shell 0.4.1

An extension to the existing `exit` functionality is introduced here. Now the shell can accept an integer `status` as an argument when exiting.

### Environment Control: Setenv and Unsetenv

This feature set adds two new built-in commands, `setenv` and `unsetenv`, allowing the user to initialize, modify, or remove environment variables.

### Directory Navigation: CD Command

In this phase, the `cd` built-in command is implemented. It changes the current directory of the process and supports features like `cd DIRECTORY` and `cd -`, which returns to the previous directory. Additionally, it updates the `PWD` environment variable.

### Command Sequencing: Semicolon Support

Here, the shell gains the ability to handle command separators (`;`), allowing for the execution of multiple commands within a single input line.

### Conditional Execution: Logical Operators

This version enables the shell to interpret logical operators like `&&` and `||`, thus supporting conditional execution of commands based on the success or failure of previous commands.

### Command Alias Management: Alias Command

This feature introduces the `alias` built-in command, empowering users to create and manage command shortcuts or aliases.

### Variable Substitution

This upgrade brings in the ability to handle variable replacement dynamically, including the incorporation of special variables like `$?` and `$$`.

### Comment Handling

The shell now recognizes comments. Any input line starting with `#` is treated as a comment and is not executed.

### File-Driven Execution

In this advanced feature set, the shell is equipped to read commands from a file passed as a command-line argument. It reads and executes these commands one per line. During this operation, the shell neither displays a prompt nor reads from stdin.

## Compilation Instructions

Execute the following command for compilation:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Acknowledgments

Special acknowledgment goes to our mentors and the educational cadre at the ALX program for their invaluable support and guidance. A big shoutout to all contributors and colleagues who have written code, submitted issues, or provided indispensable feedback.

## Frequently Asked Questions (FAQs)

- **Q: How do I compile the code?**
  - **A:** Execute `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`.

- **Q: What commands are currently supported?**
  - **A:** Refer to the "Detailed Features and Functional Capabilities" section of the README for a comprehensive list of supported commands and features.

- **Q: I've found a bug, where should I report it?**
  - **A:** Please file an issue on the GitHub project page.

- **Q: Does the shell support scripting?**
  - **A:** Yes, the shell can execute commands from a file passed as a command-line argument.

- **Q: How can I reach you?**
  - **A:** Reach me via:
	   - LinkedIn: [David Oluremi](https://www.linkedin.com/in/vect0r/)
	   - Twitter: [Vector Twits](https://twitter.com/Vector_twits)
