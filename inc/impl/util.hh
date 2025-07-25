// COPYRIGHT (C) HARRY CLARK 2025
// LIGHTWEIGHT CODE EMITTER/GENERATOR FOR THE HITACHI SUPERH2

// THIS FILE PERTAINS TOWARDS A BUNCH OF GENERAL PURPOSE FUNCTIONALITY
// AND UITLITY THAT WOULD OTHERWISE BE TOO OUT OF PLACE IN ANY OTHER FILE

#pragma once

#ifndef SH2_UTIL_HH
#define SH2_UTIL_HH

// NESTED INCLUDES

#include <common.hh>

// SYSTEM INCLUDES

#include <cstdint>
#include <limits>
#include <type_traits>

#if defined(SH2_USE_OPTS)
#define SH2_USE_OPTS
#else
#define SH2_USE_OPTS

#define         SH2_OPT_OFF         0
#define         SH2_OPT_ON          1

#endif

namespace maria
{
    // GENERATE A BIT MASK WITH A SPECIFIED BIT SET 
    // THE IDEA IS TO BE ABLE TO USE THIS TO DETERMINE THE LOGISTICS SURROUNDING 
    // WHICH BITS ARE CONCURRENT IN A COROUTINE

    // SOME OF THE BIT RANGES FOR SPECIFIC COMPONENTS SUCH AS DMAC HAVE RESERVED BITS THAT ARE
    // EITHER THERE FOR RESERVED MEMORY RANGES OR JUST FOR PADDING SAKE
    
    template<typename T>
    constexpr auto SH2_BIT(T POSITION) -> 
        typename std::enable_if<std::is_unsigned<T>::value, U32>::type
    {
        static_assert(std::numeric_limits<T>::digits <= 32, "POSITION TOO LARGE FOR U32 RESULT");
        return 1U << static_cast<U32>(POSITION);
    }

    // DO THE SAME BUT FOR A BITFIELD OF CONTIGUOUS BITS
    // THIS PRESUPPOSES THE SIZE OF A BITFIELD BASED ON A START
    // AND A DISPLACEMENT VALUE TO USE SAID BITS IN THAT RANGE

    template<typename T, typename U>
    constexpr auto SH2_BITFIELD(T POSITION, U WIDTH) ->
        typename std::enable_if<std::is_unsigned<T>::value && std::is_unsigned<U>::value, U32>::type
        {
            // PROVIDE A DISPENSATION FOR THE SIZE OF THE WIDTH (-1)
            return WIDTH ? ((1U << static_cast<U32>(WIDTH)) - 1) << static_cast<U32>(POSITION) : 0;
        }

    // EXTRACT A SINGLE BIT CURRENT STATE FROM A VALUE
    // THIS WAY, WE WILL BE ABLE TO CHECK TO DETERMINE IF A GIVEN BIT IS SET

    template<typename T, typename U>
    constexpr auto SH2_GET_BIT(T VALUE, U POSITION) ->
        typename std::enable_if<std::is_unsigned<T>::value && std::is_unsigned<U>::value, bool>::type
        {
            return (VALUE >> static_cast<U32>(POSITION)) & 1U;
        }

    constexpr U32 SH2_CHCR_TE_MASK = SH2_BIT(0U);
    constexpr U32 SH2_CHCR_TS_MASK = SH2_BITFIELD(3U, 2U);



    // EXTRAPOLATE THE BYTE OFFSET FOR AN ARBITRARY BRANCH DISPLACEMENT
    // SH2 DEFAULS TO 12 BIT SIGNED WORD OFFSETS SO WE CAN EMULATE THIS SIMPLY

    constexpr U16 SH2_BRANCH_IMM(U32 IMM)
    {
        const U16 DISP = (IMM >> 1) & 0xFFF;
        return DISP;
    }
}

#endif
