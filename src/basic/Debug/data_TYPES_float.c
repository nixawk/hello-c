/* 64 bit */

int
main()
{
    float x = 1.2;
    return 0;
}

/*

   0x0000555555554660 <+0>: push   rbp
   0x0000555555554661 <+1>: mov    rbp,rsp
=> 0x0000555555554664 <+4>: movss  xmm0,DWORD PTR [rip+0x98]        # 0x555555554704
   0x000055555555466c <+12>:    movss  DWORD PTR [rbp-0x4],xmm0
   0x0000555555554671 <+17>:    mov    eax,0x0
   0x0000555555554676 <+22>:    pop    rbp
   0x0000555555554677 <+23>:    ret

*/