## 改进冒泡排序伪代码

### 分析

优化二的 "无交换则提前停止" 实际上被优化三的 "设置排序边界为后续部分如果无交换则跳过排序" 完全包含，实际只需要添加三个优化。

### 伪代码

```
lower = 0, upper = length - 1
while (lower < upper){
    
    new_upper = lower
    max_value = arr[lower]
    for i from lower + 1 to upper - 1
        if (arr[i] > max_value)
            arr[i - 1] = max_value # 不动
            max_value = arr[i] # 新的最值
        else then
            arr[i - 1] = arr[i] # 将值前移
            new_upper = i # 如果出现交换，则认为前面的部分可能无序
    upper = new_upper

    new_lower = upper
    min_value = arr[upper]
    for i from upper - 2 to lower
        if (arr[i] < min_value)
            arr[i + 1] = min_value
            min_value = arr[i]
        else then
            arr[i + 1] = arr[i]
            new_lower = i
    lower = new_lower
}
```