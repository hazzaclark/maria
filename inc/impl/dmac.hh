// COPYRIGHT (C) HARRY CLARK 2025
// LIGHTWEIGHT CODE EMITTER/GENERATOR FOR THE HITACHI SUPERH2

// THIS FILE PERTAINS TOWARDS THE FUNCTIONALITY ENCOMPASSING THE DMA CONTROL
// DETERMINING THE CIRCUMSTANCES BY WHICH OPERATIONS OFTEN CONTROL THE FLOW OF DMA BETWEEN OPERANDS

#pragma once

// NESTED INCLUDES

#include <common.h>
#include <impl/reg.hh>

namespace maria
{
    class SH2_DMAC
    {
        // https://segaretro.org/images/2/2c/SH7604_Hardware_Manual.pdf#page=249
        public:
            enum class SH2_DMA_MODE { FIXED, INCREMENT, DECREMENT, RESVERSE };
            enum class SH2_DMA_SIZE { BYTE, WORD, LONG, QUAD };
            enum class SH2_DMA_BUS : U8 { CYCLE, INST };
            enum class SH2_DMA_ADDR : U8 { SINGLE, DUAL };
            enum class SH2_DMA_DETECT : U8 { EDGE, LEVEL };
            enum class SH2_DMA_RESC : U8 { TXI, RXI, DREQ, RESERVE };

            SH2_DMAC() noexcept = default;
            ~SH2_DMAC() noexcept;

            bool IS_ENABLED(U8 CHANNEL) const;
            void SH2_DMAC_ENABLED(U8 CHANNEL, bool STATE);

            // DEFINE THE REGISTERS FOR THE DMA CHANNEL
            struct SH2_CHN
            {
                U32 SAR;
                U32 DAR;
                U32 TCR;
                U32 CHCR;
            };

        private:
            U32 XREF_COUNT : 24;           // XREF COUNT FOR TLB PAGING  
            SH2_CHN CHANNELS[4];                // DMA CHANNELS
            SH2_DMA_BUS CURRENT_BUS;            // WHICH CURRENT BUS IS BEING USED (0 OR 1)

            bool IS_CHN_VALID(U8 CHANNEL) const;
    };
}
