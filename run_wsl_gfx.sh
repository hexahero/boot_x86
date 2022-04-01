export DISPLAY="`grep nameserver /etc/resolv.conf | sed 's/nameserver //'`:0"
DISPLAY=127.0.0.1:0
echo xfce4-session > ~/.xsession
qemu-system-x86_64 -drive format=raw,file=bin/boot.bin,index=0,if=floppy