There sub commands list

We have global buffer that we can manipulate with sub commands and i/o

| Command         | Behavior                                                |
| --------------- | ------------------------------------------------------- |
| `a`             | Puts cursor after cursor and reads until `.`            |
| `i`             | Puts cursor before cursor and reads until `.`           |
| `w`             | Write contents of buffer to file                        |
| `f file` or `f` | Sets remembered file or prints remembered file name     |
| `e file` or `e` | Replaces buffer with content of file or remembered file |
| `r file` or `r` | Appends content of file or remembered file after cursor |
| `w file` or `w` | Write to file or remembered file                        |
| `1-$`           | Puts cursor to given index                              |

* All commands with `file` specification replaces remembered file with `file`
* `$` - `len(buffer) - 1`
