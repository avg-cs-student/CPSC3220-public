# Helpful tools for x86_64 OS debugging.

## final-checks:
  <ins>_Description_</ins>: 

  Bash script that checks for possible magic numbers, dead code, and unwanted print
  statements.

 <ins>_How To_</ins>: 
 - Clone this script into your project's directory
 - run `./final-checks` to check all .c and .h files for potential careless mistakes
 
## fat-generator:
  <ins>_Description_</ins>:
  
  Bash script for generating random FAT12 images.
  
  <ins>_How To_</ins>:
  - Clone this repository onto a linux x86 machine (tested on Joey machines)
  - Run ```./generate-image [-d <subdirectory-depth>] [-x <0|1>] [-r <0|1>] [-o <output-filename>]```
  - Example ```./generate-image -d 2 -x 1 -l 0 -o myimage``` would generate an image named 'myimage.img' with at most 2 levels of nested subdirectories, deleted files allowed, no large directories
  

## test-sctracer:
  <ins>_Description_</ins>: 
  
  Bash script for testing your "sctracer" program. 

  <ins>_Requires_</ins>:
  
  - "getsyscall.c" (found in this repo)
  - Must have your own original, compiled test files.

  <ins>_How To_</ins>: 

  - Clone this repository onto an x86_64 Linux machine in the same folder as your project1.
  - Ensure you have one or more compiled test files.
  - Edit the variable at the top of test-sctracer to include the names of YOUR test executables
  - Compile "getsyscall.c" and name it "getsyscall"
  - Ensure your "sctracer" is compiled
  - Run "./test-sctracer" in your shell.
  _(tested on SoC Linux machine "joey1")_

## getsyscall.c[^1]: 

  <ins>_Description_</ins>: 
  
  Retrieves name of system call by number
  
## syscall_def.txt[^1]:

  <ins>_Description_</ins>: 
  
  Information regarding linux system calls on SoC lab machines
  
  
[^1]: Adapted from [Filippo Valsorda's post](https://filippo.io/linux-syscall-table/)
