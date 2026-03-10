#include "encryption/encryption.hpp"
#include "encryption/simple_hash.hpp"
#include "encryption/default_encryption.hpp"
#include <memory>

std::unique_ptr<EncryptionStrategy> createEncryptionStrategy(bool useDefault)
{
    // 目前只有一种加密策略，未来可以根据需要添加更多
    if (useDefault)
        return std::make_unique<DefaultEncryption>();
    else                                              // 可以添加用户自定义的加密策略的创建逻辑
        return std::make_unique<DefaultEncryption>(); // 默认返回DefaultEncryption
}