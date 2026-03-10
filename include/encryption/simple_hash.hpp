// simple_hash.hpp - 轻量级自定义哈希算法
#ifndef SIMPLE_HASH_HPP
#define SIMPLE_HASH_HPP

#include <string>
#include <cstdint>

/**
 * @brief 简单的自定义哈希函数
 *
 * 这是一个轻量级的哈希函数，用于生成固定长度的哈希值。
 * 算法特点：
 * 1. 使用简单的混合函数
 * 2. 生成32位十六进制字符串
 * 3. 截取前15位作为最终输出
 *
 * 注意：这不是加密强度的哈希，仅用于教学示例。
 */
class SimpleHash
{
public:
    /**
     * @brief 计算输入字符串的哈希值
     * @param input 输入字符串
     * @return 32位十六进制哈希字符串的前15位
     */
    static std::string hash(const std::string &input);

    /**
     * @brief 计算完整32位哈希值
     * @param input 输入字符串
     * @return 完整的32位十六进制哈希字符串
     */
    static std::string hashFull(const std::string &input);

private:
    /**
     * @brief 核心哈希计算函数
     * @param input 输入字符串
     * @return 32位无符号整数哈希值
     */
    static uint32_t computeHash(const std::string &input);

    /**
     * @brief 将32位整数转换为8位十六进制字符串
     * @param value 32位整数
     * @return 8位十六进制字符串
     */
    static std::string toHexString(uint32_t value);

    /**
     * @brief 扩展哈希值到32位十六进制字符串
     * @param hash 原始哈希值
     * @return 32位十六进制字符串
     */
    static std::string expandTo32Hex(uint32_t hash);
};

#endif // SIMPLE_HASH_HPP