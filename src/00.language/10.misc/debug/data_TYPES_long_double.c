int
main()
{
    long double x = 1.2;
    return 0;
}


/*

   0x0000555555554660 <+0>: push   rbp
   0x0000555555554661 <+1>: mov    rbp,rsp
=> 0x0000555555554664 <+4>: fld    TBYTE PTR [rip+0xa6]        # 0x555555554710
   0x000055555555466a <+10>:    fstp   TBYTE PTR [rbp-0x10]
   0x000055555555466d <+13>:    mov    eax,0x0
   0x0000555555554672 <+18>:    pop    rbp
   0x0000555555554673 <+19>:    ret  

*/