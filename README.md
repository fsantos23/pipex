# 📡 Pipex

A program that mimics shell pipe behavior (|), implementing Unix process management and file handling.

## 🔍 Overview

```bash
# Shell command:
< infile cmd1 | cmd2 > outfile

# Pipex equivalent:
./pipex infile "cmd1" "cmd2" outfile
```

## 🛠️ Features

- Handles multiple pipes
- Supports input/output redirection
- Error management
- Memory leak prevention
- Bonus: Multiple pipes (n commands)
- Bonus: Here_doc support

## 📋 Usage

```bash
# Basic usage
./pipex infile "ls -l" "wc -l" outfile

# Multiple commands (bonus)
./pipex infile "ls -l" "grep .c" "wc -l" outfile

# Here_doc (bonus)
./pipex here_doc LIMITER "cmd1" "cmd2" outfile
```

## ⚙️ Implementation Details

### Core Functions
```c
// Process handling
pid_t fork(void);
int pipe(int pipefd[2]);
int dup2(int oldfd, int newfd);
int execve(const char *pathname, char *const argv[], char *const envp[]);

// File operations
int open(const char *pathname, int flags);
void exit(int status);
```

## 🚀 Installation

```bash
git clone https://github.com/[your-username]/pipex.git
cd pipex
make
```

## 🧪 Testing

```bash
# Basic test
./pipex infile "grep a" "wc -l" outfile

# Compare with shell
< infile grep a | wc -l > outfile_shell
diff outfile outfile_shell

# Memory test
valgrind ./pipex infile "ls -l" "wc -l" outfile
```

## ⚠️ Error Handling

- Command not found
- Permission denied
- File access errors
- Pipe creation failures
- Fork errors
- Memory allocation failures

## 🎯 Learning Objectives

- Process creation and management
- File descriptors and redirection
- Pipe communication
- Error handling
- Memory management
- Command execution

## 📚 Resources

- Unix Processes
- File Descriptors
- Pipes and FIFOs
- Environment Variables
- execve and fork

## ⭐ Show your support

Give a ⭐️ if this project helped you!
