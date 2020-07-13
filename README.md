# A While Program Interpreter
An interpreter for while-programs.

## What are while-programs?
While-programs are written in a minimal language that is meant for studying computability. While programs manipulate the contents of variables (with global scope) that contain natural numbers (including 0). The following 3 instructions are used to manipulate variables:

1. `x := CONSTANT` [puts the natural number CONSTANT into the variable `x`.]
2. `x := y + z` [puts the sum of `y` and `z` into `x`. `y` and `z` have to be defined.]
3. `x := y - z` [puts `y - z` into `x`. If `z > y`, then `y - z` is defined to be 0. `y` and `z` have to be defined.]

Besides this there is also the titular while statement. The while statement executes the program in its body as long as the controlling variable is not 0. Essentially, this gives

```
while x != 0 do
  P
od
```

which executes `P` as long as `x != 0`. AWPI omits the implicit `!= 0`, meaning the syntax simplifies to

```
while x do
  P
od
```

While-programs also formalize adjacent lines of code as 'concatenated'. Thus, there exists the concatenation operator

`P;Q` [executes program `P`, then program `Q`]

AWPI simply concatenates succeeding lines of code, so no operator such as `;` is required. This operation is entirely implicit, but it relates to the so-called Gödelisation of while-programs.

## Additional features
* You can import the contents of other scripts by using `#import FILEPATH`. You can also use the prelude scripts by using `#include FILENAME`.
* Variables whose name starts with a `_` are 'hidden' and will not be displayed upon termination.

## Usage
Follow the instructions below to compile the program. Once you have obtained the binary, run it with the path to the source script as a command line argument. If the program terminates it will display an overview of every defined variable and its value.

### Linux
Make a folder called `bin` in the root of the repository and run `make compile`.

### Mac
The above *would* work, except `make compile` uses `g++`, which is an alias for `gcc`, which you may not have. Use your own C++ compiler, or get one, then change the makefile to use that. Instead of changing the makefile, you could also compile `src` manually.

### Windows
1. `constants.hpp` defines `PRELUDE` with `/` as a path delimiter. Likewise, `parser.cpp` uses `root.find_last_of("/")` to find the last path delimiter. Change these to be a sufficiently escaped `\`, which Windows uses as a path delimiter instead.
2. Compile `src` with your C++ compiler of choice.
3. Switch to a better OS.
