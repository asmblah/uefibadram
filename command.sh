#!/bin/sh
docker run --rm -v "$PWD":/uefibadram -w /uefibadram $(docker build -q .) $@
