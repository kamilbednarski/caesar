#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>


string encipher_text(string plain_text, int key_value);


int main(int argc, string argv[])
{
    //If condition checks if there are two command line arguments.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //TEST
    //printf("argv[1]: %s\n", argv[1]);
    //TEST


    //GET KEY VALUE.
    int key_value = atoi(argv[1]);

    //TEST
    //printf("key value: %i\n", key_value);
    //TEST

    //If condition checks if command line argument is numerical value.
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    if (key_value == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    //GET PLAIN TEXT.
    string plain_text = get_string("Plaintext: ");

    //ENCIPHER.
    string cipher_text = encipher_text(plain_text, key_value);

    //PRINT CIPHERTEXT.
    printf("ciphertext: ");
    for (int i = 0; cipher_text[i] != '\0'; i++)
    {
        printf("%c", cipher_text[i]);
    }
    printf("\n");

}




string encipher_text(string plain_text, int key_value)
{
    //This function enciphers text using key value.
    //It uses ASCII code table.

    string cipher_text = plain_text;
    int temp = 0;

    for (int i = 0; plain_text[i] != '\0'; i++)
    {
        //Condition below checks if character from plain_text is a letter,
        //ASCII codes for lowercase letters are 65 to 90,
        // and for upper case letters from 97 to 122.

        //Condition below ensures that letter isn't going to be
        //enciphered as any character other than a letter.
        //If ASCII code for character after encryption is outside
        //the range of codes assigned to letters, program calculates new
        //index by moving the excess to the beginning of a range of letters.

        temp = (int)plain_text[i] + key_value;

        //Case for upper case letters.
        if (((int)plain_text[i] > 64 && (int)plain_text[i] < 91))
        {
            if (temp > 90)
            {
                while (temp > 90)
                {
                    temp = temp % 90 + 64;
                }
                cipher_text[i] = (char)temp;
            }
            else
            {
                cipher_text[i] = (char)temp;
            }
        }


        //Case for lower case letters.
        if ((int)plain_text[i] > 96 && (int)plain_text[i] < 123)
        {

            if (temp > 122)
            {

                while (temp > 122)
                {
                    temp = temp % 122 + 96;
                }

                cipher_text[i] = (char)temp;
            }
            else
            {
                cipher_text[i] = (char)temp;
            }

        }

    }

    return cipher_text;

}