# strcopy is a program to extract .str .xa file from a Playstation(R) 1 image.

You will have to extract the .str or .xa file using ISOBuster or other programs which support 2352 mode extraction from CD image.
This program will convert the 2352 mode file into correct file size which must be in multiple of 2336 bytes.

Usage:

strcopy example.str example.tmp

del example.str

ren example.tmp example.str
