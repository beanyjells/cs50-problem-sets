#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//user to input number unprompted

int main(int argc, string argv[])
{
    //iterate to make sure only one argument is inputted
    
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
    }
    else 
    {   //iterate to make sure the string only has numeric digits
        for (int j = 0; j <= (strlen(argv[1])); j++)
        {
            if (((argv[1][j] >= 'a') || (argv[1][j] >= 'A')) && ((argv[1][j] <= 'z') || (argv[1][j] <= 'Z')))
            {
                printf("Usage: ./caesar key \n");
                return 1;
            }
        }
        //converting digit string to an integer called key
        int key = atoi(argv[1]);
        if (key < 0) //making sure the key is positive
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }
        
        //after validity has been checked
        else
        {
            //prompt user to input plaintext
            string plain = get_string("plaintext: ");
            int len_plain = strlen(plain);
            
            //convert plaintext to ciphertext using inputted key
            string cipher = plain;
            for (int x = 0; x < len_plain; x++)
            {
                if (plain[x] >= 'a' && plain[x] <= 'z')
                {
                    cipher[x] = ((plain[x] + key)%122);
                    if (cipher[x]<97)
                    {
                        cipher[x] = cipher[x] + 96;
                    }
                }
                else if (plain[x] >= 'A' && plain[x] <= 'Z')
                {
                    cipher[x] = ((plain[x] + key)%90);
                    if (cipher[x] < 65)
                    {
                        cipher[x] = cipher[x] + 64;
                    }
                }
                else 
                {
                    cipher[x] = plain[x];
                }   
            }
            printf("ciphertext: %s\n", cipher);
        }
    }
}       
        

    
    
        
        
        
    

