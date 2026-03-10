# key_mapping

## 简介

通过加密算法避免用户记住复杂的密码，这里我们假设用户只需要记住两个东西，一个是字符串(e.g. username)，另一个是简单的密码(e.g. 123465)
本程序通过对这两个部分进行加密，生成一个新的密码，用户可以使用这个新的密码进行登录，而不需要记住复杂的密码。

## 构建方式

```
mkdir build
cd build
cmake ..
cmake --build . --config Release or cmake --build .
```

## 使用方法
通过命令行使用，将用户名和简单密码作为参数传入，程序会输出一个新的密码。

```
bash

./key_mapping 123 123
encrypted string: bb57285bb57285

 ./key_mapping username google1
encrypted string: 5d02cb5acc38f4
```