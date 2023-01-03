#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int expressiveWords(string s, vector<string>& words);
bool ok(string s1, string s2);
int main() {
	string s = "vvvppppeeezzzzztttttkkkkkkugggggbbffffffywwwwwwbbbccccddddddkkkkksssppppddpzzzzzhhhhbbbbbmmmy";
	vector<string>words{"vvpeezttkkuggbbfywwbbccddkkspdpzhbbmmyy", "vvppeeztkkugbfywwbccddkksspdppzhhbmyy", "vppezzttkkugbffyywbccddksspddpzhhbmy", "vvppezztkugbffyywwbbccddkssppddpzzhhbbmmy", "vvppezttkuggbfyywwbbcddkspdppzhhbmy", "vppeezzttkkuugbfyywwbbccdkkssppdpzzhbbmy", "vpeezztkkugbbffyywwbbccddkksppdpzzhhbbmmy", "vppeeztkkuuggbffywbbccddkksppdppzhhbmyy", "vpeeztkkuggbfyywbbccdksppdpzhbmy", "vpeezztkkugbffywwbbccdkkssppddppzzhhbbmmy", "vvpeztkkugbbfyywbcdkssppddpzzhhbbmyy", "vpezztkugbbffyywwbcddksppddpzzhbbmy", "vvpeezztkkugbbffywwbccdkkspddpzzhbmmyy", "vvpeezzttkkuuggbbffyywbbccdkspdppzhhbmy", "vvppeezztkkuggbbfywbcdkspdpzhhbmyy", "vvppeezzttkkuugbffyywwbbccddkkspddpzzhbmyy", "vppezztkuuggbffywwbcdksspdppzhhbmyy", "vvppeezzttkuuggbffywbccddkksspddppzzhhbmmy", "vvppezzttkuggbffywbbccdkspddppzzhhbmy", "vvpezzttkuugbbfywwbccdkssppdpzhbbmmy", "vvpeezzttkuugbbffyywbccdksppddppzhhbmyy", "vpeezzttkkuggbbffywbccddksppddpzhhbbmy", "vvpezttkuuggbffywwbbccddkspdppzhhbmmyy", "vppeezzttkkuugbffywbccddksppddpzhhbmmyy", "vvpezttkkuugbbfywbccdkspddppzzhbbmmy", "vppezzttkkuugbbffywwbcddkssppddpzhhbmmy", "vppezzttkugbfywbbcdksppddppzzhhbmyy", "vppeeztkuggbbffywbbccdkkspddppzzhbbmmy", "vvpeeztkuuggbbfywbcdkksspddppzhhbbmmyy", "vpezttkkuuggbbffyywwbbcdksspddppzhhbmy", "vpeezzttkkuuggbffywwbccdkksspddppzzhbmyy", "vpezttkkuugbffyywbccdksspddppzhbbmmyy", "vvppezztkugbbffyywbbccdkksppdppzhbmyy", "vvpeezttkuggbbfyywwbbcddkksppdpzzhbbmyy", "vvpeztkuuggbffyywbbccdkksspddppzzhbbmy", "vppeezzttkugbbffyywbccddksppdppzzhbmmyy", "vppeezttkkuugbbfywwbccddkksspdpzhhbmmy", "vpeezzttkugbbffywbbccdkksspddppzhbbmyy", "vpeezttkkuugbbfywbbccddksppddppzzhhbmmy", "vpeezztkuuggbbffywwbbccddksspddpzzhhbbmmyy", "vppeezttkkuggbbffyywwbccdksspdpzzhbmy", "vpezzttkkuugbbfyywbbcdksspdppzzhbbmyy", "vvppezttkkuggbbfyywbbccdkksspddpzhbbmyy", "vvpezzttkuggbbffyywbbcdkksppdpzzhbmmyy", "vvpeztkugbfywwbccddkkspddpzhhbbmyy", "vvppezttkuugbbfyywwbcddkksspdppzhhbbmy", "vvpeeztkkuuggbbfywwbcdkspddpzzhhbmmy", "vvpeezttkugbffywbbccdkkssppddppzhhbbmyy", "vpeztkuuggbbfyywwbcddksppddpzhbbmy", "vppeztkuggbbfyywbcdksspdppzzhhbmy", "vppeezttkkugbbffyywbccddkksppdpzhhbmy", "vvppeeztkugbfyywbcdkksppdppzhbmyy", "vpezttkuugbbffywbcdksppddpzzhhbbmmy", "vppezzttkuugbfyywbcddkksspdpzhbbmmy", "vppezzttkkuggbffywbbcdksspdpzzhhbbmmyy", "vpezzttkuggbfyywbbccdksspdpzhhbbmmy", "vvppezttkkugbffyywbcdkssppdpzzhbmy", "vvpeezttkkuuggbbfyywbbccdkspdppzhhbmy", "vpeezttkkuugbfywbccddkksppddpzzhhbmmy", "vvppezttkuuggbbffywbbccdkksppdpzzhhbbmmy", "vvppeeztkuggbbffyywbccdksspddppzzhbmmyy", "vvppeezztkuggbfywwbccddkkspddpzhbbmy", "vpezttkuuggbfyywwbcdkkspdpzhhbbmmyy", "vppezzttkuggbffywbbcdkkssppddppzhhbmyy", "vppeztkuuggbffyywbccdkkspdppzzhhbmmyy", "vppeezztkuuggbfywbccddkksspddppzhhbbmyy", "vvppeztkuugbfywwbccdkkspddppzzhhbmmy", "vvpezztkuugbbffyywwbbccddksppdpzhbbmmyy", "vvpezzttkkuuggbffyywwbbcdkspdpzhbmmyy", "vvppeztkkuuggbbfyywbbccdksppdppzzhbmmyy", "vvppezztkuggbffyywwbcddkkssppdpzhbmmyy", "vvpezzttkkuggbbffywwbcddkksspdpzzhhbbmmy", "vpezztkkuuggbfyywwbccddkssppdppzhhbbmmy", "vvppezztkuugbffywwbccdkkspdppzhhbmmy", "vpeztkugbfyywwbcdkksspdppzzhbmmy", "vvpeezzttkkugbbfywwbcdkkspdpzzhhbmmy", "vpezzttkuuggbbfywbccdkspddppzzhhbbmmy", "vppeztkkuugbffyywwbbcddksspddppzhbbmyy", "vpeztkkuggbffyywbbccddkssppdppzhbmyy", "vvppeezztkuggbffyywwbcddkksppdppzhbmyy", "vpeezztkugbfyywbbccdkkspdppzhbmmyy", "vvppeezttkugbfywwbcddkkssppdppzhbmmyy", "vpeeztkuggbffywwbbccddksspdppzzhhbmmy", "vvppeeztkuugbfywbcddkssppddppzzhhbbmyy", "vpezzttkuggbbffyywwbbccdkssppddppzhbbmy", "vpezttkugbfywbbcddkksspddppzhbbmy", "vpeezzttkkuggbbffyywwbccddkspddppzhbmyy", "vppeezzttkugbffywbccdkkspddpzhhbbmyy", "vpezzttkuggbbfyywbbccdkksspddpzzhhbmmy", "vvppezttkugbfywwbbcdkksspddpzzhhbbmyy", "vppezztkkuggbffyywbcddkkssppddpzzhhbbmmy", "vppeztkkuggbfywwbccdkksppdppzhhbmmy", "vvpeezzttkugbffyywwbbcddkssppddpzzhbmmy", "vvpezztkkuuggbfyywbccdkksspddpzhhbbmyy", "vpezttkuuggbffywbbccdksppdpzhbmmyy", "vvpezzttkuggbbfywbccddksspdpzzhhbmmy", "vvpeezzttkkugbbfywwbcdkksppddpzhbmy", "vppeezttkkuugbbfyywwbcddkkspdpzhhbbmmyy", "vvppeeztkkuugbbfyywwbbcddkksspdppzhbbmyy", "vvpeezzttkkuugbfywwbbcddkspdpzzhbbmyy"
};
	int ans = expressiveWords(s, words);
	cout << ans << endl;


	return 0;
}
int expressiveWords(string s, vector<string>& words) {
	int ans = 0;
	for (int i = 0; i < words.size(); i++) {
		if (ok(s, words[i])) {
			ans++;
		}
	}
	return ans;
}
//通过双指针计算两个string中每个字母的个数，并比较
bool ok(string s1, string s2) {
	int p1 = 0, p2 = 0;
	
	int length1 = s1.size(), length2 = s2.size();
	while (p1<length1 && p2<length2){
		int cnt1 = 0, cnt2 = 0;
		char c = s1[p1];
		while (p1<length1 && s1[p1]==c)
		{
			p1++;
			cnt1++;
		}
		while (p2 < length2 && s2[p2] == c)
		{
			p2++;
			cnt2++;
		}
		if (cnt1 < cnt2 || (cnt1>cnt2 && cnt1<3)) {
			return 0;
		}
		
	}
	return p1 == length1 && p2 == length2;

}