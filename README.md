# Unix Programming Examples

A collection of C programs demonstrating Unix/Linux system programming concepts and techniques.

## About

This repository contains selected programs from:
- **"Advanced Programming in the UNIX Environment"** by W. Richard Stevens and Stephen A. Rago
- **"The Design of the UNIX Operating System"** by Maurice J. Bach

The examples cover fundamental Unix system calls, process management, file I/O, inter-process communication, and other low-level programming concepts.

## Prerequisites

- GCC or any C compiler
- Unix-like operating system (Linux, macOS, BSD, etc.)
- Basic knowledge of C programming
- Understanding of Unix/Linux system concepts

## Getting Started

### Building Programs

Each program can be compiled using GCC:

```bash
gcc -o program_name program_name.c
./program_name
```

For programs requiring specific libraries or flags, refer to comments in the source files.

## Project Structure

```
unix-batch2/
├── [contributor-name]/     # Individual contributor folders
│   └── *.c                 # C source files
└── README.md
```

## Contributing

We welcome contributions from anyone interested in Unix system programming!

### How to Contribute

1. **Fork this repository**
2. **Create a folder with your name** in the root directory
3. **Add your C programs** to your folder
4. **Commit your changes** with clear, descriptive commit messages
5. **Submit a Pull Request**

### Contribution Guidelines

Your PR will be rejected if it contains:

- Object files (`.o`), binaries, or compiled executables
- Sensitive information (passwords, private keys, email addresses, tokens)
- Large files (PDFs, audio/video files)
- Plagiarized code or code without proper attribution

### Best Practices

- Include comments explaining what your program demonstrates
- Add a brief description at the top of each file
- Ensure your code compiles without errors
- Test your programs before submitting
