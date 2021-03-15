#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG_BUAA_123
#define MAX_WORD_LEN 128
#define MAX_LEN 300
#define KW_NUM 3

/**
 * 将一段源代码中间的，位于双引号“”的以#代替
 */
void replaceQuota(char buf[]){
    int i;
    int len = strlen(buf);
    int quotaL = 0,quotaR = 0;
    for(i=0;i<len;i++){
        if(buf[i] == '"'){
            if(quotaL == 0){	//左引号
                quotaL = 1;
            }else{	//右引号
                quotaL = quotaR = 0;
            }
        }
        else{
            if(quotaL == 1){	//该字符属于引号之间的，替换为#
                buf[i] = '#';
            }
        }
    }
}

// 判断字符是否为分隔符
int isdelim(char ch){
    switch(ch){
        case ' ':
        case '=':
        case ',':
        case ';':
        case '<':
        case '>':
        case '(':
        case ')':
        case '{':
        case '}':return 1;
        default:return 0;
    }
}

/**
 * 从input数组下标pos处开始一个单词,返回的单词放在word数组中
 * 返回下次查找开始的位置
 */
int getWord(char input[],int pos,char word[]){
    int len = strlen(input);
    int i;
    int isbegin = 0;
    int wpos = 0;
    for(i=pos;i<len;i++){
        if(isdelim(input[i])){
            if(isbegin == 0){	//略过该分隔符
                continue;
            }
            else{	//单词获取结束
                break;
            }
        }
        else{
            isbegin = 1;
            word[wpos++] = input[i];
        }
    }
    word[wpos]='\0';	//结束标志，勿忘，切记
    return (i>=len) ? -1:i;	//如果到文件结尾了，返回-1
}


int main(){
    char input[300];
    char word[MAX_WORD_LEN];

#ifdef DEBUG_BUAA_123
    freopen("/Users/bwiunbuaa/tmp/oj/buaa_123.in", "r", stdin);
#endif /* JOBDU_H_ */

    char delim[] = " ,();\",+-*/=<>?:";	//单词分隔符

    while(gets(input) != NULL){
        //首先对input进行预处理，将引号中间的字符都转化为#
        replaceQuota(input);
        int beg_pos = 0;
        do
        {
            beg_pos = getWord(input,beg_pos,word);
            int wlen = strlen(word);
            //判断是否为指定的关键字
            if(strcmp("if",word) == 0){
                printf("if:%d\n",beg_pos-wlen+1);//位置以1开始，而不是0，所以要加1
            }
            else if(strcmp("while",word) == 0){
                printf("while:%d\n",beg_pos-wlen+1);
            }
            else if(strcmp("for",word) == 0){
                printf("for:%d\n",beg_pos-wlen+1);
            }
        }while(beg_pos >= 0);
    }
    return 0;
}
