#pragma once
#include "encryption/encryption.hpp"
#include "encryption/simple_hash.hpp"

class DefaultEncryption : public EncryptionStrategy
{
public:
    std::string encryptString(const std::string &input);
    std::string encryptKey(const std::string &input);

private:
    SimpleHash hashUtil; // 使用简单哈希工具
};