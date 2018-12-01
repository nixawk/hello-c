int
main()
{
    unsigned char x = 'a';
    return 0;
}

/*

   0x0000555555554660 <+0>: push   rbp
   0x0000555555554661 <+1>: mov    rbp,rsp
=> 0x0000555555554664 <+4>: mov    BYTE PTR [rbp-0x1],0x61
   0x0000555555554668 <+8>: mov    eax,0x0
   0x000055555555466d <+13>:    pop    rbp
   0x000055555555466e <+14>:    ret

*/