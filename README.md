# Helpful tools for x86_64 OS debugging.

__test-sctracer__:
  _Description_: Bash script for testing your "sctracer" program. 
  _Requires_: 
        1. "getsyscall.c" (found in this repo)
        2. Must have your own original, compiled test files.
  _How To_: (tested on SoC Linux machine "joey1")
        1. Clone this repository onto an x86_64 Linux machine in the same folder as
                your project1.
        2. Ensure you have one or more compiled test files.
        3. Compile "getsyscall.c" and name it "getsyscall"
        4. Ensure your "sctracer" is compiled.
        5. Run "./test-sctracer" in your shell.

[^1]__getsyscall.c__: 
  _Description_: Retrieves name of system call by number
  
[^1]__syscall_def.txt__:
  - Information regarding linux system calls on SoC lab machines
  
  
[^1]: Adapted from [Filippo Valsorda's post](https://filippo.io/linux-syscall-table/)
