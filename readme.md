# Get Next Line (GNL)

## Overview

`get_next_line` is a C function that allows reading a file descriptor line by line. It includes both a mandatory and a bonus implementation. The function efficiently handles memory and buffering to return one line per call, including the newline character (`\n`) if present.

## Features

- **Dynamic Memory Management**: Handles variable-length lines using custom memory management functions.
- **Efficient Buffering**: Utilizes a static buffer for optimal performance when reading files.
- **Error Handling**: Includes robust error checking to manage invalid inputs or memory allocation failures.
- **Bonus Feature**: Supports multiple file descriptors simultaneously.

## How It Works

1. **File Reading**:
   - Reads data from the file descriptor in chunks of `BUFFER_SIZE` until a newline or the end of the file is found.

2. **Line Extraction**:
   - Extracts the current line from buffered data.

3. **Static Buffer Update**:
   - Updates the static buffer to retain remaining data after the current line.

4. **Bonus**:
   - Implements an array of static buffers to handle up to 1024 file descriptors simultaneously.

5. **Memory Management**:
   - Uses custom functions for memory allocation (`gnl_ft_calloc`), string joining (`gnl_ft_strjoin`), and string manipulation.
