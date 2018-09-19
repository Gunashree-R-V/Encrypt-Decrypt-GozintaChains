# Encrypt-Decrypt-GozintaChains
 Using Gozinta chains to generate a new password encoding algorithm for a typical unix text file.
 
## PROBLEM STATEMENT

A gozinta chain for n is a sequence {1,a,b,...,n} where each element properly divides the next. There are eight gozinta chains for 12: {1,12} ,{1,2,12}, {1,2,4,12}, {1,2,6,12}, {1,3,12}, {1,3,6,12}, {1,4,12} and {1,6,12}. Let g(n) be the number of gozinta chains for n, so g(12)=8. g(48)=48 and g(120)=132. Use these chains to generate a new password encoding algorithm for a typical unix text file.

## MODEL
1.Usage: $ make -f makefile <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	 $./encoder file-name key 0(encryption)/1(decryption)\n

2.The key can be alphanumeric.

3.The input file must contain only alphanumeric characters and space. [a-zA-z0-9 ]

4.During the encryption, for a given input file the encrypted contents are stored in a file called encrypt.txt

5.For decryption pass the encrypt.txt file along with the key, the decrypted content is displayed on the terminal.

## APPROACH

### CIPHER SYSTEM DETAILS

	1.Key : A alphanumeric key
	2.Cipher Generation: 
		Generate the first longest Gozinta chain based upon the ascii values of each character in the given Key, combine the chains to form the Shift Key. The Shift Key is wrapped around the text, the corresponding text character value and the key value is added and after the mod operation the value of the output cipher character is determined.
	3.Deciphering:
		Given the Key as input, the shift key is calculated. From the value of the corresponding text character , the key value is subtracted and after the mod operation the input text value is retrieved.
  
### CIPHER SYSTEM OUTCOME

	Upon calling the encrypt function with the input text file and the key,  based on the cipher generation, a encrypt.txt file is generated where in the input text file contents are encrypted and stored.
	Upon calling the decrypt function with the key and encrypt.txt file, the Deciphering process is carried out and the result is displayed on the terminal.
	If the key provided is the original key then the original contents are retrieved accurately
	If the key provided is not the original key, the output will contain garbled text. 

## Contributors
1. <a href= "https://www.github.com/deep-j"> Deepika </a> <br/>
2. <a href= "https://www.github.com/gunashree-r-v"> Gunashree </a> <br/>
