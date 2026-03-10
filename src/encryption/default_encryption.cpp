#include "encryption/default_encryption.hpp"

std::string DefaultEncryption::encryptString(const std::string &input)
{
    // 截取前7位
    std::string str = hashUtil.hashFull(input);
    std::string str7 = str.substr(0, 7);
    return str7;
}

std::string DefaultEncryption::encryptKey(const std::string &input)
{
    // 截取前7位
    std::string str = hashUtil.hashFull(input);
    std::string str7 = str.substr(0, 7);
    return str7;
}