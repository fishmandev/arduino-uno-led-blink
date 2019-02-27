cmake_minimum_required(VERSION 3.13)

set(PROG_TYPE arduino)
set(F_CPU 16000000)
set(MCU   atmega328p)
set(USBPORT /dev/ttyUSB0)
set(PROG_ARGS -P ${USBPORT})

set(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_C_COMPILER   avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(AVRDUDE  avrdude)


set(PROJECT_NAME main)
project(${PROJECT_NAME})

set(SOURCE_FILES main.c)
add_definitions(-DF_CPU=${F_CPU})

set(COPT     "-Os")
set(CMCU     "-mmcu=${MCU}")
set(CDEFS    "-DF_CPU=${F_CPU}")

set(CFLAGS   "${CMCU} ${COPT}")
set(CMAKE_C_FLAGS   "${CFLAGS}")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

add_custom_target(flash ALL
        COMMAND
        ${AVRDUDE} -c ${PROG_TYPE} -p ${MCU} ${PROG_ARGS} -U flash:w:${PROJECT_NAME}
        DEPENDS ${PROJECT_NAME}
        )
