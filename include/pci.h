//
// Copyright (C) 2019 Assured Information Security, Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef XUE_PCI_H
#define XUE_PCI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "portio.h"

static inline int cf8_is_enabled(uint32_t cf8)
{ return ((cf8 & 0x80000000UL) >> 31) != 0; }

static inline uint32_t cf8_to_bus(uint32_t cf8)
{ return (cf8 & 0x00FF0000UL) >> 16; }

static inline uint32_t cf8_to_dev(uint32_t cf8)
{ return (cf8 & 0x0000F800UL) >> 11; }

static inline uint32_t cf8_to_fun(uint32_t cf8)
{ return (cf8 & 0x00000700UL) >> 8; }

static inline uint32_t cf8_to_reg(uint32_t cf8)
{ return (cf8 & 0x000000FCUL) >> 2; }

static inline uint32_t cf8_to_off(uint32_t cf8)
{ return (cf8 & 0x00000003UL); }

static inline uint32_t cf8_read_reg(uint32_t cf8, uint32_t reg)
{
    const uint32_t addr = (cf8 & 0xFFFFFF03UL) | (reg << 2);
    _outd(0xCF8, addr);
    return _ind(0xCFC);
}

static inline void cf8_write_reg(uint32_t cf8, uint32_t reg, uint32_t val)
{
    const uint32_t addr = (cf8 & 0xFFFFFF03UL) | (reg << 2);
    _outd(0xCF8, addr);
    _outd(0xCFC, val);
}

#ifdef __cplusplus
}
#endif
#endif
