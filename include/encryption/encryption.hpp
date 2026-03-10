#pragma once
#include <string>
#include <memory>

// encryption.hpp
class EncryptionStrategy
{
public:
    virtual ~EncryptionStrategy() = default;
    virtual std::string encryptString(const std::string &input) = 0;
    virtual std::string encryptKey(const std::string &input) = 0;
};

// 工厂函数，可以切换不同的加密策略
std::unique_ptr<EncryptionStrategy> createEncryptionStrategy(bool useDefault = true);
