#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

// TRANSPOSITION MATRIX WLAAA

std::vector<std::string> split_len(const std::string &seq, int length)
{
    std::vector<std::string> result;
    for (size_t i = 0; i < seq.length(); i += length)
    {
        result.push_back(seq.substr(i, length));
    }
    return result;
}
std::string encode(const std::string &key, const std::string &plaintext)
{
    std::map<int, int> order;
    for (int i = 0; i < key.length(); ++i)
    {
        order[key[i] - '0'] = i;
    }
    std::string ciphertext;
    for (const auto &kv : order)
    {
        int index = kv.first;
        for (const std::string &part : split_len(plaintext, key.length()))
        {
            try
            {
                ciphertext += part.at(order[index]);
            }
            catch (const std::out_of_range &e)
            {
                continue;
            }
        }
    }
    return ciphertext;
}
int main()
{

     std::string key ;// "3214";
    std::string plaintext ;//= "orange";
    cout << "Enter your key : ";
    cin >> key;
    cout << "Enter your plaintext : ";
    cin >> plaintext;
    std::cout << "Encoded Text: " << encode(key, plaintext) << std::endl;
    return 0;
} 