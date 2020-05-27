/*
 * this is no code revision , this is simply to revise about array variables and pointers
 * so when an array variable is declares as 
 * int num[]={1,2,33};
 * num is an array variable, there is no memory allocated to it , it can only point to address of 1 . &num==num
 * but for an pointer &pointer != pointer
 * size of an array variable is the size of the array itself. in this case 3*8bytes.
 * but sizeof a pointer is 4 bytes or 8 bytes.
 * array variables can be used as pointers num[0]=*num ,num[2]=*(num+2)
 * this is the reason that is pointer arithmatic why the index starts from 0
 * pointers have types also for pointer arithmatic so that when added or subtracted it can compensate according to the data type .char-1 byte, int -4 byte
 * so case of lethal list says 3[doses] which is also *(3+doses) == *(doses+3)==doses[3]
 */
