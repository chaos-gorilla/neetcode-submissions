class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for (string &s : strs) {
            // ["hello", "world"] => 5+"hello"+"#"+""
            int length = s.length();
            encoded_string += to_string(length);
            encoded_string += "#";
            encoded_string += s;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        string number = "";
        vector<string> decoded_strings;
        for (int i = 0; i < s.length();) {
            char ch = s.at(i);
            if (isdigit(ch)) {
                number += ch;
                i++;
                continue;
            } else {
                int total_chars_to_get = stoi(number);
                i++;
                string to_append = s.substr(i, total_chars_to_get);
                decoded_strings.push_back(to_append);
                i += total_chars_to_get;
                number = "";
            }
        }
        return decoded_strings;
    }
};
