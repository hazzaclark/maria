// COPYRIGHT (C) HARRY CLARK 2025
// LIGHTWEIGHT CODE EMITTER/GENERATOR FOR THE HITACHI SUPERH2

// THIS FILE PERTAINS TOWARDS THE MAIN FUNCTIONALITY ENCOMPASSING THE ACTUAL EMITTER
// THROUGH THIS, I WILL LEVERAGE A ALLOCATABLE BUFFER WHICH PRESUPPOSES THE CURRENT STRUCTURE
// ENCOMPASSING THE INSTRUCTIONS 

// THIS WILL ALSO PRESUPPOSE ANY AND ALL ARBITRARY MEMORY INCLUDED WITHIN THE BUFFER
// SO, THE BUFFER WILL BE ABLE TO DYNAMICALLY GROW AND EMIT ACCORDINGLY

#pragma once

// NESTED INCLUDES

#include <common.h>
#include <dmac.hh>
#include <reg.hh>

namespace maria
{
    class BUFFER
    {
        public:
            static constexpr UNK SH2_DEFAULT_BUFFER = 4096;

            explicit BUFFER(UNK CAPACITY = SH2_DEFAULT_BUFFER);

            BUFFER(const BUFFER&) = delete;
            BUFFER(BUFFER&& BUFFER_MOVE) noexcept;
            BUFFER& operator=(const BUFFER&) = delete;

        // MEMBERS TO HELP WITH CONSTRUCTING METHODS

        private:
            U8* _BUFFER = nullptr;              // BASE MEMORY BUFFER
            U8* _CURSOR = nullptr;              // THE CURRRENT POSITION IN THE BUFFER BEING READ
            UNK _CAPACITY;                      
            bool _MANAGE = false;               // IS THE CURRENT BUFFER HANDLING MEMORY
    };
}
