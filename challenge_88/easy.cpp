/*
 *The easy challenge today is to implement the famous Vigenère cipher. 
 *The Wikipedia article explains well how it works, but here's a short 
 *description anyway:
 *
 *You take a message that you want to encrypt, for instance 
 *"THECAKEISALIE" (lets assume that all characters are upper-case 
 *and there are no spaces in the messages, for the sake of simplicity), 
 *and a key you want to encrypt it with, for instance "GLADOS". You 
 *then write the message with the key repeated over it, like this:
 *
 *GLADOSGLADOSG
 *THECAKEISALIE
 *
 *The key is repeated as often as is needed to cover the entire message.
 *Now, one by one, each letter of the key is "added" to the letter of 
 *the clear-text to produce the cipher-text. That is, if A = 0, B = 1, 
 *C = 2, etc, then E + G = K (because E = 4 and G = 6, and 4 + 6 = 10, 
 *and K = 10). If the sum is larger than 25 (i.e. larger than Z), it 
 *starts from the beginning, so S + K = C (i.e. 18 + 10 = 28, and 28 - 26 
 *is equal to 2, which is C).
 *
 *For a full chart of how characters combine to form new characters, see:
 *http://en.wikipedia.org/wiki/File:Vigen%C3%A8re_square_shading.svg
 *The cipher text then becomes:
 *
 *GLADOSGLADOSG
 *THECAKEISALIE
 *-------------
 *ZSEFOCKTSDZAK
 *
 *Write funtions to both encrypt and decrypt messages given the right key.
 *As an optional bonus, decrypt the following message, which has been 
 *encrypted with a word that I've used in this post:
 *
 *HSULAREFOTXNMYNJOUZWYILGPRYZQVBBZABLBWHMFGWFVPMYWAVVTYISCIZRLVGOPGBRAKLUGJUZGLN
 *BASTUQAGAVDZIGZFFWVLZSAZRGPVXUCUZBYLRXZSAZRYIHMIMTOJBZFZDEYMFPMAGSMUGBHUVYTSABB
 *AISKXVUCAQABLDETIFGICRVWEWHSWECBVJMQGPRIBYYMBSAPOFRIMOLBUXFIIMAGCEOFWOXHAKUZISY
 *MAHUOKSWOVGBULIBPICYNBBXJXSIXRANNBTVGSNKR
 *
 *As an additional challenge, attempt to pronounce "Vigenère" properly. I think it's like "Viche-en-ere", but I'm not entirely sure.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string format_key_length(string& key, const string &message) {
    string formatted_key = "";

    string::iterator key_iterator = key.begin();
    for (int i = 0; i < message.length(); i++) {
        formatted_key += *key_iterator;
        if (key_iterator < key.end() - 1) {
            key_iterator++;
        }
        else {
            key_iterator = key.begin();
        }
    }
    
    return formatted_key;
}

string vig_cipher_encrypt(string& key, const string& message) {
    string encrypted_str = "";
    string formatted_key = format_key_length(key, message);

    for (int i = 0; i < message.length(); i++) {
        int message_char = (int) message.at(i) - 65;    // 65 turns ascii value to 0-25 <-> A-Z
        int formatted_key_char = (int) formatted_key.at(i) - 65;
        int encrypted_str_char = message_char + formatted_key_char;
        if (encrypted_str_char > 25) {
            encrypted_str_char -= 26;   // start over from beginning if above 25
        }
        encrypted_str += (char) encrypted_str_char + 65; // convert back to ascii
    }
   
    return encrypted_str;
}

string vig_cipher_decrypt(string& key, const string& encrypted_str) {
    string decrypted_str = "";
    string formatted_key = format_key_length(key, encrypted_str);

    for (int i = 0; i < encrypted_str.length(); i++) {
        int encrypted_str_char = (int) encrypted_str.at(i) - 65;    // 65 turns ascii value to 0-25 <-> A-Z
        int formatted_key_char = (int) formatted_key.at(i) - 65;
        int decrypted_str_char = encrypted_str_char - formatted_key_char;
        if (decrypted_str_char < 0) {
            decrypted_str_char += 26;   // start over from beginning if above 25
        }
        decrypted_str += (char) decrypted_str_char + 65; // convert back to ascii
    }

    return decrypted_str;
}

int main() {
    ifstream inFile("input");

    string key;
    string encrypted_message;
    inFile >> key;
    inFile >> encrypted_message;

    string decrypted_message = vig_cipher_decrypt(key, encrypted_message);

    ofstream outFile("output");
    outFile << key << endl;
    outFile << encrypted_message << endl;
    outFile << decrypted_message << endl;
    
    return 0;    
}
