#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


int cast_to_int(string number){
    stringstream stream;
    int output;
    stream << number;
    stream >> output;
    stream.str("");
    stream.clear();
    return output;
}

//returns an array of every word
vector <string> get_words(){
    ifstream reader("english.txt");
    string current_word = "";
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    vector <string> words(0);
    int i;
    for(i=0; ! reader.eof(); i++){
        char letter;
        reader.get(letter);
        if (isalpha(letter)){
            current_word += letter;
        }else{
            words.push_back(current_word);
            current_word = "";
        }
    }
    words.push_back(current_word);
    return words;
}


bool findWord(string word, vector <string> use){
    bool is_found = false;
    int wn;
    for (wn=0; wn<use.size(); wn++){
        if (word == use.at(wn)){
            is_found = true;
        }
    }
    return is_found;
}

vector <string> fromFront(string s, vector <string> use){
    vector <string> found;
    int length = s.size();
    int wn;
    for (wn=0; wn<use.size()
; wn++){
        string word = use.at(wn);
        if (word.size() >= length){
            bool not_broken = true;
            int pos;
            for (pos=0; pos<length; pos++){
                char letter = s[pos];
                if (isalpha(letter)){
                    if (word[pos] != letter){
                        not_broken = false;
                        break;
                    }
                }
            }
            if (not_broken){
                found.push_back(word);
            }
        }
    }
    return found;
}

vector <string> fromFrontExact(string s, int length, vector <string> use){
    vector <string> found;
    int wn;
    for (wn=0; wn<use.size(); wn++){
        string word = use.at(wn);
        if (word.size() == length){
            bool not_broken = true;
            int pos;
            for (pos=0; pos<length; pos++){
                char letter = s[pos];
                if (isalpha(letter)){
                    if (word[pos] != letter){
                        not_broken = false;
                        break;
                    }
                }
            }
            if (not_broken){
                found.push_back(word);
            }
        }
    }
    return found;
}

vector <string> fromBack(string s, vector <string> use){
    vector <string> found;
    int length = s.size();
    int wn;
    for (wn=0; wn<use.size(); wn++){
        string word = use.at(wn);
        if (word.size() >= length){
            bool not_broken = true;
            int pos;
            for (pos=0; pos<length; pos++){
                int index = pos - length + word.size();
                char letter = s[pos];
                if (isalpha(letter)){
                    if (word[index] != letter){
                        not_broken = false;
                        break;
                    }
                }
            }
            if (not_broken){
                found.push_back(word);
            }
        }
    }
    return found;
}

vector <string> fromAny(string s, vector <string> use){
    vector <string> found;
    int length = s.size();
    int wn;
    for (wn=0; wn<use.size(); wn++){
        string n_word = use.at(wn);
        string word = n_word;
        while (n_word.size() >= length){
            bool not_broken = true;
            int pos;
            for (pos=0; pos<length; pos++){
                char letter = s[pos];
                if (isalpha(letter)){
                    if (n_word[pos] != letter){
                        not_broken = false;
                        break;
                    }
                }
            }
            if (not_broken){
                found.push_back(word);
                break;
            }
            n_word.erase(0,1);
        }
    }
    return found;
}

vector <string> fromAnyExact(string s, int length, vector <string> use){
    vector <string> found;
    int wn;
    for (wn=0; wn<use.size(); wn++){
        string n_word = use.at(wn);
        string word = n_word;
        while (n_word.size() == length){
            bool not_broken = true;
            int pos;
            for (pos=0; pos<length; pos++){
                char letter = s[pos];
                if (isalpha(letter)){
                    if (n_word[pos] != letter){
                        not_broken = false;
                        break;
                    }
                }
            }
            if (not_broken){
                found.push_back(word);
                break;
            }
            n_word.erase(0,1);
        }
    }
    return found;
}

