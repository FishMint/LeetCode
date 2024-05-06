# c++算法（代码随想录）

------

## 数组篇：



### 二分法：

> 相关题目：
>
> - [x] 35.搜索插入位置
> - [x] 34.在排序数组中查找元素的第一个和最后一个位置
> - [x] 69.x 的平方根
> - [x] 367.有效的完全平方数

#### [力扣704 二分查找](https://leetcode-cn.com/problems/binary-search/)

- 方法一：传统二分查找

```c++
class Solution
{
public:
int search(vector<int> &nums, int target)
{
   int left = 0, right = nums.size() - 1, mid;
   while (left <= right)
   {
       mid = (left + right) / 2;
       if (nums[mid] == target)
       {
           return mid;
       }
       else if (nums[mid] < target)
       {
           left = mid + 1;
       }
       else
       {
           right = mid - 1;
       }
   }
   return -1;
}
};
```



- 方法二 二分查找变种：

```c++
class Solution
{
public:
int search(vector<int> &nums, int target)
{ 
   int left = 0, right = nums.size(), mid;

   while (left < right)
   {
       mid = (left + right) / 2;		//保证mid向左偏
       if (nums[mid] < target)
       {
           left = mid + 1;
       }
       else if (nums[mid] > target)
       {
           right = mid;					//这个right指的一定是那个没有用的数据，因为right = mid
       }								//这样才能保证这个 while的（）中的条件不会因为left = right
       else								//就退出然后是错过可能答案
       {
           return mid;
       }
   }
   return -1;
}
};
```





#### [35.搜索插入位置](https://leetcode.cn/problems/search-insert-position/submissions/)

- **解题思路：**

  简单的思路就是普通的二分查找，（我用的是变种的）

  - 要么找到target下标 ， 找到就返回，

  - 要么没有找到 ， 返回插入的位置，

    找到while循环最终退出时 left 和 right 的位置  与   最终的target 的关系就行

    这关系无非两种情况：

    - left（mid ） ， right  ——>  target 比nums[mid] 大 ， left ++ 和right重合退出while
    - left（mid ） ， right  ——>  target 比nums[mid] 小 ，right = mid 和 left 重合退出while

    但是两种情况怎么看都是right 就是插入的下标，所以返回right就行了

  

```c++
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size(), mid;
        //变种 ， right一直指着（有效数据的最后一位+1）的位置
        while (left < right)
        {
            mid = (left + right) / 2;//靠左
            if (nums[mid] > target)
            {
                right = mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return right;
    }
};
```





#### [34.在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/)

**方法一思路：**

就是普通的一个个遍历然后，然后通过一个开关来判断

这个是第一个target  还是 最后一个target的坐标



**方法二思路：**

就是变种二分，然后找到第一个，或者是最后一个，然后 ++ 或者是 -- ，

直到找到最后一个target的下标，

如果没有就是没有，但是要多多考虑特殊情况下标有没有越界



**方法三思路：**

就是两边都用二分，分别找最大，最小的下标，最后合起来。



**方法一的代码：**

```c++
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> result = {-1, -1};
        // 第一次对上的开关
        bool flag = false;
        int i = 0, lenth = nums.size() - 1;
        for (; i <= lenth; i++)
        {
            // 第一次 ==
            if (nums[i] == target && !flag)
            {
                flag = true;
                result[0] = i;
                continue;
            }

            // 最后一次==
            if (flag && nums[i] != target)
            {
                result[1] = i - 1;
                return result;
            }
        }

        // 防止target一直延续到数组最后一位，”最后一次“ 没有触发，导致{起始,-1}的情况
        if (flag)
        {
            result[1] = i - 1;
        }

        return result;
    }
};
```



**方法二代码:**

```c++
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size(), mid, lenth = nums.size() - 1;
        int start, end ,i;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid] >= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        //不这样可能引起nums引用空指针
        if(left == nums.size()) return vector<int>{-1,-1};
        if(nums[left] != target)  return vector<int>{-1,-1};
        else
        {
            start =left;
            end =left;
            for ( i = left; i <= lenth; i++)
            {
                if(nums[i] != target)    break;
                end++;
            }
        }
        return vector<int>{start,end};
    }
};
```





#### [69.x 的平方根](https://leetcode.cn/problems/sqrtx/)

**解题思路有两个：**

1. 直接用for循环，一个一个，把最小的那个找出来
2. 用二分查找



**第二种方法代码：**

```c++
class Solution
{
public:
    
    int mySqrt(int x)
    {
        long left = 1, right = x / 2 + 1, mid;
//——————————————————————————————————————————————————————————————————————————————————
        //第二种 可行的left 和right
        //但是 left = 1 ， right =x，就把1包括进来了，0也是 ，但是0是歪打正着
//——————————————————————————————————————————————————————————————————————————————————
        while (left <= right)
        {
            mid = (left + right + 1) / 2;   //只有偏右才能让最后 平方小于x 的数字 都是right
            if (mid * mid < x)
            {
                left = mid + 1;
            }
            else if (mid * mid > x)
            {
                right = mid - 1;
            }
            else
            {
                return (int)mid;
            }
        }
        return (int)right;
    }
};
```





