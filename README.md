# LeetCodeRecord
用来记录刷LeetCode题的一些经验。

## BinarySearch 二分查找
- 前提条件  
    有序数组nums：查找数组，t：待查找目标元素
- 初始化  
  left=0：左边界，right=nums.size()-1：右边界，mid=（left + right）/ 2：查找的中间位置
- 查找过程  
  \[left,right\]：while(left <= right)  
  ![avatar](https://pic.leetcode-cn.com/1641871925-DYgiPG-QQ%E6%88%AA%E5%9B%BE20200217120142.png)  
  （https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/zai-pai-xu-shu-zu-zhong-cha-zhao-yuan-su-w1h4/ ）   
- 相关题目  
  [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)：用二分查找分别查找左右边界，查找左边界时收紧右侧，查找右边界时收紧左侧。  
  [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)：先根据 nums\[mid] 与 nums\[left] 的关系判断 mid 是在左段还是右段，接下来再判断 target 是在 mid 的左边还是右边，从而来调整左右边界。  
  [74. 搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/)：将m\*n二维数组转换为一维， num = matrix\[mid/n]\[mid%n]  
  [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)：[中值与右值作比较](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/er-fen-cha-zhao-wei-shi-yao-zuo-you-bu-dui-cheng-z/)  
  [162. 寻找峰值](https://leetcode-cn.com/problems/find-peak-element/)：nums\[mid]与nums\[mid+1]进行比较。若nums\[mid]>nums\[mid+1]，则一定存在一个峰值在左侧（含中值）；反之在右侧（不含中值）。

## DoublePointer 双指针  
- 相关题目  
[82. 删除排序链表中的重复元素 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/)：是删除所有的重复元素，所以要在head前再加一个dummyhead。（记得判断空指针！  
[15. 三数之和](https://leetcode-cn.com/problems/3sum/)：排序+双指针（比较i，i+1和len-1）  
[844. 比较含退格的字符串](https://leetcode-cn.com/problems/backspace-string-compare/)：从后向前循环，统计退格符的次数，如果退格符不为0，那么这个字符可以不用比较。  
[986. 区间列表的交集](https://leetcode-cn.com/problems/interval-list-intersections/)：比较四个角的大小，通过右侧值的大小来决定是否移到下一个区间。  
- 双指针实现滑动窗口题目（左右指针）  
[438. 找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)：异位词：通过对字母计数来判断。 双指针实现滑动窗口。  
[713. 乘积小于K的子数组](https://leetcode-cn.com/problems/subarray-product-less-than-k/)：增右减左。每增加一个元素，增加（right-left+1）个子集。  
[209. 长度最小的子数组](https://leetcode-cn.com/problems/minimum-size-subarray-sum/)：增右减左。
