cmd_/home/mohan/practiceDriver/module/mod1.ko := ld -r -m elf_x86_64 -z max-page-size=0x200000 -T ./scripts/module-common.lds --build-id  -o /home/mohan/practiceDriver/module/mod1.ko /home/mohan/practiceDriver/module/mod1.o /home/mohan/practiceDriver/module/mod1.mod.o ;  true