#### [367.有效的完全平方数](https://leetcode.cn/problems/valid-perfect-square/description/)

**思路一：**

二分法同上面的那个一样，一个不漏的去找，找得到target ， 就直接return 正确

找不到就在末尾return 错误，不用考虑 0 

**思路二：**

还是直接用for （1—num/2 ）, 然后直接一个一个找



**思路一代码：**

```c++
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        long left = 1, right = num / 2 + 1, mid;
        while (left <= right)
        {
            mid = (left + right + 1) / 2;	//这里偏左偏右无所谓，只要能保证有target就能找出来
            if (mid * mid < num){
                left = mid + 1;
            }
            else if (mid * mid > num){
                right = mid - 1;
            }
            else{
                return true;
            }     
        }
        return false;
    }
};
```

**思路二代码：（别人的 最小内存解法）**

```c++
class Solution {
public:
    bool isPerfectSquare(int num) {
         if(num ==1){
            return true;
         }

        for(int i = 2; i < num/2+1; i++ ){
            if((long long)i*i == num){
                return true;
            }
            if((long long)i*i > num){
                return false;
            }
        }
        return false;

    }
};
```



### 双指针法：

> 相关题目：
>
> - [x] 26.删除排序数组中的重复项
> - [x] 283.移动零
> - [x] 844.比较含退格的字符串
> - [x] 977.有序数组的平方

#### [移除元素](https://leetcode-cn.com/problems/remove-element/)

1. **首算法的过程就是下面是最傻的**：

![图片](assets/640-20240130223307639.gif) 



2. **双指针法的流程**

  ![图片](assets/640-20240130223307745.gif) 



**代码：（ 这里我只用了 双指针法）**

```c++
class Solution
{
public:
   // 双指针法
   int removeElement(vector<int> &nums, int val)
   {
       int fast = 0, slow = 0; // 快慢指针
       for (; fast < nums.size(); fast++)
       {
           if (nums[fast] != val)
           {
               nums[slow++] = nums[fast];
           }
       }
       return slow;
   }
};
```

> 其实有个更加简单的理解这个代码，就是快指针，遍历每个元素，
>
> 不是目标的，就直接放到慢指针（从零开始，可以理解为一个新的数组）那里， 是目标就不放







#### [977.有序数组的平方](https://leetcode-cn.com/problems/squares-of-a-sorted-array/)

- 思路一：全部平方，然后直接排序（n + nlogn）

- 思路二：双指针

![图片](assets/640-20240130223307695.gif) 

**思路一的代码（Java）：**

> 纯纯暴力暴力破解，调用自带的API

```java
class Solution {
        public int[] sortedSquares(int[] nums) {
            for(int i=0;i<nums.length;i++)
                nums[i]=nums[i]*nums[i];
            Arrays.sort(nums);
            return nums;
        }
    }
```



**思路二的代码（cpp）：**

```c++
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> result(nums.size(), 0); // 构造一个和nums一样的vector向量
        int left = 0, right = nums.size() - 1, current_position = nums.size() - 1;
        int L_value, R_value; // 左右两边的平方
        while (left < right)
        {
            L_value = nums[left] * nums[left];
            R_value = nums[right] * nums[right];
            if (L_value <= R_value) // 如果右边的平方大 ， 就把右边的平方放到 current_position的位置
            {
                result[current_position--] = R_value; // 赋值完就向前移动
                right--;                              // 右指针向左移动
            }
            else // 左边大就是把左边的放上去
            {
                result[current_position--] = L_value; // 赋值完就向前移动
                left++;                               // 左指针向右移动
            }
        }
        /*最后由于while的条件是< 而不是 <= 所以最后会有一种 left = right 的情况，这个位置上的数还没有放，
        但是这个一定是最小的，所以直接放在最后的current_position位置上就好了
        */
        result[current_position] = nums[left] * nums[left];
        return result;
    }
};
```





#### [26.删除排序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/)

**思路:**

就是双指针的思路，

首先定义一个slow慢指针 ，  再来一个fast快指针 ， 一前一后

初始化的时候 ： slow先占掉第一个数字，fast则去第二个

fast往后一个个遍历 ，  如果和slow的不一样，那就让slow把后面那个位置放不一样的数字，以此类推

`简单来说:`就是fast遍历一遍， slow看着有谁不一样，从0开始 一个个(slow++ )把不一样数字塞进数组

最后，`slow肯定是最后一个独立数字的下标`， 所以返回`slow + 1`



```c++
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int slow = 0, fast = 1;
        for (; fast < nums.size(); fast++)
        {
            // 如果不一样就直接把数字填上去
            if (nums[slow] != nums[fast])
            {
                nums[++slow] = nums[fast];
            }
        }
        return (slow + 1);
    }
};
```





#### [283.移动零](https://leetcode.cn/problems/move-zeroes/)

**思路一：**

