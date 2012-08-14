/* 
 * DailyProgrammer Challenge #86
 *
 * Run-Length encoding is a simple form of compression that detects 
 * 'runs' of repeated instances of a symbol in a string and compresses them to a
 * list of pairs of 'symbol' 'length'. For example, the string
 * "Heeeeelllllooooo nurse!" Could be compressed using run-length encoding to
 * the list of pairs [(1,'H'),(5,'e'),(5,'l'),(5,'o'),(1,'n'),(1,'u'),(1,'r'),(1,'s'),(1,'e')]
 * Which seems to not be compressed, but if you represent it as an array of 18bytes
 * (each pair is 2 bytes), then we save 5 bytes of space compressing this string.
 *
 * Write a function that takes in a string and returns a run-length-encoding of 
 * that string. (either as a list of pairs or as a 2-byte-per pair array)
 * BONUS: Write a decompression function that takes in the RLE representation
 * and returns the original string
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef pair<char, int> runlength;

vector<runlength> runLengthEncode(string& str) {
    vector<runlength> encodedStr;

    char previous_char;
    int length = 0;

    string::iterator it;
    for (it = str.begin(); it < str.end(); it++) {
        char current_char = *it;
        if (it == str.begin() || current_char == previous_char) {
            length++; 
            previous_char = current_char;
        }
        else {
            encodedStr.push_back(runlength(previous_char, length));
            length = 1;
            previous_char = current_char;
        }
    }
    encodedStr.push_back(runlength(previous_char, length));

    return encodedStr;
}

string runLengthDecode(vector<runlength>& encodedStr) {
    string str = "";
    
    for (vector<runlength>::iterator it = encodedStr.begin(); it < encodedStr.end(); it++) {
        char current_char = (*it).first;
        int length = (*it).second;
        while (length > 0) {
            str += current_char;
            length--;
        }
    }

    return str;
}

int main() {
    string str("ttaaaaaaylllooorrr!!!!");
    vector<runlength> encodedStr = runLengthEncode(str);
    
    cout << "Encoded: [";
    for (vector<runlength>::iterator it = encodedStr.begin(); it < encodedStr.end(); it++) {
        char current_char = (*it).first;
        int length = (*it).second;
        cout << "(" << current_char << "," << length << ")";
        if (it < encodedStr.end() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    string decodedStr = runLengthDecode(encodedStr);
    cout << "Decoded: " << decodedStr << endl;

    return 0;
}
