# C++迭代器辅助函数

## 1. std::advance

用于将迭代器前进指定的步数。

```c++
std::advance(iter, n); // 将迭代器 iter 前进 n 个位置
```

```c++
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // 获取 vector 的起始和结束迭代器
    auto iter = numbers.begin();
    auto endIter = numbers.end();

    // 将迭代器向前移动2个位置
    std::advance(iter, 2);

    // 打印移动后的迭代器指向的元素
    if (iter != endIter) {
        std::cout << "The element at the new iterator position: " << *iter << std::endl;
    } else {
        std::cout << "Iterator moved beyond the end of the vector" << std::endl;
    }

    return 0;
}

// The element at the new iterator position: 3
```

## 2. std::distance

用于计算两个迭代器之间的距离。

```c++
auto dist = std::distance(first, last); // 计算 first 和 last 之间的距离
```

```c++
#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // 获取 vector 的起始和结束迭代器
    auto beginIter = numbers.begin();
    auto endIter = numbers.end();

    // 计算起始迭代器和结束迭代器之间的距离
    auto dist = std::distance(beginIter, endIter);

    // 打印迭代器之间的距离
    std::cout << "The distance between the iterators: " << dist << std::endl;

    return 0;
}

//The distance between the iterators: 5
```

## 3. std::next和std::prev

分别用于获取指向当前迭代器位置后一个位置和前一个位置的迭代器。

```c++
auto nextIter = std::next(iter); // 获取 iter 的下一个位置的迭代器
auto prevIter = std::prev(iter); // 获取 iter 的前一个位置的迭代器
```

```c++
#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // 获取 vector 的起始和结束迭代器
    auto iter = numbers.begin();

    // 使用 std::next 获取下一个位置的迭代器
    auto nextIter = std::next(iter);

    // 使用 std::prev 获取前一个位置的迭代器
    auto prevIter = std::prev(iter);

    // 打印前一个和后一个位置的元素
    std::cout << "Element at the next position: " << *nextIter << std::endl;
    std::cout << "Element at the previous position: " << *prevIter << std::endl;

    return 0;
}

// Element at the next position: 2
// Element at the previous position: 0
```

## 4. std::begin和 std::end

用于获取容器的起始和结束迭代器。

```c++
auto beginIter = std::begin(container); // 获取容器 container 的起始迭代器
auto endIter = std::end(container); // 获取容器 container 的结束迭代器
```

```c++
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // 使用 std::begin 获取 vector 的起始迭代器
    auto beginIter = std::begin(numbers);

    // 使用 std::end 获取 vector 的结束迭代器
    auto endIter = std::end(numbers);

    // 使用起始和结束迭代器遍历 vector 并打印元素
    for (auto iter = beginIter; iter != endIter; ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

