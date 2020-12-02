# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)
set(BOARD nucleo_l476rg)
set(DTC_OVERLAY_FILE board/nucleo_l476rg.overlay)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(zephyr_RTOS_nucleo_l476rg)

add_subdirectory(src)
target_include_directories(app
    PUBLIC 
        inc
)