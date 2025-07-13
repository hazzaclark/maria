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
    public:
        enum class SH2_DMA_MODE { FIXED, INCREMENT, DECREMENT, RESVERSE };
        enum class SH2_DMA_SIZE { BYTE, WORD, LONG, QUAD };
        enum class SH2_DMA_BUS : std::uint8_t { CYCLE, INST };
        enum class SH2_DMA_ADDR : std::uint8_t { SINGLE, DUAL };
        enum class SH2_DMA_DETECT : std::uint8_t { EDGE, LEVEL };
        enum class SH2_DMA_RESC : std::uint8_t { TXI, RXI, DREQ, RESERVE };

        SH2_DMAC() noexcept = default;
        ~SH2_DMAC() noexcept;

        // DEFINE THE REGISTERS FOR THE DMA CHANNEL
        struct SH2_CHN
        {
            uint32_t SAR;
            uint32_t DAR;
            uint32_t TCR;
            uint32_t CHCR;
        };

    private:
        uint32_t XREF_COUNT : 24;           // XREF COUNT FOR TLB PAGING  
        SH2_CHN CHANNELS[4];                // DMA CHANNELS
        bool ENABLED() const;               // IS THE DMA ENABLED FOR THE CURRENT CHANNEL BEING USED    
        SH2_DMA_BUS CURRENT_BUS;            // WHICH CURRENT BUS IS BEING USED (0 OR 1)
};
