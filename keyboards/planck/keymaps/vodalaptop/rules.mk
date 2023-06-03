ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

SRC += helper_functions.c
