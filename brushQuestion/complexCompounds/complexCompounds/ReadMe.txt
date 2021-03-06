Problem:




APIs to be implemented: init(), addDB() and SearchBestCase() (Check main for exact signatures).

Helper API: CalculateRelation()




A complex compound is defined by an ordered set of 5 strings{str1, str2, str3, str4, str5}. On each call of addDB(), a complex compound will be added to the database. Once all the compounds are added through successive calls to addDB(), SearchBestCase() API will be called repeatedly. Given as its parameter will be the description of a new complex compound. It should return the maximum correlation possible of the new compound on comparing it with the existing database. Exact methodology is as follows:

CalculateRelation(str1, str2) gives the correlation between two strings.

Correlation between two complex compounds  = For all i, sum of CalculateRelation(stri1, stri2) where stri1 is the ith string of compound1 and stri2 is the ith string of compound2.

The return value of SearchBestCase(compound) will be the maximum correlation possible between the new compound and the already existing database's compounds having atleast one component string similar to the corresponding string of new compound.

 

Constraints:

1. For one test case, addDB() will be called successively. Only after that, SearchBestCase() will be called.

2. For each test case, calls to addDB() <= 5000; also, calls to SearchBestCase() <=5000;

3. All the five component strings of the new compound will be present in the existing database.  
