// COPYRIGHT (C) HARRY CLARK 2025
// LIGHTWEIGHT CODE EMITTER/GENERATOR FOR THE HITACHI SUPERH2

// THIS FILE PERTAINS TOWARDS THE MAIN FUNCTIONALITY ENCOMPASSING THE ACTUAL EMITTER
// THROUGH THIS, I WILL LEVERAGE A ALLOCATABLE BUFFER WHICH PRESUPPOSES THE CURRENT STRUCTURE
// ENCOMPASSING THE INSTRUCTIONS 

// THIS WILL ALSO PRESUPPOSE ANY AND ALL ARBITRARY MEMORY INCLUDED WITHIN THE BUFFER
// SO, THE BUFFER WILL BE ABLE TO DYNAMICALLY GROW AND EMIT ACCORDINGLY

#pragma once

// NESTED INCLUDES

#include <common.hh>
#include <impl/dmac.hh>
#include <impl/reg.hh>
#include <impl/util.hh>

// SYSTEM INCLUDES

#include <cstring>

namespace maria
{
    class BUFFER
    {
        public:
            static constexpr size_t SH2_MIN_BUFFER = 1024;
            static constexpr size_t SH2_DEFAULT_BUFFER = 4096;

            explicit BUFFER(size_t CAPACITY = SH2_DEFAULT_BUFFER);
            explicit BUFFER(U8* BUFFER, size_t CAPACITY);

            BUFFER(const BUFFER&) = delete;
            BUFFER(BUFFER&& BUFFER_MOVE) noexcept;
            BUFFER& operator=(const BUFFER&) = delete;

            ~BUFFER() noexcept;

            size_t SH2_GET_CAPACITY() const { return _CAPACITY; }
            U8* SH2_GET_BUFFER() const { return _BUFFER; }

            // EMIT ANY ARBITRARY VALUE GIVEN INTO THE MEMORY BUFFER
            // THIS IS THE MAIN ENCOMPASSING FUNCTION BEHIND EVERYTHING
            // BEING ABLE TO COPY THE CURRENT CURSOR POSSITION INTO SAID BUFFER

            template <typename T>
            void SH2_EMIT(T VALUE) noexcept
            {
                std::memcpy(_CURSOR, &VALUE, sizeof(T));
                _CURSOR += sizeof(T);
            }

            // NOW WE CAN DO THIS FOR ANY SORT OF ARBITARY SIZE OF THE OPERAND
            // PRESUPPOSE ANY AND ALL CONDITION FOR THE INSTRUCTION SIZE

            void SH2_EMIT_WORD(U32 VALUE) noexcept
            {
                SH2_EMIT(static_cast<U16>(VALUE));
            }

            void SH2_EMIT_LONG(U32 VALUE) noexcept
            {
                SH2_EMIT(VALUE);
            }

            void SH2_EXEC(void);
            void SH2_WRITEABLE(void);
            void SH2_READONLY(void);
            void SH2_STACK_GROW(size_t _CAPACITY);
            bool SH2_MANAGED() const noexcept { return _MANAGE; }

            S32 SH2_CURSOR_OFFSET(void) const noexcept { return _CURSOR - _BUFFER; }
            U32 SH2_GET_OFFSET_ADDR(S32 OFFSET) const noexcept { return reinterpret_cast<U32>(SH2_GET_OFFSET_PTR(OFFSET)); }
            U8* SH2_GET_OFFSET_PTR(S32 OFFSET) const noexcept { return _BUFFER + OFFSET; }

        // MEMBERS TO HELP WITH CONSTRUCTING METHODS

        private:
            U8* _BUFFER = nullptr;              // BASE MEMORY BUFFER
            U8* _CURSOR = nullptr;              // THE CURRRENT POSITION IN THE BUFFER BEING READ
            size_t _CAPACITY;                      
            bool _MANAGE = false;               // IS THE CURRENT BUFFER HANDLING MEMORY
    };
}
