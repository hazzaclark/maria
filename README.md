# maria
Lightweight Hitachi SuperH2 Emitter/Generator

# Motive:

The ambition behind this project is to uncover the intrinsic properties of the Hitachi SuperH2, in regards to how it handles it's innate functionality. Through this, I aim to provide a standalone reference solution for being able to dynamically assemble and generate code in-memory at runtime.

This reference utility, created in the C++17 standard, aims to provide liaise in uncovering the enigmatic problems that come about with dynamic recompilation for the Hitachi SuperH2, hopefully aiding in subsequent developments.

# Usage:

So far, this project is still very much a WIP though, I am to provide some API examples of working with the Code Generator to showcase the likeness.

# Building:

To build this project, you will need a C++ compiler which supports CMake 3.20. From there, it is just a case of:

```
mkdir build && cd build

cmake ..
```

# Sources:

[SH2 PROGRAMMER MANUAL](https://antime.kapsi.fi/sega/files/h12p0.pdf)

[SH2 REGISTERS](https://bitsavers.trailing-edge.com/components/hitachi/superH/1995_SH1_SH2_Programming_Manual_3rd_Edition.pdf)
