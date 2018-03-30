//
// Created by zsh_o on 2018/3/29.
//

#include <stdlib.h>
#include <stdio.h>

/* Declare imported function so that we can actually use it. */
__declspec(dllimport) int __cdecl Add(int a, int b);

int main(int argc, char** argv)
{
    printf("%d\n", Add(6, 23));

    return EXIT_SUCCESS;
}