@if not exist .\bin\. mkdir .\bin
clang -o .\bin\hddled.exe -std=c99 -Wall -Wextra -pedantic -Wvla -Wunused-macros -Wshadow -Wno-c11-extensions -O0 -g -gcodeview main.c -fuse-ld=lld -nostdlib -Wl,--pdb= -Wl,--subsystem,windows -Xlinker -stack=0x200000,0x200000 -mno-stack-arg-probe -lkernel32 -luser32 -lshell32 -lole32 -lwbemuuid
@copy busy.ico .\bin\busy.ico
@copy idle.ico .\bin\idle.ico
