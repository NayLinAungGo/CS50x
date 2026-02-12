# Section 4
## Pointers
### Pointer Syntax

**`type \*`** is a pointer that stores the address of **`type`**

**`&x`** gets its address of **`x`**

**`\*x`** goes to the address stored at the pointer **`x`**

## File I/O
### `fopen`

```c
FILE *fopen(const char *pathname, const char *mode);
```

Opens a file, `pathname`. Supported values for mode include

* "`r`", to read from file
* "`w`", to write to file
* "`a`", to append to file

**Return Value:** when successful, returns a pointer to a `FILE` representing the opened file or,
in case of error (as when pathname doesn't exist), `NULL`

### `fread`

```c
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
```

Reads data from a file that has been opened via `fopen`.
It expects as input:

* `ptr`: address (of the first byte) of memory into which to read the data
* `size`: size (in bytes) of the type of data to read
* `nmemb`: number of those types to read at once
* `stream`: pointer to a `FILE` returned by `fopen`

**Return Value:** when successful, returns the **number of items read**.
If an error occurs, or the end of the file is reached,
returns a value smaller than `nmemb` or even 0.

### `fwrite`

```c
size_t fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
```

Writes data to a file that has been opened via `fopen`.
It expects as input:

* `ptr`: address (of the first byte) of memory into which to write the data
* `size`: size (in bytes) of the type of data to write
* `nmemb`: number of those types to write at once
* `stream`: pointer to a `FILE` returned by `fopen`

**Return Value:** when successful, returns the **number of items written**.
If an error occurs, returns a value smaller than `nmemb` or even 0.
