@echo off

call x64.bat

cl ..\priv.c advapi32.lib
