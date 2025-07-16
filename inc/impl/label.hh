// COPYRIGHT (C) HARRY CLARK 2025
// LIGHTWEIGHT CODE EMITTER/GENERATOR FOR THE HITACHI SUPERH2

// THIS FILE PERTAINS TOWARDS THE HELPER FUNCTIONALITY ENCOMPASSING THE INNATE DESIGN OF LABELS
// THIS WILL LOOK TO DETERMINE THE LABEL TYPE, IT'S RELEVANT DISPLACEMENT, AND ANY OTHER INTRINSIC CHARACTERISTICS

// NESTED INCLUDES

#include <common.h>
#include <impl/buffer.hh>
#include <impl/util.hh>

// SYSTEM INCLUDES

#include <cstdint>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace maria
{
    class SH2_LABEL_BASE;
    class SH2_LABEL
    {
        private:
            U32 LABEL_POS = static_cast<U32>(-1);

        public:
            explicit SH2_LABEL(const std::string& NAME);
    };
}