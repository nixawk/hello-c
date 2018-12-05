/* 64 bit */

int
main()
{
    double x = 1.2;
    return 0;
}

/*

   0x0000555555554660 <+0>: push   rbp
   0x0000555555554661 <+1>: mov    rbp,rsp
=> 0x0000555555554664 <+4>: movsd  xmm0,QWORD PTR [rip+0x9c]        # 0x555555554708
   0x000055555555466c <+12>:    movsd  QWORD PTR [rbp-0x8],xmm0
   0x0000555555554671 <+17>:    mov    eax,0x0
   0x0000555555554676 <+22>:    pop    rbp
   0x0000555555554677 <+23>:    ret

*/