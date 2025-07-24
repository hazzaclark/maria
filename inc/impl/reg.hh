// COPYRIGHT (C) HARRY CLARK 2025
// LIGHTWEIGHT CODE EMITTER/GENERATOR FOR THE HITACHI SUPERH2

// THIS FILE PERTAINS TOWARDS THE DEFINITIONS ENCOMPASSING THE REGISTERS OF THE CPU
// THROUGH THIS, IT WILL PRESUPPOSE THE FILLING IN OF THE RESPECTIVE FIELDS AT RUNTIME
// RATHER THAN STATICALLY TYPING EACH DECLARATION

#pragma once

// NESTED INCLUDES 

#include <common.hh>

// SYSTEM INCLUDES

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <stdexcept>

namespace maria
{
    struct REGISTER 
    {
        REGISTER() noexcept = default;

        constexpr void SH2_VALID_RANGE(int INDEX)
        {
            if(INDEX < 0 || INDEX > 21)
            {
                throw std::out_of_range("REGISTERS ARE OUT OF RANGE");
            }
        }

        // OPTIMISE SPACE FOR DEFINING A REGISTER BUFFER
        // USING STATIC CASTING
        constexpr explicit REGISTER(int INDEX) noexcept
            : SH2_REG_INDEX(static_cast<std::int8_t>(INDEX)) 
            {
                SH2_VALID_RANGE(INDEX);
            }

            constexpr int GET_INDEX() const noexcept { return SH2_REG_INDEX; }

        private:
            std::uint8_t SH2_REG_INDEX;
    };

    // DEFINE THE SAME BY FOR THE GPR'S
    struct GP_REGISTER : public REGISTER
    {
        public:
            GP_REGISTER() noexcept : REGISTER{0} {}
            constexpr explicit GP_REGISTER(int INDEX) noexcept : REGISTER{INDEX} {}

            friend constexpr bool operator == (GP_REGISTER, GP_REGISTER);
    };

    struct SR : public REGISTER { constexpr SR() noexcept : REGISTER(16) {} };
    struct GBR : public REGISTER { constexpr GBR() noexcept : REGISTER(17) {} };
    struct VBR : public REGISTER { constexpr VBR() noexcept : REGISTER(18) {} };
    struct MACH : public REGISTER { constexpr MACH() noexcept : REGISTER(19) {} };
    struct MACL : public REGISTER { constexpr MACL() noexcept : REGISTER(20) {} };
    struct PR : public REGISTER { constexpr PR() noexcept : REGISTER(21) {} };

    struct PC : public GP_REGISTER { constexpr PC() noexcept : GP_REGISTER(15) {} };
    struct SP : public GP_REGISTER { constexpr SP() noexcept : GP_REGISTER(14) {} };

    namespace SH2_REGISTERS
    {
        constexpr GP_REGISTER R0(0);
        constexpr GP_REGISTER R1(1);
        constexpr GP_REGISTER R2(2);
        constexpr GP_REGISTER R3(3);
        constexpr GP_REGISTER R4(4);
        constexpr GP_REGISTER R5(5);
        constexpr GP_REGISTER R6(6);
        constexpr GP_REGISTER R7(7);
        constexpr GP_REGISTER R8(8);
        constexpr GP_REGISTER R9(9);
        constexpr GP_REGISTER R10(10);
        constexpr GP_REGISTER R11(11);
        constexpr GP_REGISTER R12(12);
        constexpr GP_REGISTER R13(13);
        constexpr GP_REGISTER R14(14);
        constexpr GP_REGISTER R15(15);

        constexpr SR STATUS_REGISTER;
        constexpr GBR GLOBAL_BASE;
        constexpr VBR VECTOR_BASE;
        constexpr MACH MUL_HIGH;
        constexpr MACL MUL_LOW;
        constexpr PR PROCEDURE;

        constexpr PC PROGRAM_COUNTER;
        constexpr SP STACK_POINTER;
    }

    // GLOBAL DEFINITION FOR THE OPERATION
    // THIS LOOKS FOR COMPARATOR'S
    constexpr bool operator==(GP_REGISTER REG_A, GP_REGISTER REG_B)
    {
        return REG_A.GET_INDEX() == REG_B.GET_INDEX();
    }

    constexpr bool IS_GPR(const REGISTER& REG_BASE) noexcept
    {
        return REG_BASE.GET_INDEX() >= 0 && REG_BASE.GET_INDEX() <= 15;
    }

    constexpr bool IS_CONTROL_REG(const REGISTER& REG_BASE) noexcept
    {
        return REG_BASE.GET_INDEX() >= 16;
    }
}
