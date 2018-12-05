/* 64 bit */

int
main()
{
    int x = 1;
    return 0;
}

/*

   0x0000555555554660 <+0>: push   rbp
   0x0000555555554661 <+1>: mov    rbp,rsp
=> 0x0000555555554664 <+4>: mov    DWORD PTR [rbp-0x4],0x1
   0x000055555555466b <+11>:    mov    eax,0x0
   0x0000555555554670 <+16>:    pop    rbp
   0x0000555555554671 <+17>:    ret  

*/