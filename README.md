[![Build status](https://ci.appveyor.com/api/projects/status/gl7l5ac5xtei54ha?svg=true)](https://ci.appveyor.com/project/SSE4/strings-h)

header-only Windows implementation of the `<strings.h>` header.

tested on the following compilers:
- Visual Studio
- Clang for Windows (clang-cl)
- GCC (MinGW)

implements the following functions:
- bcmp
- bcopy
- bzero
- explicit_bzero
- index
- rindex
- ffs
- ffsl
- ffsll
- strcasecmp
- strncasecmp
- strcasecmp_l
- strncasecmp_l
