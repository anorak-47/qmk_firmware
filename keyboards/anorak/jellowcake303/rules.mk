## chip/board settings
#
# jellowcake keyboard driver 
# MCU is a STM32F303CCT6
#
# the next two should match the directories in
#  <chibios>/os/hal/ports/$(MCU_FAMILY)/$(MCU_SERIES)
MCU_FAMILY = STM32
MCU_SERIES = STM32F3xx
# linker script to use
# it should exist either in <chibios>/os/common/startup/ARMCMx/compilers/GCC/ld/
#  or <this_dir>/ld/
MCU_LDSCRIPT = STM32F303xC
# startup code to use
# is should exist in <chibios>/os/common/startup/ARMCMx/compilers/GCC/mk/
MCU_STARTUP = stm32f3xx
# it should exist either in <chibios>/os/hal/boards/
#  or <this_dir>/boards
BOARD = jellowcake303
# Cortex version
# STM32L073 is cortex-m0
MCU  = cortex-m4
# ARM version, CORTEX-M0/M1 are 6, CORTEX-M3/M4/M7 are 7
ARMV = 7
#USE_FPU = yes

# Do not put the microcontroller into power saving mode
# when we get USB suspend event. We want it to keep updating
# backlight effects.
#OPT_DEFS += -DNO_SUSPEND_POWER_DOWN

# If you want to be able to jump to bootloader from firmware on STM32 MCUs,
# set the correct BOOTLOADER_ADDRESS. Either set it here, or define it in
# ./bootloader_defs.h or in ./boards/<FOO>/bootloader_defs.h (if you have
# a custom board definition that you plan to reuse).
# If you're not setting it here, leave it commented out.
# It is chip dependent, the correct number can be looked up here (page 175):
# http://www.st.com/web/en/resource/technical/document/application_note/CD00167594.pdf
# This also requires a patch to chibios:
#   <tmk_dir>/tmk_core/tool/chibios/ch-bootloader-jump.patch
#STM32_BOOTLOADER_ADDRESS = 0x1FFFC800
#STM32_BOOTLOADER_ADDRESS = 0x1FFFD800

# Options to pass to dfu-util when flashing
DFU_ARGS = -d 0483:df11 -a 0 -s 0x08000000:leave
DFU_SUFFIX_ARGS = -p df11 -v 0483

# Build Options
#   change yes to no to disable
# 
BOOTMAGIC_ENABLE = yes          # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = no            # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes           # Audio control and System control(+450)
CONSOLE_ENABLE = yes            # Console for debug(+400) (use hidlisten)
CONSOLE_USE_UART_ENABLE = yes   # Enable console debug output to UART Channel 1
COMMAND_ENABLE = no             # Commands for debug and configuration
NKRO_ENABLE = yes               # USB Nkey Rollover
MIDI_ENABLE = no                # MIDI support (+2400 to 4200, depending on config)
VIRTSER_ENABLE = no        
KEYBOARD_SHARED_EP = no
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no           # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no           # Enable keyboard backlight functionality on B7 by default
RGBLIGHT_ENABLE = no            # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = IS31FL3733
UNICODE_ENABLE = no             # Unicode
BLUETOOTH_ENABLE = no           # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no               # Audio output on port C6
FAUXCLICKY_ENABLE = no          # Use buzzer to emulate clicky switches
HD44780_ENABLE = no             # Enable support for HD44780 based LCDs (+400)
OLED_DRIVER_ENABLE = yes        # OLED modules using SSD1306 ICs, communicating over I2C
##LOCAL_GLCDFONT = no           # use the local glcdfont.c file
LINK_TIME_OPTIMIZATION_ENABLE = yes



