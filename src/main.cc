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

    std::printf("R0 VALUE: %d\n", maria::SH2_REGISTERS::R0.GET_INDEX());

    maria::PC SH2_PC;
    std::printf("PC VALUE: %d\n", SH2_PC.GET_INDEX());

    maria::PC SH2_SP;
    std::printf("SP VALUE: %d\n", SH2_SP.GET_INDEX());

    maria::SR SH2_SR;
    std::printf("SR VALUE: %d\n", SH2_SR.GET_INDEX());
        
    return 0;
}
