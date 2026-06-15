# C Exercises — Advanced Programming

A repository of hands-on labs to deepen your **C and C++** skills beyond the basics: dynamic memory, concurrency, generic data structures, networking, compilation, dynamic plugins, and signal processing. Each exercise includes an objective, requirements, concepts to practice, a suggested approach, and extension ideas.

Ideal for those who already master syntax and types and want to practice **low-level software engineering** with guided projects of increasing complexity.

---

## Table of Contents

- [Overview](#overview)
- [Prerequisites](#prerequisites)
- [Repository Structure](#repository-structure)
- [Exercise Track](#exercise-track)
- [How to Study Each Lab](#how-to-study-each-lab)
- [Included Solutions](#included-solutions)
- [Concept Map](#concept-map)
- [Recommended Tools](#recommended-tools)
- [Contributing](#contributing)
- [License](#license)

---

## Overview

| Aspect | Description |
|--------|-------------|
| **Format** | 10 exercise prompts in Markdown (`01`–`10`) |
| **Languages** | C (primary focus) and C++ (reference solution for exercise 1) |
| **Level** | Intermediate to advanced |
| **Solutions** | Partial — [Exercise 1](SOLUTIONS/01-enhanced-text-adventure/) implemented |
| **Goal** | Consolidate topics typical of systems, algorithms, and software engineering |

The exercises are designed as a **progression**: they begin with I/O, memory, and modularization; move on to parsing, synchronization, and generic structures; and culminate in compilation, plugins, and real-time processing.

---

## Prerequisites

- **GCC** or **Clang** compiler (`gcc`, `g++`)
- `make` and basic build tools
- Familiarity with pointers, structs, and dynamic allocation
- For specific exercises:
  - **Threads**: POSIX threads (`pthread`) or equivalent
  - **Networking**: BSD sockets (Linux/macOS) or Winsock (Windows)
  - **Plugins**: `dlopen` / `dlsym` (POSIX) or `LoadLibrary` (Windows)
  - **Memory**: Valgrind or AddressSanitizer (recommended for exercise 3)
  - **Audio/signals** (exercise 10): basic knowledge of sampling and digital filters

---

## Repository Structure

```
C-Exercises/
├── README.md                          # This file
├── 01-enhanced-text-adventure.md      # Text adventure with dynamic memory
├── 02-expression-evaluator.md         # Calculator with operator precedence
├── 03-memory-management-lab.md        # Memory management laboratory
├── 04-concurrent-dining-philosophers.md
├── 05-generic-data-structures.md
├── 06-finite-state-machine-compiler.md
├── 07-networked-chat-application.md
├── 08-simple-language-compiler.md
├── 09-plugin-system.md
├── 10-real-time-signal-processing.md
└── SOLUTIONS/
    └── 01-enhanced-text-adventure/    # Reference solution (C++)
        ├── src/
        ├── locations.txt
        ├── items.txt
        ├── Makefile
        └── README.md
```

Each `NN-name.md` file in the root is a **self-contained exercise prompt**. Implement your code in your own folders (e.g., `my-work/02-evaluator/`) or contribute new solutions to `SOLUTIONS/`.

---

## Exercise Track

### 01 — Enhanced Text Adventure

**File:** [`01-enhanced-text-adventure.md`](01-enhanced-text-adventure.md)

Extend a text-based world with **dynamic memory**, file-based location loading, inventory, NPCs, and save/load.

| Topics | File I/O, `malloc`/`realloc`/`free`, structs, modularization |
| Difficulty | ★★☆☆☆ |

---

### 02 — Expression Evaluator

**File:** [`02-expression-evaluator.md`](02-expression-evaluator.md)

Command-line calculator with `+`, `-`, `*`, `/`, `%`, parentheses, integers, and floating point, respecting **precedence and associativity**.

| Topics | Shunting Yard or recursive descent, stacks, expression trees |
| Difficulty | ★★★☆☆ |

---

### 03 — Memory Management Laboratory

**File:** [`03-memory-management-lab.md`](03-memory-management-lab.md)

Custom allocator (first-fit, best-fit), demonstrations of leaks, buffer overflow, use-after-free, double free, and a simple **garbage collector**.

| Topics | Memory safety, pools, Valgrind/ASan |
| Difficulty | ★★★★☆ |

---

### 04 — Dining Philosophers (Concurrency)

**File:** [`04-concurrent-dining-philosophers.md`](04-concurrent-dining-philosophers.md)

Implement the classic problem with threads, avoiding **deadlock** and **starvation**; compare mutex, semaphores, and resource hierarchy.

| Topics | `pthread`, mutex, semaphores, race conditions |
| Difficulty | ★★★★☆ |

---

### 05 — Generic Data Structures Library

**File:** [`05-generic-data-structures.md`](05-generic-data-structures.md)

Linked list, hash table, and binary search tree using **`void*`** and **function pointers** for compare/copy/free.

| Topics | Generic programming in C, callbacks, rehash |
| Difficulty | ★★★★☆ |

---

### 06 — Finite State Machine Compiler

**File:** [`06-finite-state-machine-compiler.md`](06-finite-state-machine-compiler.md)

A language for describing FSMs and **C code generation** (transition table, entry/exit actions, guards).

| Topics | Lexer, parser, code generation, automata |
| Difficulty | ★★★★★ |

---

### 07 — Networked Chat

**File:** [`07-networked-chat-application.md`](07-networked-chat-application.md)

Multi-client TCP server, public rooms, private messages, and basic authentication.

| Topics | Sockets, `select`/`poll` or threads, application protocol |
| Difficulty | ★★★★☆ |

---

### 08 — Simple Language Compiler

**File:** [`08-simple-language-compiler.md`](08-simple-language-compiler.md)

Minimal language with expressions, assignments, `if`/`else`, `while`, and `print`; **lexer → parser → semantic analysis → code generation** pipeline.

| Topics | AST, semantic analysis, assembly or bytecode generation |
| Difficulty | ★★★★★ |

---

### 09 — Plugin System

**File:** [`09-plugin-system.md`](09-plugin-system.md)

Host application that loads extensions at runtime via **`dlopen`** / **`dlsym`** (or Windows API), with versioning and discovery.

| Topics | Dynamic libraries, function pointer interfaces |
| Difficulty | ★★★★☆ |

---

### 10 — Real-Time Signal Processing

**File:** [`10-real-time-signal-processing.md`](10-real-time-signal-processing.md)

FIR/IIR filters, FFT, audio effects, and block-based processing with latency measurement.

| Topics | DSP, numerical methods, optimization, and visualization |
| Difficulty | ★★★★★ |

---

## How to Study Each Lab

1. **Read the exercise prompt** — objective, requirements, and suggested approach.
2. **Define the scope** — implement the required features before the extensions.
3. **Prototype in C** — most exercises call for pure C; use C++ only if it makes sense for you.
4. **Test incrementally** — one requirement per commit makes review and debugging easier.
5. **Document decisions** — a short `README` in your solution folder helps with review.
6. **Compare with the reference solution** (when available) after trying on your own.

Suggested order for beginners: `01 → 02 → 03 → 05 → 04 → 07 → 09 → 06 → 08 → 10`.

---

## Included Solutions

### Exercise 1 — Enhanced Text Adventure (C++17)

Location: [`SOLUTIONS/01-enhanced-text-adventure/`](SOLUTIONS/01-enhanced-text-adventure/)

Modular implementation with file-based location and item loading, inventory, and save/load commands.

**Build and run:**

```bash
cd SOLUTIONS/01-enhanced-text-adventure
make
make run
```

**In-game commands:** `look`, `go <location>`, `inventory`, `take <item>`, `drop <item>`, `save`, `load`, `help`, `quit`.

Details on file formats (`locations.txt`, `items.txt`) and architecture are in the [solution README](SOLUTIONS/01-enhanced-text-adventure/README.md).

> **Note:** The reference solution uses STL containers (`vector`, `unordered_map`), which handle dynamic memory behind the scenes. To align with the original exercise prompt in pure C, reimplement using `malloc`/`realloc`/`free` and structs.

---

## Concept Map

```mermaid
flowchart LR
    subgraph Fundamentals
        A[01 Text Adventure]
        B[02 Expression Evaluator]
        C[03 Memory Lab]
    end
    subgraph Structures and Concurrency
        D[05 Generic DS]
        E[04 Dining Philosophers]
    end
    subgraph Systems
        F[07 Network Chat]
        G[09 Plugin System]
    end
    subgraph Compilation and DSP
        H[06 FSM Compiler]
        I[08 Simple Compiler]
        J[10 Signal Processing]
    end
    A --> B --> C
    C --> D
    C --> E
    D --> H
    D --> I
    E --> F
    F --> G
    H --> I
    B --> J
```

| Exercise | Core Concepts |
|----------|---------------|
| 01 | I/O, dynamic memory, modularization |
| 02 | Parsing, stacks, precedence |
| 03 | Allocators, safety, GC |
| 04 | Threads, deadlock, starvation |
| 05 | `void*`, function pointers, ADTs |
| 06 | Lexer, parser, code generation |
| 07 | TCP, concurrency, protocols |
| 08 | AST, semantics, compilers |
| 09 | `dlopen`, extensibility |
| 10 | FFT, filters, real-time |

---

## Recommended Tools

| Tool | Usage |
|------|-------|
| **GCC / Clang** | Compilation with `-Wall -Wextra -pedantic` |
| **Valgrind** (`memcheck`) | Leaks and heap errors (e.g., exercise 03) |
| **AddressSanitizer** | `-fsanitize=address` in debug builds |
| **GDB / LLDB** | Step-by-step debugging |
| **pthread** | Exercise 04 |
| **Wireshark** (optional) | Inspect chat traffic (exercise 07) |
| **flex/bison** (optional) | Speed up lexer/parser in exercises 06 and 08 |

---

## Contributing

Contributions are welcome:

1. Fork the repository.
2. Create a branch for your feature or solution (`git checkout -b solution/02-evaluator`).
3. Add code in `SOLUTIONS/NN-name/` with a `README`, `Makefile`, and build instructions.
4. Open a Pull Request describing what was implemented and how to test it.

Priority for new solutions: exercises **02** through **10** still lack a reference implementation.

---

## License

This repository is educational material. Consult the repository author for specific terms of use. By contributing, you agree to license your contributions under the same terms as the project.

---

**Author:** [douglasrocha91](https://github.com/douglasrocha91)

If this material was helpful, consider starring the repository and sharing it with anyone learning systems programming in C.
