# 哈希表

## 引入

主要解决的问题：一般哈希表用来快速判断一个元素是否出现在集合中。

举例：查询一个名字是否在这所学校，哈希表只需要O（1）的时间复杂度。

当我们想使用哈希法来解决问题的时候，我们一般会选择如下三种数据结构。

- 数组
- set （集合）
- map(映射)

在C++中，set 和 map 分别提供以下三种数据结构，其底层实现以及优劣如下表所示：

| 集合               | 底层实现 | 是否有序 | 数值是否可以重复 | 能否更改数值 | 查询效率 | 增删效率 |
| ------------------ | -------- | -------- | ---------------- | ------------ | -------- | -------- |
| std::set           | 红黑树   | 有序     | 否               | 否           | O(log n) | O(log n) |
| std::multiset      | 红黑树   | 有序     | 是               | 否           | O(logn)  | O(logn)  |
| std::unordered_set | 哈希表   | 无序     | 否               | 否           | O(1)     | O(1)     |

std::unordered_set底层实现为哈希表，std::set 和std::multiset 的底层实现是红黑树，红黑树是一种平衡二叉搜索树，所以key值是有序的，但key不可以修改，改动key值会导致整棵树的错乱，所以只能删除和增加。

| 映射               | 底层实现 | 是否有序 | 数值是否可以重复 | 能否更改数值 | 查询效率 | 增删效率 |
| ------------------ | -------- | -------- | ---------------- | ------------ | -------- | -------- |
| std::map           | 红黑树   | key有序  | key不可重复      | key不可修改  | O(logn)  | O(logn)  |
| std::multimap      | 红黑树   | key有序  | key可重复        | key不可修改  | O(log n) | O(log n) |
| std::unordered_map | 哈希表   | key无序  | key不可重复      | key不可修改  | O(1)     | O(1)     |

std::unordered_map 底层实现为哈希表，std::map 和std::multimap 的底层实现是红黑树。同理，std::map 和std::multimap 的key也是有序的（这个问题也经常作为面试题，考察对语言容器底层的理解）。

当我们要使用集合来解决哈希问题的时候，优先使用unordered_set，因为它的查询和增删效率是最优的，如果需要集合是有序的，那么就用set，如果要求不仅有序还要有重复数据的话，那么就用multiset。

## 有效的字母异位词

[LeetCode49.cpp](https://github.com/niu0217/Documents/blob/main/Algorithm/HashTable/LeetCode49.cpp)

[LeetCode242.cpp](https://github.com/niu0217/Documents/blob/main/Algorithm/HashTable/LeetCode242.cpp)

[LeetCode383.cpp](https://github.com/niu0217/Documents/blob/main/Algorithm/HashTable/LeetCode383.cpp)

[LeetCode438.cpp](https://github.com/niu0217/Documents/blob/main/Algorithm/HashTable/LeetCode438.cpp)

## 两个数组的交集

[LeetCode349.cpp](https://github.com/niu0217/Documents/blob/main/Algorithm/HashTable/LeetCode349.cpp)

[LeetCode350.cpp](https://github.com/niu0217/Documents/blob/main/Algorithm/HashTable/LeetCode350.cpp)

## 快乐数

[LeetCode202.cpp](https://github.com/niu0217/Documents/blob/main/Algorithm/HashTable/LeetCode202.cpp)

## 两数之和

[LeetCode1.cpp](https://github.com/niu0217/Documents/blob/main/Algorithm/HashTable/LeetCode1.cpp)

## 四数相加III

[LeetCode454.cpp](https://github.com/niu0217/Documents/blob/main/Algorithm/HashTable/LeetCode454.cpp)

## 赎金信

[LeetCode383.cpp](https://github.com/niu0217/Documents/blob/main/Algorithm/HashTable/LeetCode383.cpp)

## 三数之和

[LeetCode15.cpp](https://github.com/niu0217/Documents/blob/main/Algorithm/HashTable/LeetCode15.cpp)

## 四数之和

[LeetCode18.cpp](https://github.com/niu0217/Documents/blob/main/Algorithm/HashTable/LeetCode18.cpp)