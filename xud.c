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
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <xue/xue.h>

void _vmcall(uint64_t rax, uint64_t rbx, uint64_t rcx, uint64_t rdx);

static inline void test(uint64_t rax)
{
    _vmcall(rax, 0, 0, 0);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("ERROR: xud expects 1 arg\n");
        return 22;
    }

    if (!strcmp("init", argv[1])) {
        test(XUE_INIT);
    } else if (!strcmp("disable", argv[1])) {
        test(XUE_DISABLE);
    } else if (!strcmp("dump", argv[1])) {
        test(XUE_DUMP);
    }
}
