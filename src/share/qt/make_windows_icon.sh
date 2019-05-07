#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/entanglement.png
ICON_DST=../../src/qt/res/icons/entanglement.ico
convert ${ICON_SRC} -resize 16x16 entanglement-16.png
convert ${ICON_SRC} -resize 32x32 entanglement-32.png
convert ${ICON_SRC} -resize 48x48 entanglement-48.png
convert entanglement-16.png entanglement-32.png entanglement-48.png ${ICON_DST}

