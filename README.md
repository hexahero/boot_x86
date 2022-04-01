##boot_x86
**One more pointless bootloader implemented in educational purposes**

##                          **BUILD AND RUN**                 

**UNDER LINUX ENVIRONMENT**

1. Install<br>
`#apt-get update`<br>
`#apt-get install gcc`<br>
`#apt-get install build-essential manpages-dev`<br>
`#apt-get install nasm`<br>
`#apt-get install qemu`<br>
`#apt-get install qemu-system-x86`<br>


2. Build<br>
`#./build.sh`

3. Run<br>
`#./run.sh`

**TERMINAL OUTPUT (VGA Blank Mode)**

1. Build<br>
`#./build.sh`

2. Run with tty output<br>
```./run_wsl_tty.sh```

**RUN ON BARE METAL**

1. Build<br>
`#./build.sh`

2. Simply write `bin/krnl.img` on your USB drive using any image file burning software<br>

**<!>** Frequent repartitioning may damage your drive

**FOR WSL USERS**

Graphics output:<br>

1. Install and run **VcXsrv Windows X Server** https://sourceforge.net/projects/vcxsrv/<br>

2. Check **"Disable access control"** at the startup settings window, save config if you wish, press **"finish"**<br>

3. Build<br>
`#./build.sh`

4. Run<br>
```./run_wsl_gfx.sh```
