1) you have 8 distinct book. In how many ways can they be arranged on a shelve if two specific books(says A and B) must have atleast 2 other books between them?
answer -> total - (0 books between them , AB or BA (act as 1 book)) - (1 book between them, A_B or B_A) 
8! - (7! * 2) - (6C1 * 2 * 6! )

2) From 15 candidate, how many ways can you form a committee of 6, if there are 3 particular candidate such that atmost one of them may be on the committee?
answer -> 3C0 * 12C6 + 3C1 * 12C5

3) BALLON, How many distinct arrangement are there if the two 0's must appear together?
answer -> 6! / 2!

4) x1+x2+x3+x4+x5=40, xi>=3
Find the number of valid integral solution

answer =>
y1+3+y2+3+y3+3+y4+3+y5+3=40
y1+y2+y3+y4+y5=25 , yi>=0

star and bar method 
x1+x2+x3...+xr = n, where xi>=0
(n+r-1)C(r-1)

5) nCr

int mod =1e9+7;
int fact[100100];
void pre(){
    fact[0]=1;
    for(int i=1;i<=100000;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
}

int binpow(int a, int p){
    if(p==0) return a;
    if(p%2!=0) return a*binpow(a,p-1)%mod;
    return binpow(a,p/2)*binpow(a,p/2)%mod;
}

int inv(int a){
    return binpow(a,mod-2);
}

nCr % mod

//log(mod)
int nCr(int n, int r){
    if(r<0||r>n) return 0;
    int num = fact[n];
    int deno = fact[n-r]*fact[r]%mod;
    return num * inv(deno) % mod;
}

How to calculate inverse of factorial - 
int ifact[100100];
ifact[0]=1;
// O(n) . log(mod)
for(int i=1;i<=100000;i++)
{
    ifact[i] = inv(fact[i]);
}

//o(1)
int nCr(int n, int r){
    if(r<0||r>n) return 0;
    int num = fact[n];
    int deno = ifact[n-r]*ifact[r]%mod;
    return (num * deno) % mod;
}

// another way to calculate ifact -> in O(1)
// inv(x!) * x = inv((x-1)!)
int ifact1[100100];
ifact1[100000] = inv(fact[100000]);
for(int i=100000;i>=1;i--){
    ifact1[i-1] = (ifact1[i]*i)%mod;
} 

// recurrence relation 
nCk = (n-1)C(k-1) + (n-1)Ck

// Hockey stick formula
rCr + (r+1)Cr + (r+2)Cr + ... + nCr = (n+1)Cr
