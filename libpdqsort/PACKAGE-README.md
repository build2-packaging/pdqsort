# libpdqsort - Pattern-defeating quicksort C++ library

This is a `build2` package for the [`pdqsort`](https://github.com/orlp/pdqsort)
C++ library. It provides pattern-defeating quicksort (pdqsort), a novel
sorting algorithm that combines the fast average case of randomized
quicksort with the fast worst case of heapsort, while achieving linear time
on inputs with certain patterns. It is a drop-in replacement for
`std::sort`.

This package tracks upstream commit `b1ef26a` (2021-03-14) as version
`0.0.1`. Upstream does not publish releases.


## Usage

To start using `libpdqsort` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libpdqsort ^0.0.1
```

Then import the library in your `buildfile`:

```
import libs = libpdqsort%lib{pdqsort}
```


## Importable targets

This package provides the following importable targets:

```
lib{pdqsort}
```

A single header-only (binless) library target. Include `<pdqsort.h>` to use
`pdqsort()` and `pdqsort_branchless()`.


## Configuration variables

This package provides no configuration variables.
