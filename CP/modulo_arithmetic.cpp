int mod = 1e9+7;

((x%mod)+mod)%mod

// rule 1 -> #define int long long

// rule 2 -> take two at a time
(a*b*c)%mod => (((a*b)%mod)*c)%mod

// rule 3 -> never use pow function

(a^p % mod) -> (a^(p-1) . a)%mod , when p is odd
            -> (a^p/2 . a^p/2)%mod, when p is even
            
int mod = 1e9+7;
int binPow(int a, int p)
{
   if(p==0) return 1;
   if(p%2==0) return (binPow(a,p/2)*binPow(a,p/2))%mod;
   else return (a*binPow(a,p-1))%mod;
}

// rule 4 -> dividing

Fermat's little theorem
a^(p-1)%p = 1 , where p is prime number

Modular multiplicative inverse

a^(-1)%m =a^(m-2)%m

how derived?

a^(p-1)%p=1 => a.a^(p-2)%p=1 => a.a^(-1)%p=1 , a^(-1) = a^(p-2)

// rule 5 -> printing

((ans%mod)+mod)%mod


// Note - modulo can be taken inside expression anywhere on the same level
