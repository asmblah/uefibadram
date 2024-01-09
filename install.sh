#!/bin/sh

sudo mkdir -p /Volumes/efi
sudo mount -t msdos /dev/disk0s1 /Volumes/efi

mkdir -p /Volumes/efi/EFI/asmblah

cp uefibadram.efi /Volumes/efi/EFI/asmblah

sudo diskutil umount /Volumes/efi

echo 'Installed into EFI partition'
