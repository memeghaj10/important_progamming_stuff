class Solution {
public:
  
 
   int compareVersion(string version1, string version2) {
		int idx1 = 0, idx2 =0, val1 = 0, val2 = 0;
		while (idx1 < version1.size() || idx2 < version2.size()) { // Keep going while they are equal and at least one of them has more
			while (idx1 < version1.size()) {
				if (version1[idx1] == '.') {
					idx1++;
					break;
				}
				val1 = val1 * 10 + (version1[idx1++] - '0'); // ascii digit - '0' = that digit in integer
			}

			while (idx2 < version2.size()) {
				if (version2[idx2] == '.') {
					idx2++;
					break;
				}
				val2 = val2 * 10 + (version2[idx2++] - '0'); // ascii digit - '0' = that digit in integer
			}

			if (val1 > val2)
				return 1;
			
			if (val2 > val1)
				return -1;

			val1 = 0;
			val2 = 0;
		}
		return 0;
	}
};