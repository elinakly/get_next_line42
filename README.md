# Get_next_line

Get_next_line is a School 42 project that involves implementing a function to read a line from a file descriptor. The function must handle reading efficiently and work with multiple file descriptors when the bonus part is completed.

## Project Details
- **Score**: 125/100 (Bonus completed)
- **Language**: C

This repository includes both the mandatory implementation and the bonus functionality for handling multiple file descriptors.

## Features
- Reads a single line from a file descriptor, including `\n`.
- Handles edge cases such as empty files and extremely long lines.
- Bonus: Supports multiple file descriptors simultaneously.

## Installation
1. Clone the repository:
   ```bash
   git clone <repository_url>
   ```
2. Navigate to the project directory:
   ```bash
   cd get_next_line42
   ```

## Usage
1. Since there is no Makefile included, compile the files manually. For example:
```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl
```

2. Create a your_file.txt and change the name in my main to run the program
  fd1 = open("your_file.txt", O_RDONLY);
3. Run the program:
```bash
./gnl
```


Feel free to contribute or provide feedback on this repository!

