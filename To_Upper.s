	.file	"To_Upper.s"
	.text
	.globl	To_Upper
	.type	To_Upper, @function

/* **********************
    Name: Francis Lu
    Wisc ID Number: 9080557540  
    Wisc Email: flu38@wisc.edu
************************ */


To_Upper:

# C version
/* **********************
 void To_Upper(char *str){
      int i = 0;
   
   while(*(str+i)!='\0'){
		if(*(str+i)>=97 && *(str+i)<=122){
			*(str+i)=*(str+i)-32;
		  }
	  	i++;
	  }
 }
    

************************ */


# Memory Layout
/* ************************ 
    Make a table showing the stack frame for your function (in the comment block)
    The first column should have a memory address (e.g. 8(%rsp))
    The second column should be the name of the C variable used above
    Update the example below with your variables and memory addresses
        -4(%rbp)  |  int x
        -24(%rbp)  |  int *px
        -32(%rbp) | load effective address
************************ */


# Prologue
        pushq   %rbp
        #push the value onto the stack
        
        movq    %rsp, %rbp
        #move whatevers in rsp into rbp
        
# This code prints the letter 'a' (ascii value 97)
# Use this for debugging
# Comment out when finished - your function should not print anything
# Note putchar overwrites all caller saved registers including argument registers
	# movl	$97, %eax
	# movl	%eax, %edi
	# call	putchar@PLT


# Body of function
      
      movq    %rdi, -24(%rbp) 
      #moves whatever is in rdi into the pointer
      
      movl    $0, -4(%rbp) 
      #increments the 0
      
      jmp     Conditional 
      #jumps to the conditional 
       
Body1:
        movq    -24(%rbp), %rax 
        #moves whatever is in the pointer into rax
        
        movl    -4(%rbp), %edx
        #moves whatever is in the index into edx
      
        
        addq    %rdx, %rax
        #adds whatever is in rdx into rax
        
        movb   (%rax), %al
        #moves whatever value is in rax into al
        
        cmpb    $97, %al
        #compares 97 the value of a to whatever is in al
        
        jle     Incrementation
        #jumps to increment block
   
Body2:        
        movq    -24(%rbp), %rax
        #move whatever is in the pointer into rax
        
        movl    -4(%rbp), %edx
        #move whatever is in the index into edx 
        
        addq    %rdx, %rax
        #add whatever is in rdx into rax
        
        movb  (%rax), %al
        #moves whatever is in rax into al
        
        cmpb    $122, %al
        #compares al to lower case z 
        
        jg      Incrementation
        #jumps to increment block
 
Body3:        
        movl    -4(%rbp), %edx
        #moves whatever is in the index into edx
        
        movq    -24(%rbp), %rax
        #moves what the pointer is pointing at into rax
        
        addq    %rdx, %rax
        #adds whatevers in rdx into rax
        
        movb  (%rax), %al
        #moves whatever is in rax into al
        
        leal    -32(%rax), %ecx
        #load effective address
        
        movl    -4(%rbp), %edx
        #move whatevers in the index into edx

        movq    -24(%rbp), %rax
        #move address into rax
        
        addq    %rdx, %rax
        #addes whatever is in rdx with rax
       
        movl    %ecx, %edx
        #moves the load effective address into edx
        
        movb    %dl, (%rax)
        #moves dl into whatevers in the index

Incrementation:
  
        incl     -4(%rbp)
        #increment the value in rbp by 4 bytes


Conditional:
  
        movq    -24(%rbp), %rax
        #move the pointer address into rax
        
        movl    -4(%rbp), %edx
        #move index into edx
        
        addq    %rdx, %rax
        #store whatever is in rdx into rax

        movb  (%rax), %al
        #move address into al

        andb  %al, %al
        #check if the als are equal
        
        jne    Body1
        #if so go to the first body
        
      


# Epilogue
 ENDING:   
      popq    %rbp  
      #clear stack
      
      ret 
      #return
