There are two DNA sequences. Your job is to find the sequence similarity between the two genetic codes. 
 
A DNA sequence is presented as a sequence of characters, which may be 'A', 'G', 'C' or 'T'. The similarity between the two DNA sequences can be found using LCS. 
 
LCS means the longest subsequence common to all sequences in a set of sequences.  
 
You are given two DNA sequences. Print the length of LCS of the two sequences. 



[Input]
The first line contains a single integer T, the number of total test cases. (1 ¡Ü T ¡Ü 10)
 
The first and second lines of each test case contain DNA sequences. The length of a DNA sequence is less than or equal to 1,000. 


[Output] 
For each test case, on a single line, print the number of test case ¡°#(TC) ¡°and the length of LCS of the two DNA sequences.

Input Example:

1        // number of total test case

ACGT    // 1st DNA sequence

AGCT    // 2nd DNA sequence

Output Example:

#1 3   //1st TC output value