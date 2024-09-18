# About

The purpose of this project is to code a small data exchange program using *UNIX signals*. \
Keep in mind:
- You have to handle errors sensitively. In no way can your program quit unexpectedly (Segmentation fault, bus error, double free, etc).
- Your program cannot have memory leaks.
- You can use one global variable but it must be justified.

## Mandatory

- Produce `server` & `client` executables
- `client` must communicate a string passed as a parameter to `server` *(referenced by its process ID)* which then displays it
- Use `SIGUSR1` & `SIGUSR2` signals **ONLY**

## Bonus

- Add reception acknowledgement system
- Support Unicode characters
