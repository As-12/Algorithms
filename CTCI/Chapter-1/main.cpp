#include <iostream>
#include <string>
#include <bitset>
#include <unordered_map>
#include <cmath>

template <typename T>
const char * CHECK(const T& a, const T& b) {
  return a == b ? "pass" : "fail";
}

// CTCI 1.1

// O(N) where N is length of string
const bool isUnique(const std::string & str ) {
    // Cannot use additional data structure.
    // Assume all character are lower case alphabets
    // Use integer to encode the ASCII character
    long checked = 0;
    for(char c : str) {
        long mask = 1 << ( c - 'a');
        if ( (checked & mask) > 0) {
            return false;
        }
        checked |= mask;
    }
    return true;
}

void testIsUnique() {
    std::cout<< CHECK<bool>(isUnique("ab"), true) <<std::endl;
    std::cout<< CHECK<bool>(isUnique("acb"), true) <<std::endl;
    std::cout<< CHECK<bool>(isUnique("bab"), false) <<std::endl;
    std::cout<< CHECK<bool>(isUnique("abdega"), false) <<std::endl;
    std::cout<< CHECK<bool>(isUnique("abbbbb"), false) <<std::endl;
    std::cout<< CHECK<bool>(isUnique("abedsxghjiyr"), true) <<std::endl;
}


// CTCI 1.2

// O(N) where N is length of string
const bool isPermutation(const std::string & str, const std::string &subStr){

    int j = 0;
    for(int i = 0; i != str.size(); ++i) {
        if (j == subStr.size()) {
            return true;
        }
        if (str[i] == subStr[j]) {
            ++j;
        }
        else {
            j = 0;
        }
    }
}

void testIsPermutation() {
    std::cout<< CHECK<bool>(isPermutation("john","jo"), true) <<std::endl;
    std::cout<< CHECK<bool>(isPermutation("abcde","cde"), false) <<std::endl;
    std::cout<< CHECK<bool>(isPermutation("abdsdsadsada","aswe"), false) <<std::endl;
    std::cout<< CHECK<bool>(isPermutation("johnny bravo","john"), true) <<std::endl;

}



// CTCI 1.3
//Encode space with %20
// Simply build a new string with linked list or stringbuild, then it will O(n)
// C++ String is mutable, so we do not need a string builder
const std::string URLify(const std::string & str){
    std::string result;
    // Cound the space and reserve the string first
    int space_count = 0;
    for(auto c : str) {
        if (c == ' ') {
            space_count++;
        }
    }
    result.reserve( str.size() + space_count * 2 );
    for (char c : str) {
        if (c == ' ' ){
            result.append("%20");
        }
        else {
            result.push_back(c);
        }
    }
    return result;
}

void testURLify() {
    std::cout<< CHECK<std::string>(URLify("john"), "john") <<std::endl;
    std::cout<< CHECK<std::string>(URLify("john corner"), "john%20corner") <<std::endl;
    std::cout<< CHECK<std::string>(URLify("john "), "john%20") <<std::endl;
    std::cout<< CHECK<std::string>(URLify(" john"), "%20john") <<std::endl;
    std::cout<< CHECK<std::string>(URLify("john corner adam"), "john%20corner%20adam") <<std::endl;
}

//CTCI 1.4
// Palindrome Permutation
const bool isPalindromePermutation(const std::string & str) {
    // Permutation
        // str == str.reverse
    // However, to check if permutation of string, palindrome just add the character count
        //Every character should have even count, except for one character

    std::unordered_map<char, int> map;  // This is C++ STL Hashtable;
    for(char c : str) {
        if (c == ' ') continue;
        auto i = map.find(c);
        if (i != map.end()) {
            map[c] = 0;
        }
        else {
            ++map[c];
        }
    }
    bool first_odd = false;
    for(auto iter = map.begin(); iter != map.end(); ++iter) {
        if(iter->second % 2 == 1) {
            if(first_odd == true) {
                return false;
            }
            else {
                first_odd = true;
            }
        }
    }
    return true;
}

void testIsPalindromePermutation() {
    std::cout<<CHECK<bool>(isPalindromePermutation("taco cat"), true) <<std::endl;
    std::cout<<CHECK<bool>(isPalindromePermutation("atco cta"), true) <<std::endl;
    std::cout<<CHECK<bool>(isPalindromePermutation("tact coa"), true) <<std::endl;
    std::cout<<CHECK<bool>(isPalindromePermutation("john"), false) <<std::endl;
    std::cout<<CHECK<bool>(isPalindromePermutation("aabb"), true) <<std::endl;
}

//CTCI 1.5
const bool isOneEditAway(const std::string & str1, const std::string & str2) {

    if (std::abs(long(str1.size() - str2.size())) > 1) {
        return false;
    }

    auto iter1 = str1.begin();
    auto iter2 = str2.begin();
    int count = 0;
    while(iter1 != str1.end() && iter2 != str2.end()) {

        if(*iter1 != *iter2) {
            if (count > 0) {
                return false;
            }
            ++count;

            if(str1.size() > str2.size()) {
                iter1++;
            }
            else if (str2.size() > str1.size()) {
                iter2++;
            }
            else {
                iter1++;
                iter2++;
            }
        } else {
            iter1++;
            iter2++;
        }
    }

    if (iter1 != str1.end() || iter2 != str2.end()) {
        count += 1;
    }
    return count <= 1;
}

void testIsOneEditAway() {
    std::cout<<CHECK<bool>(isOneEditAway("kit", "kat"), true) <<std::endl;
    std::cout<<CHECK<bool>(isOneEditAway("kit", "kat2"), false) <<std::endl;
    std::cout<<CHECK<bool>(isOneEditAway("kit", "kit1"), true) <<std::endl;
    std::cout<<CHECK<bool>(isOneEditAway("kit", "kitsda"), false) <<std::endl;
    std::cout<<CHECK<bool>(isOneEditAway("kit", "kit"), true) <<std::endl;
    std::cout<<CHECK<bool>(isOneEditAway("kit", "kt"), true) <<std::endl;
}

//CTCI 1.6
const std::string stringCompression(const std::string & str1) {

    if (str1.size() == 0) {
        return "";
    }

    std::string result;

    char current_char = str1[0];
    int count = 0;
    for(char c : str1) {
        if (current_char != c) {
            result.push_back(current_char);
            if (count > 1) {
                result.append(std::to_string(count));
            }
            count = 1;
            current_char = c;
        }
        else {
            ++count;
        }
    }
    result.push_back(current_char);
    if (count > 1) {
        result.append(std::to_string(count));
    }
    return result;
}

void testStringCompression() {
    std::cout<<CHECK<std::string>(stringCompression("kit"), "kit") <<std::endl;
    std::cout<<CHECK<std::string>(stringCompression("kitt"), "kit2") <<std::endl;
    std::cout<<CHECK<std::string>(stringCompression("aabbccc"), "a2b2c3") <<std::endl;
}


int main() {
    //testIsUnique();
    //testIsPermutation();
    //testURLify();
    //testIsPalindromePermutation();
    //testIsOneEditAway();
    testStringCompression();
    return 0;
}