就是和之前的双指针一个思路，把不是 0 的前移动 ， 最后从 最后一个非0数字的后面一个开始变成0

太麻烦，有可能需要两次 n 的循环



**思路二：**

从第一个0开始， 把后面的非0数字想着第一个指针那里移动， 在原来的位置放0

只需要一次n的循环， 因为0已经补完了

**思路一代码：**

```c++
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slow = -1, fast = 0;
        for (; fast < nums.size(); fast++)
        {
            if (nums[fast] != 0)
            {
                nums[++slow] = nums[fast];
            }
        }
        slow++; // 往后面跳一个格
        for (; slow < nums.size(); slow++)
        {
            nums[slow] = 0;
        }
    }
};
```

**思路二代码：**

```c++
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slow = -1;
        for (int fast = 0; fast < nums.size(); fast++)
        {
            // 确定第一个 0 的位置
            if (slow == -1 && nums[fast] == 0)
            {
                slow = fast;
            }
            else if (slow != -1 && nums[fast] != 0)
            {
                nums[slow++] = nums[fast];
                nums[fast] = 0;
            }
        }
    }
};
```



#### [844.比较含退格的字符串](https://leetcode.cn/problems/backspace-string-compare/)

**思路一：**

最简单的就是重新创建一个数组，是#就pop，不是#就是push。

**思路二**：

和之前的思路是一样的，就是快慢指针，然后是非#，就往 以 slow 为下标的数组里放，

如果是#，那就slow--，反正新的来了会覆盖 的，

`但是这里可能会出现一堆# ， 让slow直接变成负数的情况，所以这个时候加一个条件就好了 slow > 0 再 --`

最后截取，从0开始，slow个字符作为新的字符串就好了



**思路一代码：**

```c++
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        string s1 = this->Remove_Backspace(s), t1 = this->Remove_Backspace(t);
        return s1 == t1;
    }
    // 去掉退格符
    string Remove_Backspace(string &tmp)
    {
        string result;
        for (char c : tmp)
        {
            if (c != '#')
            {
                result.push_back(c);
            }
            else
            {
                //这里怕是"" 不能用pop
                if(result !="")
                {
                    result.pop_back();
                }               
            }
        }

        return result;
    }
};
```

**思路二代码：**

```c++
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        return this->Remove_Backspace(s) == this->Remove_Backspace(t);
    }
    // 去掉退格符
    string Remove_Backspace(string &tmp)
    {
        int slow = 0;
        for (int fast = 0; fast < tmp.size(); fast++)
        {
            if (tmp[fast] != '#')
            {
                tmp[slow++] = tmp[fast];
            }
            //防止 slow直接减到负数
            else if (slow > 0)
            {
                slow--;
            }
        }
        return tmp.substr(0, slow);
    }
};
```



### 滑动窗口：

> 相关题目：
>
> - [x] 904.水果成篮
> - [x] 76.最小覆盖子串



#### [长度最小的子数组](https://leetcode-cn.com/problems/minimum-size-subarray-sum/)

- **解题思路**

> 十分完美的滑动窗口解法

![图片](assets/640-20240130223307881.gif) 



**代码:（滑动窗口，O(n) ）**

```c++
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // 定义前后指针，作为滑动窗口的左右边沿
        int pre = 0, after = 0, min = INT32_MAX, sub_length, sum = 0;
        for (; pre < nums.size(); pre++)
        {
            sum += nums[pre];
            while (sum >= target)
            {
                sub_length = pre - after + 1;              // 字串长度
                min = sub_length > min ? min : sub_length; // 取最小
                sum -= nums[after++];                      // 窗口从左向右缩小
            }
        }
        if (min == INT32_MAX) // min为INT32_MAX,说明连while都没有进去过
        {
            return 0;
        }
        return min;
    }
};
```







#### [904.水果成篮](https://leetcode.cn/problems/fruit-into-baskets/submissions/462679381/)

**思路：**

用一个哈希表当成是果篮，对应种类的水果装放到国篮里，——>  map（水果种类， 水果数量）

右指针遍历，如果map里面有三个key，那就说明有多出来的，

左指针开始向右移动，把途经的所有的水果都移出来，直到其中一个map对应的水果的数量为0，说明这个水果已经完全被移除

就只剩下两个了，然后重复，记录最大长度



**代码：**

```c++
class Solution
{
public:
    // 滑动窗口（ + 哈希表）
    int totalFruit(vector<int> &fruits)
    {
        int left = 0, right = 0, kind = 0, result = 2, length = fruits.size();
        int baskets[100000];
        memset(baskets, 0, 100000);		//把数组里面的元素都置零，局部整形变量的值是随机的
        //这里排除长度小于等于2的情况的干扰
        if (length <= 2)
        {
            return length;
        }
		//右指针一个个遍历
        for (; right < fruits.size(); right++)
        {
            baskets[fruits[right]]++;	//水果塞到果篮里
            if (baskets[fruits[right]] == 1) // 统计水果种类
            {
                kind++;
            }

            // 如果种类比2大就直接滑动窗口
            // 这里从哈希表中去掉left
            while (kind > 2)
            {
                baskets[fruits[left]]--;
                if (baskets[fruits[left]] == 0)
                {
                    kind--;
                }
                left++;
            }
            //这里的left肯定是第一个果篮里的水果第一次出现的位置
            result = max(result, right - left + 1);
        }
        return result;
    }
};
```





