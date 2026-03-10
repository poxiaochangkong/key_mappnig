// simple_hash.cpp - 轻量级自定义哈希算法实现
#include "encryption/simple_hash.hpp"
#include <sstream>
#include <iomanip>
#include <algorithm>

// 核心哈希计算函数 - 使用简单的混合算法
uint32_t SimpleHash::computeHash(const std::string &input)
{
    if (input.empty())
    {
        return 0xDEADBEEF; // 空字符串返回一个默认值
    }

    uint32_t hash = 0x811C9DC5; // FNV-1a初始值

    // 简单的混合函数
    for (char c : input)
    {
        // 使用FNV-1a算法的简化版本
        hash ^= static_cast<uint32_t>(c);
        hash *= 0x01000193; // 32位FNV质数
    }

    // 额外的混合步骤
    hash ^= hash >> 16;
    hash *= 0x85EBCA6B;
    hash ^= hash >> 13;
    hash *= 0xC2B2AE35;
    hash ^= hash >> 16;

    return hash;
}

// 将32位整数转换为8位十六进制字符串
std::string SimpleHash::toHexString(uint32_t value)
{
    std::stringstream ss;
    ss << std::hex << std::setw(8) << std::setfill('0') << value;
    return ss.str();
}

// 扩展哈希值到32位十六进制字符串
std::string SimpleHash::expandTo32Hex(uint32_t hash)
{
    // 使用不同的种子生成4个不同的哈希值，然后组合
    std::string result;

    // 生成4个8位十六进制字符串
    for (int i = 0; i < 4; ++i)
    {
        // 对原始哈希进行不同的变换
        uint32_t transformed = hash;

        // 每次使用不同的变换
        switch (i)
        {
        case 0:
            transformed ^= 0x5A827999;
            break;
        case 1:
            transformed = (transformed << 13) | (transformed >> 19);
            transformed ^= 0x6ED9EBA1;
            break;
        case 2:
            transformed = ~transformed;
            transformed ^= 0x8F1BBCDC;
            break;
        case 3:
            transformed = (transformed << 17) | (transformed >> 15);
            transformed ^= 0xCA62C1D6;
            break;
        }

        // 添加到结果中
        result += toHexString(transformed);
    }

    return result;
}

// 计算完整32位哈希值
std::string SimpleHash::hashFull(const std::string &input)
{
    uint32_t hash = computeHash(input);
    return expandTo32Hex(hash);
}

// 计算输入字符串的哈希值（截取前15位）
std::string SimpleHash::hash(const std::string &input)
{
    std::string fullHash = hashFull(input);

    // 确保至少有15个字符
    if (fullHash.length() < 15)
    {
        // 如果不够15个字符，用0填充
        fullHash.append(15 - fullHash.length(), '0');
    }

    // 截取前15个字符
    return fullHash.substr(0, 15);
}