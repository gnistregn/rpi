# crunky

> 32 bits ought to be enough for anyone


Attempt to build a "unikernel" for Raspberry Pi 3

## setup

Define the environment variable CRUNKY in your .bashrc file:
```
export CRUNKY=/path/to/crunky
```


## Dissasembly

One of 
```
aarch64-linux-gnu-objdump -D kernel8.elf | less
arm-none-eabi-objdump -D kernel.elf 
```

## FAT32 and SD

Adapted from https://github.com/bztsrc/raspi3-tutorial

File reading is in example 21. It crashes, though. It's clear that there's support for reading, though.
The use of memory is very suspicious for fat.c. Create a file called `test.txt` on the first FAT32
partition. You should see at least some dumping out of the contents of the file.


## In this directory

* [arch](arch.md) - architecture-specific information
* [interrupts](interrupts.md)
* [malloc](malloc.md) - also discusses the heap
* [usb](usb) - it's not easy, that's for sure.

## Links to libraries

* [bcm2835](https://www.airspayce.com/mikem/bcm2835/) v1.68 used
* [tinyprintf](https://github.com/cjlano/tinyprintf.git). Doesn't handle floats

## Links to other sites

* [keyboard](https://www.cl.cam.ac.uk/projects/raspberrypi/tutorials/os/input01.html#keyboards) - possible implementation of reading keyboard. Using assembler.
* [Raspberry Pi IoT In C - Almost Realtime Linux ](https://www.iot-programmer.com/index.php/books/22-raspberry-pi-and-the-iot-in-c/chapters-raspberry-pi-and-the-iot-in-c/33-raspberry-pi-iot-in-c-almost-realtime-linux?showall=1) book
* [VMWos](http://www.deater.net/weave/vmwprod/vmwos/) - homebrew OS for RPi
