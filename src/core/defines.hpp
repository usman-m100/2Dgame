#pragma once

#include <iostream>

#include "ext/debug_break.hpp"

#define LOG_TRACE(msg) \
    std::cout << "[TRACE]: " << msg << "\n"

#define LOG_DEBUG(msg) \
    std::cout << "[DEBUG]: " << msg << "\n"

#define LOG_INFO(msg) \
    std::cout << "[INFO]: " << msg << "\n"

#define LOG_WARN(msg) std::cout << "[WARN]: " << msg << "\n"

#define LOG_ERROR(msg) std::cerr << "[ERROR]: " << msg << "\n"

#define LOG_CRTICAL(msg) std::cerr << "[CRITICAL]: " << msg << "\n"

#define ASSERT(cond)                                                                                                      \
    {                                                                                                                     \
        if (cond) {                                                                                                       \
        } else {                                                                                                          \
            LOG_CRTICAL("Assertion failed: '" << #cond << "' in file " << __FILE__ << ", on line " << __LINE__ << ".\n"); \
            debug_break();                                                                                               \
        }                                                                                                                 \
    }

#define ASSERT_MSG(cond, msg)                                                                                         \
    {                                                                                                                 \
        if (cond) {                                                                                                   \
        } else {                                                                                                      \
            LOG_CRTICAL("Assertion failed: '" << #cond << "' in file " << __FILE__ << ", on line " << __LINE__ << "." \
                                              << "\n"                                                                 \
                                              << "'" << msg << "'"                                                    \
                                              << "\n");                                                               \
            debug_break();                                                                                           \
        }                                                                                                             \
    }

namespace game {
    using u8 = unsigned char;
    using u16 = unsigned short;
    using u32 = unsigned int;
    using u64 = unsigned long long;

    using i8 = signed char;
    using i16 = signed short;
    using i32 = signed int;
    using i64 = signed long long;
}  // namespace game