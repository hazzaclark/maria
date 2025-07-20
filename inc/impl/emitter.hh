// COPYRIGHT (C) HARRY CLARK 2025
// LIGHTWEIGHT CODE EMITTER/GENERATOR FOR THE HITACHI SUPERH2

// THIS FILE PERTAINS TOWARDS THE ACTUAL IMPLEMENTATION SURROUNDING THE EMITTER
// THE IDEA BEHIND THIS FILE IS THAT WE WANT TO BE ABLE TO MAKE A STATICALLY TYPE COLLECTION
// OF ALL OF THE OPCODE FAMILIES AND EMIT THEM ACCORDINGLY TO THEIR UNQIUE CHARACTERISTICS

// WHAT WOULD OTHERWISE MAKE THIS ADJACENT TO AN EMULATOR IS THAT WE ARE NOT CONCERN WITH THE INTRINISC
// PATTERNS AND DESIGN OF SAID OPCODE FAMILY, MOREOVER JUST WHAT THEY REPRESENT IN MEMORY AND ANYTHING
// THAT COMES ATTACHED WITH THEM IN RUNTIME

// NESTED INCLUDES

#include <impl/buffer.hh>
#include <impl/reg.hh>
#include <impl/util.hh>

namespace maria
{
    class EMITTER
    {
        public: 
            // INITIALISE ALL OF THE REQUIRED CONSTRUCTORS NECESSARY FOR THE EMITTER
            // THE MAIN ENCOMPASSING ONE WILL BE TO DETERMINE HOW MANY BYTES ARE CURRENTLY
            // HELD IN THE CODE BUFFER

            explicit EMITTER(size_t CAPACITY = BUFFER::SH2_DEFAULT_BUFFER);
            
            // THE REST OF THESE ENCOMPASS COPY AND MOVE ASSIGNMENTS RESPECTIVELY
            EMITTER(const EMITTER&) = delete;
            EMITTER(EMITTER&&) = default;

            ~EMITTER(void) noexcept;

            // ACCESS THE ENCOMPASSING CODE BUFFER THAT IS CURRENTLY BEING MANAGED
            BUFFER& GET_BUFFER(void) noexcept;

