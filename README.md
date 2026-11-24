# pdqsort - Pattern-defeating quicksort C++ library

This is a `build2` package repository for [`pdqsort`](https://github.com/orlp/pdqsort),
a header-only C++ library implementing pattern-defeating quicksort.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`pdqsort` in your `build2`-based project, then instead see the accompanying
[`libpdqsort/PACKAGE-README.md`](libpdqsort/PACKAGE-README.md) file.

The development setup for `pdqsort` uses the standard `bdep`-based workflow.
For example:

```
git clone --recurse-submodules https://github.com/build2-packaging/pdqsort.git
cd pdqsort

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