#### [76.最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/)

思路：

滑动窗口的思路：

首先明白： s_map是哈希表（当前的窗口） ，  t_map是目标的哈希表（先把它初始化了先）

滑动窗口的左边是left ， 右边是right

就是right指针向后移动，遍历s，把s_map伸长，

每次伸长的时候，用 while检查最后一个left的字符在s_map中的数量，是不是比在 t_map中的大，大的话，向右边移动一个格， 

——这就保证了一边向右拓展的同时，还能用while的检查让窗口收缩

如果检查到s_map已经满足了t_map的要求，并且right - left  + 1 <  reslut.size()，就把当前的滑动窗口的字符赋给result

一旦满足过要求后，就不可能不满足了，因为这个while不可能会破坏满足的条件

最后在检查到底有没有满足过条件，如果有，就返回result， 没有就是空字符



代码：

```c++
class Solution {
 public:
  string minWindow(string s, string t) {
    //定义s_map滑动窗口 ， t_map目标的哈希表
    unordered_map<char, int> s_map, t_map;
    int left = 0, right = 0, current = 0;
    string result = s;

    // t_map填充
    for (char &c : t) t_map[c]++;

    // right开始遍历
    for (; right < s.size(); right++) {
      s_map[s[right]]++;

      //如果当前字符是目标字符，那计数器就++,不是的话  1 !<= 0，=是因为先++的
      if (s_map[s[right]] <= t_map[s[right]]) current++;

      //开始滑动窗口，这里的滑动是个体的滑动，
      //就是left所在的字符，如果在s_map里的数量比t_map的多
      //就直接把left向后移动
      //直到left字符的数量 ==
      // t_map里的数量，因为这样就不可能在滑动窗口减少长度了
      //或者一开始就没有满足要滑动的条件
      while (left < right && s_map[s[left]] > t_map[s[left]]) {
        s_map[s[left++]]--;
      }

      //开始判断是不是满足条件
      if (t.size() == current) {
        if (result.size() > right - left + 1) {
          result = s.substr(left, right - left + 1);
        }
      }
    }

    return t.size() == current ? result : "";
  }
};
```





### 模拟行为：

> 相关题目：
>
> - [x] 54.螺旋矩阵
> - [x] 剑指Offer 29.顺时针打印矩阵



#### [螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/description/)

暴力法：

先看看row和col那个小一点，取出小的然后直接 >> 1,赋给round_time 意思就是说，

在用for循环来一个个拿，但是这里会出现两种情况：

1. 最小的那个是偶数，一个大的for循环结束之后，全部都可以拿出来
2. 最小的那个是基数，一个大的for循环结束之后，还有一条竖着的，或是横着的没有取出来



**代码；**

```c++
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row = matrix.size(), col = matrix[0].size(), round_time;
    vector<int> ans;

    //取最小值,完成最外圈的for的次数
    round_time = min(row, col);
    round_time = (round_time >> 1);

    int i, j, t;
    //开始循环
    for (t = 1; t <= round_time; t++) {
      i = t - 1;
      j = t - 1;

      //最上方填充
      for (; j < col - t; j++) {
        ans.push_back(matrix[i][j]);
      }

      //最右边
      for (; i < row - t; i++) {
        ans.push_back(matrix[i][j]);
      }

      //最下面
      for (; j > t - 1; j--) {
        ans.push_back(matrix[i][j]);
      }

      //最左边
      for (; i > t - 1; i--) {
        ans.push_back(matrix[i][j]);
      }
    }

    //如果这里是row是最小值且最小值是基数,那就把 横着的那段加进来
    if (row <= col && row % 2 == 1) {
      //这里的t是for结束的时候++的
      i = t -1;
      j = t -1;
      for (; j <= col - t; j++) {
        ans.push_back(matrix[i][j]);
      }
    }

    //如果这里是col是最小值且最小值是基数,那就把 竖着的那段加进来
    if (row > col && col % 2 == 1) {
        i = t -1;
        j = t -1;
        for (; i <= row - t; i++) {
            ans.push_back(matrix[i][j]);
        }
    }


    return ans;
  }
};
```





#### [剑指Offer 29.顺时针打印矩阵](https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/description/)

思路和上面的一样，就是多一个开局判断是否为空。

