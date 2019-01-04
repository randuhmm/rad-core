#!/usr/bin/env bash

function fix_esp8266_boards()
{
  file=`find $HOME/.arduino15/packages/esp8266/ -type f -name 'boards.txt'`
  for i in generic nodemcu nodemcuv2 d1_mini esp8285
  do
    echo "${i}.build.f_cpu=80000000L" >> $file
  done
  return 0
}
