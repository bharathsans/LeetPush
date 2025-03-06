class Solution {
public:
    int countVowelPermutation(int n) {
        const int m = 1e9 + 7;
        #define mod(a) (a)%m
        long long a, e, i, o, u, A, E, I, O, U; a = e = i = o = u = 1; n--;
        while (n--) {
            A = mod(e + i + u), 
            E = mod(a + i),
            I = mod(e + o),
            O = mod(i),
            U = mod(i + o);
            a = A, e = E, i = I, o = O, u = U;
        }
        return mod(a + e + i + o + u);
    }
};