```c++
class Solution {
 public:
  vector<int> spiralArray(vector<vector<int>>& array) {
    //开局判断是否为空
    if(array.size() == 0)    return vector<int>();
    int row = array.size(), col = array[0].size(), round_time;
    vector<int> ans;

    //行列最小值
    round_time = (min(row, col) >> 1);
    int i, j, t;

    for (t = 1; t <= round_time; t++) {
      i = t - 1;
      j = t - 1;

      //最上面
      for (; j < col - t; j++) {
        ans.push_back(array[i][j]);
      }

      //最右边
      for (; i < row - t; i++) {
        ans.push_back(array[i][j]);
      }

      //最下面
      for (; j > t - 1; j--) {
        ans.push_back(array[i][j]);
      }

      //最左边
      for (; i > t - 1; i--) {
        ans.push_back(array[i][j]);
      }
    }

    //如果最小的是row且为基数
    if (row <= col && row % 2 == 1) {
      i = t - 1;
      j = t - 1;
      for (; j <= col - t; j++) {
        ans.push_back(array[i][j]);
      }
    }

    if (col < row && col % 2 == 1) {
      i = t - 1;
      j = t - 1;
      for (; i <= row - t; i++) {
        ans.push_back(array[i][j]);
      }
    }

    return ans;
  }
};
```





#### [螺旋矩阵II](https://leetcode.cn/problems/spiral-matrix-ii/)

没有什么捷径只有暴力

![img](assets/spiraln.jpg) 

思路很简单，就是如果n是3，那么外围就需要 3\2 =1次

中间的数字分两种情况：

- 奇数，直接再中间填一个 3 * 3
- 偶数就没有中间数

剩下的自己看代码



```c++
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int total_time = n / 2, current_num = 1;
        if (n == 1)
        {
            result[0][0] = 1;
            return result;
        }

        if (n % 2 == 1) // 奇数
        {
            result[total_time][total_time] = n * n; // 直接把中间的孤儿填起来
        }
        for (int time = 1; time <= total_time; time++)
        {
            int i = 0, j = 0;
            /*最上面那行的*/
            i = time - 1; // 哪一行开始
            for (j = time - 1; j < n - time; j++)
            {
                result[i][j] = current_num++;
            }

            /*最右边面那列的*/
            // 当前 i = time - 1;    这个i是自动上面就自己有的， 一排填完数字之后，正好的，i的起始位置就是上面的那个
            for (; i < n - time; i++)
            {
                result[i][j] = current_num++;
            }

            /*最下面那行*/
            // j =n -time;
            for (; j > time - 1; j--)
            {
                result[i][j] = current_num++;
            }

            /*最左边那行*/
            // i= n- time;
            for (; i > time - 1; i--)
            {
                result[i][j] = current_num++;
            }
        }
        return result;
    }
};
```







## 链表



#### [203.移除链表元素](https://leetcode-cn.com/problems/remove-linked-list-elements/)

思路一：

虚头节点，一个个删除



思路二：

没有虚头节点，但是类似于设置虚头节点，一开始用while循环保证，head不是val



**思路一代码：**

```c++
class Solution {
 public:
  ListNode *removeElements(ListNode *head, int val) {
    if (head == NULL) return NULL;  //如果本来就是空
    ListNode *v_head = new ListNode;
    v_head->next = head;                  //把虚头节点直接放上去
    ListNode *ptr = head, *pre = v_head;  //定义前驱节点和当前节点

    while (ptr != NULL) {
      //如果当前的节点的val == val
      if (ptr->val == val) {
        pre->next = ptr->next;
        delete (ptr);
        ptr = pre->next;
        continue;
      }
      //不是的话，下一跳
      pre = pre->next;
      ptr = ptr->next;
    }
	//因为有虚头节点
    return v_head->next;
  }
};

```



**思路二代码：**

```c++
class Solution {
 public:
  ListNode *removeElements(ListNode *head, int val) {
	  //这里是保证头节点不是val
	  while(head != NULL){
		  if(head->val != val)	break;
		  head = head->next;
	  }

	  //如果head是空就返回空
	  if(head == NULL)	return NULL;

	  //设置一个前驱指针，一个当前指针
	  ListNode *pre = head, *ptr = head->next;

	  //这里其实还是和虚头节点一样
	  while(ptr != NULL){
		  if(ptr->val == val){
			 pre->next = ptr->next;
			 delete(ptr);
			 ptr = pre->next;
			 continue;
		  }
		  pre = pre->next;
		  ptr = ptr->next;
	  }
	  return head;
	}
};

```





#### [206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/)

**思路：**

先定义一个NULL的pre指针，因为第一个反转之后，它的next就是NULL 了，再来一个after备份一下cur的 下一个

之后就是用pre = cur ， cur = after 来移动这个指针了 ， 毕竟改完之后next全反了

![图片](assets/640-20240130223307454.gif) 



**代码：**

```c++
 class Solution {
  public:
      ListNode* reverseList(ListNode* head) {
          if(head == NULL)    return NULL;

          //定义前中后指针
          ListNode *pre = NULL, *cur = head, after;

          //备份cur后指针
          //把cur 的next -> pre
          //再把pre向后面移动（就是cur）
          //cur也向后移动，就是after备份指针的位置
          //然后重复运行
          while(cur != NULL){
              after = cur->next;
              cur->next = pre;
              pre = cur;
              cur = after;
          }

          //退出的时候，cur肯定是NULL，pre一定是最后一个，反转后的第一个
          return pre;
      }
  };
```





