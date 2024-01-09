#!/bin/sh

set -e

cwd=$(pwd)

if [ ! -d .posix-uefi ]; then
    git clone https://gitlab.com/bztsrc/posix-uefi.git .posix-uefi
    ln -s "./.posix-uefi/uefi" uefi
fi

docker build .
