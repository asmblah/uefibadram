# UEFI Bad RAM

A UEFI loader to disable a defective area of RAM before booting into macOS.

Tested on a MacBook Pro 2019 on macOS Sonoma.

Use **[Memtest86+](https://memtest.org/)** to find the exact location and size of the area you have to disable.  
Use **[Refind](https://www.rodsbooks.com/refind/)** to execute the loader before booting into macOS.

## Installation

### Install rEFInd
See [Installing rEFInd]().

### Install MemTest86
#### Option 1:
Create a bootable USB memory stick.

#### Option 2:
Add MemTest86 as a UEFI boot loader to be run by rEFInd:
- Mount the EFI partition, you can use the `./mount.sh` script in this project to do so.
- Copy all files from the `EFI\BOOT` folder on the CD to `/Volumes/efi/EFI/tools/memtest86`.
  You should then have a file at the exact path `/Volumes/efi/EFI/tools/memtest86/BOOTX64.efi` for example.
- Unmount the EFI partition (`./unmount.sh`).

### Set up the uefibadram toolchain
- Run `./setup.sh`

### Configure uefibadram
Edit the start and end addresses `startPhysicalAddress` and `endPhysicalAddress` in `./uefibadram.c` as needed based on your results of running MemTest86.

### Build and install uefibadram
- Run `./build.sh`
- Run `./install.sh`

### Reboot to test
You should see rEFInd on boot, you will need to run uefibadram each time before pressing enter to return to rEFInd to boot into macOS.

## References
- https://wiki.osdev.org/UEFI_App_Bare_Bones
- https://github.com/0nelight/macOS-Disable-RAM-Areas

[Installing rEFInd]: https://www.rodsbooks.com/refind/installing.html
[MemTest86]: https://memtest.org/
