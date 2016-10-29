
//题目158，Read N Characters Given Read4 II - Call multiple times 用Read4来读取N个字符之二 - 多次调用
//题目157，Read N Characters Given Read4

class Solution {
public:
    int read(char *buf, int n) {
        for (int i=0; i<n; ++i) {
            if (readPos == writePos) {
                writePos = read4(buff);
                readPos = 0;
                if (writePos == 0) return i;
            }
            buf[i] = buff[readPos++];
        }
        return n;
    }
private:
    int readPos = 0, writePos = 0;
    char buff[4];
};

class Solution {
public:
    int read(char *buf, int n) {
        int i = 0;
        while (i<n && (readPos<writePos || (readPos=0)<(writePos=read4(buff))))
            buf[i++] = buff[readPos++];
        return i;
    }
    char buff[4];
    int readPos = 0, writePos = 0;
};
