@echo off

mkdir build
pushd build
cl -Zi ..\code\pluralsight.c
popd