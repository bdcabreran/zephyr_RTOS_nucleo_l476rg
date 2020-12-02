#!/bin/bash
#This is my first program

#west build -t clean /home/bayron/nucleo_project

echo "Recompiling Project ..."
export ZEPHYR_BASE=/home/bayron/zephyrproject/zephyr/
west build -b nucleo_l476rg /home/bayron/zephyr_RTOS_nucleo_l476rg
#cp -f /home/bayron/zephyrproject/zephyr/build/zephyr/zephyr.hex /home/bayron/nucleo_project/build/
cp -f /home/bayron/zephyr_RTOS_nucleo_l476rg/build/zephyr/zephyr.hex /media/sf_Shared_Folder_VM/nucleo_l476rg_hex_files/

