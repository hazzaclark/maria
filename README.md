# maria
Lightweight Hitachi SuperH2 Emitter/Generator

# Motive:

The ambition behind this project is to uncover the intrinsic properties of the Hitachi SuperH2, in regards to how it handles it's innate functionality. Through this, I aim to provide a standalone reference solution for being able to dynamically assemble and generate code in-memory at runtime.

This reference utility, created in the C++17 standard, aims to provide liaise in uncovering the enigmatic problems that come about with dynamic recompilation for the Hitachi SuperH2, hopefully aiding in subsequent developments.

# Usage:

So far, this project is still very much a WIP though, I am to provide some API examples of working with the Code Generator to showcase the likeness.

The following aims to showcase the innate design of how I am able to access register values using the operators defined per the API

```cpp
using namespace maria;

int main(void)
{
    std::printf("HARRY CLARK - SH2 EMITTER\n");

    // ACCESS THE VALUE FOR R0
    maria::GP_REGISTER SH2_R0(0);
    std::printf("R0 VALUE: %d\n", SH2_R0.GET_INDEX());

    // ACCESS THE VALUE FOR PC
    maria::PC SH2_PC;
    std::printf("PC VALUE: %d\n", SH2_PC.GET_INDEX());
    
    return 0;
}
```

# Building:

To build this project, you will need a C++ compiler which supports CMake 3.20. From there, it is just a case of:

```
mkdir build && cd build

cmake ..
```

# Sources:

[SH2 PROGRAMMER MANUAL](https://antime.kapsi.fi/sega/files/h12p0.pdf)

[SH2 REGISTERS](https://bitsavers.trailing-edge.com/components/hitachi/superH/1995_SH1_SH2_Programming_Manual_3rd_Edition.pdf)
