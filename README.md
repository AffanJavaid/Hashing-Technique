# Hashing-Technique
Hashing using C++
In this assignment, you are required to 
1-	Implement Directory Structure
2-	Allocate disk space to the files.

You are required to have to use Hash Table Implementation of Directory Structure. Next, to allocate disk space to the files, you may use one of the following techniques.
1.	Contiguous Allocation.
2.	Linked Allocation
3.	FAT
4.	Indexed Allocation
Write a C/C++program to perform the following tasks.
1-	Define appropriate data structures to be able to define and declare a hash table to implement the directory structure using open hashing (separate chaining) technique.	                   (10 marks)
2-	Write an appropriate routine for memory initialization using open hashing. Use this routine to allocate memory to the above mentioned hash table.   		                           (10 marks)
3-	Write an appropriate routine to search a particular file in the directory system. Use this routine to find a specific record by using the FileName.extension as an index into the table. The routine will return the pointer to the location of the file in the directory structure
(10 marks)
4-	Write an appropriate routine to create a new file and insert it at the appropriate location of the directory structure.
 (15 marks)	
5-	Write a routine to simulate Disk allocation to a new file. This routine will be used by the routine # 4. (You can use one of the four disk allocation scheme).			    (30 marks)	
a)	If the available disk space is less than the required space, the program should display error message.
b)	In the case of contiguous disk allocation scheme, if continuous available disk space is less than the required space, then a different error message should be displayed. 
c)	Bonus Marks to implement space defragmentation (only applicable to contiguous disk allocation scheme).
6-	Write an appropriate routine to delete a specific file from the Directory Structure.  
The routine should also deallocate (delete from) the Disk space for the deleted file for future possible re-use. 
(15 marks)	
7-	Write an appropriate routine to display the contents of the directory structure (i.e., the hash table) visually. You can either use graphics library or display it without using graphics in some innovative way. You should also display the current status of Disk (by somehow showing status of all blocks).			                                                                            (10 marks)	
 
