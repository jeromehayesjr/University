# This program writes "hello"
# to the standard output stream.

.section .data

# Use "bytes" to label the location
# of the string "hello\n" in memory.
bytes:
.ascii "hello Alice\n"

.section .text
.globl _start

_start:

# Step 1: use the Linux write-bytes
# command to write the hello string
# into the standard output stream.

# Store 1 in register ebx.
# This directs write-bytes to
# write the bytes into the
# standard output stream.
movl $1, %ebx

# Store the address of the bytes
# into register ecx.
movl $bytes, %ecx

# Store the number of bytes to write
# into register edx.
movl $14, %edx

# Store the numerical label of
# the write-bytes command in
# 4 in register eax.
movl $4, %eax

# Tell Linux to run the command
# in register eax.
int $0x80

# Step 2: Use the Linux exit command
# to terminate the program.

# Store the status code in register ebx.
# (Zero means normal termination.)
movl $0, %ebx

# Store the numerical label of
# the exit command in register eax.
movl $1, %eax

# Tell Linux to run the command
# in register eax.
int $0x80
