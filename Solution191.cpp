
//题目，Number of 1 Bits 位1的个数

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            if (n&1) {
                count++;
            }
            n = n>>1;
        }
        return count;
    }
};

//n&(n-1)可以将二进制中1的个数减少1
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return n==0 ? 0 : hammingWeight(n & (n-1));
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        n = (n & 0x55555555) + (n >>  1 & 0x55555555); // put count of each  2 bits into those  2 bits
        n = (n & 0x33333333) + (n >>  2 & 0x33333333); // put count of each  4 bits into those  4 bits
        n = (n & 0x0F0F0F0F) + (n >>  4 & 0x0F0F0F0F); // put count of each  8 bits into those  8 bits
        n = (n & 0x00FF00FF) + (n >>  8 & 0x00FF00FF); // put count of each 16 bits into those 16 bits
        n = (n & 0x0000FFFF) + (n >> 16 & 0x0000FFFF); // put count of each 32 bits into those 32 bits
        return n;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        n -= (n >> 1) & 0x55555555; //put count of each 2 bits into those 2 bits
        n = (n & 0x33333333) + (n >> 2 & 0x33333333); //put count of each 4 bits into those 4 bits
        n = (n + (n >> 4)) & 0x0F0F0F0F; //put count of each 8 bits into those 8 bits
        n += n >> 8; // put count of each 16 bits into those 8 bits
        n += n >> 16; // put count of each 32 bits into those 8 bits
        return n & 0xFF;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        n -= (n >> 1) & 0x55555555; // put count of each 2 bits into those 2 bits
        n = (n & 0x33333333) + (n >> 2 & 0x33333333); // put count of each 4 bits into those 4 bits
        n = (n + (n >> 4)) & 0x0F0F0F0F; // put count of each 8 bits into those 8 bits
        return n * 0x01010101 >> 24; // returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24)
    }
};
