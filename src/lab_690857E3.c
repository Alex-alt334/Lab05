#include <stdio.h>
void copy(char *psource, char *ptarget, unsigned num_char)
{
   unsigned count = 0;
    while (count < num_char && *psource != '\0')
    {
        *ptarget = *psource;
        ptarget++;
        psource++;
        count++;
    }
    *ptarget = '\0';
}

void concatenate(char *psrc1, char *psrc2, char *ptarget, unsigned buffer_size)
{
    // 1. Copy psrc1 to the target buffer (leave 1 byte for null terminator)
    if (buffer_size <= 1) 
    {
        if (buffer_size == 1) 
        {
            *ptarget = '\0';
        }
        return;
    }

    copy(psrc1, ptarget, buffer_size - 1);

    // 2. Find the end of the first copied string in ptarget to know where to append
    char *p = ptarget;
    unsigned len1 = 0;
    while (*p != '\0') 
    {
        p++;
        len1++;
    }

    if (len1 < buffer_size - 1) 
    {
        unsigned remaining_space = buffer_size - 1 - len1;
        copy(psrc2, p, remaining_space);
    }
}

// DO NOT change the code below
#ifndef ___TEST___
int main(void)
{
    char buffer[100];
    char *source = "This is the first sentence.  ";
    char *target = "This is the second sentence.";

    concatenate(source, target, buffer, 70);

    printf("%s", buffer);
    return 0;
}
#endif
// DO NOT change the code aboveS