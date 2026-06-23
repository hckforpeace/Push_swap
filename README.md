# Push_swap

> Sort a stack of integers using a second stack and a limited set of moves — in as few operations as possible.

Push_swap is a [42 School](https://42.fr) project. The goal is simple to state and surprisingly deep to solve: given a stack `a` of unsorted unique integers and an empty stack `b`, produce the shortest possible list of operations that leaves `a` sorted in ascending order. Only eleven stack operations are allowed, and efficiency is graded by move count.

This implementation models both stacks as **circular doubly-linked lists** and sorts with a **cheapest-insertion (Turk) strategy** that, at each step, computes the move cost of every candidate and applies the cheapest one.

## Features

- **Two binaries** — `push_swap` generates the sorting moves; `checker` (bonus) reads moves on stdin and validates that they sort the stack.
- **Cheapest-insertion algorithm** — each push to `b` and each push back to `a` is chosen by computing the total rotation cost for every element and picking the minimum.
- **Optimized small cases** — 2- and 3-element stacks are hard-coded; larger stacks use the cost-based engine.
- **Strict input validation** — rejects non-integers, duplicates, and `int` overflow before any work begins.
- **Custom libft** — built on a bundled libft (string, list, conversion, and `ft_printf` helpers); no external dependencies beyond libc.

## The allowed operations

| Op | Effect |
|------|--------|
| `sa` / `sb` / `ss` | Swap the top two elements of `a` / `b` / both |
| `pa` / `pb` | Push the top of the other stack onto `a` / `b` |
| `ra` / `rb` / `rr` | Rotate `a` / `b` / both up (first element becomes last) |
| `rra` / `rrb` / `rrr` | Reverse-rotate `a` / `b` / both down (last element becomes first) |

## Getting started

### Prerequisites

- A C compiler (`cc` / `gcc` / `clang`)
- `make`

### Build

```sh
make          # builds push_swap
make bonus    # builds the checker
```

Other targets: `make clean`, `make fclean`, `make re`.

## Usage

Pass the integers to sort as arguments — either as separate arguments or as a single quoted string.

```sh
./push_swap 3 2 1 5 4
# sa
# pb
# ...
```

```sh
./push_swap "3 2 1 5 4"
```

If the input is invalid (non-integer, duplicate, or out of `int` range), the program prints `Error` to stderr. Empty or already-sorted input produces no output.

### Checking the result (bonus)

`checker` reads operations from stdin, applies them to the stack passed as arguments, and prints `OK` if the stack ends up sorted with `b` empty, or `KO` otherwise. Invalid operations produce `Error`.

```sh
./push_swap 3 2 1 5 4 | ./checker 3 2 1 5 4
# OK
```

### Benchmarking

The bundled `rand` helper emits a shuffled sequence of integers, handy for measuring move counts:

```sh
ARG=$(./rand 100); ./push_swap $ARG | wc -l        # moves for 100 numbers
ARG=$(./rand 500); ./push_swap $ARG | ./checker $ARG
```

> [!NOTE]
> `rand` is a prebuilt helper binary, not part of the graded sources. Use it for testing only.

## How it works

```
   stack a                      stack b
 ┌─────────┐                  ┌─────────┐
 │ unsorted│   ──  pb  ──▶    │ staging │
 │  input  │   ◀──  pa  ──    │  area   │
 └─────────┘                  └─────────┘
```

1. **Parse & validate** — arguments are split, checked for valid integers, duplicates, and overflow, then loaded into circular doubly-linked stack `a`.
2. **Trivial cases** — 2 elements swap if needed; 3 elements are sorted by a fixed decision tree (`sort_3`).
3. **Push to `b`** — elements are pushed from `a` to `b`. For each candidate, the cost (`get_price`) is the rotations needed in both stacks to insert it at its target position; the cheapest element (`get_cheapestnumbera`) is moved each round. A "split-half" heuristic lets opposing rotations happen together.
4. **Push back to `a`** — elements return from `b` to `a`, again by cheapest cost, each landing above its correct neighbor so `a` ends fully sorted.

The cost model lives in `src/push_swap.c` and `src/push.c`; the circular-list primitives (swap, push, rotate, length) are in `src/instructions.c` and `src/stack.c`.

## Project structure

```
Push_swap/
├── Makefile
├── Include/
│   └── push_swap.h        # types (t_stack, t_data) and prototypes
├── src/
│   ├── main.c             # entry point, trivial-case dispatch, sort_3
│   ├── parser.c           # input validation and stack construction
│   ├── push_swap.c        # cost model (cheapest insertion)
│   ├── push.c             # move application, push-back phase
│   ├── final_push.c       # final ordering into stack a
│   ├── instructions.c     # the 11 stack operations
│   ├── stack.c            # circular doubly-linked list helpers
│   ├── utils.c / utils2.c # index/min/max/absolute helpers
│   ├── display.c          # debug stack printing
│   └── main_bonus.c       # checker entry point
├── libft/                 # bundled standard library
└── rand                   # prebuilt random-sequence generator (testing)
```

## Resources

- [Push_swap subject (42 norm)](https://github.com/42School) — official project specification
- [The Turk algorithm explained](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) — background on the cheapest-insertion strategy
