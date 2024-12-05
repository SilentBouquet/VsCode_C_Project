//字符串的输入输出
#include <stdio.h>
int main(void)
{
    char word[8];
    char word2[8];
    scanf("%7s", word);
    scanf("%7s", word2);
    printf("%s##%s##\n", word, word2);
    return 0;
}
//scanf读入一个单词(到空格，tab或回车为止)
//scanf是不安全的，因为不知道要读入的内容的长度
//在%和s之间的数字表示最多允许读入的字符的数量，这个数字应该比数组的大小小一