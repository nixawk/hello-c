/* 64 bit */

int
main()
{
    short x = 1;
    return 0;
}

/*

   0x0000555555554660 <+0>: push   rbp
   0x0000555555554661 <+1>: mov    rbp,rsp
=> 0x0000555555554664 <+4>: mov    WORD PTR [rbp-0x2],0x1
   0x000055555555466a <+10>:    mov    eax,0x0
   0x000055555555466f <+15>:    pop    rbp
   0x0000555555554670 <+16>:    ret 

*/