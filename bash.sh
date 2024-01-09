#!/bin/sh
docker run --rm -v "$PWD":/uefibadram -w /uefibadram -it $(docker build -q .) bash
