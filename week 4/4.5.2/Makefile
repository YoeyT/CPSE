.PHONY: run

run:
	Makefile.compress_native run && Makefile.decompress_due run

main.asm: compressed.asm main.asm print.cpp


include Makefile.compress_native
include Makefile.decompress_due