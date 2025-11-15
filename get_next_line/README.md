# 42 Project: get_next_line

![42 Badge](https://img.shields.io/badge/42-Project-00B2GW?style=for-the-badge)
![Score Badge](https://img.shields.io/badge/Score-125%25-brightgreen?style=for-the-badge)

`get_next_line` is a C function that reads a line from a file descriptor, handling memory and buffering efficiently. This project is a core part of the 42 curriculum, designed to teach static variables, buffer management, and file descriptor manipulation.

## Key Concepts

This project is a classic exercise in C programming that focuses on:

* **Static Variables:** Using a `static` variable to maintain data (like a "leftover" buffer) between function calls.
* **Buffer Management:** Reading data in fixed chunks (defined by `BUFFER_SIZE`) from a file descriptor.
* **Memory Allocation:** Dynamically allocating, reallocating, and freeing memory for the line being built.
* **File Descriptors:** Working with file descriptors, including `stdin` (0) and any file opened with `open()`.

---

## 🏆 Bonus: Multiple File Descriptors

This implementation successfully passed the bonus part, achieving a final score of **125/100**.

The bonus challenge requires `get_next_line` to manage **multiple file descriptors** simultaneously without losing the reading "state" of any of them.

This implementation achieves this by using a **static array of character pointers** (e.g., `static char *buffer[1024]`). The file descriptor `fd` is used as the index for this array to access and store the unique "leftover" data for each file. This ensures that no data is mixed up between `read()` calls on different files.

You can do the following, and the function will work correctly:

1.  Read a line from `fd1`.
2.  Read a line from `fd2`.
3.  Read the *next* line from `fd1`.
4.  Read the *next* line from `fd2`.

---

## 🛠 How to Use

### 1. Clone the Project
You have two options to get the code. Choose the one that fits your needs.

#### Option A: Clone *Only* This Project (Sparse Checkout)
This project is part of a larger `1337-projects` repository. To clone *only* the `get_next_line` folder, follow these steps using Git's **sparse-checkout** feature.

```bash
# 1. Clone the repo without checking out any files
git clone --depth 1 --no-checkout https://github.com/Mustapha-Nkhili/1337-projects.git
cd 1337-projects

# 2. Initialize sparse-checkout
git sparse-checkout init --cone

# 3. Set git to only pull the 'get_next_line' folder
git sparse-checkout set get_next_line

# 4. Pull the files
git checkout main
```
You will now have a 1337-projects directory that contains only the get_next_line folder. Then, cd get_next_line.

#### Option B: Clone All Projects (Full Clone)
if you want to clone all my 1337/42 projects in the repository (including this one), use a standard git clone.
```bash
# 1.Clone the repo
git clone https://github.com/Mustapha-Nkhili/1337-projects.git

# 2.Then navigate into this project's folder
cd 1337-projects/get_next_line
```
### 2. Compile Your Program

```bash
# Compile with a specific buffer size (e.g., 1337)
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1337 main.c get_next_line.c get_next_line_utils.c
```
### 3. Example main.c
Here is a simple main.c to read every line from a file named test.txt
```c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int     fd;
    char    *line;

    // Open the file
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error: Could not open file.\n");
        return (1);
    }

    // Read lines one by one
    // get_next_line returns NULL when it's done or an error occurs
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // The line returned by gnl is malloc
    }

    // Close the file
    close(fd);
    return (0);
}
```
