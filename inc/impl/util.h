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

    // DO THE SAME BUT FOR A BITFIELD OF CONTIGUOUS BITS
    // THIS PRESUPPOSES THE SIZE OF A BITFIELD BASED ON A START
    // AND A DISPLACEMENT VALUE TO USE SAID BITS IN THAT RANGE

    template<typename T, typename U>
    constexpr auto SH2_BITFIELD(T POSITION, U WIDTH) ->
        typename std::enable_if<std::is_unsigned<T>::VALUE && std::is_unsigned<U>::VALUE, U32>::TYPE
        {
            static_assert(static_cast<U32>(POSITION) + static_cast<U32>(WIDTH) <= 32, 
                  "BITFIELD EXCEEDS 32-BIT BOUNDARY");

            // PROVIDE A DISPENSATION FOR THE SIZE OF THE WIDTH (-1)
            return WIDTH ? ((1U << static_cast<U32>(WIDTH)) - 1) << static_cast<U32>(POSITION) : 0;
        }
}

#endif
