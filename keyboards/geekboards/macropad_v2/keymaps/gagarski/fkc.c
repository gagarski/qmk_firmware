#include "kc.h"
#include "fkc.h"

bool handle_fkc(uint16_t keycode, const keyrecord_t* record) {
    if (!IS_FKC(keycode)) {
        return true;
    }
    return (*(FKCS[FKC_INDEX(keycode)]))(keycode, record);
}
