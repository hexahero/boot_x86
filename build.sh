mkdir bin
cd src

nasm -f elf32 boot32P.asm -o ../bin/boot.o

gcc -fno-pie -m32 startup.cpp ../bin/boot.o -o ../bin/boot.bin -nostdlib -ffreestanding -std=c++11 -mno-red-zone -fno-exceptions -nostdlib -fno-rtti -Wall -Wextra -Werror -T ../ldscript.ld 
gcc -fno-pie -m32 startup.cpp ../bin/boot.o -o ../bin/boot.img -nostdlib -ffreestanding -std=c++11 -mno-red-zone -fno-exceptions -nostdlib -fno-rtti -Wall -Wextra -Werror -T ../ldscript.ld