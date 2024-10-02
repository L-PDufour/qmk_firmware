# Feature enable/disable flags

MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes      # Audio control and System control
CONSOLE_ENABLE = no       # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = yes          # Enable N-Key Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
MIDI_ENABLE = no           # MIDI support
AUDIO_ENABLE = no          # Audio output
UNICODE_ENABLE = no        # Unicode
BLUETOOTH_ENABLE = no      # Enable Bluetooth
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight
RGB_MATRIX_ENABLE = no     # Matrix LEDs
LTO_ENABLE = yes

CFLAGS += -flto
EXTRAFLAGS += -flto

