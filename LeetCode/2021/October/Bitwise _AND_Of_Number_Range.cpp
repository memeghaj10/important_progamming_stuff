class Solution {
public:
    /***
     * Return the bitwise and of all numbers from left to right inclusive
     * Key: Suppose left is something like:
     * 00001xxxxx
     * and right is something larger, so it's:
     * yxxxxxxxxx
     * 
     * Off the rip we know the largest bit of left to largest bit of right should be zeroed out
     * Ex:
     * left = 7 = 0111
     * right= 9 = 1001
     * Because 8 = 1000 falls in between all three bits will end up being cleared...
     * Optimal: just get the longest prefix chain of 1s that are common between left and right
     ***/
    int rangeBitwiseAnd(int left, int right) {
        if(left > right) {
            return 0;
        }
        
        int res = 0;
        for(
            int bit = 0, lMSB = getMsb(left), rMSB = getMsb(right);
            (bit = (lMSB & left)) == (rMSB & right) && lMSB != 0;  // prefix matches and haven't exhausted both
            res |= bit, lMSB >>= 1, rMSB >>= 1                     // extend result, extract next msb
        );
        
        return res;
    }
    
    /***
     * Given a 32-bit integer x get its most significant bit only
     * Ex: x = 0000 0000 0000 0000 0000 1xxx xxxx xxxx
             =>0000 0000 0000 0000 0000 1000 0000 0000
     ***/
    int getMsb(int x) {
        if(x == 0) {
            return 0;
        }
        
        int res = 0x01; // figure out where to put the singleton 1
        if(x & 0xFFFF0000) { // check top 16 bits of 32-bit number; if any bit is set within this range, adjust
            x >>= 16;
            res <<= 16;
        }
        
        if(x & 0x0000FF00) { // check top 8 bits of 16-bit number
            x >>= 8;
            res <<= 8;
        }
        
        if(x & 0x000000F0) { // check top 4 bits of 8 bit number
            x >>= 4;
            res <<= 4;
        }
        
        if(x & 0x0000000c) { // check top 2 bits of 4 bit number 
            x >>= 2;
            res <<= 2;
        }
        
        if(x & 0x00000002) {
            x >>= 1;
            res <<= 1;
        }
        
        return res;
    }
};