#include <iostream>
using namespace std;

// §J§O«N…O∆Ó«p«s«r??
long long N, Q;
string S;
long long a[200009], b[200009], c[200009], d[200009];

// «À«ø«≥«·?«y≠p∫‚«@«r«F«h«U??
long long mod = 2147483647;
long long T[200009], H[200009];
long long Power100[200009];

// S[l, r] «U«À«ø«≥«·?«y™«@öT?
// ßE«q«U≠p∫‚«R™`∑N°I°]5.3 ∏`°^
long long Hash_value(int l, int r) {
	long long val = H[r] - (H[l - 1] * Power100[r - l + 1] % mod);
	if (val < 0) val += mod;
	return val;
}

int main() {
	// §J§O
	cin >> N >> Q;
	cin >> S;
	for (int i = 1; i <= Q; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

	// §Â¶r«y??«R?¥´°]C++ «U§Â¶r¶C«V 0 §Â¶r•ÿ∆Ò«p©l«e«r∆˘«O«R™`∑N°I°^
	for (int i = 1; i <= N; i++) T[i] = (S[i - 1] - 'a') + 1;

	// 100 «U n ?°]•ª§Â§§«U B^0, B^1, ... «R??°^«y´e≠p∫‚«@«r
	Power100[0] = 1;
	for (int i = 1; i <= N; i++) Power100[i] = 100LL * Power100[i - 1] % mod;

	// H[1], ..., H[N] «y≠p∫‚«@«r
	H[0] = 0;
	for (int i = 1; i <= N; i++) H[i] = (100LL * H[i - 1] + T[i]) % mod;

	// «´«§«Ê«Rµ™∆Ó«r
	for (int i = 1; i <= Q; i++) {
		long long Hash1 = Hash_value(a[i], b[i]);
		long long Hash2 = Hash_value(c[i], d[i]);
		if (Hash1 == Hash2) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}