global _start


section .text
_start:
sub byte [worst_case], 4
add byte [worst_case+1], 4

add byte [worst_case], 4
sub byte [worst_case+1], 4


section .data
worst_case db 0x00, 0xfe

