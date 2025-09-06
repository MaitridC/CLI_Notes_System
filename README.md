# Notes Project

A command-line notes application built with C++ and managed with a `Makefile`. This guide provides an overview of the project's architecture, build process, and conventions.

-----

### Project Architecture

The project adheres to a standard C++ directory structure, separating source code from compiled artifacts and headers to ensure a clean, maintainable, and scalable codebase.

  * `src/`: Contains all `.cpp` source files, which hold the implementation details of classes and functions.
  * `include/`: Contains all `.h` header files, which declare the public interfaces of classes and functions. This separation simplifies dependencies and enhances modularity.
  * `obj/`: Serves as the designated output directory for all compiled object files (`.o`). This isolates intermediate build products from the source code.
  * `build/`: The target directory for the final compiled executable. This ensures the output is easily locatable and separate from the rest of the project.
  * `Makefile`: The project's build automation script. It orchestrates the compilation and linking process, managing dependencies and providing standard build targets.

-----

### Build Process

The project utilizes the `make` utility for an automated and reproducible build process.

1.  **Compile:** The `make` command compiles each `.cpp` file into an individual object file (`.o`), placing them within the `obj/` directory.
2.  **Link:** After all source files are compiled, the object files are linked together to form the final executable.
3.  **Output:** The final executable, named `Notes`, is placed in the `build/` directory.

To build the project from the root directory, simply execute:

```bash
make
```

### Path Management and Headers

The `Makefile` is configured to simplify include paths, streamlining the development process. Developers should use simplified include statements that reference only the header file's name.

**Incorrect:**

```cpp
#include "../src/main/c++/Note.h"
```

**Correct:**

```cpp
#include "Note.h"
```

This convention, facilitated by the `Makefile`'s include path settings, eliminates the need for complex relative paths and promotes code portability. This change should be applied across all source (`.cpp`) and header (`.h`) files in the project.

-----

### Cleaning the Project

To remove all compiled files and other build artifacts, execute the `clean` target in the `Makefile`. This is useful for starting a fresh build or for preparing the repository for a clean commit.

```bash
make clean
```
