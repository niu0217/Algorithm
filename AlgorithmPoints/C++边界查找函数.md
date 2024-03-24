# C++边界查找函数

## 1. std::lower_bound

在 C++ 中，`std::lower_bound` 是一个用于在`有序序列中`寻找特定值的函数。它返回一个指向`不小于给定值的第一个元素的迭代器`，如果找不到这样的元素，则返回指向序列末尾的迭代器。

重点：

+ 只适用于有序序列中；
+ 返回指向不小于给定值的第一个元素的迭代器；

下面是 `std::lower_bound` 函数的简单示例用法：

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec = {1, 3, 5, 7, 9};

    // 将要查找的值
    int value = 6;

    // 使用 lower_bound 查找不小于 value 的第一个元素
    auto it = lower_bound(vec.begin(), vec.end(), value);

    int index = distance(vec.begin(), it);
    cout<<"第一个不大于"<<value<<"的下标为："<<index<<endl;

    if (it != vec.end()) {
        cout << "First element not less than " << value << " is: " << *it << endl;
    } else {
        cout << "No element not less than " << value << " found" << endl;
    }

    return 0;
}

// 第一个不大于6的下标为：3
// First element not less than 6 is: 7
```

在这个示例中，`std::lower_bound` 被用来查找序列中不小于给定值的第一个元素。在这个例子中，`value` 被设置为 6，`std::lower_bound` 将返回指向序列中值为 7 的元素的迭代器。

`std::lower_bound` 在二分搜索树中的应用十分常见，它提供了一种在有序序列中高效查找特定值或查找插入位置的方法。

## 2. std::upper_bound

重点：

+ 只适用于有序序列中；

+ `std::upper_bound` 返回的是第一个大于给定值的元素的迭代器；

```c++
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 3, 5, 7, 9};

    // 将要查找的值
    int value = 6;

    // 使用 upper_bound 查找大于 value 的第一个元素
    auto it = std::upper_bound(vec.begin(), vec.end(), value);

    if (it != vec.end()) {
        std::cout << "First element greater than " << value << " is: " << *it << std::endl;
    } else {
        std::cout << "No element greater than " << value << " found" << std::endl;
    }

    return 0;
}

// First element greater than 6 is: 7
```

在这个示例中，`std::upper_bound` 被用来查找序列中大于给定值的第一个元素。在这个例子中，`value` 被设置为 6，`std::upper_bound` 将返回指向序列中值为 7 的元素的迭代器。

`std::upper_bound` 在二分搜索树中的应用十分常见，它提供了一种在有序序列中高效查找大于特定值的元素或查找插入位置的方法。