vector <string> usingLetters(string letters, vector <string> use){
    vector <string> found;
    int wn;
    for (wn=0; wn<use.size(); wn++){
        string word = use.at(wn);
        int ln;
        bool not_broken = true;
        string letters_copy;
        letters_copy.assign(letters);
        for (ln=0; ln<word.size(); ln++){
            char letter = word[ln];
            int index = letters_copy.find(letter);
            if (index != -1){
                letters_copy.erase(index, 1);
            }else{
                not_broken = false;
                break;
            }
        }
        if (not_broken){
            found.push_back(word);
        }
    }
    return found;
}

vector <string> includingLetters(string letters, vector <string> use){
    vector <string> found;
    int wn;
    for (wn=0; wn<use.size(); wn++){
        string word = use.at(wn);
        int ln;
        string letters_copy;
        letters_copy.assign(letters);
        for (ln=0; ln<word.size(); ln++){
            if (letters_copy.size() > 0){
                char letter = word[ln];
                int index = letters_copy.find(letter);
                if (index != -1){
                    letters_copy.erase(index, 1);
                }
            }else{
                found.push_back(word);
                break;
            }
        }
    }
    return found;
}

vector <string> findLength(int length, vector <string> use){
    vector <string> found;
    int wn;
    for (wn=0; wn<use.size()
; wn++){
        string word = use.at(wn);
        if (word.size() == length){
            found.push_back(word);
        }
    }
    return found;
}

vector <string> withoutLetters(string letters, vector <string> use){
    vector <string> found;
    int wn;
    for (wn=0; wn<use.size(); wn++){
        string word = use.at(wn);
        int ln;
        bool not_broken = true;
        for (ln=0; ln<letters.size(); ln++){
            char letter = letters[ln];
            if (word.find(letter) != -1){
                not_broken = false;
                break;
            }
        }
        if (not_broken){
            found.push_back(word);
        }
    }
    return found;
}

