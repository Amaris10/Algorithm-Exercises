#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;
unsigned char C[1080][1920][3];//C[n][m][Pixel:RGB] 表示原图片在第n行m列的像素颜色
inline unsigned char getPixel(const char &a, const char &b) {//将16进制像素数转换为10进制的char
    return char((isalpha(a) ? (10 + a - 'a') : (a - '0')) * 16 + (isalpha(b) ? (10 + b - 'a') : (b - '0')));
}

inline void outChar(const unsigned char &ch) {//输出题意格式化的字符
    cout << "\\x" << hex << uppercase << setw(2) << int(ch);
}

inline void outStr(const string &str) {//输出题意格式化的字符串
    for (const char &c:str)outChar(c);
}

inline void outPixel(int i) {//输出题意格式化的像素
    vector<int> v;
    if (i == 0)v.push_back(0);
    while (i > 0) v.push_back(i % 10), i /= 10;//首先将数按位数分割 例：255 分割为 2、5、5三个数
    for (i = v.size() - 1; i > -1; --i) outChar(char('0' + v[i]));//输出每一位
}

#include<fstream>

int main() {
    int m, n, p, q, _B;// W H
    ifstream cin("C:\\Users\\Isidore\\Desktop\\out.txt");
    cin >> m >> n >> p >> q, _B = p * q, cout.fill('0');
    string s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> s;
            switch (s.size()) {//将s统一格式化为 #abcdef
                case 2://#a -> #aaaaaa
                    s = s + string(5, s[1]);
                    break;
                case 4://#abc -> #aabbcc
                    s = "#" + string(2, s[1]) + string(2, s[2]) + string(2, s[3]);
                    break;
            }
            for (int k = 0; k < 3; ++k) C[i][j][k] = getPixel(tolower(s[k + k + 1]), tolower(s[k + k + 2]));
        }
    }
    int R = 0, G = 0, B = 0, r = 0, g = 0, b = 0;
    for (int i = 0; i < n; i += q) {//共n/q个字符块行
        for (int j = 0; j < m; j += p) {//每字符块行共m/p段
            R = 0, G = 0, B = 0;//以下处理属于i行j段的字符块
            for (int k = i, nk = k + q; k < nk; ++k)
                for (int l = j, nl = j + p; l < nl; ++l)
                    R += C[k][l][0], G += C[k][l][1], B += C[k][l][2];
            R /= _B, G /= _B, B /= _B;//求平均值
            if (!(R == r && G == g && B == b)) {//如果与该行上一段的颜色不同
                if (R == 0 && G == 0 && B == 0)//如果与默认值相同
                    outStr(string(1, char(27)) + "[0m");
                else//其他颜色处理
                    outStr(string(1, char(27)) + "[48;2;"), outPixel(R), outChar(';'), outPixel(G), outChar(
                            ';'), outPixel(B), outChar('m');
                r = R, g = G, b = B;//记录上次的颜色
            }
            outChar(' ');//输出 (n*m)/(p*q) 个空格
        }
        if (R != 0 || G != 0 || B != 0) outStr(string(1, char(27)) + "[0m");//行尾判断是否需要重置颜色
        r = g = b = 0;//重置默认颜色
        outChar('\n');//输出n/q个回车
    }
    return 0;
}

