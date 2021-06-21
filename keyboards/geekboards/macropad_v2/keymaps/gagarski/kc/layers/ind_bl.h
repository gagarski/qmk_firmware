#pragma once

#ifndef KC_H
#    error "Please do not include this file directly"
#endif

enum fkcs_ind_bl {
    FKC_NEXT_IND_MODE = FKC_SAFE_RANGE,
    FKC_NEXT_BL_MODE,
    FKC_INC_IND_BRIGHTNESS,
    FKC_DEC_IND_BRIGHTNESS,
    FKC_INC_BL_BRIGHTNESS,
    FKC_DEC_BL_BRIGHTNESS,
    _FKC_NEW_SAFE_RANGE_IND_BL
};

#undef FKC_SAFE_RANGE
#define FKC_SAFE_RANGE _FKC_NEW_SAFE_RANGE_IND_BL
