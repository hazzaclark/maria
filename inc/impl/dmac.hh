// COPYRIGHT (C) HARRY CLARK 2025
// LIGHTWEIGHT CODE EMITTER/GENERATOR FOR THE HITACHI SUPERH2

// THIS FILE PERTAINS TOWARDS THE FUNCTIONALITY ENCOMPASSING THE DMA CONTROL
// DETERMINING THE CIRCUMSTANCES BY WHICH OPERATIONS OFTEN CONTROL THE FLOW OF DMA BETWEEN OPERANDS

#pragma once

// NESTED INCLUDES

#include <common.h>
#include <reg.hh>

class SH2_DMAC
{
    // https://segaretro.org/images/2/2c/SH7604_Hardware_Manual.pdf#page=249
    private:
        enum class SH2_DMA_MODE { FIXED, INCREMENT, DECREMENT, RESVERSE };
        enum class SH2_DMA_SIZE { BYTE, WORD, LONG, QUAD };
        enum class SH2_DMA_BUS : std::uint8_t { CYCLE, INST };
        enum class SH2_DMA_ADDR : std::uint8_t { SINGLE, DUAL };
        enum class SH2_DMA_DETECT : std::uint8_t { EDGE, LEVEL };
        enum class SH2_DMA_RESC : std::uint8_t { TXI, RXI, DREQ, RESERVE };
};
