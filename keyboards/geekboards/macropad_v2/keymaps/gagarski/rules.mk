CONSOLE_ENABLE = yes
TAP_DANCE_ENABLE = yes
UNICODE_ENABLE = yes
MOUSEKEY_ENABLE = yes

# todo relative to where???
SRC += eeconfig_user.c
SRC += indication.c
SRC += layers.c
SRC += tapdance.c
SRC += fkc.c
SRC += reset.c
SRC += os.c
SRC += layers/basic.c
SRC += layers/idea.c
SRC += layers/macros.c
# SRC += layers/idea_debug.c # absent
# SRC += layers/trucksim.c # absent
# SRC += layers/trucksim_camera.c # absent
# SRC += layers/trucksim_brakes.c # disabled
SRC += layers/rgb.c
SRC += layers/ind_bl.c
SRC += layers/layer_switch.c
SRC += layers/os.c
