/* Francis Lu
 * 9080557540
 */
#include <stdio.h>

// THE CACHE
struct LINE{
    char valid;
    int tag;
    char data[32];
};

struct SET{
    struct LINE line[1];
};

struct CACHE {
    struct SET set[8];
} cache;

// GLOBALDATA
// increment these in your function
unsigned hit_count  = 0;
unsigned miss_count = 0;
unsigned read_data_count = 0;

// SYSTEM BUS 
// call Read_Data_From_Ram to update this
char system_bus[32];



// READ DATA FROM RAM
// this function copies 32 character from the text file to
// the system_bus array aligned with the system bus
// (we will not test this with input larger than the text file)
void Read_Data_From_Ram(unsigned address) {
    address >>= 5; address <<= 5; // get align the data
    read_data_count++;
    FILE *file;
    file = fopen("alice_in_wonderland.txt", "r");
    fseek(file, address, SEEK_SET);
    for (int i = 0; i<32; i++) system_bus[i] = fgetc(file);
    return;
}


// COMPLETE THE FOLLOWING FUNCTION 
//
// this code should check to see if the data in the cache is valid and the tag matches
// if so it should return the char matching the address and increment the hit count
//
// if not it should read the data from the system bus copy it into the cache and 
// increment the miss count and return the char matching the address
// 
char Read_Data_From_Cache(unsigned address){
    
   int E = 1; //local variable
   int s = 8; //local variable
   int b = 2; //local variable
   int i = 0; //local varaible
   
  
   
   int tag = address >> (s - E); //set tag to an address right shifted 7 bits
   int set = address >> (2*b); set &= (s-E); //set the set to a right shifted address of 4 bits and then and it with 7
   int offset = address&15; //and the offset with 15.
      
      //if loop to check if the tag is the same and is valid
      if(cache.set[set].line[1].valid == 1 && cache.set[set].line[1].tag == tag){
          hit_count++; //incrementing hit count
          return cache.set[set].line[1].data[offset]; //returns the character 
      }
      else{ //else statement for if the tag doesn't match or the line isn't valid
          Read_Data_From_Ram(address); //access the data from ram
          miss_count++; //increment miss count
          
          //for loop to go through data and system bus
          for(i; i < 32; i++){
            cache.set[set].line[1].data[i] = system_bus[i]; //copy over the value from the system bus into the cache
            cache.set[set].line[1].tag = tag; //set the tag to the tag of the copied value from the bus
          }
           cache.set[set].line[1].valid = 1; //set valid to one to match up and reset
           return cache.set[set].line[1].data[offset]; //return the character matching the address
      }
    
}

int main() {
    // INITIALIZE CACHE
    for (int i = 0; i<8; i++) cache.set[i].line[0].valid = 0;
    
    // READ SOME DATA
    char c;
    c = Read_Data_From_Cache(0); printf("data = %c : hit count = %-3u : miss count = %-3u : read data count = %-3u\n", c, hit_count, miss_count,read_data_count );
    c = Read_Data_From_Cache(1); printf("data = %c : hit count = %-3u : miss count = %-3u : read data count = %-3u\n", c, hit_count, miss_count,read_data_count );
    c = Read_Data_From_Cache(2); printf("data = %c : hit count = %-3u : miss count = %-3u : read data count = %-3u\n", c, hit_count, miss_count,read_data_count );
    c = Read_Data_From_Cache(3); printf("data = %c : hit count = %-3u : miss count = %-3u : read data count = %-3u\n", c, hit_count, miss_count,read_data_count );
    c = Read_Data_From_Cache(4); printf("data = %c : hit count = %-3u : miss count = %-3u : read data count = %-3u\n", c, hit_count, miss_count,read_data_count );
    // WRITE A LOT MORE TESTS

    return 0;
}

