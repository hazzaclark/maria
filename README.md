# maria
Lightweight Hitachi SuperH2 Emitter/Generator `````(reference use only)`````


# Motive:

The ambition behind this project is to uncover the intrinsic properties of the Hitachi SuperH2, in regards to how it handles the patterns encompassing the Opcodes of this processor family. Through this, I aim to provide a standalone reference solution for being able to dynamically assemble and generate code in-memory at runtime.

This reference utility, created in the C++17 standard, aims to provide liaise in uncovering the enigmatic problems that come about with dynamic recompilation for the Hitachi SuperH2.

Inspired by contemporaries such as LLVM and N64Recomp, this project aims to represent as a testing utility to learn, uncover and to formulate a concise and indicative gameplan in being able to help with SH2 to x86 recompilation efforts. 

# Usage:

The following aims to showcase the innate design of how I am able to access register values using the operators defined per the API

All of which is subject to change of course as the project grows

```cpp
using namespace maria;

int main(void)
{
    std::printf("HARRY CLARK - SH2 EMITTER\n");

    // ACCESS THE VALUE FOR R0
    maria::GP_REGISTER SH2_R0(0);
    std::printf("R0 VALUE: %d\n", SH2_R0.GET_INDEX());         // OUTPUT: 0

    // ACCESS THE VALUE FOR PC
    maria::PC SH2_PC;
    std::printf("PC VALUE: %d\n", SH2_PC.GET_INDEX());        // OUTPUT: 15
    
    return 0;
}
```

## Emit Opcode Mask from definition:

The most nuanced and intrinsic feature related to this Emitter is the means of being able to access the Mask associated with the combination of Directives.

This is presupposed on the basis of that the definition for the Opcode already has the Mask associated with that type of Opcode Family

Through the usage of the Memory Buffer, we are able to dynamically cast the relevant size of the current Opcode being accessed and figure out the penultimate result of the operation

```cpp
using namespace maria;

int main(void)
{
    EMITTER EMITTER;
    GP_REGISTER R1(1);
    GP_REGISTER R2(2);
    
    EMITTER.SH2_ADD(R1, R2);
    
    BUFFER& BUFFER = EMITTER.GET_BUFFER();
    U16 OPCODE = *reinterpret_cast<U16*>(BUFFER.SH2_GET_BUFFER());
    
    printf("EMITTED OPCODE MASK FROM: (ADD R1, R2) 0x%04X\n", OPCODE);
    return 0;
}
```
`````
.\maria.exe
EMITTED OPCODE MASK FROM: (ADD R1, R2) 0x312C
`````

## Features:

One of the most unique and cost-effective features encompassing this Emitter is the surrogate means of being able to use templates.

C++ templates allow us to define generic types which can be filled with any sort of information related.

Through this, I was able to generate templates that follow the instructions and rules encompassing an Opcode def, down to their register specifics, mask type and imm displacment

```cpp
// THE FOLLOWING PRESUPPOSES ANY GENERIC GPR'S
// GET EACH OF THE BITS FROM RM AND RN AND EMIT THAT WORDWISE

// SH2 OPCODES WILL ALWAYS ENCOMPASS 16 BITS
template<typename REG_A, typename REG_B = REG_A>
inline void SH2_EMIT_R_TYPE(BUFFER& BUFFER, REG_A RN,
                                    REG_B RM, U16 MASK)
{
    const auto OPCODE = MASK |
    (RN.GET_INDEX() << 8) |
    (RM.GET_INDEX() << 4);

    BUFFER.SH2_EMIT_WORD(OPCODE);
}
```

By encompassing a generic template, we are able to mitigate any confusion and overhead by presupposing the definition of the Opcode against it's characteristics. Which means that all we are focussed on is retrieving the Mask that fashions up said Mask (software-quirks and nuances withstanding as those are often register-side) 

# Building:

To build this project, you will need a C++ compiler which supports CMake 3.20. From there, it is just a case of:

```
mkdir build && cd build

cmake ..
```

# Sources:

[SH2 PROGRAMMER MANUAL](https://antime.kapsi.fi/sega/files/h12p0.pdf)

[SH2 REGISTERS](https://bitsavers.trailing-edge.com/components/hitachi/superH/1995_SH1_SH2_Programming_Manual_3rd_Edition.pdf)

[SH2 OPCODE MASKS](https://www.farnell.com/datasheets/60581.pdf#page=75)
