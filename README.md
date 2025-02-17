---

---

# get_next_line

## 📚 Description

`get_next_line` is a project at 42 that introduces dynamic file reading in C. The goal is to implement a function capable of reading a file line by line, regardless of the length of the lines or the `BUFFER_SIZE` used for reading.

This project deepens the understanding of **file descriptors**, **static variables**, **dynamic memory management**, and efficient **buffer handling**.

---

## 🚀 Features

`get_next_line` implements the ffollowing functionalities :

### 1. **Dynamic File Reading**
The function `get_next_line(int fd)` is capable of :
- Reading from a **file descriptor (fd)**.
- Extracting **one complete line at a time**, including the newline **(\n)**.
- Managing **multiple file descriptors simultaneously**.
- **Preserving the remainder** of the buffer for the next call.

### 2. **Memory Management**
- Uses **static storage** to retain unprocessed data between function calls.
- Efficiently handles **concatenation of partial reads** with `ft_strjoin()`.
- Uses `ft_memmove()` (or other function) to **shift remaining data** in the buffer after extracting a line.
- Ensures **proper memory allocation and freeing** to prevent leaks.

---

## 📂 Project Structure

### 📝 Main Files
- `get_next_line.c` → Contains the **main function** `get_next_line()`.
- `get_next_line_utils.c` → Includes **helper functions** for memory operations and string handling.

---

![get_next_line_drawio](https://github.com/user-attachments/assets/463c5b55-ac41-499e-8d0e-7cd3d1901576)
