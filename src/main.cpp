#include <encryption/encryption.hpp>
#include <encryption/default_encryption.hpp>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // argv[1] simple_str
    // argv[2] simple_key
    if (argc != 3)
    {
        cout << "invalid input" << endl;
        cout << "this program accetps 2 argments, if and only if" << endl;
        cout << "you can use this program like this:" << endl;
        cout << "./key_mapping str1 str2" << endl;
        return 0;
    }
    else
    {
        unique_ptr<EncryptionStrategy> encryption = createEncryptionStrategy();
        string str1 = encryption->encryptString(argv[1]);
        string str2 = encryption->encryptKey(argv[2]);
        cout << "encrypted string: " << str1 + str2 << endl;
    }
    return 0;
}