            void SH2_ADD(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_ADDI(U32 IMM, GP_REGISTER RN) noexcept;
            void SH2_ADDC(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_ADDV(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_BRA(U32 DISP) noexcept;
            void SH2_BSR(U32 DISP) noexcept;
            void SH2_CMP_EQ_IMM(U32 IMM, GP_REGISTER R0) noexcept;
            void SH2_CMP_EQ(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_CMP_HS(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_CMP_GE(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_CMP_HI(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_CMP_GT(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_CMP_PL(GP_REGISTER RN) noexcept;
            void SH2_CMP_PZ(GP_REGISTER RN) noexcept;
            void SH2_CMP_STR(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_DIV1(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_DIV0S(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_DIV0U() noexcept;
            void SH2_DMULS_LONG(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_DMULU_LONG(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_DT(GP_REGISTER RN) noexcept;
            void SH2_EXTS_BYTE(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_EXTS_WORD(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_EXTU_BYTE(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_EXTU_WORD(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_MAC_LONG(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_MAC_WORD(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_MUL_LONG(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_MULS_WORD(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_MULU_WORD(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_NEG(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_NEGC(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_SUB(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_SUBC(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_SUBV(GP_REGISTER RM, GP_REGISTER RN) noexcept;

            void SH2_AND(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_AND_IMM(U8 IMM, GP_REGISTER R0) noexcept;
            void SH2_AND_B(U8 IMM, GP_REGISTER R0) noexcept;
            void SH2_NOT(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_OR(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_OR_IMM(U8 IMM, GP_REGISTER R0) noexcept;
            void SH2_OR_B(U8 IMM, GP_REGISTER R0) noexcept;
            void SH2_TAS(GP_REGISTER RN) noexcept;
            void SH2_TST(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_TST_IMM(U8 IMM, GP_REGISTER R0) noexcept;
            void SH2_TST_B(U8 IMM, GP_REGISTER R0) noexcept;
            void SH2_XOR(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_XOR_IMM(U8 IMM, GP_REGISTER R0) noexcept;
            void SH2_XOR_B(U8 IMM, GP_REGISTER R0) noexcept;

            void SH2_ROTL(GP_REGISTER RN) noexcept;
            void SH2_ROTR(GP_REGISTER RN) noexcept;
            void SH2_ROTCL(GP_REGISTER RN) noexcept;
            void SH2_ROTCR(GP_REGISTER RN) noexcept;
            void SH2_SHAL(GP_REGISTER RN) noexcept;
            void SH2_SHAR(GP_REGISTER RN) noexcept;
            void SH2_SHLL(GP_REGISTER RN) noexcept;
            void SH2_SHLL2(GP_REGISTER RN) noexcept;
            void SH2_SHLL8(GP_REGISTER RN) noexcept;
            void SH2_SHLL16(GP_REGISTER RN) noexcept;
            void SH2_SHLR(GP_REGISTER RN) noexcept;
            void SH2_SHLR2(GP_REGISTER RN) noexcept;
            void SH2_SHLR8(GP_REGISTER RN) noexcept;
            void SH2_SHLR16(GP_REGISTER RN) noexcept;

            void SH2_BF(U32 DISP) noexcept;
            void SH2_BF_S(U32 DISP) noexcept;
            void SH2_BT(U32 DISP) noexcept;
            void SH2_BT_S(U32 DISP) noexcept;
            void SH2_BRAF(GP_REGISTER RM) noexcept;
            void SH2_BSRF(GP_REGISTER RM) noexcept;
            void SH2_JMP(GP_REGISTER RM) noexcept;
            void SH2_JSR(GP_REGISTER RM) noexcept;
            void SH2_RTS() noexcept;

            void SH2_CLRT() noexcept;
            void SH2_CLRMAC() noexcept;
            void SH2_LDC_SR(SR SR, GP_REGISTER RM) noexcept;
            void SH2_LDC_GBR(GBR GBR,GP_REGISTER RM) noexcept;
            void SH2_LDC_VBR(VBR VBR, GP_REGISTER RM) noexcept;
            void SH2_LDC_L_SR(SR SR, GP_REGISTER RM) noexcept;
            void SH2_LDC_L_GBR(GBR GBR, GP_REGISTER RM) noexcept;
            void SH2_LDC_L_VBR(VBR VBR, GP_REGISTER RM) noexcept;
            void SH2_LDS_MACH(MACH MACH, GP_REGISTER RM) noexcept;
            void SH2_LDS_MACL(MACL MACL, GP_REGISTER RM) noexcept;
            void SH2_LDS_PR(PR PR, GP_REGISTER RM) noexcept;
            void SH2_LDS_L_MACH(MACH MACH, GP_REGISTER RM) noexcept;
            void SH2_LDS_L_MACL(MACL MACL, GP_REGISTER RM) noexcept;
            void SH2_LDS_L_PR(PR PR, GP_REGISTER RM) noexcept;
            void SH2_NOP() noexcept;
            void SH2_RTE() noexcept;
            void SH2_SETT() noexcept;
            void SH2_SLEEP() noexcept;
            void SH2_STC_SR(SR SR, GP_REGISTER RN) noexcept;
            void SH2_STC_GBR(GBR GBR, GP_REGISTER RN) noexcept;
            void SH2_STC_VBR(VBR VBR, GP_REGISTER RN) noexcept;
            void SH2_STC_L_SR(SR SR, GP_REGISTER RN) noexcept;
            void SH2_STC_L_GBR(GBR GBR, GP_REGISTER RN) noexcept;
            void SH2_STC_L_VBR(VBR VBR, GP_REGISTER RN) noexcept;
            void SH2_STS_MACH(MACH MACH, GP_REGISTER RN) noexcept;
            void SH2_STS_MACL(MACL MACL, GP_REGISTER RN) noexcept;
            void SH2_STS_PR(PR PR, GP_REGISTER RN) noexcept;
            void SH2_STS_L_MACH(MACH MACH, GP_REGISTER RN) noexcept;
            void SH2_STS_L_MACL(MACL MACL, GP_REGISTER RN) noexcept;
            void SH2_STS_L_PR(PR PR, GP_REGISTER RN) noexcept;
            void SH2_TRAPA(U8 IMM) noexcept;

        private:
            BUFFER _BUFFER;

        // PROTECTED FIELDS FOR ACCESSING VARIOUS OPCODE TYPES
        // EACH OF THE DEFINITIONS WILL PRESUPPOSE A FEW CONDITIONS

        // BUFFER: THE CURRENT MEMORY BUFFER BEING ACCESSED 
        // RN/RM: THE REGISTERS BEING READ
        // MASK: THE OPCODE MASK
        // BITMASK: THE BITMASK MATCH TO ACCESS SAID OPCODE 

        protected:
            template<typename REG_A, typename REG_B = REG_A>
            inline void SH2_EMIT_R_TYPE(BUFFER& BUFFER, REG_A RN, 
                                REG_B RM, U16 MASK)
            {
                const auto OPCODE = MASK |
                                    (RN.GET_INDEX() << 8) |
                                    (RM.GET_INDEX() << 4);

                BUFFER.SH2_EMIT_WORD(OPCODE);
            }

            // NOW WE ACCESS A REGISTER ON IT'S OWN
            // FOR OPERATIONS THAT ONLY REQUIRE ONE OPERAND

            template<typename REG_A>
            inline void SH2_EMIT_SINGLE_R_TYPE(BUFFER& BUFFER, REG_A RM, U16 MASK)
            {
                const auto OPCODE = MASK | (RM.GET_INDEX() << 8);
                BUFFER.SH2_EMIT_WORD(OPCODE);
            }

            inline void SH2_EMIT_IMM_TYPE(BUFFER& BUFFER, GP_REGISTER RN, 
                                                        U8 IMM, U16 MASK)
            {
                const U16 OPCODE = MASK |
                                    (RN.GET_INDEX() << 8) | 
                                    (IMM & 0xFF);

                BUFFER.SH2_EMIT_WORD(OPCODE);
            }
            
            // MANUALLY BIT SHIFT TO ACCOMMODATE FOR THE IMM BRANCH VALUE
            inline void SH2_EMIT_B_TYPE(BUFFER& BUFFER, U32 IMM, U32 OPCODE)
            {
                BUFFER.SH2_EMIT_WORD(OPCODE | SH2_BRANCH_IMM(IMM));
            }
    };
}
