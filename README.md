# Trabalhos_Algotimos

Assignments from the Algorithms course: sorting algorithm implementations in C, timed with `clock()` on generated inputs on several CPUs, with the results plotted.

## Contents

| Files | Content |
|-------|---------|
| `trabalho_0.*.c` | Successive versions of the main assignment program (`trabalho_0.9.9.c` is actually a Windows executable saved with a `.c` extension, not source) |
| `bubblesort.c`, `cocktail_sort.c`, `heapsort.c`, `mergesort.c`, `pancakesort.c`, `quicksort.c`, `quicksort_invertido.c`, `shellshort.c`, `parallelquick.c` | Sorting algorithm implementations (`parallelquick.c` uses OpenMP; build it with `-fopenmp`) |
| `teste*.csv`, `teste*.txt`, `vpsteste.csv`, `teste64bits.csv` | Benchmark inputs and timing results |
| `graficos/` | Results per machine (i5-4670, i7-3610QM, i7-860 overclocked, Intel Dual-Core T4500), MATLAB plotting scripts and notes (`consideracoes.txt`) |
| `algoritimos2/` | Earlier exercises from Algorithms 2 |
| `trabalho.docx` | Assignment report |

## Building

Each `.c` file is a standalone program:

```bash
gcc -Wall bubblesort.c -o bubblesort
```
