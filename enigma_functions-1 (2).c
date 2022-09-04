/* Francis Lu
 * 9080557540
 */

#include "enigma.h"

const char *ROTOR_CONSTANTS[] = {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ", // Identity Rotor (index 0 - and useful for testing):
        "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
        "AJDKSIRUXBLHWTMCQGZNPYFVOE",
        "BDFHJLCPRTXVZNYEIWGAKMUSQO",
        "ESOVPZJAYQUIRHXLNFTGKDCMWB",
        "VZBRGITYUPSDNHLXAWMJQOFECK",
        "JPGVOUMFYQBENHZRDKASXLICTW",
        "NZJHGRCXMYSWBOUFAIVLPEKQDT",
        "FKQHTLXOCBJSPDZRAMEWNIUYGV",
};

// This method reads a character string from the keyboard and 
// stores the string in the parameter msg.
// Keyboard input will be entirely uppercase and spaces followed by 
// the enter key.  
// The string msg should contain only uppercase letters spaces and 
// terminated by the '\0' character
// Do not include the \n entered from the keyboard
void Get_Message(char msg[]){
    int i; 
    scanf("%[^\n]%*c", msg); //scans the inputed keys including the enter key
    for(i = 0; msg[i] != '\0'; i++){
          msg[i] = toupper(msg[i]); //in case inputed keys are lower case, make them upper case.
        }
    }
    return;
}

// This function reads up to 4 characters from the keyboard
// These characters will be only digits 1 through 8. The user
// will press enter when finished entering the digits.
// The rotor string filled in by the function should only contain 
// the digits terminated by the '\0' character. Do not include
// the \n entered by the user. 
// The function returns the number of active rotors.
int Get_Which_Rotors(char which_rotors[]){
  int active_rotors = 0;
  int i = 0;
  
  scanf("%[^\n]%*c", which_rotors); //scans the inputed keys
  for(i; which_rotors[i] != '\0'; i++){ //loops through array to see if there are inputs
      active_rotors++;
      }
      return active_rotors;
  }

// This function reads an integer from the keyboard and returns it 
// This number represents the number of rotations to apply to the 
// encryption rotors.  The input will be between 0 and 25 inclusive
int Get_Rotations(){
  int rotations;
  int store_rotations;
  
  scanf("%d", &rotations); //scans and checks inputed integer
  
  if(rotations != '\0'){
    if(rotations >= 0 && rotations <= 25){ //checks if input is between 0 and 25 inclusive
    store_rotations = rotations; //stores the inputed information
    }
  }
  return store_rotations;
}

// This function copies the rotors indicated in the which_rotors string 
// into the encryption_rotors.  For example if which rotors contains the string 
// {'3', '1', '\0'} Then this function copies the third and first rotors into the 
// encryption rotors array in positions 0 and 1.  
// encryptions_rotors[0] = "BDFHJLCPRTXVZNYEIWGAKMUSQO"
// encryptions_rotors[1] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ"
void Set_Up_Rotors(char encryption_rotors[4][27], char which_rotors[5]){
    int i;
    int across = 0;
    int column = 0;
    for(i = 0; which_rotors[i] != '\0'; i++){ //for loop that iterates through which_rotors to get the string value wanted
        column = which_rotors[i] - 48; //subtract by 48 to get int value (used ascii table)
        for(across = 0; ROTOR_CONSTANTS[column][across] != '\0'; across++){ //for loop that goes through ROTOR_CONSTANTS and stores the value of said row into encryption_rotors
          encryption_rotors[i][across] = ROTOR_CONSTANTS[column][across]; 
    }
     encryption_rotors[i][across] = '\0'; // null terminated string
  }

    return;
}


