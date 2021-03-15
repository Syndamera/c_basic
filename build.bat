@echo off

mkdir build
pushd build
cl -Zi ..\code\main.c Kernel32.lib
popd