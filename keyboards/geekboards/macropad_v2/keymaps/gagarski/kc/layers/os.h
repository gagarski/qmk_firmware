#pragma once

#ifndef KC_H
#    error "Please do not include this file directly"
#endif

enum fkcs_os {
    // These must be sequential
    FKC_OS_FIRST_GUARD = FKC_SAFE_RANGE - 1, // this must be first
    FKC_OS_TO_WINDOWS_10,
    FKC_OS_TO_MACOS,
    FKC_OS_TO_LINUX,
    FKC_OS_TO_WINDOWS_7,
    _FKC_NEW_SAFE_RANGE_OS
};

#define FKC_OS_BASE (FKC_OS_FIRST_GUARD + 1)

#undef FKC_SAFE_RANGE
#define FKC_SAFE_RANGE _FKC_NEW_SAFE_RANGE_OS
