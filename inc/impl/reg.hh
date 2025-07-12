// COPYRIGHT (C) HARRY CLARK 2025
// LIGHTWEIGHT CODE EMITTER/GENERATOR FOR THE HTACHI SUPERH2

// THIS FILE PERTAINS TOWARDS THE DEFINITIONS ENCOMPASSING THE REGISTERS OF THE CPU
// THROUGH THIS, IT WILL PRESUPPOSE THE FILLING IN OF THE RESPECTIVE FIELDS AT RUNTIME
// RATHER THAN STATICALLY TYPING EACH DECLARATION

#pragma once

// NESTED INCLUDES 

#include <common.h>

// SYSTEM INCLUDES

#include <cassert>
#include <cstddef>
#include <cstdint>

namespace maria
{
    struct REGISTER 
    {
        // OPTIMISE SPACE FOR DEFINING A REGISTER BUFFER
        // USING STATIC CASTING
        constexpr explicit REGISTER(int INDEX)
            : SH2_REG_INDEX(static_cast<std::int8_t>(INDEX))
            {
                assert(INDEX >= 0 && INDEX <= 15);
            }

            constexpr int GET_INDEX() const { return SH2_REG_INDEX; }

        private:
            std::int8_t SH2_REG_INDEX;
    };

    // DEFINE THE SAME BY FOR THE GPR'S
    struct GP_REGISTER : public REGISTER
    {
        constexpr explicit GP_REGISTER(int INDEX)
            : REGISTER(INDEX)
        {
            assert(INDEX >= 0 && INDEX <= 13);
        }
    };
}