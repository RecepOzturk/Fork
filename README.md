# Fork
The mini program to understand usage fork() function

It was published for students and interested persons who interest of usage fork() function and want to understand multiprocess structure.

You have one parent process (P1).

It has four child process (three processes are child, the other one is grandson) and they do following items, respectively.

o The first child (C1) process job is to create a file; its name is opSys.txt in working directory.

o The fourth child (C4) process (the grandson). Its parent process (C2) is child for the parent process (P1) in this system.

o The second child (C2) process take an input as password from user and write this input to opSys.txt file.

o The third child (C3) process compare the parent process (P1) id with the input. If it is matched, write “matched” to screen, else “not matched”;
