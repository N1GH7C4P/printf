# ft_printf

A Hive Helsinki school project where the aim is to recreate c standard library function 'printf'.
https://cplusplus.com/reference/cstdio/printf/

The Makefile compiles a static library file called 'ftprintflib.a'.

To use the library file include it like any static lib (omitting the .a and lib parts) like so:

```
gcc <your src files> -L ftprintf
```
