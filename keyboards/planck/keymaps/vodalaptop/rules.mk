CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes

ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

VPATH += keyboards/gboards
SRC += helper_functions.c
