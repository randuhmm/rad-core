#!/usr/bin/env bash

function fix_esp8266_boards()
{
  # Fixing a Problem with the boards.txt
  # ld: cannot open linker script file {build.flash_ld}: No such file or directory
  # choosing "4M (3M SPIFFS)" Configuration
  file=`find $HOME/.arduino15/packages/esp8266/ -type f -name 'boards.txt'`
  echo Changing $file

  sed -i.bak 's/generic.menu.FlashSize.4M3M/generic/g' $file
  sed -i.bak 's/nodemcu.menu.FlashSize.4M3M/nodemcu/g' $file
  sed -i.bak 's/nodemcuv2.menu.FlashSize.4M3M/nodemcuv2/g' $file
  sed -i.bak 's/d1_mini.menu.FlashSize.4M3M/d1_mini/g' $file
  sed -i.bak 's/esp8285.menu.FlashSize.1M128/esp8285/g' $file

  for i in generic nodemcu nodemcuv2 d1_mini esp8285
  do
    echo "${i}.build.f_cpu=80000000L" >> $file
  done

  return 0
}
