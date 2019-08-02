#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int shift(char c);

int main(int argc, string argv[])
{
    //iterate to make sure only one argument is inputted
    
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword \n");
        return 1;
    }
    
    
    else
    {
        for (int x = 0, n = strlen(argv[1]); x < n; x++)
        {
            if (!isalpha(argv[1][x]))  //iterate to make sure the string doesn't have numeric digits
            {
                printf("Usage: ./vigenere key \n");
                return 1;
            }
        }
        
        int key = 0; //returns number value of alphabetic key inputted by user
        int keylength = strlen(argv[1]);  //calculating length of keyword so as to iterate over it     
        string plain = get_string("plaintext:  "); //prompt user to input plaintext
        int len_plain = strlen(plain); //calculate length of inputted plaintext
        string cipher = plain; //to ensure non-alphabetic characters remain the same
        
        for (int i = 0, j = 0; i < len_plain; i++)
        {
            j = (j % keylength); //iterates over keyword length 
            key = shift(argv[1][j]);
            if (plain[i] >= 'a' && plain[i] <= 'z')
            {
                cipher[i] = ((plain[i] + key)%122);
                if (cipher[i]<97)
                {
                    cipher[i] = cipher[i] + 96;
                }
                j++;
            }
            else if (plain[i] >= 'A' && plain[i] <= 'Z')
            {
                cipher[i] = ((plain[i] + key)%90);
                if (cipher[i] < 65)
                {
                    cipher[i] = cipher[i] + 64;
                }
                j++;
            }
            else
            {
                cipher[i] = plain[i];
            }
        }  
        printf("ciphertext: %s\n", cipher);
        return 0;
    }  
}


int shift(char c)
{
    int num_val = c;
    int convert_key = 0;
    if (c >= 'a' && c<= 'z')
    {
        convert_key = num_val - 'a';
    }
    else
    {
        convert_key = num_val - 'A';
    }
    return convert_key;
}