#### [链表相交](https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/)

**思路：**

先把两条链子的长度算出来，做一个差，然后把长的那条链子用while(差--)

把它的移动到和短的开头同一位置

  因为如果要交叉的话，那他的最后几个肯定是    

A ：  ++++｜++｜

​			   ｜+++++++++++

B：           ｜ ++｜

就是让A移动到第一个｜到位置



**代码：**

```c++
  class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      int Len_A = 0, Len_B = 0, Diff;
      ListNode *curA = headA, *curB = headB;

      //计算节点个数
      while (curA != NULL) {
        Len_A++;
        curA = curA->next;
      }
      while (curB != NULL) {
        Len_B++;
        curB = curB->next;
      }

      //保证永远是A长于B
      curA = headA;
      curB = headB;
      if (Len_A < Len_B) {
          std::swap(curA, curB);
          std::swap(Len_A, Len_B);
      }
      Diff = Len_A - Len_B;

      //和B对齐
      while(Diff--){
          curA = curA->next;
      }

      //看看A和B有没有重叠的地方
      while(curA != curB){
          curA=curA->next;
          curB= curB->next;
      }

      return curA;
    }
  };
```





#### [19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

**思路：**

其实就是加上虚头节点（不加超级麻烦），

把总长度 算出来， 减去n ， 然后算差值，用while（n--）把cur指针移动到要删除的位置，由于虚头节点，pre必定在前面

然后就正常删除，把虚头节点后面的那个返回



**代码：**

```c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *cur =head, *v_head = new ListNode;

        //来一个虚头节点
        v_head->next = head;

        //开始统计一下总长度
        while(cur != NULL){
            len++;
            cur = cur->next;
        }

        //差值
        len = len - n;
        //重置一下节点
        ListNode *pre = v_head;
        cur = head;

        //因为虚头节点的原因，pre一直是要删除的点前面的那个
        while(len--){
            pre = pre->next;
            cur = cur->next;
        }

        //直接把中间的那个删除前接上后，最后返回虚头节点的后面那个就好了
        pre->next = cur->next;
        delete(cur);
        return v_head->next;
    }
};
```



#### 

#### [142. 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/)

**思路：**

![img](assets/7bed2bff-a26c-4aa6-a37b-8640afae82d9-24472406.jpg)

![img](assets/96a5064e-2255-4805-9362-4ce5138eb5dd-24472406.jpg)

![img](assets/967d3cd2-4e5d-4801-bbfb-a04a9192a6c8-24472406.jpg)



**代码：**

```c++
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;

    //看看有没有环，有环内部处理，没有返回NULL
    while (fast != NULL && fast->next != NULL) {
      //开始移动
      slow = slow->next;
      fast = fast->next->next;

      if (fast == slow) {
        slow = head;
        while (fast != slow) {
          fast = fast->next;
          slow = slow->next;
        }   
        return fast;
      }   
    }   

    return NULL;
  }
};

```







## 哈希表

#### [242. 有效的字母异位词](https://leetcode.cn/problems/valid-anagram/)

**思路：**

简单的利用哈希表，先把s的字符串 ， 塞到哈希表里，顺便记个数，因为搜索快，s_map

然后再使用遍历一遍 string t ： char c ，然后把对应的s_map[c] -- ,

再遍历一遍s_map ， 如果都是0 就是true ， 如果有一个不是0 ，就是false



**代码：**

```c++
class Solution {
 public:
  bool isAnagram(string s, string t) {
    //如果个数都不一样直接返回false
    if (s.size() != t.size()) return false;
    map<char, int> s_map;

    //简单的hash表，来填充s_map
    for (char c : s) {
      s_map[c]++;
    }

    //把s_map给-回去
    for (char c : t) {
      s_map[c]--;
    }

    //检查一下所有的元素是不是为0
    for (auto it = s_map.begin(); it != s_map.end(); it++) {
      if (it->second != 0) return false;
    }

    return true;
  }
};
```





#### [1002. 查找共用字符](https://leetcode.cn/problems/find-common-characters/)

**思路：**

首先制造一个26个字母的哈希表，再把各个word对应的字母的数量当道hash表插到对应的字母后面，

如下图——int map[26]\[word_num]

<img src="assets/bbacdf20-cf28-4ef9-8240-43a4c7b2144e-24472406.jpg" alt="image" style="zoom: 25%;" /> 

然后统计每个字母在每个word中出现的频率，

然后遍历map[ 1 - 26 ]{   

​	map[]\[1- word_num]

   }

然后取一个最小值，用while 把当前的这个字母塞进result的数组里（最小的是 0 ，那就塞不进去，如果是1，2，3 ， 那就循环塞进去）



**代码：**

