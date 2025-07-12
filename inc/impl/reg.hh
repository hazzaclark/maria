// COPYRIGHT (C) HARRY CLARK 2025
// LIGHTWEIGHT CODE EMITTER/GENERATOR FOR THE HITACHI SUPERH2

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
        REGISTER() noexcept = default;

        // OPTIMISE SPACE FOR DEFINING A REGISTER BUFFER
        // USING STATIC CASTING
        constexpr explicit REGISTER(int INDEX)
            : SH2_REG_INDEX(static_cast<std::int8_t>(INDEX)) { }

            constexpr int GET_INDEX() const { return SH2_REG_INDEX; }

        private:
            std::int8_t SH2_REG_INDEX;
    };

    // DEFINE THE SAME BY FOR THE GPR'S
    struct GP_REGISTER : public REGISTER
    {
        GP_REGISTER() noexcept : REGISTER{0} {}
        constexpr explicit GP_REGISTER(uint32_t INDEX) noexcept : REGISTER{INDEX} {}

        friend constexpr bool operator == (GP_REGISTER, GP_REGISTER);
    };

    // GLOBAL DEFINITION FOR THE OPERATION
    // THIS LOOKS FOR COMPARATOR'S
    constexpr bool operator==(GP_REGISTER REG_A, GP_REGISTER REG_B)
    {
        return REG_A.GET_INDEX() == REG_B.GET_INDEX();
    }
}
