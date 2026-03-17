*This project has been created as part of the 42 curriculum by \<dstumpf\>.*

# Pipex 
## Description
Pipex is a systems programming project designed to help understand Unix process management and inter-process communication (IPC). 

The core objective is to replicate the functionality of a shell pipeline (e.g., < file1 cmd1 | cmd2 > file2).

### Core Technical Concepts

    pipe(): Creates a unidirectional data channel that allows one process to send data to another.

    fork(): Spawns child processes, enabling the "simultaneous" execution of different commands.

    dup2(): Used to redirect standard input (stdin) and standard output (stdout) to specific file descriptors.

    execve(): Replaces the current process image with a new program, allowing the execution of Unix commands.

## Instructions
### Requirements
- **Linux**
- **clang** (```sudo apt install clang```)
- **make** (```sudo apt install make```)

### Compilation
- ```make``` will compile the binary
- ```make clean``` will remove all object and dependency files
- ```make fclean``` will clean and remove the binary
- ```make re``` will run fclean and then make
- ```make bonus``` will compile the bonus binary (also named pipex)

### Execution
After compiling with make, the executable takes 5 arguments. The program opens the input file, creates two child processes communicating via a pipe, and opens the output file in truncate mode (creating it if necessary). 
- ```./pipex infile cmd1 cmd2 outfile```      

After compiling with make bonus, the executable takes 5 or more arguments: 
- ```./pipex infile cmd1 cmd2 ... cmdn outfile``` 
- ```< infile cmd1 | cmd2 | ... | cmdn > outfile``` 

Alternatively, it can take a heredoc, in which case the output file is opened in append mode:
- ```./pipex here_doc LIMITER cmd1 cmd2 ... cmdn outfile``` 
- ```<< LIMITER cmd1 | cmd2 | ... | cmdn >> outfile``` 

## Resources
- For understanding redirections, the [Bash manual](https://www.gnu.org/software/bash/manual/bash.html#Redirecting-Input) was used.
- For understanding processes on Linux, [Core Dumped's YouTube video](https://www.youtube.com/watch?v=SwIPOf2YAgI) was used.