```c++
class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    int num = words.size(), min;
    int map[26][num];
    vector<string> result;

    //初始化，头文件cstring
    memset(map,0,sizeof(map));

    //开始统计各个字母在各个word中出现的频率
    for (int i = 0; i < words.size(); i++) {
      for (char c : words[i]) {
        map[c -97][i]++;
      }
    }

    //每个map[字母] 的数组中，拿出最小的，就是公共字母出现的次数
    for(int i =0; i<26;i++){
        min = INT_MAX;
        for(int j =0; j<num;j++){
            if(min > map[i][j]) min = map[i][j];
        }
        while(min--)    result.push_back(string(1,'a'+i));
    }

          return result;
  }
};
```





#### [349. 两个数组的交集](https://leetcode.cn/problems/intersection-of-two-arrays/)

**思路：**

首先把nums1里面的数字全部都放到 set1（数字不重复的数组）里面

然后遍历nums2中的数字，拿出一个就在set1里找有没有，

有就塞到set2里，——因为nums2的数字可能有重复比如{ 1 ,1 1, 2 ,3 }

如果是这样的话那每次检测到 nums2 中的1都要添加那就重复了，

所以再创建一个set2  ，把 nums2在set1中出现的数字塞到set2 （而不是 vector ，避免重复）

最后再用set2创建vector



**代码：**

```c++
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //先把nums1放到 没有重复元素的 ，并且无序的unordered_map里（效率高）
    unordered_set<int> set(nums1.begin(), nums1.end());
    //因为nums2中可能有重复的元素，直接用vector 可能会有重复元素
    unordered_set<int> result;

    for (int i : nums2) {
      //如果set里有，nums2中的元素，直接插入，反正是unordered_map，肯定没有重复
      if (set.find(i) != set.end()) result.insert(i);
    }

    //直接使用vector的构造方法 ———— （it->begin(), it->end()）
    return vector<int>(result.begin(), result.end());
  }
};
```





#### [202. 快乐数](https://leetcode.cn/problems/happy-number/)

**思路：**

创建一个set ， 

用while把题目给的数字 n ，和n的求和每次循环放一个进去

如果循环求和的过程中 ， 有重复，那就说明是死循环，就直接返回false

如果有一个是 == 1的，那就直接返回true



**代码：**

```c++
class Solution {
 public:
  //就是普通的取各个位上的数字的平方和
  int getSum(int n) {
    int sum = 0;
    int v;
    while (n) {
      v = n % 10; 
      sum += v * v;
      n /= 10; 
    }   
    return sum;
  }

  bool isHappy(int n) {
    unordered_set<int> set;
    int sum = n;

    //每次取和在set里面找，有重复就退出，没有就继续
    while (set.find(sum) == set.end()) {
      if (sum == 1) return true;  //如果算出来是1，就退出
      set.insert(sum);
      sum = getSum(sum);
    }   
    return false;
  }
};
```





#### [ 1.两数之和](https://leetcode.cn/problems/two-sum/)

**思路：**

首先创建一个map ——（nums[index]  ,  index）

遍历nums ， 每记为nums[i] , 

每次在map里找 ， （target  -  nums[i] ）有没有 ，

- 没有就插入 （ nums[i]  ,  i ）

- 有的话，就返回 { `（map 的对应的那个 index ）` ， i}



**代码：**

```c++
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> n_map;

    for (int idx = 0; idx < nums.size(); idx++) {
      //如果找得到的话就直接返回
      if (n_map.find(target - nums[idx]) != n_map.end())
        return {idx, n_map[target - nums[idx]]};

      //插入当前的数字和下标
      n_map.insert(pair<int, int>(nums[idx], idx));
    }   

    //找不到就返回空
    return {}; 
  }
};

```





#### [454. 四数相加 II](https://leetcode.cn/problems/4sum-ii/)

**思路：**

先创建一个u_map（`nums1 + nums2的所有可能` ,      `对应的和的次数`  ）

再遍历nums3 ，nums4， 记target =  0 -（nums3 + nums4）

然后在u_map里找target 如果有的话，那就直接把它的 second 加到计数器里



**代码：**

```c++
class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    unordered_map<int, int> map1_2;
    int target = 0, result = 0;

    //计算nums 1，2的和
    for (int a : nums1) {
      for (int b : nums2) {
        map1_2[a + b]++;
      }
    }

    for (int c : nums3) {
      for (int d : nums4) {
        target = -c - d;
        if (map1_2.find(target) != map1_2.end()) result += map1_2[target];
      }
    }

    return result;
  }
}; 
```





#### [383. 赎金信](https://leetcode.cn/problems/ransom-note/)

**思路：**

就是把magazine全部放到u_map里面		  u_map（  magazine[]  ,   字母出现的次数）

然后再遍历一遍 ransomNote   :   c ， 遍历一次，umap[c ]--，

如果减完之后发现umap[c ] < 0 ，说明在magazine中 ， 这个字母不够用了，就返回false



**代码：**

```c++
// 时间复杂度: O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        for (int i = 0; i < magazine.length(); i++) {
            // 通过recode数据记录 magazine里各个字符出现次数
            record[magazine[i]-'a'] ++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            // 遍历ransomNote，在record里对应的字符个数做--操作
            record[ransomNote[j]-'a']--;
            // 如果小于零说明ransomNote里出现的字符，magazine没有
            if(record[ransomNote[j]-'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
```





