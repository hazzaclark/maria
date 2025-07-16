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

            explicit EMITTER(UNK CAPACITY = BUFFER::SH2_DEFAULT_BUFFER);
            
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
            void SH2_CMP_EQ_IMM(U32 IMM, GP_REGISTER RN) noexcept;
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
            void SH2_DMULS_LONG(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_DMULU_LONG(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_DT(GP_REGISTER RN) noexcept;
            void SH2_EXTS_BYTE(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_EXTS_WORD(GP_REGISTER RM, GP_REGISTER RN) noexcept;
            void SH2_EXTS_LONG(GP_REGISTER RM, GP_REGISTER RN) noexcept;
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

        private:
            BUFFER _BUFFER;

        // PROTECTED FIELDS FOR ACCESSING VARIOUS OPCODE TYPES
        // EACH OF THE DEFINITIONS WILL PRESUPPOSE A FEW CONDITIONS

        // BUFFER: THE CURRENT MEMORY BUFFER BEING ACCESSED 
        // RN/RM: THE REGISTERS BEING READ
        // MASK: THE OPCODE MASK
        // BITMASK: THE BITMASK MATCH TO ACCESS SAID OPCODE 

        protected:
            inline void SH2_EMIT_R_TYPE(BUFFER& BUFFER, GP_REGISTER RN, 
                                GP_REGISTER RM, U16 MASK)
            {
                const auto OPCODE = MASK |
                                    (RN.GET_INDEX() << 8) |
                                    (RM.GET_INDEX() << 4);

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
    };
}