// This function rotates the characters in each of the active encryption rotors
// to the right by rotations.  For example if rotations is 3 encryption_rotors[0]
// contains "BDFHJLCPRTXVZNYEIWGAKMUSQO" then after rotation this row will contain
// SQOBDFHJLCPRTXVZNYEIWGAKMU.  Apply the same rotation to all for strings in 
// encryption_rotors
void Apply_Rotation(int rotations, char encryption_rotors[4][27]) { //fix
    int tracker;
    int start = 0;
    int transfer = 0;
    int column;
    int store_rotations;
    char store[100];
   
    ///first for loop to store all of encryption_rotors into a blank array to have a copy
    for(column = 0; encryption_rotors[column][27] != '\0'; column++){
      for(tracker = 0; encryption_rotors[column][tracker] != '\0'; tracker++){
      store[tracker] = encryption_rotors[column][tracker]; //stores the entire row and then goes to the next.
    }
      store[tracker] = '\0';
   //for loop to set the last however few many characters to blank
    for(start; encryption_rotors[column][start] != '\0'; start++){
      store_rotations = rotations;
      if(store_rotations != 0){
      encryption_rotors[column][tracker - store_rotations] = ' ';
      store_rotations--;
      }
     }
  
   //for loop to shift over the remaining characters to the correct poisiton 
    for(start = rotations; encryption_rotors[column][start] != '\0'; start++){
    encryption_rotors[column][start] = store[transfer];
    transfer++;
    }
    
    //loop to move the last few of the original string into the front of the array.
    for(start = 0; encryption_rotors[column][start] != '\0'; start++){
    if(rotations != 0){
    encryption_rotors[column][start] = store[tracker-rotations];
    rotations--;
    }
   }
  }
  encryption_rotors[column][start] = '\0'; // null terminated string
    return;
}

// This function takes a string msg and applys the enigma machine to encrypt the message
// The encrypted message is stored in the string encryped_msg 
// Do not change spaces, make sure your encryped_msg is a \0 terminated string
void Encrypt(char encryption_rotors[4][27], int num_active_rotors, char msg[], char encrypted_msg[]){
    int i = 0;
    int j;
    int rotors = 0;
    int across = 0;
    
    for(i = 0; i < num_active_rotors; i++){//loop goes through total number of active rotors
      for(rotors; msg[rotors] != '\0'; rotors++){ // loop goes through message array
        for(across = 0; ROTOR_CONSTANTS[0][across] != '\0'; across++){ //goes through ROTOR_CONSTANTS and stores it
        if(ROTOR_CONSTANTS[0][across] == msg[rotors]){
          encrypted_msg[rotors] = encryption_rotors[i][across];
        }
        else{
          encrypted_msg[rotors] = ' ';
          }
        }
      }
      encrypted_msg[rotors] = '\0';
    }
    //loop to store encrypted message    
    for(j = 0; encrypted_msg[j] = '\0'; j++){
      msg[j] = encrypted_msg[j];
    }
      msg[j] = '\0'; // null terminated string
    return;
}


// This function takes a string msg and applys the enigma machine to decrypt the message
// The encrypted message is stored in the string encryped_msg and the decrypted_message 
// is returned as a call by reference variable
// remember the encryption rotors must be used in the reverse order to decrypt a message
// Do not change spaces, make sure your decrytped_msg is a \0 terminated string
void Decrypt(char encryption_rotors[4][27], int num_active_rotors, char encrypted_msg[], char decrypted_msg[]) {
    int i = 0;
    int j = 0;
    int rotors = 0;
    int across = 0;
    char store_msg[100]; 
    
    //loop goes through and stores the encrypted message into a blank array.
    for(i = 0; encrypted_msg[i] != '\0'; i++){
      store_msg[i] = encrypted_msg[i];
    } 
      store_msg[i] = '\0'; // null terminated string
    
    for(i = (num_active_rotors - 1) ; i >= 0; i--){ //goes through the total number of active rotors until it hits 0
      for(rotors = 0; store_msg[rotors] != '\0'; rotors++){ //goes through store_msg array
       for(across = 0; encryption_rotors[i][across] != '\0'; across++){ //goes through encryption array
         if(encryption_rotors[i][across] == store_msg[rotors]){ //checks if encryption is equal to stored message
           decrypted_msg[rotors] = ROTOR_CONSTANTS[0][across];
         }
         else{
           decrypted_msg[rotors] = ' '; 
         }
       }
      }
      decrypted_msg[rotors] = '\0'; // null terminated string
     
      //stores decrypted message into a blank array
      for(j = 0; decrypted_msg[j] != '\0'; j++){
        store_msg[j] = decrypted_msg[j];
      }
    }
    store_msg[j] = '\0';  // null terminated string
    return;
}