int main() {
    vector <string> words = get_words();
    vector <string> use = words;
    bool done = false;
    vector <string> result;
    vector <vector <string>> memory = {{},{},{}};
    cout << "type \"help\" at for a list of fucntions\n";
    while (! done){
        cout << "=============================================\n";
        cout << "enter function: ";
        string action;
        cin >> action;
        cout << endl;

        if (action == "help"){
            cout << "-find:              prints True if the word exists.\n-fromFront:         prints the words starting with the letters entered. type \"_\" for an unknown character.\n-fromBack:          prints the words ending with the letters entered. type \"_\" for an unknown character.\n-fromFrontLength:   prints the words starting with the letters entered and which have the length specified. type \"_\" for an unknown character.\n-fromMiddle:        prints the words containing the string entered. type \"_\" for an unknown character.\n-fromMiddleLength:  prints the words containing the string entered and which have the length specified. type \"_\" for an unknown character.\n-usingLetters:      prints the words which are made up only using the letters entered.\n-containingLetters: prints the words which include all of the letters entered.\n-withLength:        prints the words which have the specified length.\n-withoutLetters:    prints the words which do not contain any of the letters entered.\n-save:              saves the words returned into the specified memory slot.\n-load:              use the words in the specified memory slot.\n-unload:            use the full array of words.\n-memory:            prints out the words in the specified memory slot.\n-end:               exit.\n\n";
        }else if (action == "find"){
            string word;
            cout << "please enter the word: ";
            cin >> word;
            cout << "\n\n";
            bool value = findWord(word, use);
            if (value){
                cout << "True\n";
            }else{
                cout << "False\n";
            }
        }else if (action == "fromFront"){
            string s;
            cout << "please enter the string: ";
            cin >> s;
            cout << "\n";
            result = fromFront(s, use);
            int i;
            for (i=0; i<result.size(); i++){
                cout << result.at(i) << endl;
            }
            cout << endl << result.size() << " results found\n";
        }
        else if (action == "fromBack"){
            string s;
            cout << "please enter the string: ";
            cin >> s;
            cout << "\n";
            result = fromBack(s, use);
            int i;
            for (i=0; i<result.size(); i++){
                cout << result.at(i) << endl;
            }
            cout << endl << result.size() << " results found\n";
        }
        else if (action == "fromFrontLength"){
            string s;
            string length;
            cout << "please enter the string: ";
            cin >> s;
            cout << "please enter the length: ";
            cin >> length;
            cout << "\n";
            int len = cast_to_int(length);
            result = fromFrontExact(s, len, use);
            int i;
            for (i=0; i<result.size(); i++){
                cout << result.at(i) << endl;
            }
            cout << endl << result.size() << " results found\n";
        }
        else if (action == "fromMiddle"){
            string s;
            cout << "please enter the string: ";
            cin >> s;
            cout << "\n";
            result = fromAny(s, use);
            int i;
            for (i=0; i<result.size(); i++){
                cout << result.at(i) << endl;
            }
            cout << endl << result.size() << " results found\n";
        }
        else if (action == "fromMiddleLength"){
            string s;
            string length;
            cout << "please enter the string: ";
            cin >> s;
            cout << "please enter the length: ";
            cin >> length;
            cout << "\n";
            int len = cast_to_int(length);
            result = fromAnyExact(s, len, use);
            int i;
            for (i=0; i<result.size(); i++){
                cout << result.at(i) << endl;
            }
            cout << endl << result.size() << " results found\n";
        }
        else if (action == "usingLetters"){
            string s;
            cout << "please enter the string: ";
            cin >> s;
            cout << "\n";
            result = usingLetters(s, use);
            int i;
            for (i=0; i<result.size(); i++){
                cout << result.at(i) << endl;
            }
            cout << endl << result.size() << " results found\n";
        }
        else if (action == "containingLetters"){
            string s;
            cout << "please enter the string: ";
            cin >> s;
            cout << "\n";
            result = includingLetters(s, use);
            int i;
            for (i=0; i<result.size(); i++){
                cout << result.at(i) << endl;
            }
            cout << endl << result.size() << " results found\n";
        }
        else if (action == "withLength"){
            string length;
            cout << "please enter the length: ";
            cin >> length;
            cout << "\n";
            int len = cast_to_int(length);
            result = findLength(len, use);
            int i;
            for (i=0; i<result.size(); i++){
                cout << result.at(i) << endl;
            }
            cout << endl << result.size() << " results found\n";
        }
        else if (action == "withoutLetters"){
            string s;
            cout << "please enter the string: ";
            cin >> s;
            cout << "\n";
            result = withoutLetters(s, use);
            int i;
            for (i=0; i<result.size(); i++){
                cout << result.at(i) << endl;
            }
            cout << endl << result.size() << " results found\n";
        }
        else if (action == "save"){
            string slot_s;
            cout << "memory slot (0-2): ";
            cin >> slot_s;
            cout << "\n";
            int slot = cast_to_int(slot_s);
            if (slot < memory.size()){
                memory.at(slot) = result;
            }else{
                cout << "index out of range\n\n";
            }
        }
        else if (action == "memory"){
            string slot_s;
            cout << "memory slot (0-2): ";
            cin >> slot_s;
            cout << "\n";
            int slot = cast_to_int(slot_s);
            if (slot < memory.size()){
                vector <string> contents = memory.at(slot);
                int i;
                for (i=0; i<contents.size(); i++){
                    cout << contents.at(i) << endl;
                }
                cout << endl << contents.size() << " results found\n";
            }else{
                cout << "index out of range\n\n";
            }
        }
        else if (action == "load"){
            string slot_s;
            cout << "memory slot (0-2): ";
            cin >> slot_s;
            cout << "\n";
            int slot = cast_to_int(slot_s);
            if (slot < memory.size()){
                use = memory.at(slot);
            }else{
                cout << "index out of range\n\n";
            }
        }
        else if (action == "unload"){
            use = words;
        }
        else if (action == "end"){
            done = true;
        }
    }

    return 0;
}