#### [15.三数之和](https://leetcode-cn.com/problems/3sum/)

**思路：**

**第一个是哈希**，：

但是太慢了就是直接来选不同的两个的数组合，然后直接在剩下来的数中看看有没有 (sum - (num1 + num2))



**第二个就是滑动窗口**：

先来一个sort，从小到大排序，再确认第一个数a ，剩下来的数的从 （a + 1）—— ( end )  中选择两个，就是下图的left和right。

满足就返回 （a, left, right) , 小的话就 left++, 大的话就right++。

然后再a++ , 尝试后续可能的情况。          ⚠️题目的 **去重** 和 优化的 **剪枝**

![图片](assets/640-6625186.gif)



**代码：**

```c++
/*
不使用哈希  (timeout)
直接使用滑动窗口
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left , right, sum, lenth = nums.size();
        vector<vector<int>> ans;
    
        //确定第一个数字
        for (int i = 0; i < lenth - 2; i++) {
            //因为是升序,最小的都大于0了,那肯定是没有结果的
            //如果和前面一个有重复，那就直接跳过
            if(nums[i] > 0) break;  
            else if(i > 0 && nums[i] == nums[i - 1]) continue;

            left = i + 1;   
            right = lenth - 1;

            while(left < right){
                sum = nums[left] + nums[right];     //计算和

                if(sum > -nums[i])  right--;    //大的话右边向左移动
                else if(sum < -nums[i]) left++;    
                else{
                    ans.push_back( vector<int> {nums[i], 
                                                nums[left], 
                                                nums[right]});

                    //这里是为了去重
                    while(nums[right] == nums[right - 1] && left < right)   right--;
                    while(nums[left] == nums[left + 1] && left < right)     left++;
                    left++;
                    right--;
                }   
            }   
        }   

        return ans;
    }                                                                                        

};
```







## 字符串

#### [344.反转字符串](https://leetcode.cn/problems/reverse-string/)

**思路：**

方法一：直接使用algorithm头文件里的reverse函数

方法二： 用一个for循环直接遍历一半的数组，然后直接 首尾互换。



**代码：**

```c++
//方法一：
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};


//方法二：
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();

        /*这个方法内存占大，但是快
        char tmp;
        for(int i = 0; i < len / 2; i++){
            tmp = s[i];
            s[i] = s[len - i - 1];
            s[len - i - 1] = tmp;
        }
        */

      //这个方便看懂，但是慢
        for(int i = 0, j = len - 1; i < len /2; i++, j--){
            swap(s[i], s[j]);
        }

    }
};
  
  
```







#### [541.反转字符串II](https://leetcode.cn/problems/reverse-string-ii/description/)

**思路：**

题目的意思就是说，2k一个区间，前k个反转，如果剩下来的k-2k区间，也是前k反转，如果剩下来小于k个，那就全部反转。

每次begin + 2k，在while中每次判断

—>那就直接判断是不是够k个，反转前k个，如果不够就全部反转。





**代码：**

```c++
class Solution {
public:
    string reverseStr(string s, int k) {
        int begin = 0, len = s.size();

        while(begin < len){
            //判断 前k个是不是在s.size()中,
            if(begin + k <= len){
                reverse(s.begin() + begin, s.begin() + begin + k);
            }else{
            //如果不是，剩下来的<k，那就反转begin - s.end()
                reverse(s.begin() + begin, s.end());
            }

            begin += (2 * k);
        }

        return s;
    }
};
```





#### [LCR 122. 路径加密](https://leetcode.cn/problems/ti-huan-kong-ge-lcof/)

**思路：**

就是直接遍历一整个数组，然后是'.' 的直接换成  ‘space’。

 

**代码：**

```c++
class Solution {
public:
    string pathEncryption(string path) {
        for(int i =0; path[i] != '\0'; i++){
            if(path[i] == '.'){
                path[i] = ' ';
            }
        }

        return path;
    }
};
```





#### 剑指Offer 05.替换空格

> **题目：（leetcode下架了剑指offer）**
>
> 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
>
> 示例 1：输入：s = "We are happy." 输出："We%20are%20happy."





**思路：**

这个的思路就是先统计一下原来的单词中的空格的数量count

然后再扩容，直接使用双指针，如下图这样移动插入。

![图片](assets/640.gif)



**代码：**

```c++
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;

        //统计空格的数量
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] == ' ')     count++;
        }

        int old_size = s.size();
        int new_size = s.size() + count * 2;
        //扩容
        s.resize(new_size);

        //使用双指针直接扩容老的
        //注意for的判断条件，这个 > 写的就很妙
        for(int new_p = new_size - 1, old_p = old_size - 1;
            new_p > old_p; new_p--, old_p--)
        {
            if(s[old_p] != ' ') {
                s[new_p] = s[old_p];
            }else{
                s[new_p] = '0';
                s[new_p - 1] = '2';
                s[new_p - 2] = '%';
                new_p -= 2;
            }
        }

        return s;
    }
};
```

