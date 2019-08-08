# Questions

## What's `stdint.h`?

It is a header file.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

They are aliases for C/C++ primitive data types and we need them to define the structs BITMAPFILEHEADER, BITMAPINFOHEADER and RGBTRIPLE.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

They are 1, 4, 4 and 2 bytes respectively.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

0x424d

## What's the difference between `bfSize` and `biSize`?

bfSize is the size of the bitmap file in bytes, whereas biSize is the number of bytes required by the structure.

## What does it mean if `biHeight` is negative?

If the biHeight is negative, it means that the bitmap is a top-down DIB which originates at the top-left. It also means that this DIB cannot be compressed.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in `copy.c`?

inptr and outptr

## Why is the third argument to `fread` always `1` in our code?

Because that is the quantity of units of size that it reads from the file it is pointed to. 

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

0

## What does `fseek` do?

It sets the pointer position to that of padding from the beginning.

## What is `SEEK_CUR`?

It is the current position of the file pointer.
