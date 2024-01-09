#!/bin/sh

sudo mkdir -p /Volumes/efi
sudo mount -t msdos /dev/disk0s1 /Volumes/efi

echo 'Mounted EFI partition'
