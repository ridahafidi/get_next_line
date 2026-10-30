# Get Next Line (GNL)

A file-reading function developed as part of the 42 curriculum.

The objective of this project is to implement a function that reads and returns one line at a time from a file descriptor, handling buffered input efficiently while preserving unread data between successive calls.

## 🛠️ Technologies

- **Language:** C
- **System Calls:** `read()`
- **Memory Management:** `malloc()`, `free()`
- **Storage:** Static variables
- **Build System:** Makefile
- **Environment:** Linux / Unix

## ⚙️ Implementation

Implemented `get_next_line()` to retrieve individual lines from a file descriptor, regardless of the underlying input source.

### Core Features

- Reads input incrementally using a configurable buffer size.
- Returns one line per function call.
- Preserves remaining buffered data between successive calls.
- Handles newline characters and end-of-file conditions.
- Manages dynamically allocated memory.
- Supports different file descriptors.
- Handles invalid file descriptors and reading errors.

### Function Prototype

```c
char *get_next_line(int fd);
```

The function returns:
- A dynamically allocated string containing the next line, including `\n` when present.
- `NULL` when there is nothing left to read or an error occurs.

## 🧠 Concepts Explored

- File descriptors and low-level I/O.
- Buffered reading and system calls.
- Static variables and persistent state.
- Dynamic memory allocation.
- String manipulation and concatenation.
- Buffer management.
- Memory leaks and resource cleanup.
- End-of-file and error handling.

## 🚀 Compilation

Clone the repository:

```bash
git clone <repository-url>
cd get_next_line
```

Compile your source files:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c main.c -o gnl
```

Run:

```bash
./gnl
```

To test with a file:

```bash
./gnl < input.txt
```

## 🎯 Learning Objectives

- Understand how low-level file reading works.
- Learn to manage persistent data using static variables.
- Implement efficient buffered input.
- Develop a deeper understanding of dynamic memory management.
- Handle multiple file descriptors and edge cases.

## 👨‍💻 Author

**Rida Hafidi**

- GitHub: [@ridahafidi](https://github.com/ridahafidi)
- LinkedIn: [Rida Hafidi](https://www.linkedin.com/in/rida-hafidi-8b7a47420/)

---

*One file descriptor, one line at a time.*
