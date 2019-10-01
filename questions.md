# Questions

## What's `stdint.h`?
_It is a header file that defines
specific exact-width integers 
for 8, 16, 32, & 64 bytes._



## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Defines specifc integer sizes that won't be confused
on different computers.
uint8_t  1 byte unsigned in a 8-bit computer.
uint16_ means 2 bytes unsigned or in binary 2^16 or 65536 bits
uint32_t means 4 bytes unsigned (32-bit computer) 
int32 means 32 bits
uint64_t means 8 bytes (64-bit computer) a LONG LONG

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE    1 byte  (8 bits)
DWORD   4 bytes (32 bits)
LONG    4 bytes (32 bits)
WORD    2 bytes (16 bits)

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

ASCII "B" ASCII "M"

## What's the difference between `bfSize` and `biSize`?

bfsize - size of the bmp file in bytes
bisize - size of the structure in bytes

## What does it mean if `biHeight` is negative?

if biHeight is negative the image is bottom down

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

color depth is bibitcount (0-255)

## Why might `fopen` return `NULL` in `copy.c`?

no file or can't find file

## Why is the third argument to `fread` always `1` in our code?

we are reading 1 element (pixel) at a time

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3 so  (3*3) = 9 plus 3 = 12 a multple of 4

## What does `fseek` do?

changes the pointer offent

## What is `SEEK_CUR`?

reports the current position of cursor in the file
