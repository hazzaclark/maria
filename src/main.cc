// COPYRIGHT (C) HARRY CLARK 2025
// LIGHTWEIGHT CODE EMITTER/GENERATOR FOR THE HITACHI SUPERH2

// NESTED INCLUDES

#include <common.h>
#include <impl/reg.hh>

// SYSTEM INCLUDES

#include <cstdio>

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
