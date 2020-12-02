cmake_minimum_required(VERSION 3.13.1)

set(SOURCE_1
   main.c
   heartbeat.c
   pwm_led.c
   fat_fs.c
)

set(SOURCES
   ${SOURCE_1}
)

target_sources(app PRIVATE ${SOURCES})