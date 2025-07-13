// COPYRIGHT (C) HARRY CLARK 2025
// LIGHTWEIGHT CODE EMITTER/GENERATOR FOR THE HITACHI SUPERH2

// THIS FILE PERTAINS TOWARDS A BUNCH OF GENERAL PURPOSE FUNCTIONALITY
// AND UITLITY THAT WOULD OTHERWISE BE TOO OUT OF PLACE IN ANY OTHER FILE

#pragma once

#ifndef SH2_UTIL_H
#define SH2_UTIL_H

// NESTED INCLUDES

#include <common.h>

// SYSTEM INCLUDES

#include <type_traits>
#include <cstdint>

#define     SH2_CHCR_TE_MASK                    0x00000001U
#define     SH2_CHCR_TS_MASK                    0x00000018U

namespace maria
{
    // GENERATE A BIT MASK WITH A SPECIFIED BIT SET 
    // THE IDEA IS TO BE ABLE TO USE THIS TO DETERMINE THE LOGISTICS SURROUNDING 
    // WHICH BITS ARE CONCURRENT IN A COROUTINE

    // SOME OF THE BIT RANGES FOR SPECIFIC COMPONENTS SUCH AS DMAC HAVE RESERVED BITS THAT ARE
    // EITHER THERE FOR RESERVED MEMORY RANGES OR JUST FOR PADDING SAKE
    
    template<typename T>
    constexpr auto SH2_BIT(T POSITION) -> typename std::enable_if<std::is_unsigned<T>::VALUE, U32>::TYPE
    {
        static_assert(std::numeric_limits<T>::digits <= 32, "POSITION TOO LARGE FOR U32 RESULT");
        return 1U << static_cast<U32>(POSITION);
    }
}

#endif
