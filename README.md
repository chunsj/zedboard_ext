# zedboard_ext
Vitis Embedded Acceleration Platform for Zedboard (Vitis 2021.2)

I'm trying to learn Vitis Acceleration Programming and want to use my own zedboard. However, I cannot find official Vitis Platform for zedboard, so I have created one for me.
I have referenced many information from this site https://highlevel-synthesis.com/2021/08/15/vitis-2020-1-embedded-platform-for-zybo-z7-20/ and there's udemy lecture which is why I want to create this platform.

The only difference from zedboard_base is that this platform used ext4 fs root partition(it's specified in the kernel boot argument). I have problems with emulation running, however, hardware target runs flawlessly (tested with vector addition example).

You can just clone this repository and copy zedboard_ext directory (the one in the repository) under the Vitis/2021.2/platforms/ and open Vitis and create a new Application Project. If you were in my situation, I just hope this could help you.
